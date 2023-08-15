#ifndef TIMER_H
#define TIMER_H

#include <export.h>

//adapted from https://github.com/RayCarrot/rayman-ps1-modding/tree/main/mods/Timer

extern char timer_str[12];

void timer_new_game_start();
void timer_update(char done);
void timer_display(char done);

#endif