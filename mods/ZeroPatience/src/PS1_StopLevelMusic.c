#include "globals.h"

void PS1_StopLevelMusic(void)
{
    short i = 0;
    
    if (PS1_CurTrack == 7 || PS1_SongIsPlaying(13))
        for (; PS1_SongIsPlaying(13) && i < 48; i++)
            VSync(0);
    PS1_CanPlayDeathMusic = true;
    stop_cd();
    PS1_StopPlayingAllSnd();
    stop_all_snd();
    FUN_80168f40();
}