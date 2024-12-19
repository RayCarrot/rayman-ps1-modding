#ifndef CHEATS_H
#define CHEATS_H

#include <export.h>

// Constants
#define MENU_COUNT 15
#define MENU_PAGES_COUNT 6
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
#define MENUITEM_FIST_HANG_GRAB 7
#define MENUITEM_HELICO 8
#define MENUITEM_RUN 9
#define MENUITEM_SHOW_SPEED_STORAGE 10
#define MENUITEM_SPEED_STORAGE 11
#define MENUITEM_SAVE_SPEED_STORAGE 12
#define MENUITEM_TINGS 13
#define MENUITEM_SAVE_TINGS 14

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
} CheatsInfo;

// Variables
extern CheatsInfo cheatsInfo;

void cheats_display_update();

#endif