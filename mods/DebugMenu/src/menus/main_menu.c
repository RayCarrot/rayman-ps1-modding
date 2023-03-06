#include <export.h>
#include "main_menu.h"
#include "level_menu.h"
#include "cheats_menu.h"
#include "general_menu.h"
#include "menu.h"
#include "globals.h"

MENU(main_menu, "main",
    MENU_SUB_MENU("level...", &level_menu),
    MENU_SUB_MENU("cheats...", &cheats_menu),
    MENU_SUB_MENU("general...", &general_menu),
    MENU_NONE("display..."), // TODO: Implement
    MENU_NONE("options..."), // TODO: Implement
);
