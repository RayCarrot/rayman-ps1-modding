#ifndef EFFECTS_H
#define EFFECTS_H

#include <export.h>

#define NUM_EFFECTS 14

int is_effect_available(int effect, short world, short level, uint currentEffects);
void toggle_effect(int effect, int enable);
void run_effect(int effect);

#endif
