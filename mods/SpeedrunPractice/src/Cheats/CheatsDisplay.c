#include <export.h>

// Constants
#define MENU_COUNT 8
#define SOUND_NAVIGATE 0x44
#define SOUND_SELECT 0x45
#define SPEED_STORAGE_MIN 0
#define SPEED_STORAGE_MAX 112
#define SPEED_STORAGE_STEP 16
#define SPEED_STORAGE_LEFT ray.eta[2][0x11].speed_x_left
#define SPEED_STORAGE_RIGHT ray.eta[2][0x11].speed_x_right

// External variables
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
extern RaymanEvents RayEvts;

// Variables
byte selectedMenuIndex;
bool showFist;
bool showSpeedStorage;
byte selectedSpeedStorageValue;

sbyte savedSpeedStorageValue1;
sbyte savedSpeedStorageValue2;

char menu_names[] =  // Single string to save space
    "show fist state\0"
    "gold fist\0"
    "show speed storage\0"
    "show gendoors\0"
    "fist | hang | grab\0"
    "helico\0"
    "run\0"
    "speed storage\0"
    "save speed storage\0";

void CheatsDisplay()
{
    if (in_pause)
    {
        // Navigate menu
        if (PS1_SpecialTOUCHE(INPUT_DOWN))
        {
            if (selectedMenuIndex < MENU_COUNT - 1)
            {
                selectedMenuIndex++;
                PlaySnd_old(SOUND_NAVIGATE);
            }
        }
        else if (PS1_SpecialTOUCHE(INPUT_UP))
        {
            if (selectedMenuIndex > 0)
            {
                selectedMenuIndex--;
                PlaySnd_old(SOUND_NAVIGATE);
            }
        }

        // Display menu
        int yPos = 80;
        for (int i = 0; i < MENU_COUNT; i++)
        {
            // Get the name
            char *name = menu_names;
            byte index = i;
            while (index) 
            {
                if ( !*name ) 
                    index--;
                name++;
            }

            // Get the color - have it be multi-colored if selected
            byte color = selectedMenuIndex == i ? 0xe0 : 0x00;

            // Display the name
            display_text(name, 20, yPos, 2, color);

            bool click = selectedMenuIndex == i && PS1_SpecialTOUCHE(INPUT_CROSS);
            int onOff = -1;

            switch (i)
            {
                // Show fist state
                case 0:
                    if (click)
                        showFist = !showFist;
                    onOff = showFist;
                    break;

                // Gold fist
                case 1:
                    onOff = level.objects[poing_obj_id].init_sub_etat >= 8;
                    if (click)
                    {
                        onOff = !onOff;
                        byte newSubEtat;
                        if (onOff)
                            newSubEtat = level.objects[poing_obj_id].init_sub_etat + 7;
                        else
                            newSubEtat = level.objects[poing_obj_id].init_sub_etat - 7;
                        level.objects[poing_obj_id].init_sub_etat = newSubEtat;
                        level.objects[poing_obj_id].sub_etat = newSubEtat;
                        poing.sub_etat = newSubEtat;
                    }
                    break;

                // Show speed storage
                case 2:
                    if (click)
                        showSpeedStorage = !showSpeedStorage;
                    onOff = showSpeedStorage;
                    break;

                // Show gendoors
                case 3:
                    onOff = *(uint *)0x8013c49c == 0;
                    if (click)
                    {
                        onOff = !onOff;
                        if (onOff)
                            *(uint *)0x8013c49c = 0;
                        else
                            *(uint *)0x8013c49c = 0x10620096;
                    }
                    break;

                // Fist, hang, grab
                case 4:
                    onOff = (RayEvts.flags0 & (RAYEVTS0_POING | RAYEVTS0_HANG | RAYEVTS0_GRAP)) == (RAYEVTS0_POING | RAYEVTS0_HANG | RAYEVTS0_GRAP);
                    if (click)
                    {
                        onOff = !onOff;
                        if (onOff)
                            RayEvts.flags0 |= (RAYEVTS0_POING | RAYEVTS0_HANG | RAYEVTS0_GRAP);
                        else
                            RayEvts.flags0 &= ~(RAYEVTS0_POING | RAYEVTS0_HANG | RAYEVTS0_GRAP);
                    }
                    break;

                // Helico
                case 5:
                    onOff = (RayEvts.flags0 & RAYEVTS0_HELICO) != 0;
                    if (click)
                    {
                        onOff = !onOff;
                        if (onOff)
                            RayEvts.flags0 |= RAYEVTS0_HELICO;
                        else
                            RayEvts.flags0 &= ~RAYEVTS0_HELICO;
                    }
                    break;

                // Run
                case 6:
                    onOff = (RayEvts.flags1 & RAYEVTS1_RUN) != 0;
                    if (click)
                    {
                        onOff = !onOff;
                        if (onOff)
                            RayEvts.flags1 |= RAYEVTS1_RUN;
                        else
                            RayEvts.flags1 &= ~RAYEVTS1_RUN;
                    }
                    break;

                // Speed storage
                case 7:
                    if (click)
                        selectedSpeedStorageValue = !selectedSpeedStorageValue;

                    int value1 = SPEED_STORAGE_LEFT;
                    int value2 = SPEED_STORAGE_RIGHT;
                    int selectedValue = selectedSpeedStorageValue == 0 ? value1 : value2;

                    if (PS1_SpecialTOUCHE(INPUT_LEFT))
                    {
                        if (selectedValue >= 0)
                        {
                            selectedValue -= SPEED_STORAGE_STEP;
                            if (selectedValue < SPEED_STORAGE_MIN)
                                selectedValue = SPEED_STORAGE_MIN;
                        }
                        else
                        {
                            selectedValue += SPEED_STORAGE_STEP;
                            if (selectedValue > -SPEED_STORAGE_MIN)
                                selectedValue = -SPEED_STORAGE_MIN;
                        }
                    }
                    else if (PS1_SpecialTOUCHE(INPUT_RIGHT))
                    {
                        if (selectedValue >= 0)
                        {
                            selectedValue += SPEED_STORAGE_STEP;
                            if (selectedValue > SPEED_STORAGE_MAX)
                                selectedValue = SPEED_STORAGE_MAX;
                        }
                        else
                        {
                            selectedValue -= SPEED_STORAGE_STEP;
                            if (selectedValue < -SPEED_STORAGE_MAX)
                                selectedValue = -SPEED_STORAGE_MAX;
                        }
                    }

                    if (selectedSpeedStorageValue == 0)
                    {
                        value1 = selectedValue;
                        SPEED_STORAGE_LEFT = selectedValue;
                    }
                    else
                    {
                        value2 = selectedValue;
                        SPEED_STORAGE_RIGHT = selectedValue;
                    }

                    char str[4];

                    // Absolute values
                    if (value1 < 0)
                        value1 = -value1;
                    if (value2 < 0)
                        value2 = -value2;

                    PS1_itoa(value1, (char *)&str, 4);
                    display_text((char *)&str, 180, yPos, 2, selectedSpeedStorageValue == 0 ? color : 0x00);
                    PS1_itoa(value2, (char *)&str, 4);
                    display_text((char *)&str, 180 + 32, yPos, 2, selectedSpeedStorageValue == 1 ? color : 0x00);
                    break;

                // Save speed storage
                case 8:
                    if (click)
                    {
                        savedSpeedStorageValue1 = SPEED_STORAGE_LEFT;
                        savedSpeedStorageValue2 = SPEED_STORAGE_RIGHT;
                    }

                    if (PS1_SpecialTOUCHE(INPUT_SQUARE))
                    {
                        SPEED_STORAGE_LEFT = savedSpeedStorageValue1;
                        SPEED_STORAGE_RIGHT = savedSpeedStorageValue2;
                        PlaySnd_old(SOUND_SELECT);
                    }
                    break;
            }

            if (click)
                PlaySnd_old(SOUND_SELECT);

            if (onOff != -1)
            {
                if (onOff)
                    display_text("on", 180, yPos, 2, color);
                else
                    display_text("off", 180, yPos, 2, color);
            }

            yPos += 16;

            // Add a gap
            if (i == 5)
                yPos += 8;
        }
    }

    // Display fist state
    if (showFist)
    {
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
            PS1_itoa(poing.charge, fistText, 3);
            display_text(fistText, 255, 230, 2, 0);
        }
    }

    // Display speed storage
    if (showSpeedStorage)
    {
        char *text = "speed";
        int value1 = SPEED_STORAGE_LEFT;
        int value2 = SPEED_STORAGE_RIGHT;

        char str[16];
        int txtWidth;

        // Absolute values
        if (value1 < 0)
            value1 = -value1;
        if (value2 < 0)
            value2 = -value2;

        txtWidth = PS1_CalcTextWidth(text, 2);
        display_text(text, 125, 28, 2, 1);

        sprintf((char *)&str, "%d %d", value1, value2);
        display_text((char *)&str, 125 + txtWidth + 6, 28, 2, 2);
    }
}
