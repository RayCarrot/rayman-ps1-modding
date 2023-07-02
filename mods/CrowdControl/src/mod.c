#include <export.h>
#include "mod.h"
#include "globals.h"

#define DARK_RAY_ADDR 0x801e553c
#define DARKNESS_ADDR 0x801e5534

void CC_LEVEL()
{
    CC_Dark_RAY();
    CC_Darkness();
}

void CC_Dark_RAY()
{
    Obj* blackRay;
    Obj* blackFist;
    int isEnabled;

    isEnabled = *(int *)DARK_RAY_ADDR;
    
    // If the effect is disabled and we don't have a Dark Rayman then we do nothing
    if (!isEnabled && black_ray_obj_id == -1)
        return;

    // Create Dark Rayman if it doesn't exist
    if (black_ray_obj_id == -1)
    {
        // Rayman's feet are unused in every level, so convert to Dark Rayman
        blackRay = findfirstObject(TYPE_PIEDS_RAYMAN);
        black_ray_obj_id = blackRay->id;
        
        // Set fields
        memcpy(blackRay, &raytmp, 24);
        blackRay->offset_bx = 80;
        blackRay->offset_by = 80;
        blackRay->offset_hy = 20;
        blackRay->hit_points = 0;
        blackRay->hit_sprite = 254;
        set_main_and_sub_etat(blackRay, 0, 0);
        blackRay->type = TYPE_BLACK_RAY;
        first_obj_init(blackRay);
        obj_init(blackRay);

        // Use one of the nova effect objects for Dark Rayman's fist
        blackFist = findfirstObject(TYPE_NOVA2);
        black_fist_obj_id = blackFist->id;

        // Set fields
        memcpy(blackFist, &level.objects[poing_obj_id], 24);
        blackFist->offset_bx = 60;
        blackFist->offset_by = 48;
        blackFist->offset_hy = 32;
        blackFist->hit_points = 1;
        blackFist->hit_sprite = 254;
        set_main_and_sub_etat(blackFist, 5, 1);
        blackFist->type = TYPE_BLACK_FIST;
        first_obj_init(blackFist);
        obj_init(blackFist);
    }

    // Get Dark Rayman
    blackRay = &level.objects[black_ray_obj_id];

    // If we want him enabled and he's dead then we have to re-enable him
    if (isEnabled && (blackRay->flags & OBJ_ALIVE) == 0)
    {
        blackRay->flags |= (OBJ_ALIVE | OBJ_ACTIVE);
        blackRay->hit_points = 0xfe;
        set_main_and_sub_etat(blackRay, 0, 0);
        blackRay->x_pos = 0;
        blackRay->y_pos = 0;
        blackRay->init_x_pos = ray.x_pos;
        blackRay->init_y_pos = ray.y_pos;
        blackRay->display_prio = 0;

        ray_stack_is_full = 0;
        ray_pos_in_stack = 0;
        black_pos_in_stack = 0;
    }
    // If we want him disabled and he's alive then we have to disable him
    else if (!isEnabled && (blackRay->flags & OBJ_ALIVE) != 0)
    {
        blackRay->flags &= ~(OBJ_ALIVE|OBJ_ACTIVE);
        blackRay->speed_x = 0;
        blackRay->speed_y = 0;
        DO_NOVA(blackRay);
        level.objects[black_fist_obj_id].flags &= ~(OBJ_ALIVE|OBJ_ACTIVE);
    }
}

void CC_Darkness()
{
    int isEnabled;
    int wasEnabled;

    // Don't run in the level where it normally appears
    if (num_world == 5 && num_level == 4)
    {
        return;
    }

    isEnabled = *(int *)DARKNESS_ADDR;
    wasEnabled = RayEvts.flags1 & RAYEVTS1_LUCIOLE;

    // Enable
    if (isEnabled && !wasEnabled)
    {
        INIT_LUCIOLE();
        RayEvts.flags1 |= RAYEVTS1_LUCIOLE;
        *(uint *)(0x8012f89c) = NULL; // if (num_world == 5 && ...
        *(uint *)(0x8012f8b0) = NULL; // ... num_level == 4)
        *(uint *)(0x80159c2c) = NULL; // if ((RayEvts.flags1 & RAYEVTS1_LUCIOLE) != RAYEVTS1_NONE)
        *(uint *)(0x8013c3a4) = NULL; // if (num_world == 5 && ...
        *(uint *)(0x8013c3b8) = NULL; // ... num_level == 4)
    }
    // Disable
    else if (!isEnabled && wasEnabled)
    {
        RayEvts.flags1 &= ~RAYEVTS1_LUCIOLE;
        *(uint *)(0x8012f89c) = 0x14620008; // if (num_world == 5 && ...
        *(uint *)(0x8012f8b0) = 0x14620003; // ... num_level == 4)
        *(uint *)(0x80159c2c) = 0x10400003; // if ((RayEvts.flags1 & RAYEVTS1_LUCIOLE) != RAYEVTS1_NONE)
        *(uint *)(0x8013c3a4) = 0x1462001A; // if (num_world == 5 && ...
        *(uint *)(0x8013c3b8) = 0x14620015; // ... num_level == 4)
    }
}

int CC_IS_ON_RESSORT_BLOC(Obj *obj)
{
    if ((block_flags[obj->btypes[0]] & BLOCK_SOLID) && (-1 < obj->speed_y)) 
    {
        if (obj->type == TYPE_RAYMAN) 
        {
            button_released = 1;
            set_main_and_sub_etat(&ray, 0, 0);
            ray_jump();
            //PlaySnd(0xf9, -1); - the bounce sound doesn't exist in most worlds
            jump_time = 12;
            ray.speed_y -= 3;
            //allocatePaillette(&ray); - the RAYON sparkles object only exists in Image levels
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

void CC_Tings_Heal(short snd, short objId)
{
    // Call function we overwrote
    PlaySnd(snd, objId);

    ray.hit_points++;
    
    if (status_bar.max_hp < ray.hit_points) 
    {
        ray.hit_points = status_bar.max_hp;
    }
}
