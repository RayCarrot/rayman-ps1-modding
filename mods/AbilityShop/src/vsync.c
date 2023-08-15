#include <vsync.h>

void vsync_update()
{
    char done=coll_left(collection())<=0;
    dist_update(done);
    timer_update(done);
}