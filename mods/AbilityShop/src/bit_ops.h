#ifndef BIT_OPS_H
#define BIT_OPS_H

#include <export.h>

struct Bit{
    unsigned int addr;
    char pos;
};

char bit1(struct Bit bit);
char bit2(struct Bit bit);

#endif