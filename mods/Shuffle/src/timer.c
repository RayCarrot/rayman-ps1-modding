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

void shuffle_objects()
{
    Obj *src;
    Obj *dst;
    byte validObjs[256];
    int validObjsCount = 0;

    srand(frames);

    for (int i = 0; i < level.nb_objects; i++) 
    {
        if (level.objects[i].x_pos > 0 && level.objects[i].y_pos > 0)
        {
            validObjs[validObjsCount] = i;
            validObjsCount++;
        }
    }

    for (int i = 0; i < validObjsCount - 1; i++) 
    {
        int j = i + rand() / (RAND_MAX / (validObjsCount - i) + 1);
        
        src = &level.objects[validObjs[i]];
        dst = &level.objects[validObjs[j]];

        dst->init_x_pos = dst->x_pos = src->x_pos + src->offset_bx - dst->offset_bx;
        dst->init_y_pos = dst->y_pos = src->y_pos + src->offset_by - dst->offset_by;        
    }
    
    PlaySnd_old(12);
}
