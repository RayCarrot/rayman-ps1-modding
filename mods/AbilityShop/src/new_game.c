#include <new_game.h>

char new_game_started=0;

void new_game(){ new_game_started=0; }

void new_game_start()
{
    if(!new_game_started && !MENU_RETURN)
    {
        new_game_started=1;

        for (byte i=0; i<NUM_LEVELS; i++){ t_world_info[i].state = 1; }
        finBosslevel[1]=finBosslevel[1] | (1 << 3); //Helped musician
        RayEvts|=1; //Start with fist

        int menu_size=sizeof(menu_items)/sizeof(menu_items[0]);
        for(int i=0; i<menu_size; i++){ menu_items[i].qty=menu_items[i].qty_start; }
        credits_spent=0;
        full_fist_bought=0;

        dist_new_game_start();
        timer_new_game_start();
        rs_new_game_start();
    }
    DO_FADE_OUT(); // Call function we overwrote
}