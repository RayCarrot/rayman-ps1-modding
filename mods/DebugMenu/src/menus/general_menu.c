#include <export.h>
#include "general_menu.h"
#include "menu.h"
#include "globals.h"

MENU(general_menu, "general",
    MENU_ACTION("checkpoint", checkpoint),
    MENU_ACTION("die", die),
    MENU_TOGGLE("small ray", small_ray),
    MENU_TOGGLE("dark ray", dark_ray),
    MENU_ACTION("vram", show_vram),
);

void checkpoint()
{
    ray.flags |= OBJ_ACTIVE;
    restore_gendoor_link();
    saveGameState(0x0, &save1);
    correct_gendoor_link();
}

void die()
{
    if ((ray.flags & (OBJ_ALIVE | OBJ_ACTIVE)) == (OBJ_ALIVE | OBJ_ACTIVE))
    {
        ray.hit_points = 0;
        RAY_HIT(1, (Obj *)0x00);
        in_pause = 0;
        PS1_OnPauseOff();
    }
}

int small_ray(MenuItem *menuItem, int toggle)
{
    if (toggle && reduced_rayman_id != -1) 
        RAY_DEMIRAY();

    return (RayEvts & 0x200) != 0;
}

int dark_ray(MenuItem *menuItem, int toggle)
{
    Obj* blackRay;
    Obj* blackFist;
    int isEnabled;

    blackRay = findfirstObject(TYPE_BLACK_RAY);

    if (blackRay->type != TYPE_BLACK_RAY)
        blackRay = 0x00;

    isEnabled = blackRay != 0x00 && (blackRay->flags & OBJ_ALIVE) != 0;

    if (toggle) 
    {
        isEnabled = !isEnabled;

        if (blackRay == 0x00)
        {
            // Rayman's feet are unused in every level, so convert to Dark Rayman
            blackRay = findfirstObject(TYPE_PIEDS_RAYMAN);
            
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

        if (isEnabled)
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
        else
        {
            blackRay->flags &= ~(OBJ_ALIVE|OBJ_ACTIVE);
            blackRay->speed_x = 0;
            blackRay->speed_y = 0;
            DO_NOVA(blackRay);
            level.objects[black_fist_obj_id].flags &= ~(OBJ_ALIVE|OBJ_ACTIVE);
        }
    }

    return isEnabled;
}

void show_vram()
{
    PS1_DisplayVRAM();

    // Fix developer bug... they probably made a typo in the code
    PS1_Displays[1].field0_0x0.pad0 = 0;
}
