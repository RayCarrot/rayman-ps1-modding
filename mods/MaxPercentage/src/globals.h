#ifndef GlOBALS_H
#define GlOBALS_H

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define NULL 0
#define TRUE 1
#define FALSE 0

extern LevelData level;
extern short PS1_PolygonsCount;
extern Display *PS1_CurrentDisplay;
extern Display PS1_Display1;
extern void *PS1_PrevPrim;
extern ObjFlag flags[256];
extern bool in_pause;
extern Font alpha;
extern short xmap;
extern short ymap;
extern short bonus_map;
extern Obj *mapobj;

#endif
