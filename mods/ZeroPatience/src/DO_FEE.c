#include "globals.h"

void DO_FEE(Obj *obj)
{
    byte old_txt;
    Obj *png_or_fee;
    byte ray_main_etat;
    byte unk_1;
    byte flag_set;
    short y;

    old_txt = display_txt_fee;
    png_or_fee = &level.objects[png_or_fee_id];
    switch (obj->sub_etat)
    {
    case 0:
        if (obj->detect_zone_flag != 0)
        {
            if (__builtin_abs(ray.x_pos + ray.offset_bx - obj->x_pos + 2) < 3)
            {
                ray_main_etat = ray.main_etat;
                unk_1 = 21;
                if(
                    ray_main_etat < 2 ||
                    (ray.main_etat == 3 && (ray.sub_etat == 20 || ray.sub_etat == unk_1))
                )
                {
                    // changed these sub_etats from vanilla
                    set_sub_etat(obj, 4);
                    skipToLabel(obj, 0, 1);
                    set_main_and_sub_etat(&ray, 3, 36);
                    remoteRayXToReach = -32000;
                    ray.flags |= OBJ_FLIP_X;
                }
            }
        }
        else
            ray_in_fee_zone = false;
        obj->field56_0x69 = 0;
        break;
    case 1:
        if (display_txt_fee == 0xFF)
        {
            obj->field56_0x69 = 1;
            display_txt_fee = 0;
            obj->timer = 0;
        }
        break;
    case 2:
    case 3:
        ray_main_etat = ray.main_etat;
        if(ray_main_etat < 2 || (ray.main_etat == 3 && ray.sub_etat == 34))
            set_main_and_sub_etat(&ray, 3, 35);
        if (ray.main_etat == 3 && ray.sub_etat == 36)
            ray.anim_frame = -1;
        break;
    case 4:
        flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
        if (
            ((flag_set && obj->anim_frame == 0) ||
            (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
            horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
        )
        {
            fee_gives_super_evts();
            obj->field56_0x69 = 2;
            display_txt_fee = 5;
            obj->timer = 0;
        }
        else
            obj->field56_0x69 = 0;
        break;
    case 6:
        if (ray.main_etat == 3)
        {
            if (ray.sub_etat == 36)
                set_sub_etat(&ray, 37);
            if (ray.main_etat == 3 && ray.sub_etat == 20)
            {
                remoteRayXToReach = ray.x_pos;
                if(obj->field56_0x69 == 4)
                {
                    set_main_and_sub_etat(&ray, 0, 0);
                    remoteRayXToReach = -32000;
                }
            }
        }
        break;
    }
    DO_FEE_ETAPE(obj);
    if (display_txt_fee != old_txt)
    {
        new_txt_fee = 1;
        if (display_txt_fee != 0xFF)
        {
            png_or_fee->active_timer = 0;
            png_or_fee->flags |= OBJ_ALIVE|OBJ_FLIP_X;
            png_or_fee->x_pos = xmap - png_or_fee->offset_bx;
            y = ymap - (png_or_fee->offset_by - 220);
            png_or_fee->y_pos = y;
            png_or_fee->screen_x_pos = -png_or_fee->offset_bx;
            png_or_fee->screen_y_pos = 220 - png_or_fee->offset_by;
            old_txt_fee = old_txt;
            png_or_fee->init_x_pos = png_or_fee->x_pos;
            png_or_fee->init_y_pos = png_or_fee->y_pos;
        }
    }
    if (new_txt_fee != 0)
    {
        if (text_to_display[old_txt_fee].y_pos < 260)
            text_to_display[old_txt_fee].y_pos++;
        else
            new_txt_fee = 0;
    }
    if (png_or_fee->flags & OBJ_ALIVE)
    {
        png_or_fee->x_pos += 4;
        png_or_fee->screen_x_pos += 4;
        if (png_or_fee->screen_x_pos > 310)
        {
            png_or_fee->anim_frame = 0;
            png_or_fee->flags &= ~OBJ_ALIVE;
            png_or_fee->flags &= ~OBJ_ACTIVE;
        }
    }
}