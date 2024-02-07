#include <export.h>
#include "Cheats.h"

void cheats_display_update()
{
    // Setup pie cage
    if (pieCageSetup && num_world == 5 && num_level == 7)
    {
        Obj *ufo = &level.objects[62];

        if (ufo->x_pos == ufo->init_x_pos && 
            ufo->y_pos == ufo->init_y_pos)
        {
            ufo->x_pos = 2690;
            ufo->y_pos = 1778;
            ufo->speed_x = 0;
            ufo->speed_y = 3;
            ufo->main_etat = 0;
            ufo->sub_etat = 14;
        }
        
        // printf("\n");
        // printf("%d\n", ufo->x_pos);
        // printf("%d\n", ufo->y_pos);
        // printf("%d\n", ufo->speed_x);
        // printf("%d\n", ufo->speed_y);
        // printf("%d\n", ufo->main_etat);
        // printf("%d\n", ufo->sub_etat);
    }

    // Infinite boss health
    if (infiniteBossHealth && PS1_BossObj != (Obj *)0x00)
    {
        PS1_BossObj->hit_points = PS1_BossObj->init_hit_points;
        ray.hit_points = status_bar.max_hp;
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

        display_sprite(mapobj, initSubEtat >= 8 ? 1 : 2, 275, 195, 0); // Fist
        display_text(fistText, 305, 210, 2, 0); // Fist speed

        // Fist charge
        if (poing.is_charging && poing.charge > 5)
        {
            PS1_itoa(poing.charge, fistText, 3);
            display_text(fistText, 255, 210, 2, 0);
        }
    }

    // Display speed storage
    if (showSpeedStorage)
    {
        char *text = "speed";
        int speedLeft = SPEED_STORAGE_LEFT;
        int speedRight = SPEED_STORAGE_RIGHT;

        char str[16];
        int txtWidth;

        // Absolute values
        if (speedLeft < 0)
            speedLeft = -speedLeft;
        if (speedRight < 0)
            speedRight = -speedRight;

        txtWidth = PS1_CalcTextWidth(text, 2);
        display_text(text, 125, 28, 2, 1);

        sprintf((char *)&str, "%d %d", speedLeft, speedRight);
        display_text((char *)&str, 125 + txtWidth + 6, 28, 2, 2);
    }
}
