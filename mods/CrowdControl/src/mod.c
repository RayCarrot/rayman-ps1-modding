#include <export.h>
#include "mod.h"
#include "globals.h"

// Custom addresses that we set from the crowd control
#define DARK_RAY_ADDR 0x801e553c
#define DARKNESS_ADDR 0x801e5534
#define SPRITE_SHADE_ADDR 0x801e554c
#define SPRITE_SHADE_COLOR_ADDR 0x801e5554

int last_checked_dark_world = 0;
int last_checked_dark_level = 0;
bool has_dark_ray_spawner = 0;

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

    if (num_world != last_checked_dark_world || num_level != last_checked_dark_level)
    {
        last_checked_dark_world = num_world;
        last_checked_dark_level = num_level;
        
        has_dark_ray_spawner = 0;
    
        for (int i = 0; i < level.nb_objects; i++)
        {
            if (level.objects[i].type == TYPE_DARK && level.objects[i].init_main_etat == 0 && level.objects[i].init_sub_etat == 15)
            {
                has_dark_ray_spawner = 1;
                break;
            }
        }
    }

    // Don't run custom code if this level has a Dark Rayman spawner
    if (has_dark_ray_spawner)
        return;

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

    // Don't run in the level where it normally appears, or the one before since that's where the flag is set
    if (num_world == 5 && (num_level == 3 || num_level == 4))
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

void CC_SetSpriteShade(POLY_FT4 *polygon)
{
    int isEnabled;

    isEnabled = *(int *)SPRITE_SHADE_ADDR;

    if (isEnabled)
    {
        // Set color
        polygon->r0 = *(byte *)(SPRITE_SHADE_COLOR_ADDR + 0);
        polygon->g0 = *(byte *)(SPRITE_SHADE_COLOR_ADDR + 1);
        polygon->b0 = *(byte *)(SPRITE_SHADE_COLOR_ADDR + 2);

        // Enable shade
        SetShadeTex(polygon, 0);
    }
    else
    {
        // Disable shade
        SetShadeTex(polygon, 1);
    }
}
