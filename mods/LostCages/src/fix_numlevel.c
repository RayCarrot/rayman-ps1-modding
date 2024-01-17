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
extern short new_world;
extern short new_level;
extern byte finBosslevel[2];
extern byte RayEvts[2];
extern WorldInfo t_world_info[24];

void fix_numlevel(Obj *obj)
{
    bool handledLevelChoice;
  
    handledLevelChoice = 0;

    if (departlevel && (new_level_init(), obj->type != TYPE_WIZARD1)) 
    {
        switch(num_world) 
        {
            // Jungle
            case 1:
                // Betila: fist
                if (num_level == 2 && (RayEvts[0] & 1) != 0) 
                    num_level_choice++;
                
                // Boss: Bzzit
                if (num_level == 5 && (finBosslevel[0] & 1) != 0)
                    num_level_choice++;

                // Betilla: hang
                //if (num_level == 7 && (RayEvts[0] & 2) != 0) 
                //    new_world = 1;
                
                // Boss: Moskito chase
                if (num_level == 13 && (finBosslevel[0] & 2) != 0) 
                    num_level_choice++;

                // Boss: Moskito
                if (num_level == 15 && (finBosslevel[0] & 2) != 0)
                    new_world = 1;
                
                // Betilla: grab
                if (num_level == 16 && (RayEvts[0] & 0x80) != 0) 
                    new_world = 1;
                break;

            // Music
            case 2:
                // Boss: Red Drummer (unused)
                if (num_level == 5 && (finBosslevel[1] & 1) != 0) 
                    new_world = 1;
                
                // Boss: Sax encounter
                if (num_level == 9 && (finBosslevel[0] & 4) != 0) 
                    new_world = 1;

                // Betilla: helico
                //if (num_level == 10 && (RayEvts[0] & 4) != 0) 
                //    new_world = 1;

                // Boss: Sax
                if (num_level == 14 && (finBosslevel[0] & 4) != 0) 
                    new_world = 1;
                break;

            // Mountain
            case 3:
                // Boss: Stone chase
                if (num_level == 1 && (finBosslevel[0] & 8) != 0) 
                    new_world = 1;
                
                // Boss: Stone
                if ((num_level == 9) && (finBosslevel[0] & 8) != 0) 
                    new_world = 1;

                // Betilla: run
                //if (num_level == 10 && (RayEvts[1] & 1) != 0) 
                //    new_world = 1;
                break;
            
            // Image
            case 4:
                // Boss: Pirate Mama
                if (num_level == 3 && (finBosslevel[0] & 0x10) != 0) 
                    new_world = 1;

                // Boss: Space Mama
                if (num_level == 10 && (finBosslevel[0] & 0x20) != 0) 
                    new_world = 1;
                break;

            // Cave
            case 5:
                // Boss: Skops
                if (num_level == 9 && (finBosslevel[0] & 0x40) != 0)
                    new_world = 1;
                break;

            // Cake
            case 6:
                // Boss: Dark (unused)
                if (num_level == 1 && (finBosslevel[0] & 0x80) != 0) 
                    new_world = 1;
                break;
        }
    }

    switch(num_world) 
    {
        // Jungle
        case 1:
            switch(num_level) 
            {
                // Bonus: Pink Plant Woods 2
                case 2:
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 21;
                        handledLevelChoice = 1;
                    }
                    break;

                // End & bonus: Pink Plant Woods 4
                case 4:
                    // Bonus
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 20;
                        handledLevelChoice = 1;
                    }
                    // End
                    else
                    {
                        new_world = 1;

                        // Unlock Anguish Lagoon and save point
                        if ((t_world_info[1].state & 1) == 0) 
                        {
                            t_world_info[1].state |= 4;
                            t_world_info[18].state |= 4;
                        }
                    }
                    break;

                // End: Anguish Lagoon
                case 7:
                    new_world = 1;

                    // Unlock The Swamps of Forgetfulness
                    if ((t_world_info[2].state & 1) == 0) 
                        t_world_info[2].state |= 4;

                    // Unlock Bongo Hills
                    if ((t_world_info[4].state & 1) == 0) 
                        t_world_info[4].state |= 4;
                    break;

                // End & bonus: The Swamps of Forgetfulness 3
                case 11:
                    // Bonus
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 18;
                        handledLevelChoice = 1;
                    }
                    // End
                    else
                    {
                        new_world = 1;

                        // Unlock Moskito's Nest
                        if ((t_world_info[3].state & 1) == 0) 
                            t_world_info[3].state |= 4;
                    }
                    break;

                // Bonus: Moskito's Nest 1
                case 12:
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 19;
                        handledLevelChoice = 1;
                    }
                    break;

                // End: Moskito's Nest
                case 17:
                    new_world = 1;
                    break;

                // End: Bonus 1
                case 18:
                    num_level_choice = 11;
                    handledLevelChoice = 1;
                    break;

                // End: Bonus 2
                case 19:
                    num_level_choice = 12;
                    handledLevelChoice = 1;
                    break;

                // End: Bonus 3
                case 20:
                    num_level_choice = 4;
                    handledLevelChoice = 1;
                    break;

                // End: Bonus 4
                case 21:
                    num_level_choice = 2;
                    handledLevelChoice = 1;
                    break;
            }
            break;

        // Music
        case 2:
            switch(num_level)
            {
                // Bonus: Bongo Hills 4
                case 4:
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 17;
                        handledLevelChoice = 1;
                    }
                    break;

                // End: Bongo Hills
                case 6:
                    new_world = 1;
                    
                    // Unlock Allegro Presto and save point
                    if ((t_world_info[5].state & 1) == 0) 
                    {
                        t_world_info[5].state |= 4;
                        t_world_info[19].state |= 4;
                    }
                    break;
                
                // Bonus: Allegro Presto 3
                case 9:
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 18;
                        handledLevelChoice = 1;
                    }
                    break;        

                // End: Allegro Presto
                case 10:
                    new_world = 1;

                    // Unlock Gong Heights
                    if ((t_world_info[6].state & 1) == 0) 
                        t_world_info[6].state |= 4;

                    // Unlock Twilight Gulch
                    if ((t_world_info[8].state & 1) == 0) 
                        t_world_info[8].state |= 4;
                    break;
                
                // End: Gong Heights
                case 13:
                    new_world = 1;
                    
                    // Unlock Mr Sax's Hullaballoo and save point
                    if ((t_world_info[7].state & 1) == 0) 
                    {
                        t_world_info[7].state |= 4;
                        t_world_info[20].state |= 4;
                    }
                    break;
                
                // End: Mr Sax's Hullaballoo
                case 16:
                    new_world = 1;
                    break;
                
                // End: Bonus 1
                case 17:
                    num_level_choice = 4;
                    handledLevelChoice = 1;
                    break;
                
                // End: Bonus 2
                case 18:
                    num_level_choice = 9;
                    handledLevelChoice = 1;
                    break;
            }
            break;

        // Mountain
        case 3:
            switch(num_level) 
            {
                // End: Twilight Gulch
                case 2:
                    new_world = 1;

                    // Unlock The Hard Rocks
                    if ((t_world_info[9].state & 1) == 0) 
                        t_world_info[9].state |= 4;
                    break;
                    
                // Bonus: The Hard Rocks 2
                case 4:
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 12;
                        handledLevelChoice = 1;
                    }
                    break;

                // End: The Hard Rocks
                case 5:
                    new_world = 1;

                    // Unlock Mr Stone's Peaks and save point
                    if ((t_world_info[10].state & 1) == 0) 
                    {
                        t_world_info[10].state |= 4;
                        t_world_info[21].state |= 4;
                    }
                    break;

                // Bonus: Mr Stone's Peaks 4
                case 9:
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 13;
                        handledLevelChoice = 1;
                    }
                    break;

                // End: Mr Stone's Peaks
                case 10:
                    new_world = 1;

                    // Unlock Eraser Plains
                    if ((t_world_info[11].state & 1) == 0) 
                        t_world_info[11].state |= 4;
                    break;

                // End: Bonus 1
                case 12:
                    num_level_choice = 4;
                    handledLevelChoice = 1;
                    break;
                
                // End: Bonus 2
                case 13:
                    num_level_choice = 9;
                    handledLevelChoice = 1;
                    break;
            }
            break;

        // Image
        case 4:
            switch(num_level) 
            {
                // Bonus: Eraser Plains 3
                case 3:
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 12;
                        handledLevelChoice = 1;
                    }
                    break;  

                // End: Eraser Plains
                case 4:
                    new_world = 1;

                    // Unlock Pencil Pentathlon
                    if ((t_world_info[12].state & 1) == 0) 
                        t_world_info[12].state |= 4;
                    break;

                // End: Pencil Pentathlon
                case 7:
                    new_world = 1;

                    // Unlock Space Mama's Crater
                    if ((t_world_info[13].state & 1) == 0) 
                        t_world_info[13].state |= 4;
                    break;

                // Bonus: Space Mama's Crater 2
                case 9:
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 13;
                        handledLevelChoice = 1;
                    }
                    break;

                // End: Space Mama's Crater
                case 11:
                    new_world = 1;

                    // Unlock Crystal Palace and save point
                    if ((t_world_info[14].state & 1) == 0)
                    {                        
                        t_world_info[14].state |= 4;
                        t_world_info[22].state |= 4;

                        // Show cutscene
                        Vignet_To_Display = 1;
                    } 
                    break;

                // End: Bonus 1
                case 12:
                    num_level_choice = 3;
                    handledLevelChoice = 1;
                    break;

                // End: Bonus 2
                case 13:
                    num_level_choice = 9;
                    handledLevelChoice = 1;
                    break;
            }
            break;

        // Cave
        case 5:
            switch (num_level)
            {
                // End & bonus: Crystal Palace 2
                case 2:
                    // Bonus
                    if (obj->type == TYPE_WIZARD1)
                    {
                        num_level_choice = 12;
                        handledLevelChoice = 1;
                    }
                    // End
                    else
                    {
                        new_world = 1;

                        // Unlock Eat at Joe's
                        if ((t_world_info[15].state & 1) == 0) 
                            t_world_info[15].state |= 4;
                    }
                    break;

                // End: Eat at Joe's
                case 8:
                    new_world = 1;

                    // Unlock Mr Skops' Stalactites and save point
                    if ((t_world_info[16].state & 1) == 0) 
                    {
                        t_world_info[16].state |= 4;
                        t_world_info[23].state |= 4;
                    }
                    break;

                // End: Mr Skops' Stalactites
                case 11:
                    new_world = 1;

                    // Show cutscene
                    Vignet_To_Display = 1;
                    break;

                // End: Bonus 1
                case 12:
                    num_level_choice = 2;
                    handledLevelChoice = 1;
                    break;
            }
            break;

        // Cake
        case 6:
            // End: Mr Dark's Dare
            if (num_level == 4) 
            {
                new_world = 1;
                You_Win = 1;
                fin_du_jeu = 1;
                fin_dark = 1;
            }
            break;
    }

    // Unlock Mr Dark's Dare
    if ((t_world_info[17].state & 1) == 0 && 102 <= Nb_total_cages) 
        t_world_info[17].state |= 4;

    // If we're in the same world and the level choice has not already been
    // handled then we increment the level by 1 to go to the next map
    if (!new_world && !handledLevelChoice)
        num_level_choice++;

    new_level = 1;
}
