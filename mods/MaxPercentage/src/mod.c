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

void on_load_level()
{
    Obj *obj;
    Collectible *coll;

    // Reset level values and update obj flags
    for (int i = 0; i < COLLECTIBLES_COUNT; i++)
    {
        coll = &collectibles[i];
        coll->remainingInLevel = 0;

        // Add the bonus flag to mark it as being a collectible bonus object
        flags[coll->type1].flags1 |= OBJ1_BONUS;
        if (coll->type2 != TYPE_INVALID)
            flags[coll->type2].flags1 |= OBJ1_BONUS; // Add the bonus flag to mark it as being a collectible bonus object
    }
    
    // Get remaining collectibles in the level
    for (int i = 0; i < level.nb_objects; i++)
    {
        obj = &level.objects[i];

        coll = findCollectible(obj);

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
            {
                collect_obj(obj);

                // Since this happens after initializing the objects we have to kill the object outself here
                obj->flags &= ~(OBJ_ALIVE | OBJ_ACTIVE);
            }
        }
        
        finishedBonus = FALSE;
    }
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

        display_text((char *)&numStr, xPos + TXT_X_OFF, yPos + TXT_Y_OFF + (coll->height >> 1) - (TXT_Y_OFF / 2), 2, 0);

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

        draw_scaled_sprite(&mapobj->sprites[coll->sprite], xPos, yPos, coll->width, coll->height);

        collXPos = xPos + TXT_X_OFF;
        collYPos = yPos + TXT_Y_OFF + (coll->height >> 1) - (TXT_Y_OFF / 2);

        atoi(coll->totalCollectedCount, numStr);
        display_text((char *)&numStr, collXPos, collYPos, 2, 0);
        collXPos += PS1_CalcTextWidth((char *)&numStr, 2);

        draw_forward_slash(collXPos, collYPos);
        collXPos += 10;

        atoi(coll->totalCount, numStr);
        display_text((char *)&numStr, collXPos, collYPos, 2, 0);

        yPos += coll->height + 6;
    }
}
