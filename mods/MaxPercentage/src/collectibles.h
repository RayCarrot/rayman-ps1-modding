#ifndef COLLECTIBLES_H
#define COLLECTIBLES_H

#include <export.h>

// Better way to do this?
//#define COLLECTIBLES_COUNT (int)(sizeof(collectibles) / sizeof(collectibles[0]))
#define COLLECTIBLES_COUNT 7

typedef struct 
{
    // Two type fields since the power objects are two types (big and small)
    ObjType type1;
    ObjType type2;

    // The sprite to show in the hud with the scaled size
    int sprite;
    short width;
    short height;

    int totalCount;
    int totalCollectedCount;
    
    int remainingInLevel;
} Collectible;

extern Collectible collectibles[];

Collectible *findCollectible(Obj * obj);
void collect_obj(Obj *obj);

#endif
