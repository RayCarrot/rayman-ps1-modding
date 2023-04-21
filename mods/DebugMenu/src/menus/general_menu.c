#include <export.h>
#include "general_menu.h"
#include "menu.h"
#include "globals.h"

MENU(general_menu, "general",
    MENU_ACTION("checkpoint", checkpoint),
    MENU_ACTION("die", die),
    MENU_TOGGLE("small ray", small_ray),
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

void show_vram()
{
    PS1_DisplayVRAM();

    // Fix developer bug... they probably made a typo in the code
    PS1_Display2.field0_0x0.pad0 = 0;
}
