#include <export.h>

extern bool in_pause;
extern Obj ray;

void do_inputs()
{
    // Instant death when pressing triangle and paused
    if (in_pause && TOUCHE(INPUT_TRIANGLE) && (ray.flags & 0xc00) == 0xc00)
    {
        ray.hit_points = 0;
        RAY_HIT(1, (Obj *)0x00);
        in_pause = 0;
        PS1_OnPauseOff();
    }
}
