#include <export.h>

#define SAVE_TAG 0xAA

extern struct StatusBar status_bar;
extern struct Obj raytmp;

// The number of deaths. We store this in status_bar as 4 bytes (using lives_digits and hp_sprites)
// upon saving to memory card. These values are runtime only, so their initial values don't matter.
uint deaths = 0;

void INIT_NEW_GAME_Extended()
{
    // Reset deaths to 0 on new game
    deaths = 0;
}

void LoadDeaths()
{
    // Load saved deaths count
    if (status_bar.wiz_digits[0] == SAVE_TAG) // Use this value to allow loading a save from before this patch - it will normally have a range of 0-9
    {
        deaths = status_bar.lives_digits[0] | (status_bar.lives_digits[1] << 8) | (status_bar.hp_sprites[0] << 16) | (status_bar.hp_sprites[1] << 24);
    }
    else
    {
        // Assume player loaded from an old save, so they should have 0 deaths starting now
        deaths = 0;
    }
}

void SaveDeaths()
{
    // Save deaths count
    status_bar.lives_digits[0] = deaths & 0xFF;
    status_bar.lives_digits[1] = (deaths >> 8) & 0xFF;
    status_bar.hp_sprites[0] = (deaths >> 16) & 0xFF;
    status_bar.hp_sprites[1] = (deaths >> 24) & 0xFF;

    // Save tag to indicate we saved using this patch
    status_bar.wiz_digits[0] = SAVE_TAG;
}

void snifRayIsDead_Extended()
{
    // Custom code, increment death counter
    deaths++;
}

void DISPLAY_FIXE_Extended(Obj *divObj)
{
    // Rayman
    //display_sprite_NoClip(obj, 0x1b, 8, 10, 0); // Original sprite
    DrawSpriteNormalEtX(raytmp.sprites + 124, 8, 10, 1); // x: 8, y: 10, flag: flipX

    // Tings
    display_sprite_NoClip(divObj, 0x38, 0xfc, 10, 0);

    // Death count

    int digits[10];

    uint num = deaths;

    if (num == 0)
    {
        display_sprite_NoClip(divObj, 0 + 0x1c, 0x2f, 10, 0);
        return;
    }

    int i = 0;
    int j, r;
  
    while (num != 0) 
    {
        r = num % 10;
        digits[i] = r;
        i++;
        num = num / 10;
    }
  
    short xPos = 0x2f;
    for (j = i - 1; j > -1; j--) 
    {
        display_sprite_NoClip(divObj, digits[j] + 0x1c, xPos, 10, 0);
        xPos += 0xF;
    }
}