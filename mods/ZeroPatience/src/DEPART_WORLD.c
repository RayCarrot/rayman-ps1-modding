#include "globals.h"

void DEPART_WORLD(void)
{
    if (num_world_choice != num_world)
    {
        num_level = 0;
        new_world = true;
        new_level = true;
    }
    else
    {
        new_world = false;
        new_level = true;
    }

    if (You_Win == true && num_world_choice == 6)
    {
        DO_VICTOIRE();
        return;
    }
    if (!fin_du_jeu)
    {
        if (new_world)
        {
            UNK_801cedfc = 1;
            PS1_PlaySnd(PS1_NewWorldMusic[num_world_choice], 1);
            //FUN_8019fb84();
            load_world(num_world_choice);
            INIT_MOTEUR_WORLD();
            PS1_ShouldFadeOutWorldIntro = true;
        }
        /*else
            FUN_8019fa94(1);*/
    }
}