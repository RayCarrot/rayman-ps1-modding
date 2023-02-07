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
    char *text;
    enum MENUITEMTYPE type;
    void *param_0;
    int param_1;
} MenuItem;

typedef struct
{
    char *text;
    byte count;
    byte selectedItem;
    MenuItem* items;
} Menu;

// Function prototypes
void level_menu__skip_level();
void level_menu__exit_level();
void level_menu__new_level(MenuItem *menuItem);
int powers_menu__toggle_power(MenuItem *menuItem, int toggle);
void cheats_menu__place_ray();
void cheats_menu__99_lives();
void general_menu__checkpoint();

// External variables
extern short ray_mode;
extern bool PS1_IsPaused;
extern StatusBar status_bar;
extern bool new_world;
extern bool new_level;
extern short num_level;
extern short num_level_choice;
extern Obj ray;
extern SaveState save1;
extern ushort RayEvts;

// Constants
#define DEFAULT_COOLDOWN 10
#define DEFAULT_ACTION_COOLDOWN 20
#define MENU_STACK_SIZE 3
#define MENU_MAX_ITEMS_ON_SCREEN 7
#define MENU_SCROLL_START 3
#define MENU_LINE_HEIGHT 20

// Menus
MENU(level_menu, "level",
    MENU_ACTION("skip", level_menu__skip_level),
    MENU_ACTION("exit", level_menu__exit_level),
    MENU_ACTION_PARAM("restart", level_menu__new_level, 0),
    MENU_ACTION_PARAM("prev", level_menu__new_level, -1),
    MENU_ACTION_PARAM("next", level_menu__new_level, 1),
);
MENU(powers_menu, "powers",
    MENU_TOGGLE_PARAM("fist", powers_menu__toggle_power, 1 << 0),
    MENU_TOGGLE_PARAM("hang", powers_menu__toggle_power, 1 << 1),
    MENU_TOGGLE_PARAM("helico", powers_menu__toggle_power, 1 << 2),
    MENU_TOGGLE_PARAM("super-helico", powers_menu__toggle_power, 1 << 3),
    MENU_TOGGLE_PARAM("seed", powers_menu__toggle_power, 1 << 6),
    MENU_TOGGLE_PARAM("grab", powers_menu__toggle_power, 1 << 7),
    MENU_TOGGLE_PARAM("run", powers_menu__toggle_power, 1 << 8),
    MENU_TOGGLE_PARAM("force-run", powers_menu__toggle_power, 1 << 12),
    MENU_TOGGLE_PARAM("reversed", powers_menu__toggle_power, 1 << 13),
);
MENU(cheats_menu, "cheats",
    MENU_ACTION("place ray", cheats_menu__place_ray),
    MENU_ACTION("99 lives", cheats_menu__99_lives),
    MENU_SUB_MENU("powers...", &powers_menu),
);
MENU(general_menu, "general",
    MENU_ACTION("checkpoint", general_menu__checkpoint),
);
MENU(main_menu, "main",
    MENU_SUB_MENU("level...", &level_menu),
    MENU_SUB_MENU("cheats...", &cheats_menu),
    MENU_SUB_MENU("general...", &general_menu),
    MENU_NONE("display..."), // TODO: Implement
    MENU_NONE("options..."), // TODO: Implement
);

// Variables
byte input_cooldown;
byte menu_stack_index = 0xFF;
Menu *menu_stack[MENU_STACK_SIZE];

// Menu actions
void level_menu__skip_level()
{
    ChangeLevel();
}

void level_menu__exit_level()
{
    new_world = 1;
}

void level_menu__new_level(MenuItem *menuItem)
{
    new_level = 1;
    // TODO: Add check in prev/next level action so the new level exists
    num_level_choice = num_level + menuItem->param_1;
}

int powers_menu__toggle_power(MenuItem *menuItem, int toggle)
{
    if (toggle)
        RayEvts ^= menuItem->param_1;

    return (RayEvts & menuItem->param_1) != 0;
}

void cheats_menu__place_ray()
{
    ray_mode = -ray_mode;
    PS1_IsPaused = 0;
}

void cheats_menu__99_lives()
{
    status_bar.num_lives = 99;
    
    // Since we're paused we need to manually
    // update the hud for it to show
    DO_FIXE();
}

void general_menu__checkpoint()
{
    ray.flags = ray.flags | 0x800;
    restore_gendoor_link();
    saveGameState(0x0, &save1);
    correct_gendoor_link();
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
    // Process inputs
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
                input_cooldown = DEFAULT_ACTION_COOLDOWN;
                menu_stack_index--;
                PlaySnd_old(0x4d);
            }
        }
        else if (TOUCHE(INPUT_CROSS))
        {
            input_cooldown = DEFAULT_ACTION_COOLDOWN;

            MenuItem *selectedItem = menu->items + menu->selectedItem;
            
            switch (selectedItem->type)
            {
                case MENU_SUB_MENU:
                    change_menu(selectedItem->param_0);
                    break;

                case MENU_ACTION:
                    ((void (*)(MenuItem *))selectedItem->param_0)(selectedItem);
                    break;

                case MENU_TOGGLE:
                    ((int (*)(MenuItem *, int toggle))selectedItem->param_0)(selectedItem, 1);
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

        yPos += MENU_LINE_HEIGHT;
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