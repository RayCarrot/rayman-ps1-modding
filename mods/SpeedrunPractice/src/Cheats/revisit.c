#include "revisit.h"

// Well this is a nice mess :p Basically 256 bits per level (we assume world 1) and then for some reason the bit index in the byte are reversed, so we have to do 7 minus
#define M_COLLECT_CAGE(level, id) setbit(save_zone, ((((level - 1) * 256) + id) & ~7) + (7 - ((((level - 1) * 256) + id) & 7)))
#define M_CLEAR_CAGE(level, id) clearbit(save_zone, ((((level - 1) * 256) + id) & ~7) + (7 - ((((level - 1) * 256) + id) & 7)))

extern WorldInfo t_world_info[24];
extern byte save_zone[2688];

void update_revisit_cages(bool revisit)
{
    if (revisit)
    {
        t_world_info[0].nb_cages = 3; // Pink Plant Woods
        t_world_info[1].nb_cages = 3; // Anguish Lagoon
        t_world_info[3].nb_cages = 4; // Moskito's Nest

        // Pink Plant Woods - Part 4
        M_COLLECT_CAGE(4, 82);
        M_COLLECT_CAGE(4, 79);
        M_COLLECT_CAGE(4, 80);

        // Anguish Lagoon - Part 1
        M_COLLECT_CAGE(5, 32);
        M_COLLECT_CAGE(5, 31);

        // Anguish Lagoon - Part 3
        M_COLLECT_CAGE(7, 25);

        // Moskito's Nest - Part 1
        M_COLLECT_CAGE(12, 61);
        
        // Moskito's Nest - Part 2
        M_COLLECT_CAGE(13, 76);
        M_COLLECT_CAGE(13, 78);
        M_COLLECT_CAGE(13, 79);
    }
    else
    {
        t_world_info[0].nb_cages = 0; // Pink Plant Woods
        t_world_info[1].nb_cages = 0; // Anguish Lagoon
        t_world_info[3].nb_cages = 0; // Moskito's Nest

        // Pink Plant Woods - Part 4
        M_CLEAR_CAGE(4, 82);
        M_CLEAR_CAGE(4, 79);
        M_CLEAR_CAGE(4, 80);
        
        // Anguish Lagoon - Part 1
        M_CLEAR_CAGE(5, 32);
        M_CLEAR_CAGE(5, 31);

        // Anguish Lagoon - Part 3
        M_CLEAR_CAGE(7, 25);

        // Moskito's Nest - Part 1
        M_CLEAR_CAGE(12, 61);
        
        // Moskito's Nest - Part 2
        M_CLEAR_CAGE(13, 76);
        M_CLEAR_CAGE(13, 78);
        M_CLEAR_CAGE(13, 79);
    }
}
