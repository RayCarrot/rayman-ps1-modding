#include <export.h>

extern bool in_pause;
extern StatusBar status_bar;

void do_inputs()
{
    // 99 lives when pressing circle and paused
    if (in_pause && TOUCHE(INPUT_CIRCLE))
    {
        status_bar.num_lives = 99;
    }
}
