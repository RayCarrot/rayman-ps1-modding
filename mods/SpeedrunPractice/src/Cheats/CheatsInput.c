#include <export.h>

extern bool in_pause;
extern bool PS1_Ingame;
extern byte dead_time;
extern short ray_mode;
extern SaveState save1;
extern Obj ray;
extern Obj *mapobj;
extern LevelData level;
extern short new_world;
extern short poing_obj_id;
extern Poing poing;
extern StatusBar status_bar;

void cheats_input()
{
    // Re-implement pause toggle
    if (PS1_Ingame && PS1_TOUCHE_0x9())
    {
        if (in_pause) 
        {
            in_pause = 0;
            PS1_OnPauseOff();
        }
        else 
        {
            in_pause = 1;
            PS1_OnPauseOn();
        }
    }

    // Paused
    if (in_pause)
    {
        // Create checkpoint
        if (PS1_SingleTOUCHE(INPUT_SELECT))
        {
            restore_gendoor_link();
            saveGameState((Obj *)0x0, &save1);
            correct_gendoor_link();
            PlaySnd_old(0x28);
        }

        // Finish map
        if (PS1_SingleTOUCHE(INPUT_R1))
        {
            ChangeLevel();
            in_pause = 0;
            PS1_OnPauseOff();
        }

        // Exit to worldmap
        if (PS1_SingleTOUCHE(INPUT_L1))
        {
            new_world = 1;
            in_pause = 0;
            PS1_OnPauseOff();
        }

        // Die
        if (PS1_SingleTOUCHE(INPUT_TRIANGLE) && (ray.flags & (OBJ_ALIVE | OBJ_ACTIVE)) == (OBJ_ALIVE | OBJ_ACTIVE))
        {
            ray.hit_points = 0;
            RAY_HIT(1, (Obj *)0x00);
            in_pause = 0;
            PS1_OnPauseOff();
        }

        // Full health
        if (PS1_SingleTOUCHE(INPUT_CIRCLE))
        {
            ray.hit_points = 4;
            status_bar.max_hp = 4;
            PlaySnd(0xc, -1);
            in_pause = 0;
            PS1_OnPauseOff();
        }
    }
    // Not paused
    else
    {
        // No-clip
        if (PS1_SingleTOUCHE(INPUT_SELECT))
        {
            ray.main_etat = 2;
            ray.sub_etat = 2;
            dead_time = 0x40;
            ray.field20_0x36 = -1;
            ray_mode = -ray_mode;
        }

        // Fist speed
        if (PS1_SingleTOUCHE(INPUT_TRIANGLE))
        {
            byte initSubEtat = level.objects[poing_obj_id].init_sub_etat;

            if (initSubEtat == 1)
                initSubEtat = 3;
            else if (initSubEtat == 3)
                initSubEtat = 5;
            else if (initSubEtat == 5)
                initSubEtat = 1;
            else if (initSubEtat == 8)
                initSubEtat = 10;
            else if (initSubEtat == 10)
                initSubEtat = 12;
            else if (initSubEtat == 12)
                initSubEtat = 8;
            
            level.objects[poing_obj_id].init_sub_etat = initSubEtat;
            level.objects[poing_obj_id].sub_etat = initSubEtat;
            poing.sub_etat = initSubEtat;

            PlaySnd_old(0x44);
        }
    }
}
