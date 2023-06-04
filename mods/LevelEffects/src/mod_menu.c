#include <export.h>
#include "mod_menu.h"
#include "mod.h"
#include "effects.h"
#include "effect_names.h"
#include "global.h"

char rand_seed_digits[NUM_SEED_DIGITS];
int is_selecting_effects;

void do_mod_settings_screen()
{
    INIT_FADE_IN();
    load_mod_settings();
    SYNCHRO_LOOP(do_mod_settings_loop);
    save_mod_settings();
    DO_FADE_OUT();
}

void load_mod_settings()
{
    positiony = 3;
    positionx = -1;
    is_selecting_effects = FALSE;

    for (int i = NUM_SEED_DIGITS - 1; i >= 0; i--)
    {
        rand_seed_digits[i] = rand_seed % 10;
        rand_seed /= 10;
    }
}

void save_mod_settings()
{
    int factor;

    // Get random seed from settings
    rand_seed = 0;
    factor = 1;

    for (int i = NUM_SEED_DIGITS - 1; i >= 0; i--)
    {
        rand_seed += rand_seed_digits[i] * factor;
        factor *= 10;
    }

    setup_mod();
}

int do_mod_settings_loop()
{
    short fistX;
    short fistY;
    int ret;
    int num_pos_x;
    int num_pos_y;
    char digits_str[4];
    int num_enabled_effects;

    fistX = -1;
    fistY = -1;
    num_pos_x = 0;
    ret = 0;

    readinput();
    DO_FADE();
    CLRSCR();
    DISPLAY_FOND_MENU();

    if (is_selecting_effects)
    {
        num_pos_y = NUM_EFFECTS + 1;

        display_text("/effects/", SCREEN_WIDTH / 2, 36, 1, 0xb);

        for (int i = 0; i < NUM_EFFECTS / 2; i++)
        {
            display_text(get_effect_name(i), 40, 80 + i * 15, 2, ((enabled_effects >> i) & 1) ? 0x07 : 0x01);
        }

        for (int i = NUM_EFFECTS / 2; i < NUM_EFFECTS; i++)
        {
            display_text(get_effect_name(i), 180, 80 + (i - NUM_EFFECTS / 2) * 15, 2, ((enabled_effects >> i) & 1) ? 0x07 : 0x01);
        }

        display_text("/back/", SCREEN_WIDTH / 2, 200, 2, positiony == NUM_EFFECTS ? 0x90 : 4);
        
        if (positiony == NUM_EFFECTS)
        {
            fistX = 115;
            fistY = 185;
        }
        else
        {
            if (positiony >= NUM_EFFECTS / 2)
            {
                fistX = 180 - 25;
                fistY = 80 - 15 + (positiony - NUM_EFFECTS / 2) * 15;
            }
            else
            {
                fistX = 40 - 25;
                fistY = 80 - 15 + positiony * 15;
            }

            if (PS1_SpecialTOUCHE(INPUT_CROSS))
            {
                PlaySnd_old(0x44);
                enabled_effects ^= 1 << positiony;
            }
        }

        // BACK
        if (PS1_SpecialTOUCHE(INPUT_CIRCLE) || (positiony == NUM_EFFECTS && PS1_SpecialTOUCHE(INPUT_CROSS)))
        {
            PlaySnd_old(0x45);
            is_selecting_effects = FALSE;
            positiony = 0;
        }
    }
    else
    {
        num_pos_y = 4;

        display_text("/level effect options/", SCREEN_WIDTH / 2, 36, 1, 0xb);

        display_text("effects", 50, 80, 2, positiony == 0 ? 0x90 : 6);

        num_enabled_effects = 0;
        for (int i = 0; i < NUM_EFFECTS; i++)
        {
            if ((enabled_effects & (1 << i)) != 0)
                num_enabled_effects++;
        }
        
        sprintf((char *)&digits_str, "%d", num_enabled_effects);
        display_text((char *)&digits_str, 140, 80, 2, 6);

        display_text("per lvl", 50, 110, 2, positiony == 1 && positionx == -1 ? 0x90 : 7);
        sprintf((char *)&digits_str, "%d", effects_per_level);
        display_text((char *)&digits_str, 140, 110, 2, positiony == 1 && positionx == 0 ? 0x90 : 7);

        display_text("seed", 50, 140, 2, positiony == 2 && positionx == -1 ? 0x90 : 8);
        for (int i = 0; i < NUM_SEED_DIGITS; i++)
        {
            sprintf((char *)&digits_str, "%d", rand_seed_digits[i]);
            display_text((char *)&digits_str, 140 + (i * 12), 140, 2, positiony == 2 && positionx == i ? 0x90 : 8);
        }

        display_text("/start/", SCREEN_WIDTH / 2, 200, 2, positiony == 3 ? 0x90 : 4);

        // START
        if (positiony == 3)
        {
            fistX = 115;
            fistY = 185;

            if (PS1_SpecialTOUCHE(INPUT_CROSS))
            {
                PlaySnd_old(0x45);
                ret = 1;
            }
        }
        // OPTIONS
        else
        {
            fistX = 50 - 25;
            fistY = 80 - 15 + positiony * 30;

            // EFFECTS
            if (positiony == 0)
            {
                if (PS1_SpecialTOUCHE(INPUT_CROSS))
                {
                    PlaySnd_old(0x44);
                    is_selecting_effects = TRUE;
                }
            }
            // EFFECTS PER LEVEL
            else if (positiony == 1)
            {
                num_pos_x = 1;

                if (positionx != -1)
                {
                    if (PS1_SpecialTOUCHE(INPUT_DOWN))
                    {
                        PlaySnd_old(0x44);

                        if (effects_per_level == 1)
                        {
                            effects_per_level = NUM_EFFECTS;
                        }
                        else
                        {
                            effects_per_level--;
                        }
                    }
                    else if (PS1_SpecialTOUCHE(INPUT_UP))
                    {
                        PlaySnd_old(0x44);

                        if (effects_per_level == NUM_EFFECTS)
                        {
                            effects_per_level = 1;
                        }
                        else
                        {
                            effects_per_level++;
                        }
                    }
                }
            }
            // SEED
            else if (positiony == 2)
            {
                num_pos_x = NUM_SEED_DIGITS;

                if (positionx != -1)
                {
                    if (PS1_SpecialTOUCHE(INPUT_DOWN))
                    {
                        PlaySnd_old(0x44);

                        if (rand_seed_digits[positionx] == 0)
                        {
                            rand_seed_digits[positionx] = 9;
                        }
                        else
                        {
                            rand_seed_digits[positionx]--;
                        }
                    }
                    else if (PS1_SpecialTOUCHE(INPUT_UP))
                    {
                        PlaySnd_old(0x44);

                        if (rand_seed_digits[positionx] == 9)
                        {
                            rand_seed_digits[positionx] = 0;
                        }
                        else
                        {
                            rand_seed_digits[positionx]++;
                        }
                    }
                }
            }
        }
    }

    display_sprite(mapobj, 2, fistX, fistY, 1);

    if (num_pos_x > 0 && positionx != -1)
    {
        if (PS1_SpecialTOUCHE(INPUT_CROSS) || PS1_SpecialTOUCHE(INPUT_CIRCLE))
        {
            PlaySnd_old(0x45);
            positionx = -1;
        }
        if (positionx > 0 && PS1_SpecialTOUCHE(INPUT_LEFT))
        {
            PlaySnd_old(0x44);
            positionx--;
        }
        else if (positionx < num_pos_x - 1 && PS1_SpecialTOUCHE(INPUT_RIGHT))
        {
            PlaySnd_old(0x44);
            positionx++;
        }
    }
    else
    {
        if (num_pos_x > 0 && PS1_SpecialTOUCHE(INPUT_CROSS))
        {
            PlaySnd_old(0x44);
            positionx = 0;
        }
        else if (positiony < num_pos_y - 1 && PS1_SpecialTOUCHE(INPUT_DOWN))
        {
            PlaySnd_old(0x44);
            positiony++;
        }
        else if (positiony > 0 && PS1_SpecialTOUCHE(INPUT_UP))
        {
            PlaySnd_old(0x44);
            positiony--;
        }
    }

    return ret;
}
