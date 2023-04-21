#include <export.h>

// TODO: Optimize code length by not overwriting function calls. Instead of using jal 
//       we should use j to jump out at the end of a function and thus extending it

#define SAVE_TAG 0xAA

extern struct StatusBar status_bar;
extern struct Obj raytmp;

// The number of tings. We store this in status_bar as 4 bytes (using lives_digits and hp_sprites)
// upon saving to memory card. These values are runtime only, so their initial values don't matter.
uint tings = 0;

void INIT_NEW_GAME_Extended()
{
    // Call function we overwrote call for before
    INIT_RAY_BEGIN();

    // Reset tings to 0 on new game
    tings = 0;
}

void LoadGameOnDisk_Extended()
{
    // Call function we overwrote call for before
    POINTEUR_BOUTONS_OPTIONS_BIS();

    // Load saved tings count
    if (status_bar.wiz_digits[0] == SAVE_TAG) // Use this value to allow loading a save from before this patch - it will normally have a range of 0-9
    {
        tings = status_bar.lives_digits[0] | (status_bar.lives_digits[1] << 8) | (status_bar.hp_sprites[0] << 16) | (status_bar.hp_sprites[1] << 24);
    }
    else
    {
        // Assume player loaded from an old save, so they should have 0 tings starting now
        tings = 0;
    }
}

void SaveTings()
{
    // Save tings count
    status_bar.lives_digits[0] = tings & 0xFF;
    status_bar.lives_digits[1] = (tings >> 8) & 0xFF;
    status_bar.hp_sprites[0] = (tings >> 16) & 0xFF;
    status_bar.hp_sprites[1] = (tings >> 24) & 0xFF;

    // Save tag to indicate we saved using this patch
    status_bar.wiz_digits[0] = SAVE_TAG;
}

void setTingStateAndIncreaseCounter(Obj *obj, int substate)
{
    // Call function we overwrote call for before
    set_sub_etat(obj, substate);

    // Custom code, increment ting counter
    tings++;
}

void DISPLAY_FIXE_Extended(Obj* divObj, uint sprite, short x, short y, byte p5)
{
    // Perform the original call first:
    display_sprite(divObj, sprite, x, y, p5);

    // Ting count

    int digits[10];

    uint num = tings;

    const short tingX = 0x118;
    const short tingY = 0xca;

    int i = 0;
    int j, r;

    if (num == 0)
    {
        i = 1;
        digits[0] = 0;
    }

    while (num != 0) 
    {
        r = num % 10;
        digits[i] = r;
        i++;
        num = num / 10;
    }

    short xPos = tingX+0x23 - i*0xF;
    for (j = i - 1; j > -1; j--) 
    {
        display_sprite(divObj, digits[j] + 0x1c, xPos, tingY, 0);
        xPos += 0xF;
    }

    // Ting counter sprite in the bottom-right
    display_sprite(divObj, 0x38, tingX - i*0xF, tingY, 0);

}