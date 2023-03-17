#include <export.h>
#include "display_menu.h"
#include "menu.h"
#include "globals.h"

MENU(display_menu, "display",
    MENU_DISPLAY("map x", &xmap, 2),
    MENU_DISPLAY("map y", &ymap, 2),
    
    // TODO: Add PAL addresses
    #if BUILD == 0 // ntsc-u
    MENU_DISPLAY("speed x", (void *)0x801f61cc, 2), // ray.speed_x
    MENU_DISPLAY("speed y", (void *)0x801f61ce, 2), // ray.speed_y
    //MENU_DISPLAY("grav 1", (void *)0x801f61fb, 1), // ray_gravity_value_1
    //MENU_DISPLAY("grav 2", (void *)0x801f61fc, 1), // ray_gravity_value_2
    #endif

    MENU_DISPLAY("helico", &helico_time, 2),
    MENU_DISPLAY("jump", &jump_time, 2),
    MENU_DISPLAY("inertia", &decalage_en_cours, 2),
    MENU_DISPLAY("wind force", &ray_wind_force, 2),
);
