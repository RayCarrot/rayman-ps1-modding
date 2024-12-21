#ifndef CHEATS_H
#define CHEATS_H

#include <export.h>

// Constants
#define MENU_COUNT 17
#define MENU_PAGES_COUNT 7
#define MENU_LINE_HEIGHT 16

#define SOUND_NAVIGATE 0x44
#define SOUND_SELECT 0x45

#define SPEED_STORAGE_MIN 0
#define SPEED_STORAGE_MAX 112
#define SPEED_STORAGE_STEP 16
#define SPEED_STORAGE_LEFT ray.eta[2][0x11].speed_x_left
#define SPEED_STORAGE_RIGHT ray.eta[2][0x11].speed_x_right

#define TINGS_MIN 0
#define TINGS_MAX 99
#define TINGS_STEP 1
#define TINGS_BIG_STEP 10

#define MENUITEM_SHOW_FIST_STATE 0
#define MENUITEM_GOLD_FIST 1
#define MENUITEM_MAINTAIN_FIST_STATE 2
#define MENUITEM_SHOW_GENDOORS 3
#define MENUITEM_SHOW_INPUTS 4
#define MENUITEM_PIE_CAGE_SETUP 5
#define MENUITEM_INFINITE_BOSS_HEALTH 6
#define MENUITEM_BETILLA 7
#define MENUITEM_FIST_HANG_GRAB 8
#define MENUITEM_HELICO 9
#define MENUITEM_RUN 10
#define MENUITEM_SHOW_SPEED_STORAGE 11
#define MENUITEM_SPEED_STORAGE 12
#define MENUITEM_SAVE_SPEED_STORAGE 13
#define MENUITEM_TINGS 14
#define MENUITEM_SAVE_TINGS 15
#define MENUITEM_COLLECT_CAGES 16

// External variables
extern bool in_pause;
extern bool PS1_Ingame;
extern byte dead_time;
extern short ray_mode;
extern SaveState save1;
extern Obj ray;
extern Obj *mapobj;
extern Obj *PS1_BossObj;
extern LevelData level;
extern short poing_obj_id;
extern Poing poing;
extern RaymanEvents RayEvts;
extern short num_world;
extern short num_level;
extern StatusBar status_bar;
extern ActiveObjects actobj;
extern byte You_Win;
extern byte fin_du_jeu;
extern byte fin_dark;
extern byte Nb_total_cages;
extern byte Vignet_To_Display;
extern short departlevel;
extern short num_level_choice;
extern short new_world;
extern short new_level;
extern byte world_index;
extern byte finBosslevel[2];
extern WorldInfo t_world_info[24];
extern byte lidol_to_allocate;
extern Obj *lidol_source_obj;

typedef struct // Struct to save space 
{
    byte selectedMenuPageIndex;
    byte selectedMenuIndex;
    byte selectedSpeedStorageValue;
    sbyte savedSpeedStorageLeft;
    sbyte savedSpeedStorageRight;
    byte savedTings;
    bool showFist;
    bool showSpeedStorage;
    bool showGendoors;
    bool showInputs;
    bool pieCageSetup;
    bool infiniteBossHealth;
    bool maintainFistState;
    bool skipBetilla;
    bool collectCages;
} CheatsInfo;

// Variables
extern CheatsInfo cheatsInfo;

void cheats_display_update();

#endif