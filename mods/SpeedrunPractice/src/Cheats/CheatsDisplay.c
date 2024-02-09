#include <export.h>
#include "Cheats.h"

// Variables
CheatsInfo cheatsInfo;

char menu_names[] =  // Single string to save space
    // Fist
    "show\0"
    "gold\0"
    "maintain\0"

    // Show
    "gendoors\0"
    "inputs\0"

    // Misc
    "pie cage\0"
    "boss hp\0"
    
    // Power
    "fhg\0"
    "heli\0"
    "run\0"
    
    // Speed
    "show\0"
    "set\0"
    "save\0"
    
    // Page names
    "fist\0"
    "show\0"
    "misc\0"
    "power\0"
    "speed";
byte menuPageIndexes[] = { 
    MENUITEM_SHOW_FIST_STATE, 
    MENUITEM_SHOW_GENDOORS, 
    MENUITEM_PIE_CAGE_SETUP, 
    MENUITEM_FIST_HANG_GRAB, 
    MENUITEM_SHOW_SPEED_STORAGE,
    MENU_COUNT, // end
};
byte speedStorageSubEtats[] = { 0x11, 0x12, 0x13, 3, 5, 4, 0x20 };

void cheats_display()
{
    if (in_pause)
    {
        // Navgiate menu pages
        if (PS1_SingleTOUCHE(INPUT_R2))
        {
            if (cheatsInfo.selectedMenuPageIndex < MENU_PAGES_COUNT - 1)
            {
                cheatsInfo.selectedMenuPageIndex++;
                PlaySnd_old(SOUND_NAVIGATE);
            }
            else
            {
                cheatsInfo.selectedMenuPageIndex = 0;
            }

            cheatsInfo.selectedMenuIndex = 0;
        }
        else if (PS1_SingleTOUCHE(INPUT_L2))
        {
            if (cheatsInfo.selectedMenuPageIndex > 0)
            {
                cheatsInfo.selectedMenuPageIndex--;
                PlaySnd_old(SOUND_NAVIGATE);
            }
            else
            {
                cheatsInfo.selectedMenuPageIndex = MENU_PAGES_COUNT - 1;
            }

            cheatsInfo.selectedMenuIndex = 0;
        }

        int pageLength = menuPageIndexes[cheatsInfo.selectedMenuPageIndex + 1] - menuPageIndexes[cheatsInfo.selectedMenuPageIndex];

        // Navigate menu items
        if (PS1_SingleTOUCHE(INPUT_DOWN))
        {
            if (cheatsInfo.selectedMenuIndex < pageLength - 1)
            {
                cheatsInfo.selectedMenuIndex++;
                PlaySnd_old(SOUND_NAVIGATE);
            }
            else
            {
                cheatsInfo.selectedMenuIndex = 0;
            }
        }
        else if (PS1_SingleTOUCHE(INPUT_UP))
        {
            if (cheatsInfo.selectedMenuIndex > 0)
            {
                cheatsInfo.selectedMenuIndex--;
                PlaySnd_old(SOUND_NAVIGATE);
            }
            else
            {
                cheatsInfo.selectedMenuIndex = pageLength - 1;
            }
        }

        // Display page name
        char *name = menu_names;
        byte index = MENU_COUNT + cheatsInfo.selectedMenuPageIndex;
        while (index) 
        {
            if ( !*name ) 
                index--;
            name++;
        }
        display_text(name, 20, 60, 2, 2);

        // Display page indicators
        for (int i = 0; i < MENU_PAGES_COUNT; i++)
            display_text(".", 20 + i * 8, 70, 2, cheatsInfo.selectedMenuPageIndex == i ? 2 : 6);   

        // Display menu
        int yPos = 90;
        for (int i = 0; i < pageLength; i++)
        {
            // Get the name
            name = menu_names;
            byte index = menuPageIndexes[cheatsInfo.selectedMenuPageIndex] + i;
            while (index) 
            {
                if ( !*name ) 
                    index--;
                name++;
            }

            // Get the color - have it be multi-colored if selected
            byte color = cheatsInfo.selectedMenuIndex == i ? 0xe0 : 0x00;

            // Display the name
            display_text(name, 20, yPos, 2, color);

            bool click = cheatsInfo.selectedMenuIndex == i && PS1_SingleTOUCHE(INPUT_CROSS);
            int onOff = -1;

            switch (menuPageIndexes[cheatsInfo.selectedMenuPageIndex] + i)
            {
                // Show fist state
                case MENUITEM_SHOW_FIST_STATE:
                    if (click)
                        cheatsInfo.showFist = !cheatsInfo.showFist;
                    onOff = cheatsInfo.showFist;
                    break;

                // Gold fist
                case MENUITEM_GOLD_FIST:
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

                // Maintain fist state
                case MENUITEM_MAINTAIN_FIST_STATE:
                    if (click)
                        cheatsInfo.maintainFistState = !cheatsInfo.maintainFistState;
                    onOff = cheatsInfo.maintainFistState;
                    break;

                // Show speed storage
                case MENUITEM_SHOW_SPEED_STORAGE:
                    if (click)
                        cheatsInfo.showSpeedStorage = !cheatsInfo.showSpeedStorage;
                    onOff = cheatsInfo.showSpeedStorage;
                    break;

                // Show gendoors
                case MENUITEM_SHOW_GENDOORS:
                    if (click)
                        cheatsInfo.showGendoors = !cheatsInfo.showGendoors;
                    onOff = cheatsInfo.showGendoors;
                    break;

                // Show inputs
                case MENUITEM_SHOW_INPUTS:
                    if (click)
                        cheatsInfo.showInputs = !cheatsInfo.showInputs;
                    onOff = cheatsInfo.showInputs;
                    break;

                // Pie cage setup
                case MENUITEM_PIE_CAGE_SETUP:
                    if (click)
                        cheatsInfo.pieCageSetup = !cheatsInfo.pieCageSetup;
                    onOff = cheatsInfo.pieCageSetup;
                    break;

                // Infinite boss health
                case MENUITEM_INFINITE_BOSS_HEALTH:
                    if (click)
                        cheatsInfo.infiniteBossHealth = !cheatsInfo.infiniteBossHealth;
                    onOff = cheatsInfo.infiniteBossHealth;
                    break;

                // Fist, hang, grab
                case MENUITEM_FIST_HANG_GRAB:
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
                case MENUITEM_HELICO:
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
                case MENUITEM_RUN:
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
                case MENUITEM_SPEED_STORAGE:
                    if (click)
                        cheatsInfo.selectedSpeedStorageValue = !cheatsInfo.selectedSpeedStorageValue;

                    int leftSpeed = SPEED_STORAGE_LEFT;
                    int rightSpeed = SPEED_STORAGE_RIGHT;
                    int selectedSpeed = cheatsInfo.selectedSpeedStorageValue == 0 ? leftSpeed : rightSpeed;

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

                    if (cheatsInfo.selectedSpeedStorageValue == 0)
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
                    display_text((char *)&str, 160, yPos, 2, cheatsInfo.selectedSpeedStorageValue == 0 ? color : 0x00);
                    PS1_itoa(rightSpeed, (char *)&str, 4);
                    display_text((char *)&str, 160 + 32, yPos, 2, cheatsInfo.selectedSpeedStorageValue == 1 ? color : 0x00);
                    break;

                // Save speed storage
                case MENUITEM_SAVE_SPEED_STORAGE:
                    if (click)
                    {
                        cheatsInfo.savedSpeedStorageLeft = SPEED_STORAGE_LEFT;
                        cheatsInfo.savedSpeedStorageRight = SPEED_STORAGE_RIGHT;
                    }

                    if (PS1_SingleTOUCHE(INPUT_SQUARE))
                    {
                        for (byte i = 0; i < sizeof(speedStorageSubEtats); i++)
                        {
                            ray.eta[2][speedStorageSubEtats[i]].speed_x_left = cheatsInfo.savedSpeedStorageLeft;
                            ray.eta[2][speedStorageSubEtats[i]].speed_x_right = cheatsInfo.savedSpeedStorageRight;
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
                    display_text("x", 160, yPos, 2, color);
            }

            yPos += MENU_LINE_HEIGHT;
        }
    }

    cheats_display_update();
}
