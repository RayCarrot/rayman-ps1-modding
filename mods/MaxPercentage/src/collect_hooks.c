#include <export.h>
#include "globals.h"
#include "collectibles.h"

void collect_from_id(short objId)
{
    // Collect the object
    collect_obj(&level.objects[objId]);
}

void collect_play_snd(short snd, short objId)
{
    // Call function we overwrote
    PlaySnd(snd, objId);

    // Collect the object
    collect_obj(&level.objects[objId]);
}
