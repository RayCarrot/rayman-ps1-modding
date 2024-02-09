#include <export.h>

extern Obj ray;

void DO_RAYMAN_IN_WLD_MAP_EXT()
{
    if (ray.timer > 0 && TOUCHE(INPUT_R1))
    {
        ray.timer += 3;
    }
}
