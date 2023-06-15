#include <export.h>
#include "global.h"

void make_map_slippery()
{
    BlockType btyp;
    int blockIndex;

    // Check y from down to up since we need to check original above tile later
    for (int y = mp.height - 1; y-- > 0; )
    {
        for (int x = 0; x < mp.width; x++)
        {
            blockIndex = y * mp.width + x;
            btyp = mp.map[blockIndex] >> 10;

            // If it's an angled type we change it to the slippery equivalent
            if (btyp >= BTYP_SOLID_RIGHT_45 && btyp <= BTYP_SOLID_LEFT2_30)
            {
                btyp += 16;
            }
            // If it's a passthrough type we can always change it to be slippery
            else if (btyp == BTYP_SOLID_PASSTHROUGH)
            {
                btyp = BTYP_SLIPPERY;
            }
            // If it's a solid type it's more complicated since slipppery would make it passthrough, allowing zips everywhere!
            else if (btyp == BTYP_SOLID && y != 0)
            {
                // Get the above tile type
                btyp = mp.map[(y - 1) * mp.width + x] >> 10;

                // Only set to slippery if not solid above
                if (btyp != BTYP_SOLID)
                {
                    btyp = BTYP_SLIPPERY;
                }
            }
            
            mp.map[blockIndex] = (mp.map[blockIndex] & 0x3FF) | (btyp << 10);     
        }
    }
}
