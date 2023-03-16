#include <export.h>

#define RAND_MAX 0x7FFF

// Extern variables
extern LevelData level;

// Function prototypes
void srand(int seed);

// Variables
uint frames = 0;

void update_timer()
{
    frames++;
}

// TODO: Shuffle on level start
void shuffle_objects()
{
    Obj *src;
    Obj *dst;
    byte validObjs[256];
    int validObjsCount = 0;
    byte shuffledObjs[256];

    // TODO: Only initialize random on new game
    srand(frames);

    // Get valid objects
    for (int i = 0; i < level.nb_objects; i++) 
    {
        if (level.objects[i].x_pos > 0 && level.objects[i].y_pos > 0)
        {
            validObjs[validObjsCount] = i;
            validObjsCount++;
        }
    }

    // Set indexes
    for (int i = 0; i < validObjsCount; i++)
    {
        shuffledObjs[i] = i;
    }
    
    // Shuffle
    for (int i = 0; i < validObjsCount - 1; i++) 
    {
        size_t j = i + rand() / (RAND_MAX / (validObjsCount - i) + 1);
        byte t = shuffledObjs[j];
        shuffledObjs[j] = shuffledObjs[i];
        shuffledObjs[i] = t;
    }

    // Set positions
    for (int i = 0; i < validObjsCount - 1; i++) 
    {
        src = &level.objects[validObjs[i]];
        dst = &level.objects[validObjs[shuffledObjs[i]]];

        short newX = src->x_pos + src->offset_bx - dst->offset_bx;
        short newY = src->y_pos + src->offset_by - dst->offset_by;

        if (newX < 0)
            newX = 0;

        if (newY < 0)
            newY = 0;

        dst->init_x_pos = dst->x_pos = newX;
        dst->init_y_pos = dst->y_pos = newY;
    }
}
