#include <export.h>

// TODO: Optimize code length by not overwriting function calls. Instead of using jal 
//       we should use j to jump out at the end of a function and thus extending it

#define SAVE_TAG 0xAA

extern struct StatusBar status_bar;
extern struct Obj ray;
extern char PS1_IsPaused;
extern bool gele;
extern bool dans_la_map_monde;
extern short ray_mode;
extern short loop_time;

// The total distance. We store this in status_bar as 4 bytes (using lives_digits and hp_sprites)
// upon saving to memory card. These values are runtime only, so their initial values don't matter.
uint distance = 0;

const int PRECISION = 100;

void draw_meter_text();


void INIT_NEW_GAME_Extended()
{
    // Call function we overwrote call for before
    INIT_RAY_BEGIN();

    // Reset distance to 0 on new game
    distance = 0;
}

void LoadGameOnDisk_Extended()
{
    // Call function we overwrote call for before
    POINTEUR_BOUTONS_OPTIONS_BIS();

    // Load saved distance count
    if (status_bar.wiz_digits[0] == SAVE_TAG) // Use this value to allow loading a save from before this patch - it will normally have a range of 0-9
    {
        distance = status_bar.lives_digits[0] | (status_bar.lives_digits[1] << 8) | (status_bar.hp_sprites[0] << 16) | (status_bar.hp_sprites[1] << 24);
    }
    else
    {
        // Assume player loaded from an old save, so they should have 0 distance starting now
        distance = 0;
    }
}

void SaveDistance()
{
    // Save distance count
    status_bar.lives_digits[0] = distance & 0xFF;
    status_bar.lives_digits[1] = (distance >> 8) & 0xFF;
    status_bar.hp_sprites[0] = (distance >> 16) & 0xFF;
    status_bar.hp_sprites[1] = (distance >> 24) & 0xFF;

    // Save tag to indicate we saved using this patch
    status_bar.wiz_digits[0] = SAVE_TAG;
}

void display_meter_level()
{
    if (!dans_la_map_monde) {
        draw_meter_text();
    }
}

void update_distance() {

    // ray_mode 3 or 4 means rayman is dying (4 for dying on bzzit)
    // loop_time is non-zero in the magician bonus game end screen
    if (!PS1_IsPaused && !gele && ray_mode!=3 && ray_mode!=4 && loop_time==0) {
        int distSq = (ray.speed_x * PRECISION * ray.speed_x * PRECISION) + (ray.speed_y * PRECISION * ray.speed_y * PRECISION);
        distance += SquareRoot0(distSq);
    }

    // Allow resetting the tracker by pressing select while the game is paused
    if (PS1_IsPaused && TOUCHE(INPUT_SELECT)) {
        distance = 0;
    }
}

void draw_meter_text() {

    char str[16];

    sprintf(str, "%d.%02dpx", (distance/PRECISION), (distance%PRECISION));
    int textWidth = PS1_CalcTextWidth(str, 2);

    display_text(str, 320 - textWidth, 230, 2, 0);
    
    if (PS1_IsPaused) {
        
        char selectstr[23] = "press select to reset\0";
        textWidth = PS1_CalcTextWidth(selectstr, 2);
        display_text(selectstr, 320 - textWidth, 210, 2, 0);
    }
}