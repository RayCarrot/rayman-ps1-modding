#include <export.h>
#include "fist_menu.h"
#include "menu.h"
#include "globals.h"

MENU(fist_menu, "fist",
    MENU_TOGGLE_PARAM("normal 1", fist_state, 1),
    MENU_TOGGLE_PARAM("normal 2", fist_state, 3),
    MENU_TOGGLE_PARAM("normal 3", fist_state, 5),
    MENU_TOGGLE_PARAM("gold 1", fist_state, 8),
    MENU_TOGGLE_PARAM("gold 2", fist_state, 10),
    MENU_TOGGLE_PARAM("gold 3", fist_state, 12),
);

int fist_state(MenuItem *menuItem, int toggle)
{
    byte initSubEtat;

    initSubEtat = level.objects[poing_obj_id].init_sub_etat;

    if (!toggle)
        return initSubEtat == menuItem->param_1;

    level.objects[poing_obj_id].init_sub_etat = menuItem->param_1;
    level.objects[poing_obj_id].sub_etat = menuItem->param_1;
    poing.sub_etat = menuItem->param_1;

    return 1;
}

/*
int gold_fist(MenuItem *menuItem, int toggle)
{
    byte initSubEtat;
    bool goldFist;

    initSubEtat = level.objects[poing_obj_id].init_sub_etat;
    goldFist = initSubEtat == 8 || initSubEtat == 10 || initSubEtat == 12;

    if (!toggle)
        return goldFist;

    if (goldFist)
    {
        if (initSubEtat == 8)
            initSubEtat = 1;
        else if (initSubEtat == 10)
            initSubEtat = 3;
        else if (initSubEtat == 12)
            initSubEtat = 5;
    }
    else
    {
        if (initSubEtat == 1)
            initSubEtat = 8;
        else if (initSubEtat == 3)
            initSubEtat = 10;
        else if (initSubEtat == 5)
            initSubEtat = 12;
    }

    level.objects[poing_obj_id].init_sub_etat = initSubEtat;
    level.objects[poing_obj_id].sub_etat = initSubEtat;
    poing.sub_etat = initSubEtat;

    return !goldFist;
}
*/
