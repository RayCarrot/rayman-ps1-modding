#include <export.h>
#include "menu.h"
#include "menus/main_menu.h"
#include "globals.h"

// TODO: Save assigned shortcuts in memory card
// TODO: Polygon count of 200 might get reached in final boss due to text shadows
// TODO: Disable other inputs when holding down SELECT for shortcuts

// Constants
#define MENU_STACK_SIZE 3
#define MENU_MAX_ITEMS_ON_SCREEN 7
#define MENU_SCROLL_START 3
#define MENU_LINE_HEIGHT 20
#define VALID_INPUTS_LENGTH 15
#define SOUND_NAVIGATE 0x44
#define SOUND_SELECT 0x45
#define SOUND_RETURN 0x4d

// Variables
byte input_cooldown;
byte menu_stack_index = 0xFF;
Menu *menu_stack[MENU_STACK_SIZE];
bool is_mapping_shortcuts;
bool has_mapped_shortcuts;
byte held_down_button;
char input_names[] =  // Single string to save space
    "\0"
    "left\0"
    "right\0"
    "up\0"
    "down\0"
    "*\0" // Cross
    "\xf8\0" // Circle
    "~\0" // Square
    "%\0" // Triangle
    "\0" // Start
    "\0" // Select
    "r1\0"
    "r2\0"
    "l1\0"
    "l2";

void DO_DMENUS()
{
    if (menu_stack_index == 0xFF)
        CHANGE_DMENU(&main_menu);

    if (check_inputs())
        DO_DMENU(menu_stack[menu_stack_index]);
    
    DISPLAY_DMENU(menu_stack[menu_stack_index]);
}

void DO_DMENUS_SHORTCUTS()
{
    if (!check_inputs())
        return;

    DO_DMENU_SHORTCUTS(&main_menu);
}

void CHANGE_DMENU(Menu *menu)
{
    if ((byte)(menu_stack_index + 1) >= MENU_STACK_SIZE)
        return;

    menu_stack_index++;
    menu_stack[menu_stack_index] = menu;
}

void DO_DMENU(Menu *menu)
{
    MenuItem *selectedItem = menu->items + menu->selectedItem;

    if (TOUCHE(INPUT_SELECT) && (selectedItem->type == MENU_ACTION || selectedItem->type == MENU_TOGGLE))
    {
        is_mapping_shortcuts = 1;

        for (ushort i = 1; i < VALID_INPUTS_LENGTH; i++)
        {
            if (i != INPUT_START && i != INPUT_SELECT && TOUCHE(i))
            {
                held_down_button = i;

                selectedItem->shortcutInput = i;

                PlaySnd_old(SOUND_NAVIGATE);
                has_mapped_shortcuts = 1;
                break;
            }
        }
    }
    else
    {
        // Remove mapped shortcut
        if (is_mapping_shortcuts && !has_mapped_shortcuts)
            selectedItem->shortcutInput = INPUT_NONE;

        is_mapping_shortcuts = 0;
        has_mapped_shortcuts = 0;

        if (TOUCHE(INPUT_DOWN))
        {
            held_down_button = INPUT_DOWN;
            
            if (menu->selectedItem < menu->count - 1)
                menu->selectedItem++;
            else
                menu->selectedItem = 0;

            PlaySnd_old(SOUND_NAVIGATE);
        }
        else if (TOUCHE(INPUT_UP))
        {
            held_down_button = INPUT_UP;

            if (menu->selectedItem > 0)
                menu->selectedItem--;
            else
                menu->selectedItem = menu->count - 1;

            PlaySnd_old(SOUND_NAVIGATE);
        }
        else if (TOUCHE(INPUT_CIRCLE))
        {
            if (menu_stack_index > 0)
            {
                held_down_button = INPUT_CIRCLE;
                menu_stack_index--;
                PlaySnd_old(SOUND_RETURN);
            }
        }
        else if (TOUCHE(INPUT_CROSS))
        {
            held_down_button = INPUT_CROSS;
            DO_DMENU_ACTION(selectedItem);
            PlaySnd_old(SOUND_SELECT);
        }
    }
}

void DO_DMENU_ACTION(MenuItem *menuItem)
{
    switch (menuItem->type)
    {
        case MENU_SUB_MENU:
            CHANGE_DMENU(menuItem->param_0);
            break;

        case MENU_ACTION:
            ((void (*)(MenuItem *))menuItem->param_0)(menuItem);
            break;

        case MENU_TOGGLE:
            ((int (*)(MenuItem *, int toggle))menuItem->param_0)(menuItem, 1);
            break;
    }
}

void DISPLAY_DMENU(Menu *menu)
{
    short yPos;
    byte color;

    display_text(menu->text, 20, 65, 2, 0x02);

    if (menu->count > MENU_MAX_ITEMS_ON_SCREEN && menu->selectedItem > (MENU_SCROLL_START - 1))
    {
        int scrollPos = menu->selectedItem;

        if (menu->count - scrollPos <= MENU_SCROLL_START)
            scrollPos = menu->count - MENU_SCROLL_START;

        yPos = 90 - (scrollPos * MENU_LINE_HEIGHT) + (MENU_SCROLL_START * MENU_LINE_HEIGHT);
    }
    else
    {
        yPos = 90;
    }

    MenuItem *menuItem = menu->items;

    for (byte i = 0; i < menu->count; i++)
    {
        // Get the color - have it be multi-colored if selected
        color = menu->selectedItem == i ? 0xe0 : 0x00;

        // Display the menu item
        display_text(menuItem->text, 20, yPos, 2, color);

        // Show toggled state if a toggle
        if (menuItem->type == MENU_TOGGLE)
        {
            if (((int (*)(MenuItem *, int toggle))menuItem->param_0)(menuItem, 0))
                display_text("on", 120, yPos, 2, color);
            else
                display_text("off", 120, yPos, 2, color);
        }

        if (menuItem->shortcutInput != INPUT_NONE)
        {
            char *str = input_names;
            byte index = menuItem->shortcutInput;

            while (index) 
            {
                if ( !*str ) 
                    index--;

                str++;
            }

            display_text(str, 180, yPos, 2, 0x01);
        }

        yPos += MENU_LINE_HEIGHT;
        menuItem++;
    }
}

void DO_DMENU_SHORTCUTS(Menu *menu)
{
    MenuItem *menuItem = menu->items;

    for (byte i = 0; i < menu->count; i++)
    {
        if (menuItem->type == MENU_SUB_MENU)
            DO_DMENU_SHORTCUTS(menuItem->param_0);

        if (menuItem->shortcutInput != INPUT_NONE)
        {
            if (TOUCHE(INPUT_SELECT) && TOUCHE(menuItem->shortcutInput))
            {
                DO_DMENU_ACTION(menuItem);
                held_down_button = menuItem->shortcutInput;
                return;
            }
        }

        menuItem++;
    } 
}

bool check_inputs()
{
    if (held_down_button != INPUT_NONE)
    {
        if (!TOUCHE(held_down_button))
        {
            held_down_button = INPUT_NONE;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 1;
}
