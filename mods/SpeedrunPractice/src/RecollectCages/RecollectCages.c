#include <export.h>
#include "Cheats/Cheats.h"

void break_cage(Obj *obj)
{
    // Only change the initial state values if the cage should remain collected
    if (cheatsInfo.collectCages)
    {
        obj->init_main_etat = 0;
        obj->init_sub_etat = 8;
        obj->init_x_pos = obj->x_pos;
        obj->init_y_pos = obj->y_pos;
    }

    // Break the cage
    set_sub_etat(obj, 0xc);
    obj->init_flag = 7;
    ALLOCATE_MEDAILLON_TOON();
    lidol_to_allocate = 5;
    lidol_source_obj = obj;

    // Conditionally count as collected
    if (cheatsInfo.collectCages)
    {
        Nb_total_cages = Nb_total_cages + 1;
        take_bonus((int)obj->id);
    }
    else
    {
        // If we don't count as collected them reset the level cage count that ALLOCATE_MEDAILLON_TOON incremented
        t_world_info[world_index].nb_cages = 0;
    }
}
