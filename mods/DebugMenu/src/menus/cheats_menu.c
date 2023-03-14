#include <export.h>
#include "cheats_menu.h"
#include "powers_menu.h"
#include "fist_menu.h"
#include "menu.h"
#include "globals.h"

MENU(cheats_menu, "cheats",
    MENU_TOGGLE("place ray", place_ray),
    MENU_ACTION("99 lives", max_lives),
    MENU_ACTION("all lvls", all_levels),
    MENU_SUB_MENU("fist...", &fist_menu),
    MENU_SUB_MENU("powers...", &powers_menu),
);

int place_ray(MenuItem *menuItem, int toggle)
{
    if (toggle)
        ray_mode = -ray_mode;
    
    return ray_mode < 1;
}

void max_lives()
{
    status_bar.num_lives = 99;
    
    // Since we're paused we need to manually
    // update the hud for it to show
    DO_FIXE();
}

void all_levels()
{
    for (byte i = 0; i < 24; i++)
        t_world_info[i].state = 1;
}
