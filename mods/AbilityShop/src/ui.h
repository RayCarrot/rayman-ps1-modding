#ifndef UI_H
#define UI_H

#include <export.h>

#include <collection.h>
#include <fist_info.h>
#include <distance_counter.h>
#include <timer.h>

extern short RayEvts;
extern short new_world;
extern struct Obj *mapobj;
extern char in_pause;
extern char PS1_Ingame;
extern SaveState save2;

extern int credits_spent;

int coll_left(int coll);
int ui_credits(int coll);

struct Menu{
    const int x;
    const int y;
    int selected_item;
    char cooldown;
    const char def_cooldown;
};
extern const char def_f_size;

struct MenuItem{
    char text[12];
    char (*get)(struct MenuItem *);
    void (*set)(struct MenuItem *);
    char re_pos;
    int credits_req;
    char qty;
    char qty_start;
};
extern struct MenuItem menu_items[6];

extern char full_fist_bought;
char get_fist(struct MenuItem *item);
void set_fist(struct MenuItem *item);
char get_re(struct MenuItem *item);
void set_re(struct MenuItem *item);
void set_item(struct MenuItem *item, char is_fist);
void ui_off();
void ui_no_pause_text();

int full_fist_enforce(short param_1,short x,short y,short w,short h,Obj *obj);

void ui_update();
void ui_input();
void ui_display();
void ui_debug();

#endif