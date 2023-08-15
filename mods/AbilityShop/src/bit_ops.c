#include <bit_ops.h>

char bit1(struct Bit bit)
{
    return (((unsigned char *)bit.addr)[0] >> bit.pos) & 1;
}

char bit2(struct Bit bit)
{
    return (((short *)bit.addr)[0] >> bit.pos) & 1;
}