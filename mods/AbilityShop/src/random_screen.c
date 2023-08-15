#include <random_screen.h>

char seed[9]="";

char num_level_rand=0;
char magician_return=-1;

char levels_rand[18][10];

struct Magician magician_screens[]=
{
    {.world=1, .screen=2, .directs_to=21},
    {.world=1, .screen=4, .directs_to=20},
    {.world=1, .screen=11, .directs_to=18},
    {.world=1, .screen=12, .directs_to=19},
    {.world=2, .screen=4, .directs_to=17},
    {.world=2, .screen=9, .directs_to=18},
    {.world=3, .screen=4, .directs_to=12},
    {.world=3, .screen=9, .directs_to=13},
    {.world=4, .screen=3, .directs_to=12},
    {.world=4, .screen=9, .directs_to=13},
    {.world=5, .screen=2, .directs_to=12},
};

struct Menu rs_menu=
{
    .x=70,
    .y=180,
    .selected_item=8,
    .cooldown=0,
    .def_cooldown=10
};

void rs_options()
{
    if(!new_game_started)
    {
        char seed_text[]="screen seed:";
        display_text(seed_text, rs_menu.x, rs_menu.y, def_f_size, 0);

        int text_width=PS1_CalcTextWidth(seed_text, def_f_size);
        int cur_x=rs_menu.x+text_width;
        int cur_y=rs_menu.y;
        int dig_count=sizeof(seed)/sizeof(seed[0]);
        int sel_it=rs_menu.selected_item;
        for(int i=0; i<dig_count; i++)
        {
            char cur_dig[2]="";
            sprintf(cur_dig, "%i", seed[i]);
            display_text(cur_dig, cur_x, cur_y, def_f_size, i==sel_it ? 7 : 2);
            cur_x+=10;
        }

        if(rs_menu.cooldown==0)
        {
            if(TOUCHE(INPUT_L1))
            {
                rs_menu.selected_item--;
                if(rs_menu.selected_item<0){ rs_menu.selected_item=dig_count-1; }
                rs_menu.cooldown=rs_menu.def_cooldown;
            }
            if(TOUCHE(INPUT_R1))
            {
                rs_menu.selected_item++;
                if(rs_menu.selected_item>=dig_count){ rs_menu.selected_item=0; }
                rs_menu.cooldown=rs_menu.def_cooldown;
            }
            if(TOUCHE(INPUT_L2))
            {
                seed[sel_it]--;
                if(seed[sel_it]<0){ seed[sel_it]=9; }
                rs_menu.cooldown=rs_menu.def_cooldown;
            }
            if(TOUCHE(INPUT_R2))
            {
                seed[sel_it]++;
                if(seed[sel_it]>9){ seed[sel_it]=0; }
                rs_menu.cooldown=rs_menu.def_cooldown;
            }
        }
        if(rs_menu.cooldown>0){ rs_menu.cooldown--; }
    }
}

void rs_new_game_start()
{
    char levels[18][10]=
    {
        {1, 2, 4}, //PPW
        {5, 6, 7},
        {9, 10, 11},
        {12, 13, 14, 15, 16},
        {1, 2, 3, 4, 5, 6}, //BH
        {7, 8, 9, 10},
        {12, 13},
        {14, 15, 16},
        {1, 2}, //TG
        {3, 4, 5},
        {6, 7, 8, 9, 10},
        {1, 2, 3, 4}, //EP
        {5, 6, 7},
        {8, 9, 10, 11},
        {1, 2}, //CP
        {3, 4, 5, 6, 7, 8},
        {9, 10, 11},
        {1, 2, 3, 4} //MDD
    };

    memcpy(levels_rand, levels, sizeof(levels));

    Sax.saved_hp=12;
    finBosslevel[1]=finBosslevel[1] | (1 << 1); //Helped joe
    finBosslevel[1]=finBosslevel[1] | (1 << 2);
    unsigned int seed_uint=digits_uint();
    if(seed_uint!=0)
    {
        srand(seed_uint);
        shuffle_screens();
    }
}

unsigned int digits_uint()
{
    unsigned int res=0;
    unsigned int mul=1;

    int dig_count=sizeof(seed)/sizeof(seed[0]);
    for(int i=dig_count-1; i>=0; i--)
    {
        res+=mul*seed[i];
        mul*=10;
    }
    return res;
}

void shuffle_screens()
{
    int level_count=sizeof(levels_rand)/sizeof(levels_rand[0]);
    for(int i=0; i<level_count; i++)
    {
        shuffle(levels_rand[i], strlen(levels_rand[i]));
        print_codes(levels_rand[i], t_world_info[i].level-1); //normalize down to numbers 1, 2, etc.
    }
}

void print_codes(char *codes, char sub)
{
    char str[100]="";
    int len=strlen(codes);
    for(int i=0; i<len; i++)
    {
        char cur[10]="";
        char cur_code=codes[i]-sub;
        if(i==len-1){ sprintf(cur, "%i", cur_code);  }
        else{ sprintf(cur, "%i, ", cur_code); }
        strcat(str, cur);
    }
    printf("%s\n", str);
}

void starting_level()
{
    if(ModeDemo==0) //demo should load it's usual screens
    {
        num_level_rand=0;
        num_level_choice=levels_rand[world_index][num_level_rand];
    }
}

char find_magician()
{
    int magician_count=sizeof(magician_screens)/sizeof(magician_screens[0]);
    for(int i=0; i<magician_count; i++)
    {
        struct Magician cur=magician_screens[i];
        if(cur.world==num_world && cur.screen==num_level)
        {
            return cur.directs_to;
        }
    }
    return -1;
}

void rs_fix_numlevel(Obj *obj)
{
    new_level=1;
    if(magician_return!=-1)
    {
        num_level_choice=magician_return;
        magician_return=-1;
        SauveRayEvts=RayEvts;
        return;
    }

    new_level_init(); //doing this earlier would overwrite rayman's position for magician_return
    if(obj->type==TYPE_WIZARD1)
    {
        char found=find_magician();
        if(found!=-1)
        {
            num_level_choice=found;
            magician_return=num_level;
            SauveRayEvts=RayEvts;
        }
        return;
    }

    num_level_rand++;
    int level_count=strlen(levels_rand[world_index]);
    if(num_level_rand>=level_count){ new_world=1; }
    else
    {
        num_level_choice=levels_rand[world_index][num_level_rand];
    }
}

void rs_magician_su_heli()
{
    //set during magician, set after
    RayEvts|=SauveRayEvts;
    if(magician_return==-1){ SauveRayEvts=0; }
}