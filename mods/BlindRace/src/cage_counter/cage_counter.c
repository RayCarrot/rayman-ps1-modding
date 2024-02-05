#include <export.h>

extern Obj *mapobj;
extern byte Nb_total_cages;

void display_cages()
{
    char numStr[4];

    // Display cage medallion icon
    display_sprite(mapobj, 90, 135, 182, 0);

    // Display cage count
    PS1_itoa(Nb_total_cages, numStr, 0);
    display_text((char *)&numStr, 160, 200, 2, 0);
}
