#include <export.h>

extern byte RayEvts[2];

void disable_run()
{
    RayEvts[1] &= 0xFE;
}

void enable_run()
{
    RayEvts[1] |= 0x01;
}