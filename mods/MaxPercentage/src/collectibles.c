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
    }
}
