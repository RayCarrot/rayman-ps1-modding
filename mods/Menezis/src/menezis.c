#include <export.h>
#include "menezis.h"

Actor actors[20];
byte shot_cooldown = 0;

void DO_MENEZIS()
{
    INIT_FADE_IN();

    INIT_MENEZIS();

    SYNCHRO_LOOP(splash_screen_loop);
    SYNCHRO_LOOP(menezis_loop);

    DO_FADE_OUT();
}

void INIT_MENEZIS()
{
    // Reset actors
    for (byte i = 0; i < sizeof(actors) / sizeof(Actor); i++)
    {
        actors[i].x_pos = 0;
        actors[i].y_pos = 0;
        actors[i].speed_x = 0;
        actors[i].speed_y = 0;
        actors[i].text[0] = 0;
        actors[i].color = 0;
        actors[i].type = -1;
        actors[i].active = 0;
    }

    byte actorIndex = 0;
    
    // Player
    actors[actorIndex].type = ACTOR_PLAYER;
    actors[actorIndex].x_pos = PLAYER_START_X;
    actors[actorIndex].y_pos = PLAYER_START_Y;
    actors[actorIndex].text[0] = PLAYER_TEXT;
    actors[actorIndex].color = PLAYER_COLOR;
    actors[actorIndex].active = 1;
    actorIndex++;

    // Shots
    for (byte i = 0; i < SHOT_MAX; i++)
    {
        actors[actorIndex].type = ACTOR_SHOT;
        actors[actorIndex].text[0] = SHOT_TEXT;
        actors[actorIndex].color = SHOT_COLOR;
        actorIndex++;
    }

    // Enemies
    for (byte i = actorIndex; i < sizeof(actors) / sizeof(Actor); i++)
    {
        actors[actorIndex].type = ACTOR_ENEMY_BASIC;
        actors[actorIndex].x_pos = myRand(SCREEN_WIDTH);
        actors[actorIndex].y_pos = myRand(SCREEN_HEIGHT);
        actors[actorIndex].speed_x = myRand(1) ? 1 : -1;
        actors[actorIndex].speed_y = myRand(1) ? 1 : -1;
        actors[actorIndex].text[0] = ENEMY_BASIC_TEXT;
        actors[actorIndex].color = ENEMY_BASIC_COLOR;
        actors[actorIndex].active = 1;
        actorIndex++;
    }
}

bool splash_screen_loop()
{
    CLRSCR();
    
    short textY = 40;

    display_text("/welcome to/", 0xA0, textY, 2, 2);
    textY += 28;
    display_text("/menezis/", 0xA0, textY, 1, 12);
    textY += 20;
    display_text("/the full text mini shoot'em up/", 0xA0, textY, 2, 2);
    textY += 40;

    display_text("use d-pad to move", 60, textY, 2, 5);
    textY += 20;
    display_text("use * to protect", 60, textY, 2, 5);
    textY += 20;
    display_text("use ~ to shoot", 60, textY, 2, 5);
    textY += 40;

    display_text("/press * or ~ to play/", 0xA0, textY, 2, 0xe0);

    readinput();

    return TOUCHE(INPUT_CROSS) || TOUCHE(INPUT_SQUARE);
}

bool menezis_loop()
{
    CLRSCR();

    for (byte i = 0; i < sizeof(actors) / sizeof(Actor); i++)
    {
        DO_ACTOR(&actors[i]);
    }
    
    for (byte i = 0; i < sizeof(actors) / sizeof(Actor); i++)
    {
        DISPLAY_ACTOR(&actors[i]);
    }

    readinput();

    return 0;
}

void DO_ACTOR(Actor *actor)
{
    if (!actor->active)
        return;
    
    switch (actor->type)
    {
        case ACTOR_PLAYER:
            if (actor->x_pos < SCREEN_WIDTH && TOUCHE(INPUT_RIGHT))
                actor->speed_x = PLAYER_SPEED;
            else if (actor->x_pos >= 0 && TOUCHE(INPUT_LEFT))
                actor->speed_x = -PLAYER_SPEED;
            else
                actor->speed_x = 0;

            if (actor->y_pos < SCREEN_HEIGHT && TOUCHE(INPUT_DOWN))
                actor->speed_y = PLAYER_SPEED;
            else if (actor->y_pos >= 0 && TOUCHE(INPUT_UP))
                actor->speed_y = -PLAYER_SPEED;
            else
                actor->speed_y = 0;

            if (shot_cooldown > 0)
                shot_cooldown--;
            
            if (TOUCHE(INPUT_SQUARE) && shot_cooldown == 0)
            {
                for (byte i = 0; i < sizeof(actors) / sizeof(Actor); i++)
                {
                    if (actors[i].type == ACTOR_SHOT && !actors[i].active)
                    {
                        actors[i].x_pos = actor->x_pos;
                        actors[i].y_pos = actor->y_pos;
                        actors[i].speed_x = SHOT_SPEED;
                        actors[i].active = 1;
                        shot_cooldown = SHOT_COOLDOWN;
                        break;
                    }
                }
            }
            break;

        case ACTOR_SHOT:
            if (actor->x_pos >= SCREEN_WIDTH)
                actor->active = 0;
            break;
        
        case ACTOR_ENEMY_BASIC:
            if (actor->x_pos >= SCREEN_WIDTH || actor->x_pos < 0)
                actor->speed_x = -actor->speed_x;
            if (actor->y_pos > SCREEN_HEIGHT || actor->y_pos < 0)
                actor->speed_y = -actor->speed_y;
            break;
        
        default:
            break;
    }

    actor->x_pos += actor->speed_x;
    actor->y_pos += actor->speed_y;
}

void DISPLAY_ACTOR(Actor *actor)
{
    if (!actor->active)
        return;

    display_text(actor->text, actor->x_pos, actor->y_pos, ACTOR_FONT, actor->color);
}
