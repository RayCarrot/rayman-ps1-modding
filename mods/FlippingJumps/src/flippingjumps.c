#include <export.h>

extern ushort RayEvts;
extern Obj ray;

#define TRUE 1
#define FALSE 0

bool wasOnGround;

void do_rayman_EXT()
{
    wasOnGround = TRUE;
    uint state = (uint)ray.main_etat;
    // If rayman cannot jump anymore, we've lifted off the ground (or still are)
    if ((ray.eta[state][ray.sub_etat].flags & 1) == 0) {
        wasOnGround = FALSE;
        return;
    }
}

void ray_jump_EXT()
{
    if (wasOnGround) {
        // Toggle reverse power when jumping
        RayEvts ^= 1 << 13;
    }
}