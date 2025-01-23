#include <export.h>
#include "effects.h"
#include "effect_names.h"
#include "map_mods.h"
#include "mod.h"
#include "pause_screen.h"
#include "global.h"

int is_effect_available(int effect, short world, short level, uint currentEffects)
{
    // Wind right can't be used with wind left or in Allegro Presto part 2
    if (effect == EFFECT_WIND_LEFT)
    {
        if (world == 2 && level == 8)
        {
            return FALSE;
        }

        return (currentEffects & (1 << EFFECT_WIND_RIGHT)) == 0;
    }
    // Wind left can't be used with wind right or in Allegro Presto part 2
    else if (effect == EFFECT_WIND_RIGHT)
    {
        if (world == 2 && level == 8)
        {
            return FALSE;
        }

        return (currentEffects & (1 << EFFECT_WIND_LEFT)) == 0;
    }
    // No i-frames can't be used with tings hurt
    else if (effect == EFFECT_NO_IFRAMES)
    {
        return (currentEffects & (1 << EFFECT_TINGS_HURT)) == 0;
    }
    // Tings hurt can't be used with no i-frames and in certain levels as they're not possible
    else if (effect == EFFECT_TINGS_HURT)
    {
        // Check if no i-frames is used
        if (currentEffects & (1 << EFFECT_NO_IFRAMES))
        {
            return FALSE;
        }

        // Allegro Presto part 1 or 2
        if (world == 2 && (level == 7 || level == 8))
        {
            return FALSE;
        }
        // Crystal Palace part 1 or 2
        else if (world == 5 && (level == 1 || level == 2))
        {
            return FALSE;
        }
    }

    return TRUE;
}

// Have all effects in a single function to save space when compiled
void toggle_effect(int effect, int enable)
{
    BlockType btyp;

    switch (effect)
    {
        // Hide Rayman
        case EFFECT_HIDE_RAY:
            *(uint *)(0x8013c788) = enable ? NULL : 0xC04E927; // display2(&ray);
            break;

        // Hide level
        case EFFECT_HIDE_LVL:
            *(uint *)(0x8012f9f0) = enable ? NULL : 0xC04DE96; // DRAW_MAP();
            break;

        // Hide objects
        case EFFECT_HIDE_OBJ:
            uint value = enable ? NULL : 0xC04E927;
            *(uint *)(0x8013c89c) = value; // display2(obj);
            *(uint *)(0x8013c6d0) = value; // display2(obj);
            *(uint *)(0x8013c6e8) = value; // display2(obj);
            *(uint *)(0x8013c3e8) = value; // display2(obj);
            break;
        
        // Wind left/right
        case EFFECT_WIND_LEFT:
        case EFFECT_WIND_RIGHT:
            *(uint *)(0x80159C3C) = enable ? NULL : 0xC0566C5; // PS1_SetWindForce();
            break;

        // Double speed
        case EFFECT_DOUBLE_SPEED:
            // Walk
            ray.eta[1][0].speed_x_right = enable ? 64 : 32;
            ray.eta[1][0].speed_x_left = enable ? -64 : -32;
            
            // Run
            ray.eta[1][3].speed_x_right = enable ? 96 : 48;
            ray.eta[1][3].speed_x_left = enable ? -96 : -48;
            break;

        // Super jumps
        case EFFECT_SUPER_JUMPS:
            *(byte *)(0x80186ED0) = enable ? 0x1A : 0x0D; // Jump height
            break;

        // Super helico
        case EFFECT_SUPER_HELICO:
            if (!enable)
                RayEvts.flags0 &= ~RAYEVTS0_SUPER_HELICO;
            break;

        // Invert controls
        case EFFECT_INV_CONTROLS:
            *(ushort *)(0x80134E70) = enable ? PAD_RIGHT : PAD_LEFT;
            *(ushort *)(0x80134e80) = enable ? PAD_LEFT : PAD_RIGHT;

            *(ushort *)(0x80134e90) = enable ? PAD_DOWN : PAD_UP;
            *(ushort *)(0x80134ea0) = enable ? PAD_UP : PAD_DOWN;

            *(ushort *)(0x80134eb0) = enable ? PAD_TRIANGLE : PAD_CROSS;
            *(ushort *)(0x80134ee0) = enable ? PAD_CROSS : PAD_TRIANGLE;
            
            *(ushort *)(0x80134ec0) = enable ? PAD_SQUARE : PAD_CIRCLE;
            *(ushort *)(0x80134ed0) = enable ? PAD_CIRCLE : PAD_SQUARE;
            
            *(ushort *)(0x80134f34) = enable ? PAD_L1 : PAD_R1;
            *(ushort *)(0x80134f54) = enable ? PAD_R1 : PAD_L1;

            *(ushort *)(0x80134f44) = enable ? PAD_L2 : PAD_R2;
            *(ushort *)(0x80134f64) = enable ? PAD_R2 : PAD_L2;

            input_reload = enable ? INPUT_SQUARE : INPUT_CIRCLE;
            input_die = enable ? INPUT_CROSS : INPUT_TRIANGLE;
            break;

        // Slippery
        case EFFECT_SLIPPERY:
            if (enable)
            {
                make_map_slippery();
            }
            break;

        // Tings hurt
        case EFFECT_TINGS_HURT:
            if (enable)
            {
                flags[TYPE_WIZ].flags0 |= OBJ0_HIT_RAY;
                flags[TYPE_WIZ].flags2 &= ~OBJ2_DO_NOT_CHECK_RAY_COLLISION;
            }
            else
            {
                flags[TYPE_WIZ].flags0 &= ~OBJ0_HIT_RAY;
                flags[TYPE_WIZ].flags2 |= OBJ2_DO_NOT_CHECK_RAY_COLLISION;
            }
            break;

        // Darkness
        case EFFECT_DARKNESS:
            if (enable)
            {
                // Since we're not changing the condition for when this gets called we need to make sure to do so here
                INIT_LUCIOLE();
            }

            *(uint *)(0x8012f89c) = enable ? NULL : 0x14620008; // if (num_world == 5 && ...
            *(uint *)(0x8012f8b0) = enable ? NULL : 0x14620003; // ... num_level == 4)
            *(uint *)(0x80159c2c) = enable ? NULL : 0x10400003; // if ((RayEvts.flags1 & RAYEVTS1_LUCIOLE) != RAYEVTS1_NONE)
            *(uint *)(0x8013c3a4) = enable ? NULL : 0x1462001A; // if (num_world == 5 && ...
            *(uint *)(0x8013c3b8) = enable ? NULL : 0x14620015; // ... num_level == 4)
            break;
    }
}

void run_effect(int effect)
{
    Obj* blackRay;
    Obj* blackFist;

    switch (effect)
    {
        // Wind left
        case EFFECT_WIND_LEFT:
            ray_wind_force = -1;
            break;
        
        // Wind right
        case EFFECT_WIND_RIGHT:
            ray_wind_force = 1;
            break;

        // Super helico
        case EFFECT_SUPER_HELICO:
            RayEvts.flags0 |= RAYEVTS0_SUPER_HELICO;
            break;

        // Remove i-frames
        case EFFECT_NO_IFRAMES:
            ray.iframes_timer = -1;
            break;
    
        // Dark rayman
        case EFFECT_DARK_RAY:
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

            // Enable Dark Rayman if not enabled
            if ((blackRay->flags & OBJ_ALIVE) == 0)
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
            break;
    }
}
