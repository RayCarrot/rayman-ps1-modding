#ifndef RANDOM_SCREEN_H
#define RANDOM_SCREEN_H

#include <export.h>

#include <shuffle.h>
#include <ui.h>
#include <new_game.h>

#define NUM_LEVELS 24

extern short num_level_choice;
extern char world_index;
extern short num_world;
extern short num_level;
extern short new_world;
extern short new_level;
extern WorldInfo t_world_info[NUM_LEVELS];
extern char ModeDemo;
extern short SauveRayEvts;

extern SaxData Sax;
extern char finBosslevel[2];

void srand(unsigned int);

struct Magician{
    char world;
    char screen;
    char directs_to;
};

void rs_options();
void rs_new_game_start();
unsigned int digits_uint();
void shuffle_screens();
void print_codes(char *codes, char sub);
void starting_level();
char find_magician();
void rs_fix_numlevel(Obj *obj);
void rs_magician_su_heli();

#endif