#ifndef GENERALMENU_H
#define GENERALMENU_H

#include "menu.h"

extern Menu general_menu;

void checkpoint();
void die();
int small_ray(MenuItem *menuItem, int toggle);
void show_vram();

#endif
