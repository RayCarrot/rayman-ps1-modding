#include <export.h>

extern byte finBosslevel[2];
extern WorldInfo t_world_info[24];
extern RaymanEvents RayEvts;

void fix_numlevel_extended()
{
    // Unlock Mr Dark's Dare if beaten Skops
    if ((t_world_info[17].state & 1) == 0 && (finBosslevel[0] & 0x40) != 0) 
        t_world_info[17].state |= 4;

    // For debugging
    //for (size_t i = 0; i < 17; i++)
    //{
    //    t_world_info[i].state |= 4;
    //}
    
    //RayEvts.flags0 |= RAYEVTS0_POING | RAYEVTS0_HANG | RAYEVTS0_GRAP | RAYEVTS0_HELICO;
    //RayEvts.flags1 |= RAYEVTS1_RUN;
}
