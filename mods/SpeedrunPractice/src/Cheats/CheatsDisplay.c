#include <export.h>
#include "Cheats.h"

// Variables
byte selectedMenuIndex;
byte selectedSpeedStorageValue;
sbyte savedSpeedStorageLeft;
sbyte savedSpeedStorageRight;
bool showFist;
bool showSpeedStorage;
bool showGendoors;
bool showInputs;
bool pieCageSetup;
bool infiniteBossHealth;
bool maintainFistState;

char menu_names[] =  // Single string to save space
    "show fist state\0"
    "gold fist\0"
    "maintain fist state\0"
    "show speed storage\0"
    "show gendoors\0"
    "show inputs\0"
    "pie cage setup\0"
    "infinite boss health\0"
    "fist | hang | grab\0"
    "helico\0"
    "run\0"
    "speed storage\0"
    "save speed storage\0";
byte speedStorageSubEtats[] = { 0x11, 0x12, 0x13, 3, 5, 4, 0x20 };

void cheats_display()
{
    if (in_pause)
    {
        // Navigate menu
        if (PS1_SingleTOUCHE(INPUT_DOWN))
        {
            if (selectedMenuIndex < MENU_COUNT - 1)
            {
                selectedMenuIndex++;
                PlaySnd_old(SOUND_NAVIGATE);
            }
        }
        else if (PS1_SingleTOUCHE(INPUT_UP))
        {
            if (selectedMenuIndex > 0)
            {
                selectedMenuIndex--;
                PlaySnd_old(SOUND_NAVIGATE);
            }
        }

        // Display menu
        int yPos;
        if (selectedMenuIndex> (MENU_SCROLL_START - 1))
        {
            int scrollPos = selectedMenuIndex;

            if (MENU_COUNT - scrollPos <= MENU_SCROLL_START)
                scrollPos = MENU_COUNT - MENU_SCROLL_START;

            yPos = 80 - (scrollPos * MENU_LINE_HEIGHT) + (MENU_SCROLL_START * MENU_LINE_HEIGHT);
        }
        else
        {
            yPos = 80;
        }
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

            bool click = selectedMenuIndex == i && PS1_SingleTOUCHE(INPUT_CROSS);
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
                        maintainFistState = !maintainFistState;
                    onOff = maintainFistState;
                    break;

                // Show speed storage
                case 3:
                    if (click)
                        showSpeedStorage = !showSpeedStorage;
                    onOff = showSpeedStorage;
                    break;

                // Show gendoors
                case 4:
                    if (click)
                        showGendoors = !showGendoors;
                    onOff = showGendoors;
                    break;

                // Show inputs
                case 5:
                    if (click)
                        showInputs = !showInputs;
                    onOff = showInputs;
                    break;

                // Pie cage setup
                case 6:
                    if (click)
                        pieCageSetup = !pieCageSetup;
                    onOff = pieCageSetup;
                    break;

                // Infinite boss health
                case 7:
                    if (click)
                        infiniteBossHealth = !infiniteBossHealth;
                    onOff = infiniteBossHealth;
                    break;

                // Fist, hang, grab
                case 8:
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
                case 9:
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
                case 10:
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
                case 11:
                    if (click)
                        selectedSpeedStorageValue = !selectedSpeedStorageValue;

                    int leftSpeed = SPEED_STORAGE_LEFT;
                    int rightSpeed = SPEED_STORAGE_RIGHT;
                    int selectedSpeed = selectedSpeedStorageValue == 0 ? leftSpeed : rightSpeed;

                    if (PS1_SingleTOUCHE(INPUT_LEFT))
                    {
                        if (selectedSpeed >= 0)
                        {
                            selectedSpeed -= SPEED_STORAGE_STEP;
                            if (selectedSpeed < SPEED_STORAGE_MIN)
                            {
                                selectedSpeed = SPEED_STORAGE_MIN;
                                PlaySnd_old(SOUND_NAVIGATE);
                            }
                        }
                        else
                        {
                            selectedSpeed += SPEED_STORAGE_STEP;
                            if (selectedSpeed > -SPEED_STORAGE_MIN)
                            {
                                selectedSpeed = -SPEED_STORAGE_MIN;
                                PlaySnd_old(SOUND_NAVIGATE);
                            }
                        }
                    }
                    else if (PS1_SingleTOUCHE(INPUT_RIGHT))
                    {
                        if (selectedSpeed >= 0)
                        {
                            selectedSpeed += SPEED_STORAGE_STEP;
                            if (selectedSpeed > SPEED_STORAGE_MAX)
                            {
                                selectedSpeed = SPEED_STORAGE_MAX;
                                PlaySnd_old(SOUND_NAVIGATE);
                            }
                        }
                        else
                        {
                            selectedSpeed -= SPEED_STORAGE_STEP;
                            if (selectedSpeed < -SPEED_STORAGE_MAX)
                            {
                                selectedSpeed = -SPEED_STORAGE_MAX;
                                PlaySnd_old(SOUND_NAVIGATE);
                            }
                        }
                    }

                    if (selectedSpeedStorageValue == 0)
                    {
                        leftSpeed = selectedSpeed;
                        for (byte i = 0; i < sizeof(speedStorageSubEtats); i++)
                            ray.eta[2][speedStorageSubEtats[i]].speed_x_left = selectedSpeed;
                    }
                    else
                    {
                        rightSpeed = selectedSpeed;
                        for (byte i = 0; i < sizeof(speedStorageSubEtats); i++)
                            ray.eta[2][speedStorageSubEtats[i]].speed_x_right = selectedSpeed;
                    }

                    char str[4];

                    // Absolute values
                    if (leftSpeed < 0)
                        leftSpeed = -leftSpeed;
                    if (rightSpeed < 0)
                        rightSpeed = -rightSpeed;

                    PS1_itoa(leftSpeed, (char *)&str, 4);
                    display_text((char *)&str, 180, yPos, 2, selectedSpeedStorageValue == 0 ? color : 0x00);
                    PS1_itoa(rightSpeed, (char *)&str, 4);
                    display_text((char *)&str, 180 + 32, yPos, 2, selectedSpeedStorageValue == 1 ? color : 0x00);
                    break;

                // Save speed storage
                case 12:
                    if (click)
                    {
                        savedSpeedStorageLeft = SPEED_STORAGE_LEFT;
                        savedSpeedStorageRight = SPEED_STORAGE_RIGHT;
                    }

                    if (PS1_SingleTOUCHE(INPUT_SQUARE))
                    {
                        for (byte i = 0; i < sizeof(speedStorageSubEtats); i++)
                        {
                            ray.eta[2][speedStorageSubEtats[i]].speed_x_left = savedSpeedStorageLeft;
                            ray.eta[2][speedStorageSubEtats[i]].speed_x_right = savedSpeedStorageRight;
                        }
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

            yPos += MENU_LINE_HEIGHT;

            // Add a gap
            if (i == 10)
                yPos += MENU_LINE_HEIGHT / 2;
        }
    }

    cheats_display_update();
}
