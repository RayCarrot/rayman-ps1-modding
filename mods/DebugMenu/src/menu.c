#include <export.h>

// Enums
enum MENUITEMTYPE { MENU_NONE, MENU_SUB_MENU, MENU_ACTION };

// Structs
typedef struct 
{
    char *text;
    enum MENUITEMTYPE type;
    void *param;
} MenuItem;

typedef struct
{
    char *text;
    byte count;
    byte selectedItem;
    MenuItem* items;
} Menu;

// Function prototypes
void main_menu__skip_level();
void main_menu__place_ray();
void main_menu__99_lives();
void main_menu__exit_level();

// External variables
extern short ray_mode;
extern bool PS1_IsPaused;
extern StatusBar status_bar;
extern bool new_world;

// Constants
#define DEFAULT_COOLDOWN 10
#define MENU_STACK_SIZE 2

// Sub menu
MenuItem sub_menu_items[] = 
{
    { .text = "dummy", .type = MENU_NONE },
};
Menu sub_menu = { .text = "sub", .count = 1, .items = sub_menu_items };

// Main menu
MenuItem main_menu_items[] = 
{
    { .text = "sub menu", .type = MENU_SUB_MENU, .param = &sub_menu },
    { .text = "place ray", .type = MENU_ACTION, .param = main_menu__place_ray },
    { .text = "99 lives", .type = MENU_ACTION, .param = main_menu__99_lives },
    { .text = "skip level", .type = MENU_ACTION, .param = main_menu__skip_level },
    { .text = "exit level", .type = MENU_ACTION, .param = main_menu__exit_level },
    { .text = "dummy", .type = MENU_NONE },
    { .text = "dummy", .type = MENU_NONE },
    { .text = "dummy", .type = MENU_NONE },
};
Menu main_menu = { .text = "main", .count = 7, .items = main_menu_items };

// Variables
byte input_cooldown;
byte menu_stack_index = 0xFF;
Menu *menu_stack[MENU_STACK_SIZE];

// Menu actions
void main_menu__skip_level()
{
    ChangeLevel();
    PS1_IsPaused = 0;
}

void main_menu__place_ray()
{
    ray_mode = -ray_mode;
    PS1_IsPaused = 0;
}

void main_menu__99_lives()
{
    status_bar.num_lives = 99;
    
    // Since we're paused we need to manually
    // update the hud for it to show
    DO_FIXE();
}

void main_menu__exit_level()
{
    new_world = 1;
    PS1_IsPaused = 0;
}

void change_menu(Menu *menu)
{
    if ((byte)(menu_stack_index + 1) >= MENU_STACK_SIZE)
        return;

    menu_stack_index++;
    menu_stack[menu_stack_index] = menu;
}

void do_menu_actions(Menu *menu)
{
    // Allow selecting one of the lines using up and down buttons
    if (input_cooldown == 0)
    {
        if (TOUCHE(INPUT_DOWN))
        {
            input_cooldown = DEFAULT_COOLDOWN;
            
            if (menu->selectedItem < menu->count - 1)
                menu->selectedItem++;
            else
                menu->selectedItem = 0;

            PlaySnd_old(0x44);
        }
        else if (TOUCHE(INPUT_UP))
        {
            input_cooldown = DEFAULT_COOLDOWN;

            if (menu->selectedItem > 0)
                menu->selectedItem--;
            else
                menu->selectedItem = menu->count - 1;

            PlaySnd_old(0x44);
        }
        else if (TOUCHE(INPUT_CIRCLE))
        {
            if (menu_stack_index > 0)
            {
                input_cooldown = DEFAULT_COOLDOWN;
                menu_stack_index--;
                PlaySnd_old(0x4d);
            }
        }
        else if (TOUCHE(INPUT_CROSS))
        {
            input_cooldown = DEFAULT_COOLDOWN;

            MenuItem *selectedItem = menu->items + menu->selectedItem;
            
            switch (selectedItem->type)
            {
                case MENU_SUB_MENU:
                    change_menu(selectedItem->param);
                    break;

                case MENU_ACTION:
                    ((void (*)())selectedItem->param)();
                    break;
            }

            PlaySnd_old(0x45);
        }
    }

    // Use a cooldown to avoid checking inputs every frame
    if (input_cooldown > 0)
        input_cooldown--;
}

void display_menu(Menu *menu)
{
    display_text(menu->text, 20, 65, 2, 0x02);

    short yPos = 90;

    MenuItem *menuItem = menu->items;

    for (byte i = 0; i < menu->count; i++)
    {
        display_text(menuItem->text, 20, yPos, 2, menu->selectedItem == i ? 0xe0 : 0x00);

        yPos += 20;
        menuItem++;
    } 
}

int menu()
{
    if (menu_stack_index == 0xFF)
        change_menu(&main_menu);

    do_menu_actions(menu_stack[menu_stack_index]);
    display_menu(menu_stack[menu_stack_index]);
}