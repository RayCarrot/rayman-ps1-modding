#ifndef DISTANCE_COUNTER_H
#define DISTANCE_COUNTER_H

#include <export.h>

//adapted from https://github.com/RayCarrot/rayman-ps1-modding/tree/main/mods/DistanceCounter

extern struct StatusBar status_bar;
extern struct Obj ray;
extern char in_pause;
extern bool gele;
extern bool dans_la_map_monde;
extern short ray_mode;
extern short loop_time;

void dist_new_game_start();
void dist_update(char done);
void dist_display(char done);

#endif