#ifndef GLOBAL_H
#define GLOBAL_H

#include <export.h>

#define RAND_MAX 0x7FFF
#define FALSE 0x00
#define TRUE 0x01
#define NULL 0x00
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

extern byte nb_levels_in_world[8];
extern short ray_wind_force;
extern short positiony;
extern short positionx;
extern short num_level;
extern short num_world;
extern Obj *mapobj;
extern RaymanEvents RayEvts;
extern Obj ray;
extern Obj raytmp;
extern byte ray_stack_is_full;
extern byte ray_pos_in_stack;
extern byte black_pos_in_stack;
extern short black_ray_obj_id;
extern short black_fist_obj_id;
extern short poing_obj_id;
extern LevelData level;
extern Poing poing;
extern ObjTypeFlags flags[256];
extern MapData mp;
extern short new_level;
extern byte PS1_HasLoadedFont;
extern byte MENU_RETURN;
extern byte in_pause;

void srand(int seed);

#endif
