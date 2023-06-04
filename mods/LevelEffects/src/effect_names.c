#include <export.h>
#include "effect_names.h"

char effect_names[] = // Single string to save space
    "hide rayman\0"
    "hide level\0"
    "hide objects\0"
    "wind left\0"
    "wind right\0"
    "double speed\0"
    "super jumps\0"
    "super helico\0"
    "remove i-frames\0"
    "invert controls\0"
    "slippery\0"
    "tings hurt\0"
    "dark rayman\0"
    "darkness";

char *get_effect_name(int effect)
{
    char *str = (char *)effect_names;
    byte index = effect;

    while (index) 
    {
        if ( !*str ) 
            index--;

        str++;
    }

    return str;
}
