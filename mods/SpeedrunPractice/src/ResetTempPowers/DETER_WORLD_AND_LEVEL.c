#include <export.h>

extern byte You_Win;
extern byte fin_du_jeu;
extern byte fin_dark;
extern byte Nb_total_cages;
extern byte Vignet_To_Display;
extern short departlevel;
extern short num_world;
extern short num_level;
extern short num_level_choice;
extern short num_world_choice;
extern short new_world;
extern short new_level;
extern byte world_index;
extern byte ModeDemo;
extern byte finBosslevel[2];
extern RaymanEvents RayEvts;
extern WorldInfo t_world_info[24];

void DETER_WORLD_AND_LEVEL()
{
    world_index = (byte)num_world_choice;

    if (ModeDemo == 0) 
    {
        num_level_choice = (short)t_world_info[num_world_choice].level;
        num_world_choice = (short)t_world_info[num_world_choice].world;
    }

    if (num_world_choice == 5) 
    {
        // Do not skip Joe screen
        /*
        if (num_level_choice == 3 && (finBosslevel[1] & 2) != 0) 
        {
            num_level_choice = 4;
            RayEvts.flags1 |= RAYEVTS1_LUCIOLE;
            return;
        }
        */

        if ((num_level_choice == 4 && (finBosslevel[1] & 2) != 0) && ModeDemo != 0) 
        {
            RayEvts.flags1 |= RAYEVTS1_LUCIOLE;
            return;
        }
    }

    // Don't need this
    /*
    if ((num_world_choice == 6) && ((finBosslevel[0] & 0x80) != 0)) {
        You_Win = true;
        fin_du_jeu = true;
        fin_dark = true;
        new_world = 1;
    }
    */

    // Disable seed
    RayEvts.flags0 &= ~RAYEVTS0_GRAIN;

    // Disable super-helico in MSP
    if (num_world_choice == 3 && num_level_choice == 6)
        finBosslevel[1] &= ~8;
}
