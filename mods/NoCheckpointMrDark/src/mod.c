#include <export.h>

extern short num_level;
extern short num_world;
extern byte dark_phase;

void terminateFistWhenRayDies_Extended()
{
    // Phases
    //  1: Mr Dark taunts Rayman
    //  2: Flames
    //  3: Hybrid bosses
    //  4: Unused
    //  5: Victory
    if (num_world == 6 && num_level == 4 && dark_phase > 1 && dark_phase < 5)
    {
        dark_phase = 2;
    }
}