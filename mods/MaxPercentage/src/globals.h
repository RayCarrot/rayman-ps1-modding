#ifndef GlOBALS_H
#define GlOBALS_H

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define NULL 0
#define TRUE 1
#define FALSE 0

//#define DEBUG

extern LevelData level;
extern short PS1_PolygonsCount;
extern Display *PS1_CurrentDisplay;
extern Display PS1_Displays[2];
extern void *PS1_PrevPrim;
extern bool in_pause;
extern Font alpha;
extern short xmap;
extern short ymap;
extern short bonus_map;
extern Obj *mapobj;
extern byte PS1_DrawSpriteSemiTrans;
extern WorldInfo t_world_info[24];
extern byte old_num_world;
extern short num_level;
extern Obj ray;
extern bool You_Win;

#endif
