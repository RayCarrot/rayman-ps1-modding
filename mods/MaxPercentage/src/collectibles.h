#ifndef COLLECTIBLES_H
#define COLLECTIBLES_H

#include <export.h>

// Better way to do this?
//#define COLLECTIBLES_COUNT (int)(sizeof(collectibles) / sizeof(collectibles[0]))
#define COLLECTIBLES_COUNT 7
#define WORLDS_COUNT 18

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

typedef struct
{
    byte levelsFinished;
    byte totalLevels; // Only needed to limit text we draw?
} WorldsFinished;

extern WorldsFinished t_worlds_finished[];

Collectible *findCollectible(Obj * obj);
void collect_obj(Obj *obj);
void check_level_finished();
bool level_finished();

#endif
