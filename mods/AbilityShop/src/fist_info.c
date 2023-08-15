#include <fist_info.h>

char fi_is_gold()
{
    return (level.objects[poing_obj_id].init_sub_etat >> 3) & 1;
}

char fi_speed()
{
    return (level.objects[poing_obj_id].init_sub_etat >> 1) & 0b11;
}

void fi_display()
{
    int cur_x=10;
    int cur_y=42;
    PS1_DrawSprite(mapobj->sprites + (fi_is_gold() ? 1 : 2), cur_x, cur_y, 1);
    cur_x+=25;
    cur_y+=5;

    for(int i=0; i<fi_speed(); i++)
    {
        PS1_DrawSprite(mapobj->sprites + 18, cur_x, cur_y, 0);
        cur_x+=15;
    }
}