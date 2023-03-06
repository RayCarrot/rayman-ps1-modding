#include <export.h>
#include "powers_menu.h"
#include "menu.h"
#include "globals.h"

MENU(powers_menu, "powers",
    MENU_TOGGLE_PARAM("fist", toggle_power, 1 << 0),
    MENU_TOGGLE_PARAM("hang", toggle_power, 1 << 1),
    MENU_TOGGLE_PARAM("helico", toggle_power, 1 << 2),
    MENU_TOGGLE_PARAM("superhelico", toggle_power, 1 << 3),
    MENU_TOGGLE_PARAM("seed", toggle_power, 1 << 6),
    MENU_TOGGLE_PARAM("grab", toggle_power, 1 << 7),
    MENU_TOGGLE_PARAM("run", toggle_power, 1 << 8),
    MENU_TOGGLE_PARAM("force-run", toggle_power, 1 << 12),
    MENU_TOGGLE_PARAM("reversed", toggle_power, 1 << 13),
);

int toggle_power(MenuItem *menuItem, int toggle)
{
    if (toggle)
        RayEvts ^= menuItem->param_1;

    return (RayEvts & menuItem->param_1) != 0;
}