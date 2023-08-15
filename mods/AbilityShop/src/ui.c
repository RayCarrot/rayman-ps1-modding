#include <ui.h>

const int to_collect=80;
const int credits_start=20;
int credits_spent=0;

struct Menu menu=
{
    .x=2,
    .y=148,
    .selected_item=0,
    .cooldown=0,
    .def_cooldown=10
};
const char def_f_size=2;

struct MenuItem menu_items[]=
{
    {.text="full fist", .get=get_fist, .set=set_fist, .re_pos=0, .credits_req=20, .qty_start=1},
    {.text="hang", .get=get_re, .set=set_re, .re_pos=1, .credits_req=20, .qty_start=1},
    {.text="swing", .get=get_re, .set=set_re, .re_pos=7, .credits_req=20, .qty_start=1},
    {.text="heli", .get=get_re, .set=set_re, .re_pos=2, .credits_req=20, .qty_start=1},
    {.text="run", .get=get_re, .set=set_re, .re_pos=8, .credits_req=20, .qty_start=1},
    {.text="su heli", .get=get_re, .set=set_re, .re_pos=3, .credits_req=0, .qty_start=1},
};

char in_menu=0;
char full_fist_bought=0;

int coll_left(int coll)
{
    int res=to_collect-coll;
    if(res<0){ res=0; }
    return res;
}
int ui_credits(int coll){ return credits_start+coll-credits_spent; }

char get_fist(struct MenuItem *item){ return full_fist_bought; }
void set_fist(struct MenuItem *item){ set_item(item, 1); }

char get_re(struct MenuItem *item)
{
    struct Bit bit={.addr=(unsigned int)&RayEvts, .pos=item->re_pos};
    return bit2(bit);
}
void set_re(struct MenuItem *item){ set_item(item, 0); }

void set_item(struct MenuItem *item, char is_fist)
{
    if(!item->get(item) && ui_credits(collection())>=item->credits_req && item->qty>0)
    {
        if(is_fist){ full_fist_bought=1; }
        else{ RayEvts|= (1 << item->re_pos); }
        
        credits_spent+=item->credits_req;
        item->qty--;
    }
}

void ui_off(){ in_pause=0; in_menu=0; }
void ui_no_pause_text()
{
    if(!in_menu){ DO_AFFICHE_PAUSE(); }
}

int full_fist_enforce(short param_1,short x,short y,short w,short h,Obj *obj)
{
    int res=CHECK_BOX_COLLISION(param_1, x, y, w, h, obj);
    if(res!=-1)
    {
        if(!full_fist_bought)
        {
            if(obj->type==TYPE_CAGE || obj->type==TYPE_PT_GRAPPIN || obj->type==TYPE_ONEUP){ return res; }
            else{ do_boum(); PlaySnd(0xd6, obj->id); return -1; } //bonk
        }
    }
    return res;
}

void ui_update()
{
    ui_input();
    ui_display();
}

void ui_input()
{
    unsigned int *old_buttons=(unsigned int*)0x801cef04; //applying TOUCHE(INPUT_START) behavior (0x80134f08) to INPUT_SELECT
    char old_select=(*old_buttons & 0x100) != 0;

    if(PS1_Ingame && PS1_TOUCHE_0xA() && !old_select)
    {
        if(in_menu){ PS1_OnPauseOff(); } //also calls ui_off()
        else
        {
            in_pause=1; PS1_OnPauseOn(); in_menu=1;
            menu.cooldown=menu.def_cooldown;
        }
    }

    if(in_menu && menu.cooldown==0)
    {
        int menu_size=sizeof(menu_items)/sizeof(menu_items[0]);
        if(TOUCHE(INPUT_UP))
        {
            menu.selected_item--;
            if(menu.selected_item<0){ menu.selected_item=menu_size-1; }
            menu.cooldown=menu.def_cooldown;
        }
        if(TOUCHE(INPUT_DOWN))
        {
            menu.selected_item++;
            if(menu.selected_item>=menu_size){ menu.selected_item=0; }
            menu.cooldown=menu.def_cooldown;
        }
        if(TOUCHE(INPUT_CROSS))
        {
            struct MenuItem *item=&menu_items[menu.selected_item];
            item->set(item);
        }
        if(TOUCHE(INPUT_CIRCLE))
        {
            PS1_OnPauseOff();
            restoreGameState(&save2);
            new_world=1; //back to map
            RayEvts|=1; //mdd, if fist was unset
        }
    }
    if(menu.cooldown>0){ menu.cooldown--; }
}

void ui_display()
{
    int coll=collection();
    int coll_l=coll_left(coll);

    int cur_x=160;
    int cur_y=18;
    char coll_left_text[12]="";
    sprintf(coll_left_text, "/collect %i/", coll_l);
    display_text(coll_left_text, cur_x, cur_y, def_f_size, 0);
    if(in_menu)
    {
        cur_y+=16;
        display_text("/cage 1up mag/", cur_x, cur_y, def_f_size, 0);
        
        cur_x=2;
        cur_y=76;
        PS1_DisplayPadButton(3, cur_x, cur_y, def_f_size); //circle button
        cur_x+=14;
        display_text("map", cur_x, cur_y, def_f_size, 0);
    }

    int menu_size=sizeof(menu_items)/sizeof(menu_items[0]);
    cur_y=menu.y;
    for(int i=0; i<=menu_size; i++)
    {
        cur_x=menu.x;
        if(i==menu_size)
        {
            char cur_cred_text[12]="";
            sprintf(cur_cred_text, "cred %i", ui_credits(coll));
            display_text(cur_cred_text, cur_x, cur_y, def_f_size, 0);
        }
        else
        {
            struct MenuItem *item=&menu_items[i];
            int color=item->get(item) ? 7 : 2; //green, else red

            if(in_menu) //Draw fully
            {
                display_text(item->text, cur_x, cur_y, def_f_size, color);

                cur_x+=74;
                char cred_text[12]="";
                sprintf(cred_text, "%i", item->credits_req);
                display_text(cred_text, cur_x, cur_y, def_f_size, color);

                cur_x+=18;
                if(i==menu.selected_item){ PS1_DrawSprite(mapobj->sprites + 2, cur_x, cur_y-15, 0); } //Draw Fist

                cur_x+=24;
                if(i==5) //...
                {
                    char super_heli_desc[26]="";
                    sprintf(super_heli_desc, "one screen and mag", item->qty);
                    display_text(super_heli_desc, cur_x, cur_y, def_f_size, color);
                }
            }
            else //First letters
            {
                char first[2]="";
                strncpy(first, item->text, 1);
                display_text(first, cur_x, cur_y, def_f_size, color);
            }
        }
        cur_y+=11;
    }

    char done=coll_l<=0;
    if(PS1_Ingame){ fi_display(); }
    if(!in_menu){ /*dist_display(done);*/ timer_display(done); }
}

int prev_cnt=0;
void ui_debug()
{
    int cnt=GetRCnt(1);
    if(cnt-prev_cnt>=0){ printf("diff: %i\n", cnt-prev_cnt); }
    prev_cnt=cnt;

    extern unsigned short PS1_PolygonsCount;
    if(PS1_PolygonsCount>158){ printf("%s %i %i %i\n", timer_str, PS1_PolygonsCount, in_menu, in_pause); }
}