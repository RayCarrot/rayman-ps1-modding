#ifndef EFFECT_NAMES_H
#define EFFECT_NAMES_H

#include <export.h>

extern char effect_names[];

char *get_effect_name(int effect);

typedef enum Effect
{
    EFFECT_HIDE_RAY = 0,
    EFFECT_HIDE_LVL = 1,
    EFFECT_HIDE_OBJ = 2,
    EFFECT_WIND_LEFT = 3,
    EFFECT_WIND_RIGHT = 4,
    EFFECT_DOUBLE_SPEED = 5,
    EFFECT_SUPER_JUMPS = 6,
    EFFECT_SUPER_HELICO = 7,
    EFFECT_NO_IFRAMES = 8,
    EFFECT_INV_CONTROLS = 9,
    EFFECT_SLIPPERY = 10,
    EFFECT_TINGS_HURT = 11,
    EFFECT_DARK_RAY = 12,
    EFFECT_DARKNESS = 13,
} Effect;

#endif
