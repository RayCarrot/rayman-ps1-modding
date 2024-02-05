#include "vis.h"

VisType vis_type=Read;

int vis_fd=NULL;
char *vis_buf=NULL;
int vis_n=NULL;

bool vis_interr=FALSE;
bool vis_displayed=TRUE;

int vis_counter=0;

SaveFrame frames[]=
{
    {.name="/name and pct/", .done=FALSE},
    {.name="/icon1/", .done=FALSE},
    {.name="/icon2/", .done=FALSE},
    {.name="/icon3/", .done=FALSE},
    {.name="/continues/", .done=FALSE},
    {.name="/wi save zone/", .done=FALSE},
    {.name="/rayevts/", .done=FALSE},
    {.name="/poing/", .done=FALSE},
    {.name="/status bar/", .done=FALSE},
    {.name="/hit points/", .done=FALSE},
    {.name="/save zone/", .done=FALSE},
    {.name="/bonus/", .done=FALSE},
    {.name="/options/", .done=FALSE},
    {.name="/world index/", .done=FALSE},
    {.name="/xmap/", .done=FALSE},
    {.name="/ymap/", .done=FALSE},
    {.name="/dir on map/", .done=FALSE},
    {.name="/bosses/", .done=FALSE},
};

bool vis()
{
    CLRSCR();
    readinput();
    //tried alternatives: InitCARD() StopCARD2()
    //should not be able to stop PS1_LoadSave before name and pct
    if(vis_counter>1 && TOUCHE(INPUT_CROSS)){ vis_interr=TRUE; }
    if(vis_counter>0 && !vis_interr)
    {
        switch(vis_type)
        {
            case Read:
                if(SaveFileRead(vis_fd,vis_buf,vis_n)>=0)
                {
                    frames[vis_counter-1].done=TRUE;
                }
                break;
            case Write:
                if(write(vis_fd, vis_buf, vis_n)>=0)
                {
                    frames[vis_counter-1].done=TRUE;
                }
                break;
            default:
                break;
        }
    }
    vis_draw();
    vis_counter++;
    return TRUE;
}

bool vis_continue()
{
    CLRSCR();
    readinput();
    if(TOUCHE(INPUT_L1)){ vis_displayed=FALSE; }
    if(TOUCHE(INPUT_R1)){ vis_displayed=TRUE; }
    vis_draw();
    display_text("start : continue", 200, SCREEN_HEIGHT-13, 2, 10);
    return TOUCHE(INPUT_START)!=NULL;
}

void vis_draw()
{
    char read_or_write[8];
    switch(vis_type)
    {
        case Read:
            strcpy(read_or_write, "loading");
            break;
        case Write:
            strcpy(read_or_write, "saving");
            break;
        default:
            break;
    }
    display_text(read_or_write, 0, 13, 2, 0);
    if(vis_displayed){ vis_draw_frames(); }
    display_text("x : interrupt", 0, SCREEN_HEIGHT-13, 2, 10);
}

void vis_draw_frames()
{
    int frames_size=sizeof(frames)/sizeof(frames[0]);
    for(int i=0; i<frames_size; i++)
    {
        display_text(frames[i].name, SCREEN_WIDTH/2, 0+13*(i+1), 2, frames[i].done==TRUE ? 7 : 2);
    }
}

void vis_reset()
{
    let_shadow=FALSE;

    vis_interr=FALSE;
    vis_counter=0;
    int frames_size=sizeof(frames)/sizeof(frames[0]);
    for(int i=0; i<frames_size; i++){ frames[i].done=FALSE; }
}

void vis_affiche_ecran_save()
{
    display_text("l1 | r1 : ", 2, SCREEN_HEIGHT-40, 2, 10);
    display_text("vis", 70, SCREEN_HEIGHT-40, 2, vis_displayed ? 7 : 2);
    if(TOUCHE(INPUT_L1)){ vis_displayed=FALSE; }
    if(TOUCHE(INPUT_R1)){ vis_displayed=TRUE; }
}