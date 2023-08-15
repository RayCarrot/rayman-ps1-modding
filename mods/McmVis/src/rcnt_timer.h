#ifndef RCNT_TIMER_H
#define RCNT_TIMER_H

#include "export.h"
#include "globals.h"

#define DescRC 0xf2000000
#define RCntCNT2 (DescRC|0x02)

void rcnt_start();
void rcnt_handler();
void rcnt_stop();
unsigned int rcnt_as_ms();

#endif