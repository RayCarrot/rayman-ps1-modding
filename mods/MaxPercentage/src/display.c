#include <export.h>
#include "display.h"
#include "globals.h"

void draw_scaled_sprite(Sprite *sprite, short x, short y, short scaledWidth, short scaledHeight)
{
    draw_displaced_sprite(sprite, x, y, 
        0, 0,
        scaledWidth, 0,
        0, scaledHeight,
        scaledWidth, scaledHeight);
}

void draw_displaced_sprite(Sprite *sprite, short x, short y, 
    short x0, short y0, 
    short x1, short y1, 
    short x2, short y2, 
    short x3, short y3)
{
    POLY_FT4 *iVar1;
    int polyIndex;
    u_char pageXEnd;
    u_char pageYEnd;
    POLY_FT4 *p;
    byte height;
    byte pageX;
    byte pageY;
    byte width;
  
    polyIndex = (int)PS1_PolygonsCount;

    if (polyIndex < 200) 
    {
        PS1_PolygonsCount = PS1_PolygonsCount + 1;
        p = PS1_CurrentDisplay->polygons + polyIndex;
    }
    else 
    {
        if (PS1_CurrentDisplay == &PS1_Displays[0]) 
        {
            iVar1 = (POLY_FT4 *)0x800d772c;
        }
        else 
        {
            iVar1 = (POLY_FT4 *)0x800e3f2c;
        }

        p = iVar1 + polyIndex;
        SetPolyFT4(p);
        PS1_PolygonsCount = PS1_PolygonsCount + 1;
    }

    if (sprite->id == 0) 
        return;

    pageX = sprite->page_x;
    pageY = sprite->page_y;
    
    width = sprite->width;
    height = sprite->height;
    
    pageXEnd = pageX + width;
    pageYEnd = pageY + height;

    p->clut = sprite->clut;
    p->tpage = sprite->tpage;

    p->u0 = pageX;
    p->$2 = pageY;
    p->u1 = pageXEnd;
    p->$3 = pageY;
    p->u2 = pageX;
    p->v2 = pageYEnd;
    p->u3 = pageXEnd;
    p->v3 = pageYEnd;

    p->x0 = x + x0;
    p->y0 = y + y0;
    p->x1 = x + x1;
    p->y1 = y + y1;
    p->x2 = x + x2;
    p->y2 = y + y2;
    p->x3 = x + x3;
    p->y3 = y + y3;

    SetShadeTex(p,1);
    SetSemiTrans(p,0);
    AddPrim(PS1_PrevPrim,p);
    PS1_PrevPrim = p;
}

void draw_forward_slash(short x, short y, uint color)
{
    Sprite *sprite;

    sprite = &alpha.sprites[46];
    sprite->clut = GetClut(0x300 + color * 0x10, 0x1ec);

    draw_displaced_sprite(sprite, x, y - sprite->height, 
        8, 0,
        16, 0,
        0, 16,
        8, 16);
}

void draw_colored_sprite(Sprite *sprite, short x, short y, bool flipX, byte r, byte g, byte b)
{
    POLY_FT4 *iVar1;
    int polyIndex;
    u_char pageXEnd;
    u_char pageYEnd;
    POLY_FT4 *p;
    byte height;
    byte pageX;
    byte pageY;
    byte width;
  
    polyIndex = (int)PS1_PolygonsCount;

    if (polyIndex < 200) 
    {
        PS1_PolygonsCount = PS1_PolygonsCount + 1;
        p = PS1_CurrentDisplay->polygons + polyIndex;
    }
    else 
    {
        if (PS1_CurrentDisplay == &PS1_Displays[0]) 
        {
            iVar1 = (POLY_FT4 *)0x800d772c;
        }
        else 
        {
            iVar1 = (POLY_FT4 *)0x800e3f2c;
        }

        p = iVar1 + polyIndex;
        SetPolyFT4(p);
        PS1_PolygonsCount = PS1_PolygonsCount + 1;
    }

    if (sprite->id == 0) 
        return;

    pageX = sprite->page_x;
    pageY = sprite->page_y;
    
    width = sprite->width;
    height = sprite->height;
    
    pageXEnd = pageX + width;
    pageYEnd = pageY + height;

    p->clut = sprite->clut;
    p->tpage = sprite->tpage;

    if (!flipX)
    {
        p->u0 = pageX;
        p->$2 = pageY;
        p->u1 = pageXEnd;
        p->$3 = pageY;
        p->u2 = pageX;
        p->v2 = pageYEnd;
        p->u3 = pageXEnd;
        p->v3 = pageYEnd;
    }
    else
    {
        p->u0 = pageXEnd + 0xff;
        p->$2 = pageY;
        p->u1 = pageX - 1;
        p->$3 = pageY;
        p->u2 = pageXEnd + 0xff;
        p->v2 = pageYEnd;
        p->u3 = pageX - 1;
        p->v3 = pageYEnd;
    }

    p->x0 = x;
    p->y0 = y;
    p->x1 = x + width;
    p->y1 = y;
    p->x2 = x;
    p->y2 = y + height;
    p->x3 = x + width;
    p->y3 = y + height;

    // Set shading
    p->r0 = r;
    p->g0 = g;
    p->b0 = b;

    SetShadeTex(p,0); // Pass in 0 to have it be shaded
    SetSemiTrans(p,0);
    AddPrim(PS1_PrevPrim,p);
    PS1_PrevPrim = p;
}