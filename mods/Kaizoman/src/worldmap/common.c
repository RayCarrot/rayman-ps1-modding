#include <export.h>
#include "common.h"
#include "constants.h"

extern byte Nb_total_cages;
extern byte finBosslevel[2];
extern WorldInfo t_world_info[24];

void check_final_level_unlock()
{
    // Unlock Mr Dark's Dare
    if ((t_world_info[17].state & 1) == 0 && REQUIRED_CAGES_FOR_DARK <= Nb_total_cages && (finBosslevel[0] & 0x40) != 0) 
        t_world_info[17].state |= 4;
}