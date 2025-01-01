#include <export.h>

// Enums
enum TIMERMODE { TIMER_OFF, TIMER_GAME, TIMER_WORLD, TIMER_LEVEL, TIMER_DEATH };
enum TIMERDISPLAYMODE { TIMERDISP_ALWAYS, TIMERDISP_ACTION, TIMERDISP_ACTION_AND_CROSS };

// Constants
#define NUM_TIMER_MODES 5
#define NUM_TIMER_DISPLAY_MODES 3
#define TIMER_DISPLAY_TIME 60
#define SOUND_NAVIGATE 0x44

#if BUILD == 1 // pal-e
#define FRAMERATE 50
#else
#define FRAMERATE 60
#endif

// External variables
extern byte dark_phase;
extern byte world_index;
extern short new_world;
extern short position;
extern Obj *PS1_BossObj;

// Variables
uint frames = 0;
uint display_frames = 0;
enum TIMERMODE timer_mode = TIMER_OFF;
enum TIMERDISPLAYMODE timer_display_mode = TIMERDISP_ALWAYS;
bool is_running = 0;
bool entered_level = 0;
int timer_display_countdown;
byte prevBossHitPoints;

void timer_action()
{
    timer_display_countdown = TIMER_DISPLAY_TIME;
    display_frames = frames;
}

void hook_checkpoint()
{
    timer_action();
    restore_gendoor_link();
}

void hook_DO_NOVA(Obj *obj)
{
    timer_action();
    DO_NOVA(obj);
}

void update_timer()
{
    if (is_running)
        frames++;

    if (timer_display_countdown > 0)
        timer_display_countdown--;

    if (timer_display_mode == TIMERDISP_ACTION_AND_CROSS && PS1_SingleTOUCHE(INPUT_CROSS))
        timer_action();

    if (timer_display_mode != TIMERDISP_ALWAYS && PS1_BossObj != (Obj *)0x00)
    {
        if (PS1_BossObj->hit_points < PS1_BossObj->init_hit_points && PS1_BossObj->hit_points != prevBossHitPoints)
            timer_action();
        
        prevBossHitPoints = PS1_BossObj->hit_points;
    }
}

void stop_level_music()
{
    bool wasRunning = is_running;
    is_running = 0;

    // We don't want to count the timer during this
    PS1_StopLevelMusic();
    
    is_running = wasRunning;
}

void display_game_vignet()
{
    bool wasRunning = is_running;
    is_running = 0;

    // We don't want to count the timer during this
    DISPLAY_GAME_VIGNET();

    is_running = wasRunning;
}

void display_timer()
{
    if (timer_mode == TIMER_OFF)
        return;

    if (timer_display_mode != TIMERDISP_ALWAYS && timer_display_countdown == 0)
        return;

    int sec, h, m, s, f;
    char str[12];
    uint value = timer_display_mode == TIMERDISP_ALWAYS ? frames : display_frames;

    sec = value / FRAMERATE;

    // Split into hours, minutes, seconds, frames
    h = sec / 3600; 
    m = (sec - (3600 * h)) / 60;
    s = (sec - (3600 * h) - (m * 60));
    f = value % 60;

    sprintf(str, "%02d:%02d:%02d:%02d", h, m, s, f);
    display_text(str, 230, 230, 2, 0);
}

bool display_timer_bonus(int world, int level)
{
    display_timer();

    // Call and return function we overwrote
    return get_bonus_map_complete(world, level);
}

void display_timer_level(short leftTime)
{
    display_timer();

    // Call function we overwrote
    display_time(leftTime);
}

void display_timer_credits()
{
    display_timer();

    // Call function we overwrote
    DISPLAY_TXT_CREDITS();
}

void set_timer_mode()
{
    if (PS1_SingleTOUCHE(INPUT_L2))
    {
        if (timer_mode > 0)
        {
            PlaySnd_old(SOUND_NAVIGATE);
            timer_mode--;
        }
    }
    else if (PS1_SingleTOUCHE(INPUT_R2))
    {
        if (timer_mode < (NUM_TIMER_MODES - 1))
        {
            PlaySnd_old(SOUND_NAVIGATE);
            timer_mode++;
        }
    }
    else if (PS1_SingleTOUCHE(INPUT_L1))
    {
        if (timer_display_mode > 0)
        {
            PlaySnd_old(SOUND_NAVIGATE);
            timer_display_mode--;
        }
    }
    else if (PS1_SingleTOUCHE(INPUT_R1))
    {
        if (timer_display_mode < (NUM_TIMER_DISPLAY_MODES - 1))
        {
            PlaySnd_old(SOUND_NAVIGATE);
            timer_display_mode++;
        }
    }

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

    display_text((char *)&text, 90, 180, 2, 15);

    // Only show when selecting the start option as to not overlap text
    if (position == 7)
    {
        char text2[40] = "l1 | r1 timer display: ";

        switch (timer_display_mode)
        {
            default:
            case TIMERDISP_ALWAYS:
                strcat((char *)&text2, "always");
                break;

            case TIMERDISP_ACTION:
                strcat((char *)&text2, "action");
                break;

            case TIMERDISP_ACTION_AND_CROSS:
                strcat((char *)&text2, "action and cross");
                break;
        }

        int width = PS1_CalcTextWidth((char *)&text2, 2);
        display_text((char *)&text2, 360 / 2 - width / 2, 195, 2, 15);
    }
}

void start_game()
{
    // Call function we overwrote
    PS1_DoGameOptions();

    frames = 0;
    entered_level = 0;
    is_running = timer_mode == TIMER_GAME;
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
    if (dark_phase == 5)
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
