#include <distance_counter.h>

// TODO: Optimize code length by not overwriting function calls. Instead of using jal 
//       we should use j to jump out at the end of a function and thus extending it

// The total distance. We store this in status_bar as 4 bytes (using lives_digits and hp_sprites)
// upon saving to memory card. These values are runtime only, so their initial values don't matter.
uint distance = 0;

const int PRECISION = 100;

void dist_new_game_start()
{
    // Reset distance to 0 on new game
    distance = 0;
}

void dist_update(char done)
{
    if(!done)
    {
        // ray_mode 3 or 4 means rayman is dying (4 for dying on bzzit)
        // loop_time is non-zero in the magician bonus game end screen
        if (!in_pause && !gele && ray_mode!=3 && ray_mode!=4 && loop_time==0) {
            int distSq = (ray.speed_x * PRECISION * ray.speed_x * PRECISION) + (ray.speed_y * PRECISION * ray.speed_y * PRECISION);
            distance += SquareRoot0(distSq);
        }
    }
}

void dist_display(char done)
{
    char str[16];

    sprintf(str, "%d.%02dpx", (distance/PRECISION), (distance%PRECISION));
    int textWidth = PS1_CalcTextWidth(str, 2);

    display_text(str, 320 - textWidth, 219, 2, !done ? 0 : 224);
}