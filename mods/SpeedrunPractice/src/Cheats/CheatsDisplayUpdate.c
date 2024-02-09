#include <export.h>
#include "Cheats.h"

// Structs
typedef struct 
{
    byte x_pos;
    byte y_pos;
    char str;
    Input input;
} InputItem;

// External variables
extern byte PS1_DrawSpriteSemiTrans;

// Variables
InputItem input_items[] =
{
    { .x_pos = 20, .y_pos = 190, .str = 'o', .input = INPUT_DOWN },
    { .x_pos = 10, .y_pos = 180, .str = 'o', .input = INPUT_LEFT },
    { .x_pos = 20, .y_pos = 170, .str = 'o', .input = INPUT_UP },
    { .x_pos = 30, .y_pos = 180, .str = 'o', .input = INPUT_RIGHT },

    { .x_pos = 60, .y_pos = 190, .str = 'o', .input = INPUT_CROSS },
    { .x_pos = 50, .y_pos = 180, .str = 'o', .input = INPUT_SQUARE },
    { .x_pos = 60, .y_pos = 170, .str = 'o', .input = INPUT_TRIANGLE },
    { .x_pos = 70, .y_pos = 180, .str = 'o', .input = INPUT_CIRCLE },

    { .x_pos = 10, .y_pos = 160, .str = '.', .input = INPUT_L1 },
    { .x_pos = 10, .y_pos = 150, .str = '.', .input = INPUT_L2 },

    { .x_pos = 70, .y_pos = 160, .str = '.', .input = INPUT_R1 },
    { .x_pos = 70, .y_pos = 150, .str = '.', .input = INPUT_R2 },
};

void cheats_display_objects()
{
    // Display gendoors
    if (cheatsInfo.showGendoors)
    {
        for (int i = 0; i < actobj.num_active_objects; i++)
        {
            if (level.objects[actobj.objects[i]].type == TYPE_GENERATING_DOOR)
                display2(&level.objects[actobj.objects[i]]);
        }        
    }
}

void restoreGameStateAfterDying(SaveState *save)
{
    byte subEtat = poing.sub_etat;
    restoreGameState(save);
    if (cheatsInfo.maintainFistState)
    {
        poing.sub_etat = subEtat;
        level.objects[poing_obj_id].init_sub_etat = subEtat;
    }
}

void cheats_display_update()
{
    // Setup pie cage
    if (cheatsInfo.pieCageSetup && num_world == 5 && num_level == 7)
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
    if (cheatsInfo.infiniteBossHealth && PS1_BossObj != (Obj *)0x00)
    {
        PS1_BossObj->hit_points = PS1_BossObj->init_hit_points;
        ray.hit_points = status_bar.max_hp;
    }

    // Display fist state
    if (cheatsInfo.showFist)
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
    if (cheatsInfo.showSpeedStorage)
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

    // Place big power in no-clip mode with square
    if (ray_mode < 0 && PS1_SingleTOUCHE(INPUT_SQUARE))
    {
        Obj *obj = (Obj *)0x00;

        // Find already placed big power to place again
        for (short i = 0; i < level.nb_objects; i++)
        {
            if (level.objects[i].img_buffer == (undefined *)0x01234567)
            {
                obj = &level.objects[i];
                break;
            }
        }

        // If not found we convert unused object to a big power
        if (obj == (Obj *)0x00)
        {
            obj = findfirstObject(TYPE_PIEDS_RAYMAN);
            obj->type = TYPE_JAUGEUP;
            obj->hit_points = 2;
            obj->hit_sprite = 0;
            obj->animations = level.objects[poing_obj_id].animations;
            obj->sprites = level.objects[poing_obj_id].sprites;
            obj->eta = level.objects[poing_obj_id].eta;
            obj->cmds = 0x00;
            obj->cmd_labels = 0x00;
            obj->img_buffer = (undefined *)0x01234567;
        }

        // Set position and state
        obj->init_x_pos = ray.x_pos;
        obj->init_y_pos = ray.y_pos;
        obj->init_main_etat = 6;
        obj->init_sub_etat = 2;
        
        // Init
        obj_init(obj);
        obj->flags |= OBJ_ALIVE | OBJ_ACTIVE;
        calc_obj_pos(obj);
    }

    // Input display
    if (cheatsInfo.showInputs)
    {
        char text[2];
        text[1] = 0x00;
        InputItem *item;

        for (uint i = 0; i < sizeof(input_items) / sizeof(InputItem); i++)
        {
            item = &input_items[i];
            if (!TOUCHE(item->input))
                PS1_DrawSpriteSemiTrans = 1;
            text[0] = item->str;
            display_text(text, item->x_pos, item->y_pos, 2, PS1_DrawSpriteSemiTrans ? 11 : 1);
            PS1_DrawSpriteSemiTrans = 0;
        }
    }
}
