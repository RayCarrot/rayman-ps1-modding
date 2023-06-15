#include <export.h>
#include "mod.h"
#include "pause_screen.h"
#include "global.h"

Input input_reload = INPUT_TRIANGLE;

void do_pause_screen()
{
    show_active_effects();

    // Don't allow custom inputs while on no hp since then you reload with -1 hp
    if (ray.hit_points == 0xFF)
    {
        return;
    }

    display_text("% to reload", 120, 220, 2, 0x3);

    // Re-randomize level
    if (TOUCHE(input_reload))
    {
        // Reload level
        new_level = TRUE;
        PS1_HasLoadedFont = TRUE; // Forces full level reload from disc

        // Setup level again
        setup_level(num_world, num_level);
    }
}
