#include <export.h>

extern StatusBar status_bar;
extern RaymanEvents RayEvts;
extern Obj ray;

void INIT_RAY_BEGIN()
{
    status_bar.max_hp = 2;
    status_bar.num_wiz = 0;
    RayEvts.flags1 = RAYEVTS1_RUN;
    RayEvts.flags0 = RAYEVTS0_POING | RAYEVTS0_HANG | RAYEVTS0_HELICO | RAYEVTS0_GRAP;
    ray.flags = ray.flags & ~OBJ_FLAG_0;
}
