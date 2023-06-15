#include <export.h>
#include "mod.h"
#include "effects.h"
#include "effect_names.h"
#include "global.h"

#define NUM_LEVELS (int)(sizeof(level_effects) / sizeof(uint))

uint level_effects[0x15 + 0x12 + 0x0D + 0x0D + 0x0C + 0x04];
uint enabled_effects = 0x3FFF; // 14 bits set
int effects_per_level = 2;
int rand_seed = 0;

int get_level_offset(short world, short level)
{
    int off;

    off = 0;

    for (int i = 0; i < world - 1; i++)
    {
        off += nb_levels_in_world[i];
    }

    return off + level;
}

void setup_mod()
{
    //printf("enabled_effects: %d\n", enabled_effects);
    //printf("effects_per_level: %d\n", effects_per_level);
    //printf("rand_seed: %d\n", rand_seed);

    // Initialize random
    srand(rand_seed);
    
    // Set effects for each level
    for (int wld = 1; wld < 6 + 1; wld++)
    {
        for (int lvl = 1; lvl < nb_levels_in_world[wld] + 1; lvl++)
        {
            setup_level(wld, lvl);
        }
    }
}

void setup_level(short world, short level)
{
    int off;
    uint checked_effects;

    off = get_level_offset(world, level);

    level_effects[off] = 0;

    for (int j = 0; j < effects_per_level; j++)
    {
        checked_effects = 0;

        while (TRUE && enabled_effects != 0)
        {
            int effect = rand() % NUM_EFFECTS;

            // Make sure the effect is enabled
            if ((enabled_effects & (1 << effect)) == 0)
            {
                continue;
            }

            checked_effects |= (1 << effect);

            // Try again if already set
            if ((level_effects[off] & (1 << effect)) != 0)
            {
                // Avoid repeating forever if we've checked all enabled effects
                if (checked_effects == enabled_effects)
                    break;

                continue;
            }

            // Try again if not available
            if (!is_effect_available(effect, world, level, level_effects[off]))
            {
                // Avoid repeating forever if we've checked all enabled effects
                if (checked_effects == enabled_effects)
                    break;

                continue;
            }
        
            level_effects[off] |= 1 << effect;
            break;
        }
    }
}

void show_active_effects()
{
    uint effects;
    int num_active_effects;

    display_text("/active effects/", SCREEN_WIDTH / 2, 60, 2, 0xc);

    effects = level_effects[get_level_offset(num_world, num_level)];
    num_active_effects = 0;
    
    for (int i = 0; i < NUM_EFFECTS; i++)
    {
        if ((effects & (1 << i)) != 0)
        {
            if (num_active_effects >= NUM_EFFECTS / 2)
                display_text(get_effect_name(i), 180, 80 + (num_active_effects - NUM_EFFECTS / 2) * 15, 2, 0x07);
            else
                display_text(get_effect_name(i), 40, 80 + num_active_effects * 15, 2, 0x07);
            num_active_effects++;
        }
    }
}

void on_enter_level()
{
    uint effects;

    effects = level_effects[get_level_offset(num_world, num_level)];
    //printf("effects: %d\n", effects);

    for (int i = 0; i < NUM_EFFECTS; i++)
    {
        if ((effects & (1 << i)) != 0)
            toggle_effect(i, TRUE);
    }
}

void on_exit_level()
{
    for (int i = 0; i < NUM_EFFECTS; i++)
    {
        toggle_effect(i, FALSE);
    }
}

void on_loop_level()
{
    uint effects;

    effects = level_effects[get_level_offset(num_world, num_level)];

    for (int i = 0; i < NUM_EFFECTS; i++)
    {
        if ((effects & (1 << i)) != 0)
            run_effect(i);
    }
}
