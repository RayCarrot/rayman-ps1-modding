#include <export.h>

byte sound;

void DO_PLAYER()
{
    char sndStr[4];

    display_text("/select sound to play/", 0xA0, 0x50, 1, 1);
 
    PS1_itoa(sound, sndStr, 0);
    display_text(sndStr, 0xA0, 0x78, 1, 1);
    
    if (PS1_SpecialTOUCHE(INPUT_RIGHT))
        sound++;
    else if (PS1_SpecialTOUCHE(INPUT_LEFT))
        sound--;
    else if (PS1_SpecialTOUCHE(INPUT_UP))
        sound += 10;
    else if (PS1_SpecialTOUCHE(INPUT_DOWN))
        sound -= 10;
    else if (PS1_SpecialTOUCHE(INPUT_CROSS))
        PlaySnd_old(sound);
    else if (PS1_SpecialTOUCHE(INPUT_CIRCLE))
        stop_all_snd();
}
