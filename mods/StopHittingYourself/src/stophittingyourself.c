#include <export.h>

extern ushort RayEvts;
extern Obj ray;
extern Poing poing;

#define true 1
#define false 0

void hurt_and_switch_off_fist(Obj* poingObj)
{
    if (poing.is_returning && !poing.is_boum) {
        RAY_HIT(1,0);
    }
    poing.is_active = false;
    poing.is_boum = false;
    poing.charge = 5;
    poing.is_returning = false;
    poingObj->flags = poingObj->flags & 0xfffff3ff;
    poingObj->sub_etat = poingObj->init_sub_etat;
    fin_poing_follow(poingObj,false);
    return;
}