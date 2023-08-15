#include <collection.h>

int lives()
{
    struct Bit bits[]={
        {.addr=0x801f9ac8, .pos=7}, {.addr=0x801f9ae9, .pos=7}, {.addr=0x801f9ae9, .pos=6}, {.addr=0x801f9b28, .pos=7}, {.addr=0x801f9b28, .pos=6}, {.addr=0x801f9b28, .pos=4}, {.addr=0x801f9b2a, .pos=5}, {.addr=0x801f9b2a, .pos=2},
        {.addr=0x801f9b4a, .pos=4}, {.addr=0x801f9b92, .pos=2}, {.addr=0x801f9b93, .pos=1},
        {.addr=0x801f9bca, .pos=3},
        {.addr=0x801f9c8d, .pos=1},
        {.addr=0x801f9d6b, .pos=1}, {.addr=0x801f9d90, .pos=7}, {.addr=0x801f9da8, .pos=5}, {.addr=0x801f9dca, .pos=5}, {.addr=0x801f9e10, .pos=1},
        {.addr=0x801f9e48, .pos=3}, {.addr=0x801f9e6b, .pos=2}, {.addr=0x801f9e6e, .pos=7},
        {.addr=0x801f9f0b, .pos=4}, {.addr=0x801f9f0f, .pos=4}, {.addr=0x801f9f28, .pos=7},
        {.addr=0x801f9fd3, .pos=7}, {.addr=0x801f9feb, .pos=5}, {.addr=0x801f9fed, .pos=1}, {.addr=0x801fa010, .pos=5}, {.addr=0x801fa02b, .pos=5}, {.addr=0x801fa02c, .pos=1}, {.addr=0x801fa02f, .pos=3},
        {.addr=0x801fa053, .pos=7}, {.addr=0x801fa0ac, .pos=4},
        {.addr=0x801fa148, .pos=0}, {.addr=0x801fa16a, .pos=6}, {.addr=0x801fa16b, .pos=4}, {.addr=0x801fa16e, .pos=2}, {.addr=0x801fa190, .pos=6}, {.addr=0x801fa193, .pos=6},
        {.addr=0x801fa1d0, .pos=0}, {.addr=0x801fa1d1, .pos=5}, {.addr=0x801fa1d3, .pos=0}, {.addr=0x801fa1f0, .pos=6}, {.addr=0x801fa20b, .pos=7},
        {.addr=0x801fa22f, .pos=4}, {.addr=0x801fa22c, .pos=3}, {.addr=0x801fa22f, .pos=5}, {.addr=0x801fa22b, .pos=4}, {.addr=0x801fa257, .pos=5}, {.addr=0x801fa274, .pos=5}, {.addr=0x801fa272, .pos=2},
        {.addr=0x801fa30d, .pos=5}, {.addr=0x801fa309, .pos=2},
        {.addr=0x801fa34c, .pos=7}, {.addr=0x801fa34c, .pos=6}, {.addr=0x801fa34a, .pos=4}, {.addr=0x801fa373, .pos=4}, {.addr=0x801fa372, .pos=4}, {.addr=0x801fa389, .pos=3}, {.addr=0x801fa3b2, .pos=3},
        {.addr=0x801fa3ef, .pos=6},
        {.addr=0x801fa48d, .pos=2}, {.addr=0x801fa488, .pos=2}, {.addr=0x801fa4b5, .pos=3}, {.addr=0x801fa4b7, .pos=6}
    };

    int num_bits=sizeof(bits)/sizeof(bits[0]);
    int res=0;
    for(int i=0; i<num_bits; i++)
    {
        res+=bit1(bits[i]);
    }
    return res;
}

int magicians()
{
    struct Bit bits[]={
        {.addr=0x801f7f42, .pos=4}, {.addr=0x801f7f42, .pos=3}, {.addr=0x801f7f42, .pos=1}, {.addr=0x801f7f42, .pos=2},
        {.addr=0x801f7f46, .pos=0}, {.addr=0x801f7f46, .pos=1},
        {.addr=0x801f7f49, .pos=3}, {.addr=0x801f7f49, .pos=4},
        {.addr=0x801f7f4d, .pos=3}, {.addr=0x801f7f4d, .pos=4},
        {.addr=0x801f7f51, .pos=3}
    };

    int num_bits=sizeof(bits)/sizeof(bits[0]);
    int res=0;
    for(int i=0; i<num_bits; i++)
    {
        res+=bit1(bits[i]);
    }
    return res;
}

int collection(){ return Nb_total_cages+lives()+magicians(); }