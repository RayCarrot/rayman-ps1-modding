#ifndef GlOBALS_H
#define GlOBALS_H

#include "export.h"

#define true 1
#define false 0
#define null 0

extern LevelData level;
extern short xmap;
extern short ymap;
extern WorldInfo t_world_info[24];
extern byte world_index;
extern byte gele;
extern short h_scroll_speed;
extern short v_scroll_speed;
extern Obj ray;
extern short decalage_en_cours;
extern byte no_ray_landing_smoke;
extern byte fin_boss;
extern byte ray_on_poelle;
extern short new_world;
extern short new_level;
extern short num_world;
extern short num_level;
extern short num_world_choice;
extern byte horloge[28];
extern short NumScrollObj;
extern short poing_obj_id;
extern Poing poing;
extern long PS1_CurTrack;
extern short PS1_CanPlayDeathMusic;
extern byte chemin_percent;
extern Obj *mapobj;
extern byte display_txt_fee;
extern byte old_txt_fee;
extern byte new_txt_fee;
extern short png_or_fee_id;
extern short remoteRayXToReach;
extern byte ray_in_fee_zone;
extern TextToDisplay text_to_display[10];
extern RaymanEvents RayEvts;
extern byte finBosslevel[2];
extern byte UNK_801cedfc;
extern byte PS1_ShouldFadeOutWorldIntro;
extern byte You_Win;
extern byte fin_du_jeu;
extern short PS1_NewWorldMusic[8];

#endif