#include <export.h>

#define DEFAULT_COOLDOWN 15

// Define two variables to use
byte menu_index;
byte input_cooldown;

// Our custom function which replaces the pause screen function call
int hello_world()
{
    // Display 3 lines of text
    display_text("hello world", 20, 100, 2, menu_index == 0 ? 0xe0 : 0x00);
    display_text("this is a selectable option", 20, 120, 2, menu_index == 1 ? 0xe0 : 0x00);
    display_text("and here is another one!", 20, 140, 2, menu_index == 2 ? 0xe0 : 0x00);

    // Allow selecting one of the lines using up and down buttons
    if (input_cooldown == 0)
    {
        if (TOUCHE(INPUT_DOWN))
        {
            input_cooldown = DEFAULT_COOLDOWN;
            
            if (menu_index < 2)
                menu_index++;
        }
        else if (TOUCHE(INPUT_UP))
        {
            input_cooldown = DEFAULT_COOLDOWN;

            if (menu_index > 0)
                menu_index--;
        }
    }

    // Use a cooldown to avoid checking inputs every frame
    if (input_cooldown > 0)
        input_cooldown--;
}