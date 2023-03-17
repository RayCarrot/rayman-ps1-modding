#include <export.h>
#include "display_menu.h"
#include "menu.h"
#include "globals.h"

MENU(display_menu, "display",
    MENU_DISPLAY("map x", &xmap, 2),
    MENU_DISPLAY("map y", &ymap, 2),
    MENU_DISPLAY("speed x", get_speed_x, DISPLAY_INT16 | DISPLAY_SIGNED | DISPLAY_DYNAMIC),
    MENU_DISPLAY("speed y", get_speed_y, DISPLAY_INT16 | DISPLAY_SIGNED | DISPLAY_DYNAMIC),
    MENU_DISPLAY("air right", get_air_speed_right, DISPLAY_INT8 | DISPLAY_SIGNED | DISPLAY_DYNAMIC),
    MENU_DISPLAY("air left", get_air_speed_left, DISPLAY_INT8 | DISPLAY_SIGNED | DISPLAY_DYNAMIC),
    MENU_DISPLAY("roll right", get_roll_speed_right, DISPLAY_INT8 | DISPLAY_SIGNED | DISPLAY_DYNAMIC),
    MENU_DISPLAY("roll left", get_roll_speed_left, DISPLAY_INT8 | DISPLAY_SIGNED | DISPLAY_DYNAMIC),
    MENU_DISPLAY("helico", &helico_time, DISPLAY_INT16 | DISPLAY_SIGNED),
    MENU_DISPLAY("jump", &jump_time, DISPLAY_INT16 | DISPLAY_SIGNED),
    MENU_DISPLAY("inertia", &decalage_en_cours, DISPLAY_INT16 | DISPLAY_SIGNED),
    MENU_DISPLAY("wind force", &ray_wind_force, DISPLAY_INT16 | DISPLAY_SIGNED),
);

int get_speed_x()
{
    return ray.speed_x;
}

int get_speed_y()
{
    return ray.speed_y;
}

int get_air_speed_right()
{
    return ray.eta[2][0].speed_x_right;
}

int get_air_speed_left()
{
    return ray.eta[2][0].speed_x_left;
}

int get_roll_speed_right()
{
    return ray.eta[2][0x11].speed_x_right;
}

int get_roll_speed_left()
{
    return ray.eta[2][0x11].speed_x_left;
}
