#ifndef TIMER_H
#define TIMER_H

#include <export.h>

// Enums
enum TIMERMODE { TIMER_OFF, TIMER_GAME, TIMER_WORLD, TIMER_LEVEL, TIMER_DEATH };
enum TIMERDISPLAYMODE { TIMERDISP_ALWAYS, TIMERDISP_ACTION, TIMERDISP_ACTION_AND_CROSS };

// Constants
#define NUM_TIMER_MODES 5
#define NUM_TIMER_DISPLAY_MODES 3
#define TIMER_DISPLAY_TIME 60
#define SOUND_NAVIGATE 0x44
#define FALSE 0x00
#define TRUE 0x01
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#if BUILD == 1 // pal-e
#define FRAMERATE 50
#else
#define FRAMERATE 60
#endif

// External variables
extern byte dark_phase;
extern byte world_index;
extern short new_world;
extern short position;
extern short positiony;
extern Obj *PS1_BossObj;

// Structs
typedef struct // Struct to save space 
{
    uint frames;
    uint display_frames;
    int timer_display_countdown;
    enum TIMERMODE timer_mode;
    enum TIMERDISPLAYMODE timer_display_mode;
    bool is_running;
    bool entered_level;
    byte prevBossHitPoints;
} TimerInfo;

// Variables
extern TimerInfo timer_info;

#endif
