#include <export.h>
#include "timer.h"

// Variables
TimerInfo timer_info;

void timer_action()
{
    timer_info.timer_display_countdown = TIMER_DISPLAY_TIME;
    timer_info.display_frames = timer_info.frames;
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
    if (timer_info.is_running)
        timer_info.frames++;

    if (timer_info.timer_display_countdown > 0)
        timer_info.timer_display_countdown--;

    if (timer_info.timer_display_mode == TIMERDISP_ACTION_AND_CROSS && PS1_SingleTOUCHE(INPUT_CROSS))
        timer_action();

    if (timer_info.timer_display_mode != TIMERDISP_ALWAYS && PS1_BossObj != (Obj *)0x00)
    {
        if (PS1_BossObj->hit_points < PS1_BossObj->init_hit_points && PS1_BossObj->hit_points != timer_info.prevBossHitPoints)
            timer_action();
        
        timer_info.prevBossHitPoints = PS1_BossObj->hit_points;
    }
}

void stop_level_music()
{
    bool wasRunning = timer_info.is_running;
    timer_info.is_running = 0;

    // We don't want to count the timer during this
    PS1_StopLevelMusic();
    
    timer_info.is_running = wasRunning;
}

void display_game_vignet()
{
    bool wasRunning = timer_info.is_running;
    timer_info.is_running = 0;

    // We don't want to count the timer during this
    DISPLAY_GAME_VIGNET();

    timer_info.is_running = wasRunning;
}

void display_timer()
{
    if (timer_info.timer_mode == TIMER_OFF)
        return;

    if (timer_info.timer_display_mode != TIMERDISP_ALWAYS && timer_info.timer_display_countdown == 0)
        return;

    int sec, h, m, s, f;
    char str[12];
    uint value = timer_info.timer_display_mode == TIMERDISP_ALWAYS ? timer_info.frames : timer_info.display_frames;

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

void start_game()
{
    // Call function we overwrote
    PS1_DoGameOptions();

    timer_info.frames = 0;
    timer_info.entered_level = 0;
    timer_info.is_running = timer_info.timer_mode == TIMER_GAME;
}

void enter_level()
{    
    if (timer_info.timer_mode == TIMER_LEVEL || timer_info.timer_mode == TIMER_DEATH)
    {
        timer_info.frames = 0;
        timer_info.is_running = 1;
    }
    else if (timer_info.timer_mode == TIMER_WORLD && !timer_info.entered_level)
    {
        timer_info.frames = 0;
        timer_info.is_running = 1;
        timer_info.entered_level = 1;
    }
}

void init_dead()
{
    if (timer_info.timer_mode == TIMER_DEATH)
        timer_info.frames = 0;
}

void change_dark_phase()
{
    if (dark_phase == 5)
        timer_info.is_running = 0;
}

void exit_level()
{
    if (!new_world)
        return;

    if (timer_info.timer_mode == TIMER_LEVEL)
    {
        timer_info.is_running = 0;
    }
    else if (timer_info.timer_mode == TIMER_WORLD)
    {
        if (world_index == 3 || world_index == 5 || world_index == 7 || world_index == 10 || world_index == 13 || world_index == 16 || world_index == 17)
        {
            timer_info.is_running = 0;
        }
    }
}
