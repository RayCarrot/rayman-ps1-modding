#include <export.h>

// Enums
enum TIMERMODE { TIMER_OFF, TIMER_GAME, TIMER_LEVEL };

// Constants
#define DEFAULT_COOLDOWN 15
#define FRAMERATE 60
#define SOUND_NAVIGATE 0x44

// Variables
uint frames = 0;
enum TIMERMODE timer_mode = TIMER_OFF;
byte input_cooldown = 0;
bool isInLevel = 0; // TODO: Use dans_la_map_monde instead? Is that consistent enough?

// Function prototypes
void display_timer();

void update_timer()
{
    frames++;
}

void display_timer()
{
    int sec, h, m, s, f;
    char str[12];

    sec = frames / FRAMERATE;

    // Split into hours, minutes, seconds, frames
    h = sec / 3600; 
    m = (sec - (3600 * h)) / 60;
    s = (sec - (3600 * h) - (m * 60));
    f = frames % 60;

    sprintf(str, "%02d:%02d:%02d:%02d", h, m, s, f);
    display_text(str, 10, 230, 2, 0);
}

void display_timer_level()
{
    // Do not display timer in a level if the mod is off or we're on
    // the worldmap. The reason for this is because drawing text on
    // the worldmap too early on causes the sprite clipping for the
    // medallions not to work. Not sure why.
    if (timer_mode == TIMER_OFF || !isInLevel)
        return;

    display_timer();
}

void display_timer_worldmap()
{
    if (timer_mode != TIMER_GAME)
        return;

    display_timer();
}

void set_timer_mode()
{
    char* text;

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
            
            if (timer_mode < 2)
            {
                PlaySnd_old(SOUND_NAVIGATE);
                timer_mode++;
            }
        }
    }

    if (input_cooldown > 0)
        input_cooldown--;

    switch (timer_mode)
    {
        default:
        case TIMER_OFF:
            text = "l2 | r2 timer: off";
            break;

        case TIMER_GAME:
            text = "l2 | r2 timer: game";
            break;

        case TIMER_LEVEL:
            text = "l2 | r2 timer: level";
            break;
    }

    display_text(text, 80, 180, 2, 15);
}

void start_game()
{
    frames = 0;
    isInLevel = 0;

    // Call function we overwrote
    DO_FADE_OUT();
}

void enter_level()
{
    isInLevel = 1;
    
    if (timer_mode == TIMER_LEVEL)
        frames = 0;
}

void init_world_map()
{
    isInLevel = 0;
}