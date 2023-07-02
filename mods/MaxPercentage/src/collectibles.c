#include <export.h>
#include "collectibles.h"
#include "globals.h"

Collectible collectibles[] =
{
    { .type1 = TYPE_CAGE,          .type2 = TYPE_INVALID, .sprite = 90, .width = 16, .height = 16, .totalCount = 102, },  // Cage
    { .type1 = TYPE_WIZARD1,       .type2 = TYPE_INVALID, .sprite = 92, .width = 16, .height = 15, .totalCount = 11, },   // Magician
    { .type1 = TYPE_WIZ,           .type2 = TYPE_INVALID, .sprite = 66, .width = 16, .height = 14, .totalCount = 2119, }, // Ting
    { .type1 = TYPE_ONEUP,         .type2 = TYPE_INVALID, .sprite = 15, .width = 16, .height = 28, .totalCount = 65, },   // Life
    { .type1 = TYPE_JAUGEUP,       .type2 = TYPE_POWERUP, .sprite = 26, .width = 16, .height = 13, .totalCount = 112, },  // Power
    { .type1 = TYPE_POING_POWERUP, .type2 = TYPE_INVALID, .sprite = 2,  .width = 16, .height = 13, .totalCount = 82, },   // Speed/gold fist
    { .type1 = TYPE_SUPERHELICO,   .type2 = TYPE_INVALID, .sprite = 47, .width = 16, .height = 17, .totalCount = 4, },    // Helicopter potion
};

WorldsFinished t_worlds_finished[]=
{
    {.levelsFinished = 0, .totalLevels = 4},
    {.levelsFinished = 0, .totalLevels = 4},
    {.levelsFinished = 0, .totalLevels = 3},
    {.levelsFinished = 0, .totalLevels = 6},
    {.levelsFinished = 0, .totalLevels = 6},
    {.levelsFinished = 0, .totalLevels = 5},
    {.levelsFinished = 0, .totalLevels = 2},
    {.levelsFinished = 0, .totalLevels = 3},
    {.levelsFinished = 0, .totalLevels = 2},
    {.levelsFinished = 0, .totalLevels = 3},
    {.levelsFinished = 0, .totalLevels = 6},
    {.levelsFinished = 0, .totalLevels = 4},
    {.levelsFinished = 0, .totalLevels = 3},
    {.levelsFinished = 0, .totalLevels = 4},
    {.levelsFinished = 0, .totalLevels = 2},
    {.levelsFinished = 0, .totalLevels = 6},
    {.levelsFinished = 0, .totalLevels = 3},
    {.levelsFinished = 0, .totalLevels = 4},
};

Collectible *findCollectible(Obj * obj)
{
    Collectible* coll;

    for (int i = 0; i < COLLECTIBLES_COUNT; i++)
    {
        coll = &collectibles[i];

        if (coll->type1 == obj->type || coll->type2 == obj->type)
            return coll;
    }

    return NULL;
}

void collect_obj(Obj *obj)
{
    Collectible* coll;

    coll = findCollectible(obj);

    if (coll != NULL && coll->remainingInLevel > 0 && !bonus_taken(obj->id))
    {
        coll->remainingInLevel--;
        coll->totalCollectedCount++;
        take_bonus(obj->id);

        check_level_finished();
    }
}

void check_level_finished()
{
    if (level_finished())
    {
        WorldsFinished *world_finished = &t_worlds_finished[old_num_world];
        byte norm_num_level = num_level - t_world_info[old_num_world].level;
        if(norm_num_level < world_finished->totalLevels)
            world_finished->levelsFinished |= 1 << norm_num_level;
    }
}

bool level_finished()
{
    Collectible* coll;
    
    for (int i = 0; i < COLLECTIBLES_COUNT; i++)
    {
        coll = &collectibles[i];
        if (coll->remainingInLevel > 0)
            return FALSE;
    }

    return TRUE;
}
