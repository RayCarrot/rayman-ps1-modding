#ifndef DISPLAY_H
#define DISPLAY_H

#include <export.h>

void draw_scaled_sprite(Sprite *sprite, short x, short y, short scaledWidth, short scaledHeight);
void draw_displaced_sprite(Sprite *sprite, short x, short y, 
    short x0, short y0, 
    short x1, short y1, 
    short x2, short y2, 
    short x3, short y3);
void draw_forward_slash(short x, short y, uint color);
    
#endif
