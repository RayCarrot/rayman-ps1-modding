#include <export.h>

extern Obj ray;

bool is_speed_display_visible;

void display_speed_value(char *text, int value1, int value2, short x, short y)
{
    char str[16];
    int txtWidth;

    // Absolute values
    if (value1 < 0)
        value1 = -value1;
    if (value2 < 0)
        value2 = -value2;

    txtWidth = PS1_CalcTextWidth(text, 2);
    display_text(text, x, y, 2, 1);

    sprintf((char *)&str, "%d %d", value1, value2);
    
    display_text((char *)&str, x + txtWidth + 6, y, 2, 2);
}

void display_speed()
{
    if (PS1_SpecialTOUCHE(INPUT_SELECT))
    {
        is_speed_display_visible = !is_speed_display_visible;
    }

    if (is_speed_display_visible)
    {
        display_speed_value("air", ray.eta[2][0].speed_x_left, ray.eta[2][0].speed_x_right, 85, 28);
        display_speed_value("roll", ray.eta[2][0x11].speed_x_left, ray.eta[2][0x11].speed_x_right, 165, 28);
    }
}
