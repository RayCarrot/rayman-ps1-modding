#include <export.h>
#include "mod.h"
#include "collectibles.h"
#include "globals.h"
#include "display.h"

bool showTotalProgress;
bool selectPressed;

bool finishedBonus;

void finish_bonus_level(int world, int level)
{
    // Call function we overwrote
    set_bonus_map_complete(world, level);

    finishedBonus = TRUE;
}

void on_new_game()
{
    #ifdef DEBUG
    for (byte i = 0; i < 24; i++)
        t_world_info[i].state = 1;

    extern ushort RayEvts;
    RayEvts=0x0187;
    #endif

    // Reset total values
    for (int i = 0; i < COLLECTIBLES_COUNT; i++)
        collectibles[i].totalCollectedCount = 0;

    for (int i = 0; i < WORLDS_COUNT; i++)
        t_worlds_finished[i].levelsFinished = 0;
}

void on_load_level()
{
    Obj *obj;
    Collectible *coll;

    // Reset level values
    for (int i = 0; i < COLLECTIBLES_COUNT; i++)
        collectibles[i].remainingInLevel = 0;
    
    // Get remaining collectibles in the level
    for (int i = 0; i < level.nb_objects; i++)
    {
        coll = findCollectible(&level.objects[i]);

        if (coll != NULL && !bonus_taken(i))
            coll->remainingInLevel++;
    }

    // Since we "collect" a magician by finishing a bonus in another level we need to check when loading back
    if (finishedBonus)
    {
        for (int i = 0; i < level.nb_objects; i++)
        {
            obj = &level.objects[i];

            if (obj->type == TYPE_WIZARD1)
                collect_obj(obj);
        }
        
        finishedBonus = FALSE;
    }

    check_level_finished();
}

void on_level_loop()
{
    if (TOUCHE(INPUT_SELECT))
    {
        if (!selectPressed)
        {
            selectPressed = TRUE;
            showTotalProgress = !showTotalProgress;
        }
    }
    else
    {
        selectPressed = FALSE;
    }

    if (showTotalProgress)
        display_hud_total();
    else
        display_hud_level();
}

void display_hud_level()
{
    Collectible *coll;
    short xPos;
    short yPos;
    char numStr[4];

    xPos = 6;

    // Calculate height to determine the initial y position to start at
    yPos = 0;
    for (int i = 0; i < COLLECTIBLES_COUNT; i++)
    {
        coll = &collectibles[i];
        if (coll->remainingInLevel > 0)
            yPos += coll->height + 6;
    }

    yPos = SCREEN_HEIGHT - yPos;

    for (int i = 0; i < COLLECTIBLES_COUNT; i++)
    {
        coll = &collectibles[i];

        if (coll->remainingInLevel <= 0)
            continue;

        draw_scaled_sprite(&mapobj->sprites[coll->sprite], xPos, yPos, coll->width, coll->height);

        PS1_itoa(coll->remainingInLevel, numStr, 0);

        display_text((char *)&numStr, xPos + TXT_X_OFF, yPos + TXT_Y_OFF + (coll->height >> 1) - (TXT_Y_OFF / 2), 2, TXT_COLOR_NORMAL);

        yPos += coll->height + 6;
    }
}

void display_hud_total()
{
    Collectible *coll;
    short xPos;
    short yPos;
    short collXPos;
    short collYPos;
    char numStr[5];
    uint color;

    xPos = 6;

    // Calculate height to determine the initial y position to start at
    yPos = 0;
    for (int i = 0; i < COLLECTIBLES_COUNT; i++)
    {
        coll = &collectibles[i];
        yPos += coll->height + 6;
    }

    yPos = SCREEN_HEIGHT - yPos;

    for (int i = 0; i < COLLECTIBLES_COUNT; i++)
    {
        coll = &collectibles[i];

        color = coll->totalCollectedCount == coll->totalCount ? TXT_COLOR_COMPLETE : TXT_COLOR_NORMAL;

        draw_scaled_sprite(&mapobj->sprites[coll->sprite], xPos, yPos, coll->width, coll->height);

        collXPos = xPos + TXT_X_OFF;
        collYPos = yPos + TXT_Y_OFF + (coll->height >> 1) - (TXT_Y_OFF / 2);

        PS1_itoa(coll->totalCollectedCount, numStr, 0);
        display_text((char *)&numStr, collXPos, collYPos, 2, color);
        collXPos += PS1_CalcTextWidth((char *)&numStr, 2);

        draw_forward_slash(collXPos, collYPos, color);
        collXPos += 10;

        PS1_itoa(coll->totalCount, numStr, 0);
        display_text((char *)&numStr, collXPos, collYPos, 2, color);

        yPos += coll->height + 6;
    }

    if(old_num_world < WORLDS_COUNT && !You_Win) // Prevent drawing on save icon or credits
    {
        WorldsFinished *world_finished = &t_worlds_finished[old_num_world];
        byte levelsfinished = world_finished->levelsFinished;
        char finishedStr[4];
        short x_centered = (SCREEN_WIDTH / 2) - (world_finished->totalLevels * TXT_FIN_X_OFF / 2);
        for(int i = 0; i < world_finished->totalLevels; i++)
        {
            sprintf(finishedStr, "%i", i + 1);
            bool levelFinished = levelsfinished >> i & 1;
            display_text(finishedStr, x_centered + TXT_FIN_X_OFF * i, 235, 2, levelFinished ? TXT_COLOR_COMPLETE : TXT_COLOR_NORMAL);
        }
    }
}

void display_obj(Obj *obj)
{
    Animation *anim;
    AnimationLayer *layer;
    Sprite *sprite;
    bool objFlipX;
    short x;

    // Draw transparent if collected
    if (bonus_taken(obj->id))
        PS1_DrawSpriteSemiTrans = 1;

    if (obj->type == TYPE_SIGNPOST)
    {
        // We know that an endsign always uses a single layer, so no need to enumerate the layers
        anim = &obj->animations[obj->anim_index];
        layer = &anim->layers[obj->anim_frame * anim->layers_count];
        sprite = &obj->sprites[layer->sprite];
        objFlipX = obj->flags & OBJ_FLIP_X;

        // I don't think endsigns can ever be flipped, so we might be able to remove this logic...
        if (objFlipX)
            x = (obj->screen_x_pos + obj->offset_bx * 2) - layer->x_pos - sprite->width;
        else
            x = obj->screen_x_pos + layer->x_pos;

        WorldsFinished *world_finished = &t_worlds_finished[old_num_world];
        byte norm_num_level = num_level - t_world_info[old_num_world].level;
        if(norm_num_level < world_finished->totalLevels)
        {
            bool levelFinished = world_finished->levelsFinished >> norm_num_level & 1;
            if(levelFinished)
                draw_colored_sprite(sprite, x, obj->screen_y_pos + layer->y_pos, objFlipX ^ layer->flip_x, 100, 255, 100);
            else
                draw_colored_sprite(sprite, x, obj->screen_y_pos + layer->y_pos, objFlipX ^ layer->flip_x, 255, 100, 255);
        }
    }
    else
        display2(obj); // Display like normal if not an endsign
}