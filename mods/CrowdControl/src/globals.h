#include <export.h>

#define NULL 0x00

extern short ray_mode;
extern bool in_pause;
extern StatusBar status_bar;
extern bool new_world;
extern bool new_level;
extern short num_world;
extern short num_level;
extern short num_level_choice;
extern Obj ray;
extern Obj raytmp;
extern SaveState save1;
extern short reduced_rayman_id;
extern WorldInfo t_world_info[24];
extern short poing_obj_id;
extern LevelData level;
extern Poing poing;
extern short xmap;
extern short ymap;
extern short helico_time;
extern short jump_time;
extern short decalage_en_cours;
extern short ray_wind_force;
extern bool PS1_Ingame;
extern Display PS1_Display2;
extern byte ray_stack_is_full;
extern byte ray_pos_in_stack;
extern byte black_pos_in_stack;
extern short black_ray_obj_id;
extern short black_fist_obj_id;
extern byte button_released;
extern ObjTypeFlags flags[256];
extern BlockFlags block_flags[32];
extern RaymanEvents RayEvts;
