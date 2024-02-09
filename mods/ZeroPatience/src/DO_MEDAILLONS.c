#include "globals.h"

void DO_MEDAILLONS(void)
{
    short i;
    Obj *cur_obj;
    WorldInfo *cur_wi;
    byte nb_cages;
    byte flag_set;

    /*if (chemin_percent < 100 && horloge[2] != 0)
        chemin_percent++;*/
    if (chemin_percent < 100)
        chemin_percent = 100;
    i = 0;
    cur_obj = mapobj;
    cur_wi = &t_world_info[0];
    while(i < 24)
    {
        CalcObjPosInWorldMap(cur_obj);
        if ((*(unsigned long *)(&cur_wi->state) & 4) && chemin_percent > 98)
        {
            *(unsigned long *)(&cur_wi->state) = *(unsigned long *)(&cur_wi->state) & ~(1 << 2) | 1;
            set_sub_etat(cur_obj, 46);
        }
        if (
            i == 17 &&
            cur_obj->sub_etat != 59 && cur_obj->sub_etat != 46 &&
            *(unsigned long *)(&cur_wi->state) & 1
        )
            set_sub_etat(cur_obj, 59);
        else if (
            (i == 18 || i == 19 || i == 20 || i == 21 || i == 22 || i == 23) &&
            !(cur_obj->sub_etat == 58 || cur_obj->sub_etat == 46) &&
            *(unsigned long *)(&cur_wi->state) & 1
        )
            set_sub_etat(cur_obj, 58);
        else
        {
            nb_cages = cur_wi->nb_cages;
            if (
                nb_cages > 5 && cur_obj->sub_etat == 51 &&
                (flag_set = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x10,
                    (!flag_set || cur_obj->anim_frame == 0) &&
                    (flag_set || cur_obj->anim_frame == cur_obj->animations[cur_obj->anim_index].frames_count - 1) &&
                    horloge[cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf] == 0
                )
            )
                set_sub_etat(cur_obj, 52);
            else if (
                nb_cages > 4 && cur_obj->sub_etat == 50 &&
                (flag_set = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x10,
                    (!flag_set || cur_obj->anim_frame == 0) &&
                    (flag_set || cur_obj->anim_frame == cur_obj->animations[cur_obj->anim_index].frames_count - 1) &&
                    horloge[cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf] == 0
                )
            )
                set_sub_etat(cur_obj, 51);
            else if (
                nb_cages > 3 && cur_obj->sub_etat == 49 &&
                (flag_set = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x10,
                    (!flag_set || cur_obj->anim_frame == 0) &&
                    (flag_set || cur_obj->anim_frame == cur_obj->animations[cur_obj->anim_index].frames_count - 1) &&
                    horloge[cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf] == 0
                )
            )
                set_sub_etat(cur_obj, 50);
            else if (
                nb_cages > 2 && cur_obj->sub_etat == 48 &&
                (flag_set = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x10,
                    (!flag_set || cur_obj->anim_frame == 0) &&
                    (flag_set || cur_obj->anim_frame == cur_obj->animations[cur_obj->anim_index].frames_count - 1) &&
                    horloge[cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf] == 0
                )
            )
                set_sub_etat(cur_obj, 49);
            else if (
                nb_cages > 1 && cur_obj->sub_etat == 47 &&
                (flag_set = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x10,
                    (!flag_set || cur_obj->anim_frame == 0) &&
                    (flag_set || cur_obj->anim_frame == cur_obj->animations[cur_obj->anim_index].frames_count - 1) &&
                    horloge[cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf] == 0
                )
            )
                set_sub_etat(cur_obj, 48);
        }
        DO_ANIM(cur_obj);
        cur_obj++;
        i++;
        cur_wi++;
    }
}