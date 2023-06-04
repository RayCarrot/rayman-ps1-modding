#ifndef MOD_MENU_H
#define MOD_MENU_H

#include <export.h>

#define NUM_SEED_DIGITS 9

void do_mod_settings_screen();
void load_mod_settings();
void save_mod_settings();
int do_mod_settings_loop();

void on_enter_level();
void on_exit_level();

void toggle_effect(int effect, int enable);
int is_effect_available(int effect, short world, short level, uint currentEffects);

#endif
