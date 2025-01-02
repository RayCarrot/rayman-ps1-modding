#include <export.h>
#include "timer_menu.h"

TimerMenuData timer_menu_data = 
{
    .options = { &timer_info.timer_mode, &timer_info.timer_display_mode },
    .sub_options_counts = { 5, 3 },

    // Single string to save space
    .text = 
    // Info
    "^: timer\0"

    // Header
    "/timer/\0"
    
    // Options
    "mode: \0"
    "show: \0"
    
    // Modes
    "off\0"
    "game\0"
    "lvl\0"
    "world\0"
    "death\0"

    // Display modes
    "always\0"
    "action\0"
    "action | cross"
};

char *get_string(int index)
{
    char *str = timer_menu_data.text;

    while (index) 
    {
        if ( !*str ) 
            index--;
        str++;
    }

    return str;
}

int do_timer_options_loop()
{
    readinput();
    CLRSCR();
    DISPLAY_FOND_MENU();

    int exitLoop = FALSE;

    display_text(get_string(TEXT_HEADER), SCREEN_WIDTH / 2, 36, 1, 0xb);

    int subOptionTextIndex = TEXT_SUB_OPTIONS;
    for (int i = 0; i < NUM_OPTIONS; i++)
    {
        char text[32];
        strcpy(text, get_string(TEXT_OPTIONS + i));

        strcat((char *)&text, get_string(subOptionTextIndex + *timer_menu_data.options[i]));

        subOptionTextIndex += timer_menu_data.sub_options_counts[i];

        display_text(text, 50, 80 + i * 30, 2, positiony == i ? 0x90 : 6);
    }

    if (positiony < NUM_OPTIONS - 1 && PS1_SingleTOUCHE(INPUT_DOWN))
    {
        PlaySnd_old(SOUND_NAVIGATE);
        positiony++;
    }
    else if (positiony > 0 && PS1_SingleTOUCHE(INPUT_UP))
    {
        PlaySnd_old(SOUND_NAVIGATE);
        positiony--;
    }
    else if (*timer_menu_data.options[positiony] < timer_menu_data.sub_options_counts[positiony] - 1 && PS1_SingleTOUCHE(INPUT_RIGHT))
    {
        PlaySnd_old(SOUND_NAVIGATE);
        *timer_menu_data.options[positiony] = *timer_menu_data.options[positiony] + 1;
    }
    else if (*timer_menu_data.options[positiony] > 0 && PS1_SingleTOUCHE(INPUT_LEFT))
    {
        PlaySnd_old(SOUND_NAVIGATE);
        *timer_menu_data.options[positiony] = *timer_menu_data.options[positiony] - 1;
    }
    else if (PS1_SingleTOUCHE(INPUT_CIRCLE))
    {
        exitLoop = TRUE;
    }

    return exitLoop;
}

void set_timer_mode()
{
    if (position == 7)
    {
        display_text(get_string(TEXT_INFO), 120, 195, 2, 15);

        if (PS1_SingleTOUCHE(INPUT_TRIANGLE))
        {
            positiony = 0;
            SYNCHRO_LOOP(do_timer_options_loop);
        }
    }
}
