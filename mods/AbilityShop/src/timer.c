#include <timer.h>

const int framerate=60;
const int s_per_h=3600;
const int s_per_m=60;

unsigned int frames=0;
char timer_str[12];

void timer_new_game_start(){ frames = 0; }

void timer_update(char done)
{
    if(!done){ frames++; }
}

void timer_display(char done)
{
    int sec, h, m, s, f;

    sec = frames / framerate;

    // Split into hours, minutes, seconds, frames (rounding, since all are ints)
    h = sec / s_per_h;
    m = (sec - (s_per_h * h)) / s_per_m;
    s = (sec - (s_per_h * h) - (m * s_per_m));
    f = frames % framerate;

    sprintf(timer_str, "%02d:%02d:%02d:%02d", h, m, s, f);

    display_text(timer_str, 241, 230, 2, !done ? 0 : 224);
}