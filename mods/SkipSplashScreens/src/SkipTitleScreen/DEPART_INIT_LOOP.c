#include <export.h>

extern byte menuEtape;
extern bool dans_la_map_monde;
extern Display *PS1_CurrentDisplay;
extern Display PS1_Display1;
extern Display PS1_Display2;

void NEW_DEPART_INIT_LOOP()
{
    // Need to call this here since we're not calling FUN_8019fdd0
    PutDispEnv(&PS1_CurrentDisplay->field0_0x0);
    PutDrawEnv(&PS1_CurrentDisplay->drawing_environment);
    PS1_InitDisplay(&PS1_Display1);
    PS1_InitDisplay(&PS1_Display2);

    // Skip main menu
    menuEtape = 1;

    // This is the same as usual
    dans_la_map_monde = 0;
    PS1_ClearPassword();
}
