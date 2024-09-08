#include <export.h>

// External variables
extern StatusBar status_bar;
extern Obj ray;

// Rewrite DO_FIXE
void NEW_DO_FIXE()
{
    // Force single hp
    if ((sbyte)ray.hit_points > 0)
        ray.hit_points = 0;

    // Rest is the same as in the original game
    status_bar.hp_sprites[0] = 0;
    status_bar.hp_sprites[1] = ray.hit_points;
    
    status_bar.lives_digits[1] = (byte)((int)status_bar.num_lives % 10);
    status_bar.lives_digits[0] = (byte)((int)status_bar.num_lives / 10);
    
    if (status_bar.num_wiz > 99)
        status_bar.num_wiz = 99;
    
    status_bar.wiz_digits[0] = status_bar.num_wiz / 10;
    status_bar.wiz_digits[1] = status_bar.num_wiz % 10;
}