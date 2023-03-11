#define PLAYER_START_X 100
#define PLAYER_START_Y 100
#define PLAYER_SPEED 2
#define PLAYER_TEXT 'e'
#define PLAYER_COLOR 12

#define SHOT_MAX 5
#define SHOT_COOLDOWN 20
#define SHOT_IFRAMES 8
#define SHOT_SPEED 3
#define SHOT_TEXT '.'
#define SHOT_COLOR 12

#define ENEMY_BASIC_IFRAMES 60
#define ENEMY_BASIC_TEXT 'x'
#define ENEMY_BASIC_COLOR 1

#define ACTOR_FONT 1
#define ACTOR_IFRAMES_COLOR 12

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

extern Font alpha2;

typedef enum
{
    ACTOR_PLAYER = 0,
    ACTOR_SHOT = 1,
    ACTOR_ENEMY_BASIC = 2,
} ActorType;

typedef struct 
{
    short x_pos;
    short y_pos;
    short speed_x;
    short speed_y;
    char text[2];
    byte color;
    ActorType type;
    bool active;
    byte iframes;
    byte hit_points;
} Actor;

void DO_MENEZIS();
void INIT_MENEZIS();
bool splash_screen_loop();
bool menezis_loop();
void DO_ACTOR(Actor *actor);
void DISPLAY_ACTOR(Actor *actor);
void getLetterPos(char letter, short letterX, short letterY, short *x, short *y, short *w, short *h);
