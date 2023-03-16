#ifndef MENU_H
#define MENU_H

#include <export.h>

// Macros
#define MENU_SUB_MENU(name, subMenu) { .text=name, .type=MENU_SUB_MENU, .param_0=subMenu}
#define MENU_ACTION(name, func) { .text=name, .type=MENU_ACTION, .param_0=func}
#define MENU_ACTION_PARAM(name, func, param) { .text=name, .type=MENU_ACTION, .param_0=func, .param_1=param}
#define MENU_TOGGLE(name, func) { .text=name, .type=MENU_TOGGLE, .param_0=func}
#define MENU_TOGGLE_PARAM(name, func, param) { .text=name, .type=MENU_TOGGLE, .param_0=func, .param_1=param}
#define MENU_NONE(name) { .text=name, .type=MENU_NONE}
#define MENU(varName, name, ...) MenuItem varName##Items[] = {\
        __VA_ARGS__\
    };\
  Menu varName = { .text = name, .count = sizeof(varName##Items)/sizeof(varName##Items[0]), .items = varName##Items };\

// Enums
enum MENUITEMTYPE { MENU_NONE, MENU_SUB_MENU, MENU_ACTION, MENU_TOGGLE };

// Structs
typedef struct 
{
    char text[12];
    byte type;
    byte shortcutInput;
    short param_1;
    void *param_0;
} MenuItem;

typedef struct
{
    char text[8];
    byte count;
    byte selectedItem;
    MenuItem* items;
} Menu;

// Functions
void DO_DMENUS();
void DO_DMENUS_SHORTCUTS();
void CHANGE_DMENU(Menu *menu);
void DO_DMENU(Menu *menu);
void DO_DMENU_ACTION(MenuItem *menuItem);
void DISPLAY_DMENU(Menu *menu);
void DO_DMENU_SHORTCUTS(Menu *menu);
bool check_inputs();

#endif
