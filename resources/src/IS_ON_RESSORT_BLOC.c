#include <export.h>

extern byte button_released;
extern short jump_time;
extern Obj ray;
extern ObjTypeFlags flags[256];

int IS_ON_RESSORT_BLOC(Obj *obj)
{
    if ((obj->btypes[0] == BTYP_RESSORT) && (-1 < obj->speed_y)) 
    {
        if (obj->type == TYPE_RAYMAN) 
        {
            button_released = 1;
            set_main_and_sub_etat(&ray, 0, 0);
            ray_jump();
            PlaySnd(0xf9, -1);
            jump_time = 12;
            ray.speed_y -= 3;
            allocatePaillette(&ray);
            return 1;
        }
        else if (flags[obj->type].flags2 & OBJ2_JUMP_ON_RESSORT_BLOCK) 
        {
            obj_jump(obj);
            return 1;
        }
    }

    return 0;
}
