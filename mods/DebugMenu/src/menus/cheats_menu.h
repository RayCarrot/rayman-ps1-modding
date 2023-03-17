#ifndef CHEATSMENU_H
#define CHEATSMENU_H

#include "menu.h"

extern Menu cheats_menu;

int place_ray(MenuItem *menuItem, int toggle);
void max_lives();
int _5_hp(MenuItem *menuItem, int toggle);
void full_health();
void all_levels();

#endif
