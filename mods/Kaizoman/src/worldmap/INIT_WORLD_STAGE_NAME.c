#include <export.h>
#include "INIT_WORLD_STAGE_NAME_strings.h"

extern byte NBRE_SAVE;
extern short fichier_selectionne;
extern short num_world_choice;
extern WorldInfo t_world_info[24];
extern TextToDisplay text_to_display[10];
extern char save_ray[4][4];

void INIT_WORLD_STAGE_NAME(void)
{
    byte color;
    char strBuffer[8];

    color = 0;

    switch(t_world_info[num_world_choice].world) 
    {
        // Jungle
        case 1:
            strcpy(text_to_display[2].text, (char *)&world_name_01);
            color = 7;
            break;

        // Music
        case 2:
            strcpy(text_to_display[2].text, (char *)&world_name_02);
            color = 4;
            break;

        // Mountain
        case 3:
            strcpy(text_to_display[2].text, (char *)&world_name_03);
            color = 0xd;
            break;

        // Image
        case 4:
            strcpy(text_to_display[2].text, (char *)&world_name_04);
            color = 0;
            break;

        // Cave
        case 5:
            strcpy(text_to_display[2].text, (char *)&world_name_05);
            color = 2;
            break;

        // Cake
        case 6:
            strcpy(text_to_display[2].text, (char *)&world_name_06);
            color = 1;
            break;

        // Save
        case 7:
            color = (byte)t_world_info[num_world_choice].color;

            if (fichier_selectionne == 0) 
            {
                if (NBRE_SAVE == 0) 
                    strcpy(text_to_display[2].text, (char *)0x8012ba1c); // Password
                else 
                    strcpy(text_to_display[2].text, (char *)0x801cf0a4); // Empty
            }
            else if (fichier_selectionne < 4)
            {
                strBuffer[0] = *(char *)0x801cf0a8;
                strcat(strBuffer, save_ray[fichier_selectionne]);
                strcat(strBuffer, (char *)0x801cf0a8);

                strcpy(text_to_display[2].text, (char *)&strBuffer);
            }
            break;
    }
    
    text_to_display[2].color = color;
    text_to_display[2].font_size = 1;
    text_to_display[2].x_pos = 0x1c2;
    text_to_display[2].y_pos = 0x28;
    text_to_display[2].is_fond = 0;
    text_to_display[2].field8_0x3d = 1;
    INIT_TXT_BOX(text_to_display + 2);
    text_to_display[2].width += 10;
    text_to_display[2].height += 2;
}
