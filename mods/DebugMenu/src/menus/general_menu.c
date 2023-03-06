#include <export.h>
#include "general_menu.h"
#include "menu.h"
#include "globals.h"

MENU(general_menu, "general",
    MENU_ACTION("checkpoint", checkpoint),
    MENU_TOGGLE("small ray", small_ray),
    MENU_ACTION("vram", show_vram),
);

void checkpoint()
{
    ray.flags |= 0x800;
    restore_gendoor_link();
    saveGameState(0x0, &save1);
    correct_gendoor_link();
}

int small_ray(MenuItem *menuItem, int toggle)
{
    if (toggle && reduced_rayman_id != -1) 
        RAY_DEMIRAY();

    return (RayEvts & 0x200) != 0;
}

void show_vram()
{
    // TODO: This doesn't reset all display values correctly thus causing screen shake. We should manually fix that.
    PS1_DisplayVRAM();
}
