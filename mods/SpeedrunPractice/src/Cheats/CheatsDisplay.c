#include <export.h>

extern bool in_pause;
extern bool PS1_Ingame;
extern byte dead_time;
extern short ray_mode;
extern SaveState save1;
extern Obj ray;
extern Obj *mapobj;
extern LevelData level;
extern short poing_obj_id;
extern Poing poing;

void CheatsDisplay()
{
    // Display fist state
    char fistText[3] = { 0, 0, 0 };

    byte initSubEtat = level.objects[poing_obj_id].init_sub_etat;

    if (initSubEtat == 1 || initSubEtat == 8)
        fistText[0] = '1';
    else if (initSubEtat == 3 || initSubEtat == 10)
        fistText[0] = '2';
    else if (initSubEtat == 5 || initSubEtat == 12)
        fistText[0] = '3';

    display_sprite(mapobj, initSubEtat >= 8 ? 1 : 2, 275, 215, 0); // Fist
    display_text(fistText, 305, 230, 2, 0); // Fist speed

    // Fist charge
    if (poing.is_charging && poing.charge > 5)
    {
        atoi(poing.charge, fistText);
        display_text(fistText, 255, 230, 2, 0);
    }
}
