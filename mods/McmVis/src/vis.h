#ifndef VIS_H
#define VIS_H

#include "export.h"
#include "globals.h"

typedef enum
{
    Read,
    Write
} VisType;
extern VisType vis_type;

typedef struct
{
    char name[20];
    bool done;
} SaveFrame;

extern int vis_fd;
extern char *vis_buf;
extern int vis_n;

extern bool vis_interr;

bool vis();
bool vis_continue();
void vis_draw();
void vis_draw_frames();
void vis_reset();
void vis_affiche_ecran_save();

#endif