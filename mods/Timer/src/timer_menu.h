#ifndef TIMER_MENU_H
#define TIMER_MENU_H

#include <export.h>
#include "timer.h"

#define NUM_OPTIONS 2

#define TEXT_LENGTH 85
#define TEXT_INFO 0
#define TEXT_HEADER 1
#define TEXT_OPTIONS 2
#define TEXT_SUB_OPTIONS (TEXT_OPTIONS + NUM_OPTIONS)

// Structs
typedef struct // Struct to save space 
{
    byte *options[NUM_OPTIONS];
    byte sub_options_counts[NUM_OPTIONS];
    char text[TEXT_LENGTH];
} TimerMenuData;

#endif