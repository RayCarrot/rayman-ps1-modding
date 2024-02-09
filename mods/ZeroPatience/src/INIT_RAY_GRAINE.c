#include "globals.h"

void INIT_RAY_GRAINE()
{
    if(num_world == 1 && num_level == 9)
        RayEvts.flags0 |= RAYEVTS0_GRAIN;
}