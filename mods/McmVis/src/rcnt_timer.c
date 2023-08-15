#include "rcnt_timer.h"

unsigned int rcnt_counter=0;
int rcnt_desc=NULL;

void rcnt_start()
{
    rcnt_counter=0;
    rcnt_desc=OpenEvent(RCntCNT2, EvSpINT, EvMdINTR, (long *)rcnt_handler);
    if(rcnt_desc==-1){ printf("rcnt_timer: OpenEvent error\n"); }
    if(!EnableEvent(rcnt_desc)){ printf("rcnt_timer: EnableEvent error\n"); }
    SetRCnt(RCntCNT2, 42236, 0x1000 | 0x0000); //33.8688 MHz * 10^6 / 8 / 100 for 100ths of a second
    StartRCnt(RCntCNT2);
}

void rcnt_handler(){ rcnt_counter++; }

void rcnt_stop()
{
    if(!CloseEvent(rcnt_desc)){ printf("rcnt_timer: CloseEvent error\n"); }
}

unsigned int rcnt_as_ms(){ return rcnt_counter*10; }