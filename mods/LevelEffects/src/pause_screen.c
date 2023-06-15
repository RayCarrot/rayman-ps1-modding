#include <export.h>
#include "mod.h"
#include "pause_screen.h"
#include "global.h"

// Input variables so we can adjust them when inverting controls
Input input_reload = INPUT_CIRCLE;
Input input_die = INPUT_TRIANGLE;

void do_pause_screen()
{
    show_active_effects();

    // Don't allow custom inputs while on no hp or dying since then you reload with -1 hp
    if (ray.hit_points == 0xFF || (ray.flags & (OBJ_ALIVE | OBJ_ACTIVE)) != (OBJ_ALIVE | OBJ_ACTIVE))
    {
        return;
    }

    display_text("\xf8 to reload", 120, 200, 2, 0x3);
    display_text("% to die", 120, 220, 2, 0x3);

    // Re-randomize level
    if (TOUCHE(input_reload))
    {
        // Reload level
        new_level = TRUE;
        PS1_HasLoadedFont = TRUE; // Forces full level reload from disc

        // Setup level again
        setup_level(num_world, num_level);
    }
    // Instant death
    else if (TOUCHE(input_die))
    {
        ray.hit_points = 0;
        RAY_HIT(1, (Obj *)0x00);
        in_pause = 0;
        PS1_OnPauseOff();
    }
}
