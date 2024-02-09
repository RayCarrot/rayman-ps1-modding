#ifndef CHEATS_H
#define CHEATS_H

#include <export.h>

// Constants
#define MENU_COUNT 13
#define MENU_SCROLL_START 4
#define MENU_LINE_HEIGHT 16
#define SOUND_NAVIGATE 0x44
#define SOUND_SELECT 0x45
#define SPEED_STORAGE_MIN 0
#define SPEED_STORAGE_MAX 112
#define SPEED_STORAGE_STEP 16
#define SPEED_STORAGE_LEFT ray.eta[2][0x11].speed_x_left
#define SPEED_STORAGE_RIGHT ray.eta[2][0x11].speed_x_right

#define MENUPAGE_SHOW_FIST_STATE 0
#define MENUPAGE_GOLD_FIST 1
#define MENUPAGE_MAINTAIN_FIST_STATE 2
#define MENUPAGE_SHOW_SPEED_STORAGE 3
#define MENUPAGE_SHOW_GENDOORS 4
#define MENUPAGE_SHOW_INPUTS 5
#define MENUPAGE_PIE_CAGE_SETUP 6
#define MENUPAGE_INFINITE_BOSS_HEALTH 7
#define MENUPAGE_FIST_HANG_GRAB 8
#define MENUPAGE_HELICO 9
#define MENUPAGE_RUN 10
#define MENUPAGE_SPEED_STORAGE 11
#define MENUPAGE_SAVE_SPEED_STORAGE 12

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

// Variables
extern bool showFist;
extern bool showSpeedStorage;
extern bool showGendoors;
extern bool showInputs;
extern bool pieCageSetup;
extern bool infiniteBossHealth;
extern bool maintainFistState;

void cheats_display_update();

#endif