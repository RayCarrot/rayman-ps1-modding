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

        atoi(coll->remainingInLevel, numStr);

        display_text((char *)&numStr, xPos + TXT_X_OFF, yPos + TXT_Y_OFF + (coll->height >> 1) - (TXT_Y_OFF / 2), 2, TXT_COLOR_NORMAL);

        yPos += coll->height + 6;
    }

    for (int i = 0; i < level.nb_objects; i++) //TODO: expensive?
    {
        Obj *obj = &level.objects[i];

        if (obj->type == TYPE_SIGNPOST)
        {
            short x_comp = (obj->x_pos - ray.x_pos);
            short y_comp = (obj->y_pos - ray.y_pos);
            bool in_distance = (x_comp * x_comp + y_comp * y_comp) < 40000;
            if(in_distance && !level_finished()) //TODO: use t_worlds_finished instead?
                display_text("not finished", 115, 150, 2, TXT_COLOR_NORMAL);
        }
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

        atoi(coll->totalCollectedCount, numStr);
        display_text((char *)&numStr, collXPos, collYPos, 2, color);
        collXPos += PS1_CalcTextWidth((char *)&numStr, 2);

        draw_forward_slash(collXPos, collYPos, color);
        collXPos += 10;

        atoi(coll->totalCount, numStr);
        display_text((char *)&numStr, collXPos, collYPos, 2, color);

        yPos += coll->height + 6;
    }

    //TODO: what if on save icon on map? (seemingly no effect, should check anyways to be sure)
    WorldsFinished *world_finished = &t_worlds_finished[old_num_world];
    byte levelsfinished = world_finished->levelsFinished;
    char finishedStr[4];
    for(int i = 0; i < world_finished->totalLevels; i++)
    {
        sprintf(finishedStr, "%i", i + 1);
        bool levelFinished = levelsfinished >> i & 1;
        display_text(finishedStr, 115 + 10 * i, 235, 2, levelFinished ? TXT_COLOR_COMPLETE : TXT_COLOR_NORMAL);
    }
}

void display_obj(Obj *obj)
{
    // Draw transparent if collected
    if (bonus_taken(obj->id))
        PS1_DrawSpriteSemiTrans = 1;

    display2(obj);
}
