#include <export.h>
#include "level_menu.h"
#include "menu.h"
#include "globals.h"

MENU(level_menu, "level",
    MENU_ACTION("skip", skip_level),
    MENU_ACTION("exit", exit_level),
    MENU_ACTION_PARAM("restart", update_level, 0),
    MENU_ACTION_PARAM("prev", update_level, -1),
    MENU_ACTION_PARAM("next", update_level, 1),
);

void skip_level()
{
    ChangeLevel();
}

void exit_level()
{
    new_world = 1;
}

void update_level(MenuItem *menuItem)
{
    new_level = 1;
    // TODO: Add check in prev/next level action so the new level exists
    num_level_choice = num_level + menuItem->param_1;
}
