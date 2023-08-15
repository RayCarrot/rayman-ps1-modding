#ifndef GlOBALS_H
#define GlOBALS_H

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define NULL 0
#define TRUE 1
#define FALSE 0

//#define DEBUG

extern char s_Maga_801cf050[5];
extern undefined4 PS1_SaveIconPalette[8];
extern undefined4 PS1_SaveIcon1[32];
extern undefined4 PS1_SaveIcon2and3[32];
extern byte nb_continue;
extern byte wi_save_zone[24];
extern RaymanEvents RayEvts;
extern Poing poing;
extern StatusBar status_bar;
extern Obj ray;
extern byte save_zone[2688];
extern byte bonus_perfect[24];
extern OptionsJeu options_jeu;
extern byte world_index;
extern short num_world_choice;
extern undefined2 xwldmapsave;
extern undefined2 ywldmapsave;
extern short xmap;
extern short ymap;
extern byte dir_on_wldmap;
extern byte finBosslevel[2];

extern char save_ray[4][4];
extern undefined4 PS1_GlobalTimer;
extern LoadInfoRay loadInfoRay[6];
extern bool dans_la_map_monde;
extern undefined4 PS1_Checksum;

extern byte let_shadow;

#endif
