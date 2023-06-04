#ifndef MOD_H
#define MOD_H

#include <export.h>

extern uint level_effects[];
extern uint enabled_effects;
extern int effects_per_level;
extern int rand_seed;

uint get_effects_in_level(short world, short level);
void setup_mod();
void show_active_effects();
void on_enter_level();
void on_exit_level();

#endif
