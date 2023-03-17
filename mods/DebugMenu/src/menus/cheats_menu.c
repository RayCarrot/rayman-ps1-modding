#include <export.h>
#include "cheats_menu.h"
#include "powers_menu.h"
#include "fist_menu.h"
#include "menu.h"
#include "globals.h"

MENU(cheats_menu, "cheats",
    MENU_TOGGLE("place ray", place_ray),
    MENU_ACTION("99 lives", max_lives),
    MENU_TOGGLE("5 hp", _5_hp),
    MENU_ACTION("full health", full_health),
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

int _5_hp(MenuItem *menuItem, int toggle)
{
    bool has5hp = status_bar.max_hp == 4;

    if (toggle)
    {
        has5hp = !has5hp;
        status_bar.max_hp = has5hp ? 4 : 2;

        if (ray.hit_points > status_bar.max_hp)
            ray.hit_points = status_bar.max_hp;

        DO_FIXE();
    }
    
    return has5hp;
}

void full_health()
{
    ray.hit_points = status_bar.max_hp;    
    DO_FIXE();
}

void all_levels()
{
    for (byte i = 0; i < 24; i++)
        t_world_info[i].state = 1;
}
