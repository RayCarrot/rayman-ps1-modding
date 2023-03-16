#include <export.h>

// Enums
enum TIMERMODE { TIMER_OFF, TIMER_GAME, TIMER_WORLD, TIMER_LEVEL, TIMER_DEATH };

// Constants
#define NUM_TIMER_MODES 5
#define DEFAULT_COOLDOWN 15
#define SOUND_NAVIGATE 0x44

#if BUILD == 1 // pal-e
#define FRAMERATE 50
#else
#define FRAMERATE 60
#endif

// External variables
extern bool dans_la_map_monde;
extern byte dark_phase;
extern byte world_index;
extern short new_world;

// Variables
uint frames = 0;
enum TIMERMODE timer_mode = TIMER_OFF;
byte input_cooldown = 0;
bool is_running = 0;
bool entered_level = 0;

void update_timer()
{
    if (is_running)
        frames++;
}

void stop_level_music()
{
    bool wasRunning = is_running;
    is_running = 0;

    // We don't want to count the timer during this
    PS1_StopLevelMusic();
    
    is_running = wasRunning;
}

void display_timer()
{
    if (timer_mode == TIMER_OFF)
        return;

    int sec, h, m, s, f;
    char str[12];

    sec = frames / FRAMERATE;

    // Split into hours, minutes, seconds, frames
    h = sec / 3600; 
    m = (sec - (3600 * h)) / 60;
    s = (sec - (3600 * h) - (m * 60));
    f = frames % 60;

    sprintf(str, "%02d:%02d:%02d:%02d", h, m, s, f);
    display_text(str, 230, 230, 2, 0);
}

void display_timer_level()
{
    // Do not display timer if we're on the worldmap. The reason for 
    // this is because drawing text on the worldmap too early on causes 
    // the sprite clipping for the medallions not to work. Not sure why.
    if (!dans_la_map_monde)
        display_timer();
}

void set_timer_mode()
{
    if (input_cooldown == 0)
    {
        if (TOUCHE(INPUT_L2))
        {
            input_cooldown = DEFAULT_COOLDOWN;

            if (timer_mode > 0)
            {
                PlaySnd_old(SOUND_NAVIGATE);
                timer_mode--;
            }
        }
        else if (TOUCHE(INPUT_R2))
        {
            input_cooldown = DEFAULT_COOLDOWN;
            
            if (timer_mode < (NUM_TIMER_MODES - 1))
            {
                PlaySnd_old(SOUND_NAVIGATE);
                timer_mode++;
            }
        }
    }

    if (input_cooldown > 0)
        input_cooldown--;

    char text[22] = "l2 | r2 timer: ";

    switch (timer_mode)
    {
        default:
        case TIMER_OFF:
            strcat((char *)&text, "off");
            break;

        case TIMER_GAME:
            strcat((char *)&text, "game");
            break;

        case TIMER_LEVEL:
            strcat((char *)&text, "level");
            break;

        case TIMER_WORLD:
            strcat((char *)&text, "world");
            break;

        case TIMER_DEATH:
            strcat((char *)&text, "death");
            break;
    }

    display_text((char *)&text, 80, 180, 2, 15);
}

void start_game()
{
    frames = 0;
    entered_level = 0;
    is_running = timer_mode == TIMER_GAME;

    // Call function we overwrote
    DO_FADE_OUT();
}

void enter_level()
{    
    if (timer_mode == TIMER_LEVEL || timer_mode == TIMER_DEATH)
    {
        frames = 0;
        is_running = 1;
    }
    else if (timer_mode == TIMER_WORLD && !entered_level)
    {
        frames = 0;
        is_running = 1;
        entered_level = 1;
    }
}

void init_dead()
{
    if (timer_mode == TIMER_DEATH)
        frames = 0;
}

void change_dark_phase()
{
    if (dark_phase == 5 && timer_mode == TIMER_GAME)
        is_running = 0;
}

void exit_level()
{
    if (!new_world)
        return;

    if (timer_mode == TIMER_LEVEL)
    {
        is_running = 0;
    }
    else if (timer_mode == TIMER_WORLD)
    {
        if (world_index == 3 || world_index == 5 || world_index == 7 || world_index == 10 || world_index == 13 || world_index == 16 || world_index == 17)
        {
            is_running = 0;
        }
    }
}
