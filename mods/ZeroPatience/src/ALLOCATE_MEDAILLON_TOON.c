#include "globals.h"

void ALLOCATE_MEDAILLON_TOON(void)
{
    short nb_objs = level.nb_objects;
    short i = 0;
    Obj *cur_obj = level.objects;
  
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_MEDAILLON_TOON /*&& !(cur_obj->flags & FLG(OBJ_ACTIVE))*/)
        {
            /*cur_obj->init_x_pos =*/ cur_obj->x_pos = xmap - (cur_obj->offset_bx - 160);
            /*cur_obj->init_y_pos =*/ cur_obj->y_pos = ymap - cur_obj->offset_by;
            cur_obj->flags |= OBJ_ALIVE|OBJ_ACTIVE;
            cur_obj->flags &= ~OBJ_READ_CMDS;
            set_sub_etat(cur_obj, t_world_info[world_index].nb_cages + 32);
            if (t_world_info[world_index].nb_cages == 6)
                t_world_info[world_index].nb_cages = 5;
            t_world_info[world_index].nb_cages++;
            //gele = 1;
            h_scroll_speed = 0;
            v_scroll_speed = 0;

            cur_obj->active_timer = 0;
            cur_obj->active_flag = 0;
            cur_obj->display_prio = 7;
            break;
        }
        cur_obj++;
        i++;
    }
}