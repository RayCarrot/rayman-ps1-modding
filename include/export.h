#ifndef EXPORT_H
#define EXPORT_H

typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef char    sbyte;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
#define unkbyte9   unsigned long long
#define unkbyte10   unsigned long long
#define unkbyte11   unsigned long long
#define unkbyte12   unsigned long long
#define unkbyte13   unsigned long long
#define unkbyte14   unsigned long long
#define unkbyte15   unsigned long long
#define unkbyte16   unsigned long long

#define unkuint9   unsigned long long
#define unkuint10   unsigned long long
#define unkuint11   unsigned long long
#define unkuint12   unsigned long long
#define unkuint13   unsigned long long
#define unkuint14   unsigned long long
#define unkuint15   unsigned long long
#define unkuint16   unsigned long long

#define unkint9   long long
#define unkint10   long long
#define unkint11   long long
#define unkint12   long long
#define unkint13   long long
#define unkint14   long long
#define unkint15   long long
#define unkint16   long long

#define unkfloat1   float
#define unkfloat2   float
#define unkfloat3   float
#define unkfloat5   double
#define unkfloat6   double
#define unkfloat7   double
#define unkfloat9   long double
#define unkfloat11   long double
#define unkfloat12   long double
#define unkfloat13   long double
#define unkfloat14   long double
#define unkfloat15   long double
#define unkfloat16   long double

#define BADSPACEBASE   void
#define code   void

typedef ulong u_long;

typedef ushort u_short;

typedef ulong size_t;

typedef uchar u_char;

typedef struct VECTOR VECTOR, *PVECTOR;

struct VECTOR {
    long vx;
    long vy;
    long vz;
    long pad;
};

typedef struct SVECTOR SVECTOR, *PSVECTOR;

struct SVECTOR {
    short vx;
    short vy;
    short vz;
    short pad;
};

typedef struct DVECTOR DVECTOR, *PDVECTOR;

struct DVECTOR {
    short vx;
    short vy;
};

typedef struct MATRIX MATRIX, *PMATRIX;

struct MATRIX {
    short m[3][3];
    long t[3];
};

typedef struct CVECTOR CVECTOR, *PCVECTOR;

struct CVECTOR {
    u_char r;
    u_char g;
    u_char b;
    u_char cd;
};

typedef struct SVECTOR *SVECTOR_0x4;

typedef struct ProgAtr ProgAtr, *PProgAtr;

struct ProgAtr {
    uchar tones;
    uchar mvol;
    uchar prior;
    uchar mode;
    uchar mpan;
    char reserved0;
    short attr;
    ulong reserved1;
    ulong reserved2;
};

typedef struct VagAtr VagAtr, *PVagAtr;

struct VagAtr {
    uchar prior;
    uchar mode;
    uchar vol;
    uchar pan;
    uchar center;
    uchar shift;
    uchar min;
    uchar max;
    uchar vibW;
    uchar vibT;
    uchar porW;
    uchar porT;
    uchar pbmin;
    uchar pbmax;
    uchar reserved1;
    uchar reserved2;
    ushort adsr1;
    ushort adsr2;
    short prog;
    short vag;
    short reserved[4];
};

typedef void (*SsMarkCallbackProc)(short, short, short);

typedef struct VabHdr VabHdr, *PVabHdr;

struct VabHdr {
    long form;
    long ver;
    long id;
    ulong fsize;
    ushort reserved0;
    ushort ps;
    ushort ts;
    ushort vs;
    uchar mvol;
    uchar pan;
    uchar attr1;
    uchar attr2;
    ulong reserved1;
};

typedef struct CdlLOC CdlLOC, *PCdlLOC;

struct CdlLOC {
    u_char minute;
    u_char second;
    u_char sector;
    u_char track;
};

typedef struct CdlATV CdlATV, *PCdlATV;

struct CdlATV {
    u_char val0;
    u_char val1;
    u_char val2;
    u_char val3;
};

typedef struct StHEADER StHEADER, *PStHEADER;

struct StHEADER {
    u_short id;
    u_short type;
    u_short secCount;
    u_short nSectors;
    u_long frameCount;
    u_long frameSize;
    u_short width;
    u_short height;
};

typedef struct CdlFILE CdlFILE, *PCdlFILE;

struct CdlFILE {
    struct CdlLOC pos;
    u_long size;
    char name[16];
};

typedef struct OptionsJeu OptionsJeu, *POptionsJeu;

struct OptionsJeu {
    undefined *Fire1ButtonFunc;
    undefined *Fire0ButtonFunc;
    undefined *Button4Func;
    undefined *Button3Func;
    ushort Jump;
    ushort Fist;
    ushort field6_0x14;
    ushort Action;
    ushort Music;
    ushort Soundfx;
    ushort StereoEnabled;
    short field11_0x1e;
    short field12_0x20;
    short field13_0x22;
    short field14_0x24;
};

typedef struct GrpStar GrpStar, *PGrpStar;

struct GrpStar {
    byte timer;
    byte length;
    byte dist;
    byte sprite_table_index;
};

typedef struct TextToDisplay TextToDisplay, *PTextToDisplay;

struct TextToDisplay {
    char text[48];
    short centered_x_pos;
    short centered_y_pos;
    short width;
    short height;
    short x_pos;
    short y_pos;
    byte font_size;
    bool field8_0x3d;
    bool is_fond;
    byte color;
};

typedef struct FloconTableEntry FloconTableEntry, *PFloconTableEntry;

struct FloconTableEntry {
    short field0_0x0;
    short field1_0x2;
    short field2_0x4;
    undefined field3_0x6;
    undefined field4_0x7;
};

typedef struct PixGerbeItem PixGerbeItem, *PPixGerbeItem;

struct PixGerbeItem {
    short x_pos;
    short y_pos;
    short speed_x;
    short speed_y;
    byte y_accel;
    byte field5_0x9;
};

typedef struct Record Record, *PRecord;

struct Record {
    int current_offset;
    int repeat_length;
    int repeat_index;
    int length;
    byte *data;
    bool is_recording;
    bool is_playing;
    bool is_finished;
};

typedef struct AllFixData AllFixData, *PAllFixData;

typedef struct Font Font, *PFont;

typedef struct Obj Obj, *PObj;

typedef struct Sprite Sprite, *PSprite;

typedef struct Animation Animation, *PAnimation;

typedef struct ObjState ObjState, *PObjState;

typedef struct CmdContext CmdContext, *PCmdContext;

typedef enum BlockType {
    BTYP_NONE=0,
    BTYP_CHDIR=1, // reactionary
    BTYP_SOLID_RIGHT_45=2,
    BTYP_SOLID_LEFT_45=3,
    BTYP_SOLID_RIGHT1_30=4,
    BTYP_SOLID_RIGHT2_30=5,
    BTYP_SOLID_LEFT1_30=6,
    BTYP_SOLID_LEFT2_30=7,
    BTYP_HURT=8,
    BTYP_RESSORT=9, // bounce
    BTYP_WATER=10,
    BTYP_LIANE=12, // climb
    BTYP_SOLID_PASSTHROUGH=14,
    BTYP_SOLID=15,
    BTYP_SLIPPERY_RIGHT_45=18,
    BTYP_SLIPPERY_LEFT_45=19,
    BTYP_SLIPPERY_RIGHT1_30=20,
    BTYP_SLIPPERY_RIGHT2_30=21,
    BTYP_SLIPPERY_LEFT1_30=22,
    BTYP_SLIPPERY_LEFT2_30=23,
    BTYP_SPIKES=24,
    BTYP_CLIFF=25,
    BTYP_SLIPPERY=30
} BlockType;

typedef enum ObjCommand {
    GO_LEFT=0,
    GO_RIGHT=1,
    GO_WAIT=2,
    GO_UP=3,
    GO_DOWN=4,
    GO_SUBSTATE=5,
    GO_SKIP=6,
    GO_ADD=7,
    GO_STATE=8,
    GO_PREPARELOOP=9,
    GO_DOLOOP=10,
    GO_LABEL=11,
    GO_GOTO=12,
    GO_GOSUB=13,
    GO_RETURN=14,
    GO_BRANCHTRUE=15,
    GO_BRANCHFALSE=16,
    GO_TEST=17,
    GO_SETTEST=18,
    GO_WAITSTATE=19,
    GO_SPEED=20,
    GO_X=21,
    GO_Y=22,
    RESERVED_GO_SKIP=23,
    RESERVED_GO_GOTO=24,
    RESERVED_GO_GOSUB=25,
    RESERVED_GO_GOTOT=26,
    RESERVED_GO_GOTOF=27,
    RESERVED_GO_SKIPT=28,
    RESERVED_GO_SKIPF=29,
    GO_NOP=30,
    GO_SKIPTRUE=31,
    GO_SKIPFALSE=32,
    INVALID_CMD=33
} ObjCommand;

typedef enum ChangeAnimMode {
    ANIMMODE_NONE=0,
    ANIMMODE_RESET_IF_NEW=1,
    ANIMMODE_RESET=2
} ChangeAnimMode;

typedef enum ObjType {
    TYPE_BADGUY1=0,
    TYPE_PLATFORM=1,
    TYPE_POWERUP=2,
    TYPE_LIDOLPINK=3,
    TYPE_NEUTRAL=4,
    TYPE_WIZARD1=5,
    TYPE_FALLING_YING_OUYE=6,
    TYPE_MORNINGSTAR=7,
    TYPE_FALLING_OBJ=8,
    TYPE_BADGUY2=9,
    TYPE_FISH=10,
    TYPE_BOUM=11,
    TYPE_CHASSEUR1=12,
    TYPE_BALLE1=13,
    TYPE_CHASSEUR2=14,
    TYPE_BALLE2=15,
    TYPE_FALLPLAT=16,
    TYPE_LIFTPLAT=17,
    TYPE_BTBPLAT=18,
    TYPE_SPLASH=19,
    TYPE_GENEBADGUY=20,
    TYPE_PHOTOGRAPHE=21,
    TYPE_MOVE_PLAT=22,
    TYPE_RAYMAN=23,
    TYPE_INTERACTPLT=24,
    TYPE_INST_PLAT=25,
    TYPE_CRUMBLE_PLAT=26,
    TYPE_BOING_PLAT=27,
    TYPE_ONOFF_PLAT=28,
    TYPE_AUTOJUMP_PLAT=29,
    TYPE_AUDIOSTART=30,
    TYPE_ONEUP_ALWAYS=31,
    TYPE_DARK_PHASE2=32,
    TYPE_DARK2_SORT=33,
    TYPE_MOVE_AUTOJUMP_PLAT=34,
    TYPE_STONEMAN1=35,
    TYPE_STONEBOMB=36,
    TYPE_TARZAN=37,
    TYPE_GRAINE=38,
    TYPE_NEN_GRAINE=39,
    TYPE_STONEDOG=40,
    TYPE_OUYE=41,
    TYPE_SIGNPOST=42,
    TYPE_STONEMAN2=43,
    TYPE_CLASH=44,
    TYPE_MOVE_OUYE=45,
    TYPE_BB1=46,
    TYPE_STONEBOMB2=47,
    TYPE_FLAMME2=48,
    TYPE_MOVE_START_PLAT=49,
    TYPE_MOSKITO=50,
    TYPE_MST_FRUIT1=51,
    TYPE_MST_FRUIT2=52,
    TYPE_MST_SHAKY_FRUIT=53,
    TYPE_MEDAILLON=54,
    TYPE_MUS_WAIT=55,
    TYPE_STONEWOMAN2=56,
    TYPE_STALAG=57,
    TYPE_CAGE=58,
    TYPE_CAGE2=59,
    TYPE_BIG_CLOWN=60,
    TYPE_WAT_CLOWN=61,
    TYPE_DROP=62,
    TYPE_MOVE_START_NUA=63,
    TYPE_SCROLL=64,
    TYPE_SPIDER=65,
    TYPE_DARD=66,
    TYPE_SWING_PLAT=67,
    TYPE_BIG_BOING_PLAT=68,
    TYPE_STONEBOMB3=69,
    TYPE_TROMPETTE=70,
    TYPE_NOTE=71,
    TYPE_PIRATE_NGAWE=72,
    TYPE_RING=73,
    TYPE_SAXO=74,
    TYPE_PAILLETTE=75,
    TYPE_DESTROYING_DOOR=76,
    TYPE_PIRATE_GUETTEUR=77,
    TYPE_PIRATE_BOMB=78,
    TYPE_STONECHIP=79,
    TYPE_BIGSTONE=80,
    TYPE_CYMBALE=81,
    TYPE_JAUGEUP=82,
    TYPE_EXPLOSION=83,
    TYPE_TIBETAIN=84,
    TYPE_ROLLING_EYES=85,
    TYPE_MARACAS=86,
    TYPE_TAMBOUR1=87,
    TYPE_TAMBOUR2=88,
    TYPE_JOE=89,
    TYPE_NOTE0=90,
    TYPE_NOTE1=91,
    TYPE_NOTE2=92,
    TYPE_BONNE_NOTE=93,
    TYPE_POING=94,
    TYPE_POING_POWERUP=95,
    TYPE_TOTEM=96,
    TYPE_BBL=97,
    TYPE_SPACE_MAMA=98,
    TYPE_RAY_POS=99,
    TYPE_MITE=100,
    TYPE_MORNINGSTAR_MOUNTAI=101,
    TYPE_BNOTE=102,
    TYPE_POI1=103,
    TYPE_POI2=104,
    TYPE_MARTEAU=105,
    TYPE_MOVE_MARTEAU=106,
    TYPE_GROSPIC=107,
    TYPE_DARK2_PINK_FLY=108,
    TYPE_PI=109,
    TYPE_PI_BOUM=110,
    TYPE_PI_MUS=111,
    TYPE_WASHING_MACHINE=112,
    TYPE_BAG1=113,
    TYPE_UNUSED_114=114,
    TYPE_BB1_PLAT=115,
    TYPE_CLOWN_TNT=116,
    TYPE_CLOWN_TNT2=117,
    TYPE_CLOWN_TNT3=118,
    TYPE_TNT_BOMB=119,
    TYPE_BATTEUR_FOU=120,
    TYPE_ECLAIR=121,
    TYPE_STONEDOG2=122,
    TYPE_BLACKTOON1=123,
    TYPE_PANCARTE=124,
    TYPE_BON3=125,
    TYPE_FOURCHETTE=126,
    TYPE_COUTEAU_SUISSE=127,
    TYPE_TIRE_BOUCHON=128,
    TYPE_PETIT_COUTEAU=129,
    TYPE_BLACKTOON_EYES=130,
    TYPE_BAG3=131,
    TYPE_POI3=132,
    TYPE_SUPERHELICO=133,
    TYPE_FALLING_OBJ2=134,
    TYPE_ETINC=135,
    TYPE_DEMI_RAYMAN=136,
    TYPE_REDUCTEUR=137,
    TYPE_ROULETTE=138,
    TYPE_MARACAS_BAS=139,
    TYPE_PT_GRAPPIN=140,
    TYPE_NEIGE=141,
    TYPE_ONEUP=142,
    TYPE_NOVA2=143,
    TYPE_LIDOLPINK2=144,
    TYPE_KILLING_EYES=145,
    TYPE_FLASH=146,
    TYPE_MST_SCROLL=147,
    TYPE_GRAP_BONUS=148,
    TYPE_CLE_SOL=149,
    TYPE_SCORPION=150,
    TYPE_BULLET=151,
    TYPE_CAISSE_CLAIRE=152,
    TYPE_FEE=153,
    TYPE_ROULETTE2=154,
    TYPE_ROULETTE3=155,
    TYPE_WALK_NOTE_1=156,
    TYPE_EAU=157,
    TYPE_PALETTE_SWAPPER=158,
    TYPE_TIBETAIN_6=159,
    TYPE_TIBETAIN_2=160,
    TYPE_WIZ=161,
    TYPE_UFO_IDC=162,
    TYPE_INDICATOR=163,
    TYPE_GENERATING_DOOR=164,
    TYPE_BADGUY3=165,
    TYPE_LEVIER=166,
    TYPE_FALLING_OBJ3=167,
    TYPE_CYMBAL1=168,
    TYPE_CYMBAL2=169,
    TYPE_RAYON=170,
    TYPE_MST_COPAIN=171,
    TYPE_STONEWOMAN=172,
    TYPE_BATEAU=173,
    TYPE_PIRATE_POELLE=174,
    TYPE_PUNAISE1=175,
    TYPE_CRAYON_BAS=176,
    TYPE_FALLING_YING=177,
    TYPE_HERSE_BAS=178,
    TYPE_HERSE_BAS_NEXT=179,
    TYPE_SAXO2=180,
    TYPE_SCROLL_SAX=181,
    TYPE_NOTE3=182,
    TYPE_SAXO3=183,
    TYPE_PIRATE_POELLE_D=184,
    TYPE_WALK_NOTE_2=185,
    TYPE_POELLE_ALWAYS=186,
    TYPE_MAMA_PIRATE=187,
    TYPE_RUBIS=188,
    TYPE_MOVE_RUBIS=189,
    TYPE_COUTEAU=190,
    TYPE_FALLING_CRAYON=191,
    TYPE_SMA_GRAND_LASER=192,
    TYPE_SMA_BOMB=193,
    TYPE_SMA_BOMB_CHIP=194,
    TYPE_SPIDER_PLAFOND=195,
    TYPE_DARD_PLAFOND=196,
    TYPE_MEDAILLON_TOON=197,
    TYPE_BB12=198,
    TYPE_BB1_VIT=199,
    TYPE_BB13=200,
    TYPE_BB14=201,
    TYPE_RAY_ETOILES=202,
    TYPE_SMA_WEAPON=203,
    TYPE_BLACK_RAY=204,
    TYPE_BLACK_FIST=205,
    TYPE_PIEDS_RAYMAN=206,
    TYPE_POELLE=207,
    TYPE_LANDING_SMOKE=208,
    TYPE_FIRE_LEFT=209,
    TYPE_FIRE_RIGHT=210,
    TYPE_BOUT_TOTEM=211,
    TYPE_DARK=212,
    TYPE_SPACE_MAMA2=213,
    TYPE_BOUEE_JOE=214,
    TYPE_DARK_SORT=215,
    TYPE_ENS=216,
    TYPE_MITE2=217,
    TYPE_HYBRIDE_MOSAMS=218,
    TYPE_CORDE=219,
    TYPE_PIERREACORDE=220,
    TYPE_CFUMEE=221,
    TYPE_CORDEBAS=222,
    TYPE_HYBRIDE_STOSKO=223,
    TYPE_STOSKO_PINCE=224,
    TYPE_PIRATE_P_45=225,
    TYPE_PIRATE_P_D_45=226,
    TYPE_MOSKITO2=227,
    TYPE_PRI=228,
    TYPE_PUNAISE2=229,
    TYPE_PUNAISE3=230,
    TYPE_HYB_BBF2_D=231,
    TYPE_HYB_BBF2_G=232,
    TYPE_HYB_BBF2_LAS=233,
    TYPE_LAVE=234,
    TYPE_PUNAISE4=235,
    TYPE_ANNULE_SORT_DARK=236,
    TYPE_GOMME=237,
    TYPE_POING_FEE=238,
    TYPE_PIRATE_GUETTEUR2=239,
    TYPE_CRAYON_HAUT=240,
    TYPE_HERSE_HAUT=241,
    TYPE_HERSE_HAUT_NEXT=242,
    TYPE_MARK_AUTOJUMP_PLAT=243,
    TYPE_SMA_PETIT_LASER=244,
    TYPE_DUNE=245,
    TYPE_CORDE_DARK=246,
    TYPE_VITRAIL=247,
    TYPE_SKO_PINCE=248,
    TYPE_RIDEAU=249,
    TYPE_PUNAISE5=250,
    TYPE_VAGUE_DEVANT=251,
    TYPE_VAGUE_DERRIERE=252,
    TYPE_PLANCHES=253,
    TYPE_SLOPEY_PLAT=254,
    TYPE_INVALID=255
} ObjType;

typedef enum ObjActiveFlag {
    ACTIVE_ALIVE=0,
    ACTIVE_DEAD=1,
    ACTIVE_REINIT=2,
    ACTIVE_SPECIAL=4
} ObjActiveFlag;

typedef enum ObjFlags {
    OBJ_NONE=0,
    OBJ_ANIM_COUNT_MASK=255,
    OBJ_FLAG_0=256,
    OBJ_CMD_TEST=512,
    OBJ_ALIVE=1024,
    OBJ_ACTIVE=2048,
    OBJ_LINKED=4096,
    OBJ_FLAG_5=8192,
    OBJ_FLIP_X=16384,
    OBJ_READ_CMDS=32768,
    OBJ_FOLLOW_ENABLED=65536,
    OBJ_FLAG_9=131072,
    OBJ_FLAG_A=262144,
    OBJ_FLAG_B=524288
} ObjFlags;

typedef struct AnimationLayer AnimationLayer, *PAnimationLayer;

typedef struct AnimationFrame AnimationFrame, *PAnimationFrame;

struct Font {
    struct Sprite *sprites;
    undefined *img_buffer;
    int nb_sprites;
};

struct CmdContext {
    short cmd_offset;
    ushort count;
};

struct Obj {
    struct Sprite *sprites;
    struct Animation *animations;
    undefined *img_buffer;
    struct ObjState **eta;
    byte *cmds;
    byte *cmd_labels;
    struct CmdContext cmd_contexts[1];
    short x_pos;
    short y_pos;
    short id;
    short screen_x_pos;
    short screen_y_pos;
    short field12_0x26;
    short init_x_pos;
    short init_y_pos;
    short speed_x;
    short speed_y;
    ushort nb_sprites;
    short cmd_offset;
    short nb_cmd;
    short field20_0x36; // For Rayman this is the current follow obj id
    short follow_y;
    short follow_x;
    short field23_0x3c;
    short field24_0x3e;
    short ray_dist;
    short iframes_timer;
    short test_block_index;
    short scale;
    ushort zdc;
    short active_timer;
    enum BlockType btypes[5];
    undefined field32_0x51;
    byte offset_bx;
    byte offset_by;
    byte anim_index;
    byte anim_frame;
    byte main_etat;
    byte init_main_etat;
    byte sub_etat;
    byte init_sub_etat;
    enum ObjCommand cmd;
    byte gravity_value_1;
    byte gravity_value_2;
    enum ChangeAnimMode change_anim_mode;
    byte offset_hy;
    byte follow_sprite;
    byte hit_points;
    byte init_hit_points;
    byte init_flag;
    enum ObjType type;
    byte hit_sprite;
    enum ObjActiveFlag active_flag;
    byte detect_zone;
    byte detect_zone_flag;
    byte cmd_context_index;
    byte field56_0x69;
    byte display_prio;
    byte timer;
    enum ObjFlags flags;
};

struct AllFixData {
    struct Font alpha;
    struct Font alpha2;
    struct Obj objects[29];
};

struct ObjState {
    char speed_x_right;
    char speed_x_left;
    byte anim_index;
    byte next_main_etat;
    byte next_sub_etat;
    byte anim_speed;
    byte sound;
    byte flags;
};

struct Sprite {
    int img_buffer_offset; // unused for final release
    byte id; // 0 is invalid
    byte width; // full width
    byte height; // full height
    byte sprite_width; // sprite width
    byte sprite_height; // sprite height
    byte sprite_pos; // x and y as 4-bit values
    byte field7_0xa;
    byte field8_0xb;
    ushort clut; // palette
    ushort tpage; // texture page
    byte page_x;
    byte page_y;
};

struct Animation {
    struct AnimationLayer *layers;
    struct AnimationFrame *frames;
    ushort layers_count;
    ushort frames_count;
};

struct AnimationFrame {
    byte x;
    byte y;
    byte width;
    byte height;
};

struct AnimationLayer {
    bool flip_x;
    byte x_pos;
    byte y_pos;
    byte sprite;
};

typedef enum Input {
    INPUT_NONE=0,
    INPUT_LEFT=1,
    INPUT_RIGHT=2,
    INPUT_UP=3,
    INPUT_DOWN=4,
    INPUT_CROSS=5,
    INPUT_CIRCLE=6,
    INPUT_SQUARE=7,
    INPUT_TRIANGLE=8,
    INPUT_START=9,
    INPUT_SELECT=10,
    INPUT_R1=11,
    INPUT_R2=12,
    INPUT_L1=13,
    INPUT_L2=14,
    INPUT_DISABLE_DEBUG=15, // unused
    INPUT_ENABLE_DEBUG=16, // unused
    INPUT_START_SELECT=17,
    INPUT_UNUSED_12=18,
    INPUT_13=19,
    INPUT_14=20,
    INPUT_UNUSED_15=21,
    INPUT_UNUSED_16=22,
    INPUT_17=23,
    INPUT_18=24,
    INPUT_UNUSED_19=25,
    INPUT_UNUSED_1A=26,
    INPUT_READ=255
} Input;

typedef struct WorldInfo WorldInfo, *PWorldInfo;

struct WorldInfo {
    short x_pos;
    short y_pos;
    byte index_up;
    byte index_down;
    byte index_left;
    byte index_right;
    byte state;
    byte nb_cages;
    byte world;
    byte level;
    byte color;
    char *level_name;
};

typedef struct LevelData LevelData, *PLevelData;

struct LevelData {
    struct Obj *objects;
    byte nb_objects;
};

typedef struct LoadInfoRay LoadInfoRay, *PLoadInfoRay;

struct LoadInfoRay {
    byte num_lives;
    byte num_wiz;
    byte num_cages;
    byte num_continues;
};

typedef struct StatusBar StatusBar, *PStatusBar;

struct StatusBar {
    short num_lives;
    byte lives_digits[2];
    byte hp_sprites[2];
    byte num_wiz;
    byte wiz_digits[2];
    byte max_hp;
};

typedef struct SaveState SaveState, *PSaveState;

struct SaveState {
    uint triggered_objects[8];
    short nb_floc[8];
    undefined2 vent_x;
    undefined2 vent_y;
    short x_map;
    short y_map;
    short time;
    short ray_x_pos;
    short ray_y_pos;
    short ray_screen_x;
    short ray_screen_y;
    ushort ray_flip_x;
    short save_obj_id;
    short save_obj_x_pos;
    short save_obj_y_pos;
    byte link_init[256];
    undefined1 save_obj_detect_zone_flag;
    byte field17_0x14b;
    enum BlockType ray_btypes[5];
    byte ray_anim_index;
    byte ray_anim_frame;
    byte ray_main_etat;
    byte ray_sub_etat;
    byte poing_sub_etat;
    byte rayevts_0;
    byte rayevts_1;
    byte rayevts_2;
    byte dead_time;
    bool has_saved;
    byte num_wiz;
};

typedef enum Video {
    VIDEO_NONE=0,
    VIDEO_PRES=1,
    VIDEO_INTRO=2,
    VIDEO_DEMO=3,
    VIDEO_MAP_INTRO=4, // Same as the normal intro, but only plays the end,
    VIDEO_WIN=5
} Video;

typedef struct PixGerbeItem *PixGerbeItem_0x6;

typedef enum RayEvts_0 {
    RAYEVTS0_NONE=0,
    RAYEVTS0_POING=1,
    RAYEVTS0_HANG=2,
    RAYEVTS0_HELICO=4,
    RAYEVTS0_SUPER_HELICO=8,
    RAYEVTS0_HANDSTAND_DASH=16,
    RAYEVTS0_HANDSTAND=32,
    RAYEVTS0_GRAIN=64,
    RAYEVTS0_GRAP=128
} RayEvts_0;

typedef struct PixGerbeItem *PixGerbeItem_0x2;

typedef enum RayEvts_1 {
    RAYEVTS1_NONE=0,
    RAYEVTS1_RUN=1,
    RAYEVTS1_DEMI=2,
    RAYEVTS1_LUCIOLE=4,
    RAYEVTS1_FORCE_RUN_TOGGLE=8,
    RAYEVTS1_FORCE_RUN=16,
    RAYEVTS1_REVERSE=32,
    RAYEVTS1_FLAG6=64,
    RAYEVTS1_UNUSED_DEATH=128
} RayEvts_1;

typedef struct Credit Credit, *PCredit;

struct Credit {
    char *text;
    short x_pos;
    short y_pos;
    byte font;
    byte cmd;
    byte color;
};

typedef enum PsxPadButtonStates {
    PAD_NONE=0,
    PAD_L2=1,
    PAD_R2=2,
    PAD_L1=4,
    PAD_R1=8,
    PAD_TRIANGLE=16,
    PAD_CIRCLE=32,
    PAD_CROSS=64,
    PAD_SQUARE=128,
    PAD_SELECT=256,
    PAD_L3=512,
    PAD_R3=1024,
    PAD_START=2048,
    PAD_UP=4096,
    PAD_RIGHT=8192,
    PAD_DOWN=16384,
    PAD_LEFT=32768
} PsxPadButtonStates;

typedef struct RaymanEvents RaymanEvents, *PRaymanEvents;

struct RaymanEvents {
    enum RayEvts_0 flags0;
    enum RayEvts_1 flags1;
};

typedef enum RayMode {
    MODE_NONE=0,
    MODE_RAYMAN=1,
    MODE_RAY_ON_MS=2,
    MODE_MORT_DE_RAYMAN=3,
    MODE_MORT_DE_RAYMAN_ON_MS=4
} RayMode;

typedef struct WorldInfo *WorldInfo_0x8;

typedef struct PixGerbe PixGerbe, *PPixGerbe;

struct PixGerbe {
    struct PixGerbeItem items[64];
    short is_active;
};

typedef struct Poing Poing, *PPoing;

struct Poing {
    int field0_0x0;
    short field1_0x4;
    short speed_x;
    short charge;
    short field4_0xa;
    byte sub_etat;
    bool is_returning;
    bool is_active;
    byte damage;
    bool is_charging;
    bool is_boum;
};

typedef struct Sprite *Sprite_0xC;

typedef struct Sprite *Sprite_0xE;

typedef struct SepInfo SepInfo, *PSepInfo;

struct SepInfo {
    short access_num;
    short seq_num;
};

typedef struct SndFileInfo SndFileInfo, *PSndFileInfo;

struct SndFileInfo {
    int field0_0x0;
    int ray_vh_offs;
    int sep_vh_offs;
    int seq_offs;
    int size;
};

typedef struct Unk_801f62a0 Unk_801f62a0, *PUnk_801f62a0;

struct Unk_801f62a0 {
    short id;
    short index;
    short prog;
    short tone;
    short note;
    short vol;
    short field6_0xc;
    short field7_0xe;
    int field8_0x10;
    short field9_0x14;
    short field10_0x16;
};

typedef struct SoundTableEntry SoundTableEntry, *PSoundTableEntry;

struct SoundTableEntry {
    byte note;
    byte prog;
    byte tone;
    byte volume;
    byte flags;
};

typedef struct VoiceTableEntry VoiceTableEntry, *PVoiceTableEntry;

struct VoiceTableEntry {
    short id;
    short field1_0x2;
    short field2_0x4;
    short field3_0x6;
    undefined field4_0x8;
    undefined field5_0x9;
    undefined field6_0xa;
    undefined field7_0xb;
};

typedef struct Unk_801f7d40 Unk_801f7d40, *PUnk_801f7d40;

struct Unk_801f7d40 {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
};

typedef struct RGB RGB, *PRGB;

struct RGB {
    byte r;
    byte g;
    byte b;
};

typedef struct FileInfo FileInfo, *PFileInfo;

struct FileInfo {
    undefined *path;
    undefined *dest;
    undefined *dest_debug;
    struct CdlFILE file;
};

typedef enum SemiTransparencyRate {
    Mode0=0,
    Mode1=1,
    Mode2=2,
    Mode3=3
} SemiTransparencyRate;

typedef struct MenuText MenuText, *PMenuText;

typedef struct RECT RECT, *PRECT;

struct RECT {
    short x;
    short y;
    short w;
    short h;
};

struct MenuText {
    char *header;
    char *rows[6];
    struct RECT vignette_rect;
    int vignette;
    int music;
    byte rows_count;
    byte selected_row;
    byte color;
};

typedef struct Display Display, *PDisplay;

typedef struct DISPENV DISPENV, *PDISPENV;

typedef struct DRAWENV DRAWENV, *PDRAWENV;

typedef struct DR_ENV DR_ENV, *PDR_ENV;

typedef struct SPRT_8 SPRT_8, *PSPRT_8;

typedef struct TILE_1 TILE_1, *PTILE_1;

typedef struct SPRT SPRT, *PSPRT;

typedef struct POLY_FT4 POLY_FT4, *PPOLY_FT4;

typedef struct TILE TILE, *PTILE;

typedef struct POLY_G4 POLY_G4, *PPOLY_G4;

typedef struct DRENVAndTile DRENVAndTile, *PDRENVAndTile;

typedef struct POLY_F4 POLY_F4, *PPOLY_F4;

typedef struct POLY_G3 POLY_G3, *PPOLY_G3;

struct DR_ENV {
    u_long tag;
    u_long _code[15];
};

struct POLY_G3 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char r1;
    u_char g1;
    u_char b1;
    u_char pad1;
    short x1;
    short y1;
    u_char r2;
    u_char g2;
    u_char b2;
    u_char pad2;
    short x2;
    short y2;
};

struct SPRT_8 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char u0;
    u_char $2;
    u_short clut;
};

struct TILE {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    short w;
    short h;
};

struct DRENVAndTile {
    struct DR_ENV drawing_environment;
    struct TILE tile;
};

struct DRAWENV {
    struct RECT clip;
    short ofs[2];
    struct RECT tw;
    u_short tpage;
    u_char dtd;
    u_char dfe;
    u_char isbg;
    u_char r0;
    u_char g0;
    u_char b0;
    struct DR_ENV dr_env;
};

struct SPRT {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char u0;
    u_char $2;
    u_short clut;
    short w;
    short h;
};

struct POLY_G4 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char r1;
    u_char g1;
    u_char b1;
    u_char pad1;
    short x1;
    short y1;
    u_char r2;
    u_char g2;
    u_char b2;
    u_char pad2;
    short x2;
    short y2;
    u_char r3;
    u_char g3;
    u_char b3;
    u_char pad3;
    short x3;
    short y3;
};

struct DISPENV {
    struct RECT disp;
    struct RECT screen;
    u_char isinter;
    u_char isrgb24;
    u_char pad0;
    u_char pad1;
};

struct POLY_F4 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
};

struct POLY_FT4 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char u0;
    u_char $2;
    u_short clut;
    short x1;
    short y1;
    u_char u1;
    u_char $3;
    u_short tpage;
    short x2;
    short y2;
    u_char u2;
    u_char v2;
    u_short pad1;
    short x3;
    short y3;
    u_char u3;
    u_char v3;
    u_short pad2;
};

struct TILE_1 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
};

struct Display {
    struct DISPENV field0_0x0;
    struct DRAWENV drawing_environment;
    struct DR_ENV map_drawing_environment_primitives[25];
    byte field_0x6b0_0x7d7[296];
    ulong map_ordering_tables[6];
    ulong ordering_table[11];
    struct SPRT_8 tiles[360];
    struct SPRT_8 field_0x1e9c_0x321b[312];
    struct TILE_1 tile1s[240];
    struct SPRT sprites[50];
    struct POLY_FT4 polygons[200];
    struct TILE field11_0x6084;
    struct POLY_G4 field12_0x6094;
    undefined field13_0x60b8;
    undefined field14_0x60b9;
    undefined field15_0x60ba;
    undefined field16_0x60bb;
    struct DRENVAndTile field17_0x60bc[17];
    struct DR_ENV unk_dr_env;
    byte field_0x664c_0x668b[64];
    struct TILE fond_box_tiles[4];
    struct TILE fond_box_tile;
    struct TILE field22_0x66dc[6];
    struct POLY_F4 unk_poly_f4s[16];
    struct POLY_G4 unk_poly_g4s[16];
    struct POLY_G3 unk_poly_g3s[16];
};

typedef struct RGBAArray RGBAArray, *PRGBAArray;

struct RGBAArray {
    byte data[4];
};

typedef struct VideoState VideoState, *PVideoState;

struct VideoState {
    byte *encodedFrameBuffers[2];
    byte *decodedFrame;
    struct RECT frameRect;
    bool hasSwappedDisplay;
    byte vsyncCounter;
    byte currentEncodeBufferIndex;
    short frame_count;
};

typedef struct DIRENTRY DIRENTRY, *PDIRENTRY;


// WARNING! conflicting data type names: /LIBAPI.H/DIRENTRY - /Rayman/psyq/DIRENTRY

struct DIRENTRY {
    char name[20];
    long attr;
    long size;
    struct DIRENTRY *next;
    long head;
    char system[4];
};

typedef enum EvSpec {
    EvSpINT=2,
    EvSpIOE=4,
    EvSpCOMP=32,
    EvSpTIMOUT=256,
    EvSpNEW=8192,
    EvSpERROR=32768
} EvSpec;

typedef struct CardFrame0 CardFrame0, *PCardFrame0;

struct CardFrame0 {
    char sc_magic[2];
    byte icon_display_flag;
    byte block_num;
    char Rayman_save_ray_pct[64];
    char Maga[28];
    byte icon_palette[32];
};

typedef enum EvMode {
    EvMdINTR=4096,
    EvMdNOINTR=8192
} EvMode;

typedef enum EvDesc {
    HwSPU=4026531849,
    HwCARD=4026531857,
    RCntCNT3=4060086275,
    SwCARD=4093640705
} EvDesc;

typedef struct BBAttackEntry BBAttackEntry, *PBBAttackEntry;

struct BBAttackEntry {
    short attack;
    byte wait_for_fin_atan;
};

typedef struct CouteauxInfo CouteauxInfo, *PCouteauxInfo;

struct CouteauxInfo {
    short x_pos;
    short y_pos;
    short field2_0x4;
    short field3_0x6;
    short field4_0x8;
    short field5_0xa;
    short field6_0xc;
    undefined field7_0xe;
    byte active;
    byte field9_0x10;
    undefined1 id; // Created by retype action
};

typedef struct SaxAttackEntry SaxAttackEntry, *PSaxAttackEntry;

struct SaxAttackEntry {
    byte next_note;
    byte time;
    short field2_0x2;
};

typedef struct SaxNoteEntry SaxNoteEntry, *PSaxNoteEntry;

struct SaxNoteEntry {
    byte type;
    short speed_x;
    short speed_y;
    short initial_iframes;
    short field4_0x8; // unused
};

typedef struct SaxData SaxData, *PSaxData;

struct SaxData {
    short x_pos;
    short y_pos;
    short note_box_coll_x;
    short note_box_coll_y;
    short sprite2_x;
    short sprite2_y;
    byte coup;
    byte saved_hp;
    byte field8_0xe;
    byte field9_0xf;
    short field10_0x10;
};

typedef struct BB1Data BB1Data, *PBB1Data;

struct BB1Data {
    short speed_x;
    short field1_0x2;
    byte field2_0x4;
    byte saved_main_etat;
    byte saved_sub_etat;
    short saved_cmd;
    short sprite6_x;
    short sprite6_y;
    byte field8_0xe;
};

typedef struct MusicCommand MusicCommand, *PMusicCommand;

struct MusicCommand {
    byte cmd_and_flags;
    byte param;
};

typedef struct Obj *Obj_0x58;

typedef struct RayStack RayStack, *PRayStack;

struct RayStack {
    short x_pos;
    short y_pos;
    short poing_x_pos;
    short poing_y_pos;
    byte main_etat;
    byte sub_etat;
    byte anim_index;
    byte anim_frame;
    byte flip_x;
    byte poing_anim_index;
    byte poing_anim_frame;
    byte poing_flip_x;
    bool poing_is_active;
    byte scale;
};

typedef struct CommandTableEntry CommandTableEntry, *PCommandTableEntry;

struct CommandTableEntry {
    bool (*read)(struct Obj *);
    bool (*skip)(struct Obj *);
    bool (*handle)(struct Obj *);
};

typedef struct Obj *Obj_0x55;

typedef struct VitrauxInfo VitrauxInfo, *PVitrauxInfo;

struct VitrauxInfo {
    short x_pos;
    short y_pos;
    byte obj_id;
    byte index; // 0-4
    byte field4_0x6;
    byte mode; // 0 is inactive, 1 is getting less bright and 2 is getting brighter
    ushort value; // goes from 100 to 0
};

typedef struct Obj *Obj_0x5C;

typedef struct Obj *Obj_0x54;

typedef struct Obj *Obj_0x53;

typedef struct Obj *Obj_0x6A;

typedef struct Obj *Obj_0x6C;

typedef struct Obj *Obj_0x1E;

typedef struct ZDC ZDC, *PZDC;

struct ZDC {
    short x_pos;
    short y_pos;
    byte width;
    byte height;
    byte flags;
    byte sprite;
};

typedef struct Obj *Obj_0x60;

typedef struct Obj *Obj_0x20;

typedef struct Obj *Obj_0x63;

typedef struct Obj *Obj_0x34;

typedef struct Obj *Obj_0x2E;

typedef struct Obj *Obj_0x2C;

typedef struct ObjHandlers ObjHandlers, *PObjHandlers;

struct ObjHandlers {
    void (*do_obj)(struct Obj *);
};

typedef struct ActiveObjects ActiveObjects, *PActiveObjects;

struct ActiveObjects {
    short objects[100];
    short num_active_objects;
};

typedef struct Obj *Obj_0x3E;

typedef struct Obj *Obj_0x3C;

typedef struct Obj *Obj_0x42;

typedef struct ObjTypeFlags ObjTypeFlags, *PObjTypeFlags;

typedef enum ObjTypeFlags_0 {
    OBJ0_NONE=0,
    OBJ0_ALWAYS=1,
    OBJ0_BALLE=2,
    OBJ0_NO_COLLISION=4,
    OBJ0_HIT_RAY=8,
    OBJ0_KEEP_ACTIVE=16,
    OBJ0_DETECT_ZONE=32,
    OBJ0_FLAG6=64,
    OBJ0_BOSS=128
} ObjTypeFlags_0;

typedef enum ObjTypeFlags_1 {
    OBJ1_NONE=0,
    OBJ1_KEEP_LINKED_OBJECTS_ACTIVE=1,
    OBJ1_BONUS=2,
    OBJ1_BIG_RAY_HIT_KNOCKBACK=4,
    OBJ1_RAY_DIST_MULTISPR_CANTHANGE=8,
    OBJ1_USE_INSTANT_SPEED_X=16,
    OBJ1_USE_INSTANT_SPEED_Y=32,
    OBJ1_SPECIAL_PLATFORM=64,
    OBJ1_READ_CMD=128
} ObjTypeFlags_1;

typedef enum ObjTypeFlags_2 {
    OBJ2_NONE=0,
    OBJ2_MOVE_ON_BLOCK=1,
    OBJ2_FALL_IN_WATER=2,
    OBJ2_BLOCKS_RAY=4,
    OBJ2_JUMP_ON_RESSORT_BLOCK=8,
    OBJ2_DO_NOT_CHECK_RAY_COLLISION=16,
    OBJ2_KILL_IF_OUTSIDE_ACTIVE_ZONE=32,
    OBJ2_UTURN_ON_BLOCK=64,
    OBJ2_INCREASE_SPEED_X=128
} ObjTypeFlags_2;

typedef enum ObjTypeFlags_3 {
    OBJ3_NONE=0,
    OBJ3_POING_COLLISION_SND=1,
    OBJ3_DIE_IN_WATER=2,
    OBJ3_STOP_MOVING_UP_WHEN_HIT_BLOCK=4,
    OBJ3_SWITCH_OFF=8,
    OBJ3_FLAG4=16,
    OBJ3_FLAG5=32,
    OBJ3_FLAG6=64,
    OBJ3_FLAG7=128
} ObjTypeFlags_3;

struct ObjTypeFlags {
    enum ObjTypeFlags_0 flags0;
    enum ObjTypeFlags_1 flags1;
    enum ObjTypeFlags_2 flags2;
    enum ObjTypeFlags_3 flags3;
};

typedef enum BlockFlags {
    BLOCK_NONE=0,
    BLOCK_FULLY_SOLID=1,
    BLOCK_SOLID=2,
    BLOCK_HURT=4,
    BLOCK_SLIPPERY=8,
    BLOCK_FLAG_4=16,
    BLOCK_CH_DIR=32,
    BLOCK_SLOPE=64,
    BLOCK_FLAG_7=128
} BlockFlags;

typedef struct MapData MapData, *PMapData;

struct MapData {
    short width;
    short height;
    int length;
    short *map;
};

typedef struct BackgroundPosition BackgroundPosition, *PBackgroundPosition;

struct BackgroundPosition {
    short x;
    short y;
};

typedef struct BackgroundData BackgroundData, *PBackgroundData;

struct BackgroundData {
    struct BackgroundPosition sprite_positions[16];
    struct Sprite sprites[16];
};

typedef struct TILE_8 TILE_8, *PTILE_8;

struct TILE_8 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
};

typedef struct POLY_F3 POLY_F3, *PPOLY_F3;

struct POLY_F3 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    short x1;
    short y1;
    short x2;
    short y2;
};

typedef struct POLY_GT3 POLY_GT3, *PPOLY_GT3;

struct POLY_GT3 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char u0;
    u_char $2;
    u_short clut;
    u_char r1;
    u_char g1;
    u_char b1;
    u_char p1;
    short x1;
    short y1;
    u_char u1;
    u_char $3;
    u_short tpage;
    u_char r2;
    u_char g2;
    u_char b2;
    u_char p2;
    short x2;
    short y2;
    u_char u2;
    u_char v2;
    u_short pad2;
};

typedef struct POLY_FT3 POLY_FT3, *PPOLY_FT3;

struct POLY_FT3 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char u0;
    u_char $2;
    u_short clut;
    short x1;
    short y1;
    u_char u1;
    u_char $3;
    u_short tpage;
    short x2;
    short y2;
    u_char u2;
    u_char v2;
    u_short pad1;
};

typedef struct LINE_F3 LINE_F3, *PLINE_F3;

struct LINE_F3 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    short x1;
    short y1;
    short x2;
    short y2;
    u_long pad;
};

typedef struct SPRT_16 SPRT_16, *PSPRT_16;

struct SPRT_16 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char u0;
    u_char $2;
    u_short clut;
};

typedef struct TILE_16 TILE_16, *PTILE_16;

struct TILE_16 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
};

typedef struct POLY_FT4 *POLY_FT4_0x16;

typedef struct LINE_G2 LINE_G2, *PLINE_G2;

struct LINE_G2 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char r1;
    u_char g1;
    u_char b1;
    u_char p1;
    short x1;
    short y1;
};

typedef struct TILE_1 *TILE_1_0xA;

typedef struct LINE_F4 LINE_F4, *PLINE_F4;

struct LINE_F4 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
    u_long pad;
};

typedef struct BLK_FILL BLK_FILL, *PBLK_FILL;

struct BLK_FILL {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    u_short x0;
    u_short y0;
    u_short w;
    u_short h;
};

typedef struct LINE_F2 LINE_F2, *PLINE_F2;

struct LINE_F2 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    short x1;
    short y1;
};

typedef struct LINE_G3 LINE_G3, *PLINE_G3;

struct LINE_G3 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char r1;
    u_char g1;
    u_char b1;
    u_char p1;
    short x1;
    short y1;
    u_char r2;
    u_char g2;
    u_char b2;
    u_char p2;
    short x2;
    short y2;
    u_long pad;
};

typedef struct LINE_G4 LINE_G4, *PLINE_G4;

struct LINE_G4 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char r1;
    u_char g1;
    u_char b1;
    u_char p1;
    short x1;
    short y1;
    u_char r2;
    u_char g2;
    u_char b2;
    u_char p2;
    short x2;
    short y2;
    u_char r3;
    u_char g3;
    u_char b3;
    u_char p3;
    short x3;
    short y3;
    u_long pad;
};

typedef struct SPRT_8 *SPRT_0xD;

typedef struct SPRT *SPRT_0xA;

typedef struct SPRT *SPRT_0x8;

typedef struct POLY_FT4 *POLY_FT4_0x22;

typedef struct POLY_GT4 POLY_GT4, *PPOLY_GT4;

struct POLY_GT4 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
    u_char u0;
    u_char $2;
    u_short clut;
    u_char r1;
    u_char g1;
    u_char b1;
    u_char p1;
    short x1;
    short y1;
    u_char u1;
    u_char $3;
    u_short tpage;
    u_char r2;
    u_char g2;
    u_char b2;
    u_char p2;
    short x2;
    short y2;
    u_char u2;
    u_char v2;
    u_short pad2;
    u_char r3;
    u_char g3;
    u_char b3;
    u_char p3;
    short x3;
    short y3;
    u_char u3;
    u_char v3;
    u_short pad3;
};

typedef struct SpuReverbAttr SpuReverbAttr, *PSpuReverbAttr;

typedef struct SpuVolume SpuVolume, *PSpuVolume;

struct SpuVolume {
    short left;
    short right;
};

struct SpuReverbAttr {
    ulong mask;
    long mode;
    struct SpuVolume depth;
    long delay;
    long feedback;
};




void gte_ldv0(SVECTOR * r0);
void gte_ldv1(SVECTOR * r0);
void gte_ldv2(SVECTOR * r0);
void gte_ldv3(SVECTOR * r0, SVECTOR * r1, SVECTOR * r2);
void gte_ldv3c(SVECTOR * r0);
void gte_ldv3c_vertc(void);
undefined FUN_20000020();
undefined FUN_20000024();
undefined FUN_20000030();
undefined FUN_20000068();
undefined FUN_200000d4();
undefined FUN_20000110();
undefined FUN_2000011c();
undefined FUN_20000120();
undefined FUN_20000124();
undefined FUN_2000013c();
undefined FUN_20000140();
undefined FUN_20000144();
undefined FUN_20000148();
undefined FUN_2000014c();
undefined FUN_20000160();
undefined FUN_20000164();
void FUN_8012d030(DVECTOR param_1,DVECTOR param_2,short param_3,short param_4,short param_5);
void FUN_8012d27c(void);
void FUN_8012d2b0(undefined2 param_1);
void PS1_RollUpTransition(short param_1,short left_to_right);
bool PS1_RollUpRToL(void);
bool PS1_RollUpLToR(void);
void FUN_8012da14(void);
int continue_fonction(void);
void DO_CONTINUE(void);
undefined4 select_level_prg(void);
int SELECT_LEVEL(short param_1);
void DISPLAY_STAGE_NAMES(void);
bool WORLD_CHOICE(void);
void DO_WORLD_MAP(void);
void DISPLAY_TXT_VIGNET(void);
bool display_vignet_prg(void);
void DISPLAY_GAME_VIGNET(void);
void DISPLAY_TXT_CREDITS(void);
bool display_credits_prg(void);
void DISPLAY_CREDITS(void);
void DISPLAY_PROTOON_BACK(void);
void DO_VICTOIRE(void);
void InitDemoJeu(void);
void FinDemoJeu(void);
bool loader_anim_prg(void);
void DO_GROS_RAYMAN(void);
void FUN_8012ece8(void);
void FUN_8012ecf0(void);
void DO_AFFICHE_PAUSE(void);
int FUN_8012eda4(short param_1,short param_2);
int PS1_LoadToVRAM(short width,short height,short x,short y,u_long *data);
void PS1_LoadVRAMBlock(uint start_page,uint start_pos,int end_page,int end_pos,int base_x,int base_y);
void FUN_8012f2cc(void);
void PouvoirsParMap(void);
void PS1_ResetSaveZone(void);
void FUN_8012f570(void);
void DO_GROS_MOTEUR_NORMAL(void);
void DO_MAIN_LOOP(void);
void PS1_FinishRecordingDemo(void);
void main(void);
void FUN_80130048(void);
void PS1_CdReadyCallback(int status,byte *result);
void PS1_CdSyncCallback(int status,byte *result);
void PS1_Mark_Callback(undefined2 access_num,undefined2 seq_num,undefined2 data);
void FUN_8013045c(void);
void PS1_SsSetSerialVolA(short vol);
void FUN_80130540(void);
void PS1_Cd_Callbacks_Disable(void);
void PS1_Mark_Callback_Disable(void);
void PS1_Cd_Callbacks_Enable(void);
void PS1_Mark_Callback_Enable(void);
void PS1_InitMusic(void);
void FUN_8013066c(void);
void FUN_80130684(void);
void FUN_801309b0(void);
bool FUN_801309b8(uint param_1,uint param_2,byte *param_3,uint param_4);
void FUN_80130a98(CdlLOC *param_1,CdlLOC *param_2,CdlLOC *param_3);
void FUN_80130b18(uint param_1,CdlLOC *param_2);
int FUN_80130bc4(CdlLOC param_1);
int FUN_80130c58(int param_1);
int FUN_80130d00(uint param_1,uint param_2);
void PS1_InitTracks(void);
bool FUN_80131474(short *param_1,uint param_2,uint param_3);
void FUN_801314c4(void);
void PS1_PlayMusic(void);
void playLevelMusic(undefined2 world,undefined2 level);
void start_cd_gros_rayman(void);
void start_cd_suspence(void);
void start_cd_credits(void);
void FUN_80131c94(void);
void start_cd_gagne(void);
void PS1_PlayDeathMusic(void);
void PS1_PlayCDTrack_0_3(void);
void start_cd_gameover(void);
void start_cd_continue(void);
int FUN_80131db8(void);
void PS1_Cd_Pause(void);
void stop_cd(void);
void PS1_Volume_Zero(void);
void FUN_80131e40(void);
void FUN_80131e5c(void);
void PS1_Music_Apply_Fade(void);
void FUN_8013202c(void);
void change_audio_track_moskito_acc(void);
void change_audio_track_moskito_dec(void);
void change_audio_track_puit(void);
void FUN_80132110(void);
void FUN_80132148(void);
void FUN_80132150(void);
void FUN_80132158(void);
void FUN_80132160(void);
void PS1_SetMusicVolume(short param_1);
void FUN_801321fc(void);
void FUN_80132244(void);
void PS1_LoadLevelMapBlock(MapData *mp);
void FUN_80132304(u_long *param_1,ushort height);
void FUN_8013234c(undefined4 *param_1);
void FUN_80132424(void);
void PS1_LoadAllFixData(void);
void PS1_LoadLevelObjBlock(void);
void FUN_80132864(int param_1);
void PS1_PlayVideo(Video video);
void FUN_80132980(void);
void PS1_PlayVideoFile(Video video);
void PS1_InitVideoState(VideoState *param_1);
void PS1_LoadVideoFile(CdlLOC *lba,u_long param_2);
void PS1_ReadVideoFile(u_long *param_1,Video video);
void FUN_80132f8c(void);
void FUN_80133010(void);
void PS1_Disable_all_Callbacks(void);
void FUN_80133048(undefined4 param_1,FileInfo *param_2,byte param_3);
undefined4 PS1_InitFiles(FileInfo *files,int count,char *name);
int FUN_801331a4(FileInfo *param_1,int param_2,undefined4 param_3);
int PS1_LoadFiles(FileInfo *files,int file_index,int count,int param_4);
int PS1_LoadVabBody(FileInfo param_1,short param_2,undefined *param_3);
int readinput(void);
int upjoy(void);
int leftjoy(void);
int rightjoy(void);
int downjoy(void);
int FUN_801336c4(void);
int FUN_80133714(void);
int FUN_80133764(void);
int FUN_801337b4(void);
int but0pressed(void);
int but1pressed(void);
int but2pressed(void);
int but3pressed(void);
undefined4 FUN_80133984(void);
undefined4 FUN_801339f4(void);
bool PS1_IsInputtingCheatCode(void);
int FUN_80133acc(void);
int FUN_80133b08(void);
int FUN_80133b44(void);
int FUN_80133b80(void);
int FUN_80133bd0(void);
int FUN_80133c20(void);
int FUN_80133c70(void);
int FUN_80133cc0(void);
int FUN_80133d10(void);
int FUN_80133d60(void);
int FUN_80133db0(void);
int FUN_80133e00(void);
int FUN_80133e50(void);
int FUN_80133ea0(void);
int FUN_80133ef0(void);
int PS1_TOUCHE_0x9(void);
int FUN_80133f90(void);
int FUN_80133fe0(void);
int PS1_TOUCHE_0xA(void);
int FUN_80134080(void);
int PS1_TOUCHE_0xE(void);
int PS1_TOUCHE_0xC(void);
int PS1_TOUCHE_0xB(void);
int PS1_TOUCHE_0xF(void);
int PS1_TOUCHE_0x12(void);
int PS1_TOUCHE_0x13(void);
int PS1_TOUCHE_0x14(void);
int PS1_TOUCHE_0x15(void);
int PS1_TOUCHE_0x16(void);
int PS1_TOUCHE_0x17(void);
int PS1_TOUCHE_0x18(void);
int FUN_80134440(void);
int FUN_80134490(void);
int PS1_TOUCHE_0x10(void);
int FUN_80134530(void);
int ValidButPressed(void);
int StartButPressed(void);
int FUN_801345c8(void);
int SelectButPressed(void);
void FUN_80134610(uint param_1);
byte FUN_8013491c(void);
void PS1_DoDemo(Record *record);
void FUN_80134be0(void);
int TOUCHE(Input param_1);
int PS1_SingleTOUCHE(Input param_1);
void PS1_LoadFondSprites(void);
void PS1_LoadFondDataAndPalettes(void);
void PS1_LoadFond(void);
void FUN_80135ab0(short param_1,short *param_2);
void FUN_80135d5c(int param_1,short *param_2,int param_3,short param_4);
void FUN_8013613c(ushort param_1,uint param_2,ushort param_3,uint param_4);
void FUN_80136340(short *param_1,uint param_2);
void FUN_801366ac(void);
void PS1_DisplayFondSprites(void);
uint FUN_80137998(byte param_1,uint param_2,uint param_3);
uint PS1_GetTileV(byte param_1,uint param_2,uint tile);
int PS1_GetTileU(uint param_1);
void DRAW_MAP(void);
void FUN_80137cc8(int param_1,short *param_2);
void allume_vitraux(byte (*param_1) [5]);
void FUN_80138360(byte *vitrailClignotement);
void FUN_80138718(char param_1);
void FUN_80138b84(short param_1,short *param_2,short param_3,short param_4);
void PS1_DisplayWorldMapBg2(ushort param_1,ushort param_2,short param_3,short param_4,short param_5,short param_6);
void FUN_801392c8(void);
void FUN_801392d0(void);
void FUN_801392d8(int param_1,short *param_2,ushort *param_3);
void FUN_80139330(uint param_1,short *param_2,ushort *param_3);
void FUN_801393c8(int param_1);
void PS1_LoadAllFixTextures(int length);
void FUN_8013948c(int param_1);
void FUN_80139514(int param_1);
void FUN_801395a8(int param_1);
void FUN_80139624(int param_1);
void FUN_80139688(int tileSetSize);
void PS1_DrawColoredSprite(Sprite *sprite,short x,short y,undefined displayMode);
void PS1_DrawSprite(Sprite *sprite,short x,short y,undefined1 param_4);
void PS1_DrawScaledSprite(Sprite *sprite,short x,short y,bool isFlipped,ushort param_5);
void FUN_80139d5c(short *param_1,short *param_2,short param_3,short param_4,short param_5);
void PS1_DrawRay(Sprite *sprite,short param_2,short param_3,char param_4,short param_5);
void display_sprite(Obj *param_1,uint sprite,short x,short y,undefined1 param_5);
void display2(Obj *obj);
void DISPLAY_POING(void);
void DISPLAY_CLING(void);
void display_bar_boss(Obj *bossObj);
void DISPLAY_FIXE(short leftTime);
void FUN_8013ad54(short param_1,short param_2,undefined2 param_3);
void DrawWldPointPlan2Normal(short param_1,short param_2);
void PS1_DisplayPtsPrim(void);
void DISPLAY_POINT(short param_1,short param_2);
void DISPLAY_PTS_TO_PLAN2(int x1,int y1,int x2,int y2,short percentage);
void DISPLAY_PLATEAU(Obj *param_1);
void draw_flocon1_Normal(short param_1,short param_2);
void draw_flocon2_Normal(short param_1,short param_2);
void draw_flocon3_Normal(short param_1,short param_2);
void draw_flocon4_Normal(short param_1,short param_2);
void draw_flocon5_Normal(short param_1,short param_2);
void FUN_8013b294(short param_1,short param_2);
void FUN_8013b304(short param_1,short param_2);
void draw_pluie4_Normal(short param_1,short param_2);
void draw_pluie5_Normal(short param_1,short param_2);
void draw_pluie6_Normal(short param_1,short param_2);
void FUN_8013b4d4(short param_1,short param_2);
void display_flocons_behind(void);
void display_flocons_before(void);
void display_pix_gerbes(void);
void DISPLAY_CYMBALE(Obj *param_1,bool param_2);
void DISPLAY_ALL_OBJECTS(void);
byte PS1_deter_num_let_old(byte param_1);
byte PS1_calc_let_Width(short sprite,byte font);
int calc_let_Width(byte param_1,undefined2 param_2);
int PS1_CalcTextWidth(char *str,byte font);
void PS1_DisplayCenteredText(char *str,ushort param_2,uint color);
void PS1_DisplayMultipleCenteredText(byte param_1,MenuText *param_2);
void DrawFondBoxNormal(short param_1,short param_2,short param_3,short param_4,u_char param_5);
void DrawBlackBoxNormal(short param_1,short param_2,short param_3,short param_4,u_char param_5);
void DISPLAY_BLACKBOX(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,byte param_5,bool isFond);
void display_text_sin(char *param_1,ushort param_2,short param_3,short param_4,byte param_5,byte param_6);
void display_text(char *text,short in_x,short in_y,byte font_size,uint param_5);
void display_box_text(TextToDisplay *txt);
void CLRSCR(void);
void display_etoile(int param_1,int param_2);
void display_grp_stars(void);
void DISPLAY_TEXT_FEE(void);
void DisplayJumellesNormal(void);
void PS1_DisplayWorldMapBg1(short param_1,short param_2,short param_3,short param_4);
void DISPLAY_SAVE_SPRITES(short param_1,short param_2);
void DISPLAY_SAVE_POING(void);
void display_time(short param_1);
void PS1_LoadPts(void);
void DISPLAY_CONTINUE_SPR(void);
void PS1_PromptCardDisplayPoing(void);
void DISPLAY_OPTIONS_POING(void);
void PS1_SetZDC(short param_1,short param_2,byte param_3,byte param_4,byte param_5,char param_6);
void PS1_SetTypeZDC(uint objType,ushort param_2,int param_3);
ushort get_nb_zdc(Obj *param_1);
ushort get_zdc_index(Obj *obj);
ZDC * get_zdc(Obj *obj,short param_2);
int get_ZDCPTR(void);
bool in_coll_sprite_list(Obj *obj,ushort param_2);
undefined4 box_inter_v_line(short param_1,short param_2,short param_3,short param_4,short param_5,short param_6,short param_7);
undefined4 box_inter_h_line(short param_1,short param_2,short param_3,short param_4,short param_5,short param_6,short param_7);
bool inter_box(int param_1,int param_2,int param_3,int param_4,short param_5,short param_6,int param_7,int param_8);
void GET_OBJ_ZDC(Obj *obj,short *x,short *y,short *w,short *h);
int GET_SPRITE_ZDC(Obj *param_1,short param_2,short *param_3,short *param_4,short *param_5,short *param_6);
int BOX_HIT_SPECIAL_ZDC(short x,short y,short w,short h,Obj *obj);
int BOX_IN_COLL_ZONES(short param_1,short param_2,short param_3,short param_4,short param_5,Obj *obj);
uint COLL_BOX_SPRITE(short param_1,short param_2,short param_3,short param_4,Obj *param_5);
int CHECK_BOX_COLLISION(short param_1,short x,short y,short w,short h,Obj *obj);
int possible_sprite(Obj *obj,int index);
int setToleranceDist(int param_1,int param_2,short param_3);
void SET_RAY_DIST_MULTISPR_CANTCHANGE(Obj *obj);
void SET_RAY_DIST_PI(Obj *obj);
void SET_RAY_DIST_BAG(Obj *obj);
void SET_RAY_DIST(Obj *obj);
void do_boum(void);
void DO_PNG_COLL_STONEMAN(Obj *obj);
void DO_PNG_COLL_STONEWOMAN(Obj *obj);
void DO_POING_COLLISION(void);
int COLL_BOX_ALL_SPRITES(short param_1,short param_2,short param_3,short param_4,Obj *param_5);
bool COLL_RAY_PIC(void);
void COLL_RAY_BLK_MORTEL(void);
void RAY_KO(void);
void RAY_HIT(bool hurt,Obj *obj);
void standard_frontZone(Obj *obj,short *x,short *w);
void SET_DETECT_ZONE_FLAG(Obj *obj);
void goToRay(Obj *obj);
void unleashMonsterHost(Obj *obj);
void DO_COLL_RAY_CYMBALE(Obj *param_1);
void DoAudioStartRaymanCollision(Obj *param_1);
void PS1_DoRaymanCollision(void);
void DO_COLLISIONS(void);
void DO_OBJ_COLLISIONS(Obj *param_1,short param_2);
void set2bits(uint *param_1,uint param_2,int param_3);
void read2bits(uint *value,uint pos,int *b1,uint *b0);
void save_objects_flags(void);
void restore_objects_flags(void);
void snapToSprite(Obj *obj1,Obj *obj2,uint param_3,int param_4,ushort param_5);
Obj * findfirstObject(ObjType objType);
Obj * findfirstInactiveObject(ObjType param_1);
void setbit(byte *buffer,uint bitIndex);
void clearbit(byte *buffer,uint bitIndex);
uint getbit(byte *buffer,uint bitIndex);
int cosinus(short param_1);
int sinus(short param_1);
int sinYspeed(Obj *obj,int param_2,short param_3,ushort *param_4);
int ashl16(ushort param_1,uint param_2);
int ashr16(ushort param_1,uint param_2);
int ashl32(uint param_1,uint param_2);
int ashr32(uint value,uint shift);
void set_proj_center(undefined2 param_1,undefined2 param_2);
int get_proj_dist(short param_1,ushort param_2);
int get_proj_dist2(short param_1,short param_2);
int get_proj_x(short param_1,short param_2);
int get_proj_y(short param_1,short param_2);
void set_zoom_mode(undefined zoomMode);
int inverse_proj_x(short param_1,short param_2);
int inverse_proj_y(short param_1,short param_2);
int vblToEOA(Obj *param_1,uint factor);
void GET_ANIM_POS(Obj *param_1,short *x,short *y,ushort *w,ushort *h);
undefined4 FUN_801473d4(Obj *param_1);
undefined4 FUN_801473dc(void);
void add_actobj(short objId);
undefined PS1_BTYPAbsPos(int x,int y);
void set_sub_etat(Obj *obj,byte subEtat);
void set_main_etat(Obj *param_1,byte etat);
void set_main_and_sub_etat(Obj *obj,byte main_etat,byte sub_etat);
short get_center_x(Obj *obj);
short get_center_y(Obj *obj);
byte on_block_chdir(Obj *obj,short param_2,short param_3);
void CALC_FOLLOW_SPRITE_SPEED(Obj *obj,Animation *anim1,Animation *anim2,short param_4);
int GET_SPRITE_POS(Obj *obj,int spriteIndex,short *x,short *y,ushort *w,ushort *h);
void GET_RAY_ZDC(Obj *ray,short *x,short *y,short *w,short *h);
void GET_BB1_ZDCs(Obj *obj,short *param_2,short *param_3,short *param_4,short *param_5,short *param_6,short *param_7,short *param_8,short *param_9);
int myRand(int param_1);
void calc_obj_dir(Obj *obj);
bool OBJ_IN_ZONE(Obj *obj);
void calc_obj_pos(Obj *obj);
void makeUturn(Obj *obj);
ushort BTYP(short xPos,short yPos);
void calc_btyp_square(Obj *obj);
void DO_OBJ_REBOND_EN_X(Obj *obj);
uint calc_btyp(Obj *obj);
void init_obj_in_the_air(Obj *obj);
void make_my_fruit_go_down(Obj *obj,short param_2);
void allocate_toons(Obj *srcObj,uint count);
void special_flags_init(void);
void switchOff(Obj *obj);
void obj_hurt(Obj *obj);
void Projectil_to_RM(Obj *obj,short *speed_x,short *speed_y,short new_speed_x,short new_speed_y);
void del_actobj(Obj *param_1);
void INIT_TEXT_TO_DISPLAY(void);
byte deter_num_let(byte param_1);
void calc_num_let_spr(char param_1,char *param_2);
int calc_largmax_text(int param_1,int param_2,short space_width,short param_4,undefined param_5);
void INIT_TXT_BOX(TextToDisplay *param_1);
void Deter_Option_Caract(char *param_1,short param_2,uint param_3);
void SwapAB(undefined2 *param_1,undefined2 *param_2);
void Bresenham(code *param_1,short param_2,short param_3,short param_4,short param_5,short param_6,short param_7);
void LOAD_CONFIG(void);
void init_finBossLevel(void);
void Change_Wait_Anim(void);
void PS1_SetSauveRayEvts(void);
void PS1_RestoreSauveRayEvts(void);
void pmamaFollowsShip(Obj *param_1);
void init_couteaux(void);
void reset_couteaux(void);
bool check_couteaux(void);
byte find_couteau(Obj *obj);
int x_pos(ushort param_1,uint param_2);
int y_pos(int param_1,short param_2);
int y_floor(uint param_1,uint param_2);
void init_move_couteau(Obj *param_1);
void init_lance_couteau(byte index);
uint couteau_frame(short speedX,short speedY);
void update_couteau(Obj *obj);
void get_cou_zdc(Obj *param_1,short *param_2,short *param_3,short *param_4,short *param_5);
void pma_attaque_suivante(void);
int convertspeed(short speed);
void lance_couteau_parabolique(Obj *obj);
void lance_couteau_droit(Obj *param_1);
void retour_couteau(Obj *obj);
void PS1_retour_couteau_old(Obj *obj);
void lance_couteau_lineaire(Obj *param_1);
void DO_COU_COMMAND(Obj *obj);
void calc_pma_dir(Obj *obj);
void DO_PMA_COMMAND(Obj *obj);
void init_mama_pirate(Obj *obj);
void PMA_SORT_DU_CANON(void);
void DO_PMA_POING_COLLISION(Obj *obj);
undefined4 pma_get_eject_sens(void);
void DO_COU_ATTER(Obj *param_1);
void DO_PMA_ATTER(Obj *param_1);
void _card_clear(long chan);
void INIT_HORLOGES(void);
void horloges(void);
void PS1_InitAllowedTime(void);
int get_allowed_time(void);
void calc_left_time(void);
void fades(void);
void FUN_8014e27c(void);
int frapsol(int param_1);
void DO_SCREEN_TREMBLE(void);
void DO_SCREEN_TREMBLE3(void);
void DO_SCREEN_TREMBLE2(void);
void DO_SCROLL(ushort *param_1,short *param_2);
void allocateLandingSmoke(Obj *param_1);
int Prio(Obj *event);
void first_obj_init(Obj *obj);
void obj_init(Obj *obj);
void INIT_OBJECTS(bool newLevel);
int instantSpeed(short speed);
void SET_X_SPEED(Obj *obj);
void REINIT_OBJECT(Obj *obj);
void make_active(Obj *obj,bool doNova);
bool in_action_zone(short x,short y,Obj *obj,char param_4);
void kill_obj(Obj *obj);
void SET_ACTIVE_FLAG(undefined2 x,undefined2 y,Obj *obj);
undefined4 DO_PESANTEUR(Obj *obj);
void FUN_80150c5c(Obj *param_1,byte param_2);
void DO_ANIM(Obj *obj);
int prof_in_bloc(int param_1);
void do_boing(Obj *param_1,char param_2,undefined1 param_3);
byte underSlope(Obj *obj);
void DO_STONEBOMB_REBOND(Obj *obj);
void DO_THROWN_BOMB_REBOND(Obj *obj,short param_2,ushort param_3);
void DO_FRUIT_REBOND(Obj *obj,short param_2,ushort param_3);
void Drop_Atter(Obj *obj);
void BadGuyAtter(Obj *obj);
void MiteAtter(Obj *param_1);
void Clown_Music_Atter(Obj *obj);
void LidolPinkAtter(Obj *obj);
void stoneDogAtter(Obj *obj);
void stoneDogBounces(Obj *obj);
void Spider_Atter(Obj *obj);
void trompetteAtter(Obj *obj);
void NormalAtter(Obj *param_1);
void OBJ_IN_THE_AIR(Obj *obj);
void test_fall_in_water(Obj *obj);
void MOVE_OBJECT(Obj *obj);
void DO_RAY_IN_ZONE(Obj *obj);
void DO_ONE_OBJECT(Obj *obj);
void fptr_init(void);
void build_active_table(void);
void Add_One_RAY_lives(void);
void DO_CLING_ANIMS(void);
void DO_OBJECTS_ANIMS(void);
void DO_OBJECTS(void);
void MOVE_OBJECTS(void);
void RECALE_ALL_OBJECTS(void);
bool RayCoince(short param_1);
void move_up_ray(void);
void move_down_ray(void);
void RecaleRayPosInJumelle(void);
void RAY_TO_THE_RIGHT(void);
void RAY_TO_THE_LEFT(void);
void FUN_80156040(void);
void TEST_FIN_FOLLOW(void);
void RAY_FOLLOW(void);
void DO_FIXE(void);
void deactivate_ship_links(void);
undefined4 linkListHoldsAGendoor(Obj *obj);
undefined4 FUN_8015666c(Obj *obj);
undefined4 FUN_80156710(Obj *obj);
void correct_gendoor_link(void);
void suppressFromLinkList(Obj *obj);
void correct_link(void);
void INIT_RAY_BEGIN(void);
void INIT_RAY(byte newLevel);
byte is_icy_pente(uint param_1);
void STOPPE_RAY_EN_XY(void);
void RAY_RESPOND_TO_ALL_DIRS(void);
void DO_RAYMAN(void);
void DO_RAY_ON_MS(void);
void DO_PLACE_RAY(void);
void DO_AUTO_SCROLL(void);
bool do_perfect_bonus(void);
void INIT_MOTEUR(bool newLevel);
void INIT_MOTEUR_BEGIN(void);
void INIT_MOTEUR_WORLD(void);
void INIT_MOTEUR_LEVEL(short newLevel);
void restore_gendoor_link(void);
void DONE_MOTEUR_LEVEL(void);
void INIT_MOTEUR_DEAD(void);
void INIT_RAY_ON_MS(char *newMs);
void PS1_SetWindForce(void);
void DO_MOTEUR(void);
void DO_MOTEUR2(void);
void RAY_REVERSE_COMMANDS(void);
void RAY_DEMIRAY(void);
void DO_MOTEUR_GELE(void);
void FUN_8015a764(void);
bool get_bonus_map_complete(int world,int level);
void set_bonus_map_complete(int wld,int lvl);
void DO_PERFECT_BONUS_MAP(void);
void DO_WIZ_AFTER_BONUS_MAP(void);
void init_bonus_perfect(void);
void allocateGrille(Obj *obj);
void new_level_init(void);
void fix_numlevel(Obj *obj);
void TEST_SIGNPOST(void);
void DO_WIZARD(Obj *obj);
short get_next_bonus_level(byte param_1);
void TEST_WIZARD(Obj *obj);
void allocate_splash(Obj *baseObj);
undefined4 can_free_fish(int param_1);
void DESACTIVE_FISH_COLLIS(Obj *obj);
void DO_PYRANHA(Obj *obj);
void DO_BALLE(Obj *obj);
void setStoneChipPos(Obj *param_1,Obj *param_2,char *param_3);
void allocateStoneChips(Obj *obj);
void DO_STONE_EXPLOSION(Obj *obj);
void DO_TIR(Obj *param_1);
void allocateStonemanStone(Obj *param_1,short param_2,char param_3);
void DO_STONEMAN1_TIR(Obj *obj);
void DO_STONEMAN2_TIR(Obj *obj);
void allocateStonewomanStone(Obj *obj,short param_2);
void DO_STONEWOMAN_TIR(Obj *obj);
void allocateDard(Obj *param_1);
void DO_SPIDER_TIR(Obj *obj);
void DO_INTERACT_PLAT(Obj *param_1);
void DO_TARZAN(Obj *obj);
Obj * oldest_planted(void);
void DO_GROWING_PLATFORM(void);
void DO_BIG_CLOWN_ATTAK(Obj *obj);
void allocatedrop(Obj *param_1);
void DO_WAT_CLOWN_ATTAK(Obj *obj);
void trompetteWind(Obj *obj,char param_2);
void DO_TRP_ATTAK(Obj *obj);
void allocateEclatPS(Obj *param_1,short param_2);
void DO_PI_EXPLOSION(Obj *obj);
void DO_CLOWN_TNT_ATTACK(Obj *param_1);
void allocate_badguy(Obj *param_1,short param_2,short param_3,short param_4);
Obj * allocateExplosion(Obj *obj);
void BombExplosion(Obj *obj);
void MARACAS_GO(Obj *obj);
int ANGLE_RAYMAN(Obj *obj);
Obj * allocateNOVA(void);
void DO_NOVA(Obj *obj);
void DO_NOVA2(Obj *param_1);
int NOVA_STATUS_BAR(void);
void add_one_floc(void);
void add_256_flocs(void);
void sub_one_floc(void);
void init_flocons(void);
void do_flocons(short param_1,short param_2,short param_3,short param_4);
void set_snow_sequence(ushort param_1,undefined2 param_2);
void set_SNSEQ_list(short param_1);
void DO_SNOW_SEQUENCE(void);
void DO_REDEYE_FIRE(short param_1,short param_2,undefined2 param_3);
void calc_esquive_poing(Obj *obj,short *param_2,short *param_3,short *param_4);
void DO_PTI_ESQUIVE(Obj *obj);
void DO_MITE2_ESQUIVE(Obj *obj);
int allocate_gerbe(void);
void start_pix_gerbe(int param_1,int param_2);
void do_pix_gerbes(void);
void START_2_PARTS_CYMBAL_ACTION(Obj *obj);
void DO_CAGE2(Obj *obj);
void DO_CAGE(Obj *obj);
void DO_MEDAILLON_TOON(Obj *obj);
void DO_MEDAILLON_TOON_GELE(void);
void ALLOCATE_MEDAILLON_TOON(void);
void INIT_LUCIOLE(void);
void DO_LUCIOLE(void);
void ChangeLevel(void);
void INIT_TXT_FEE(void);
void allocate_poing_or_fee(void);
void init_moustique(void);
void init_fee(void);
void DO_CORDE_CASSE(Obj *obj);
void DO_FUMEE_CORDE(short x,short y);
int GetY(int param_1);
void allocateSupHelico(Obj *musObj);
void allocatePaillette(Obj *obj);
void test_fin_cling(void);
void initGameSave(void);
void doneGameSave(void);
void saveGameState(Obj *obj,SaveState *state);
void restoreGameState(SaveState *save);
void PS1_PhotographerCollision(void);
int get_offset_in_save_zone(short eventIndex);
void reset_save_zone_level(void);
void take_bonus(ushort eventIndex);
byte bonus_taken(ushort param_1);
void PS1_WriteWiSaveZone(void);
void PS1_LoadWiSaveZone(void);
void DO_SPECIAL_PLATFORM(Obj *obj);
void PS1_StopPlayingAllSnd(void);
void FUN_801658e0(void);
void manage_snd_event(Obj *obj);
void PS1_LoadAllFixSound(void);
void PS1_LoadWorldSound(ushort param_1);
void PS1_PlaySnd(short param_1,short param_2);
void PS1_StopPlayingSnd(short param_1);
int PS1_SongIsPlaying(int param_1);
void FUN_80166018(void);
void SetVolumeSound(short param_1);
void FUN_801660ac(void);
void FUN_801660e8(void);
void stop_all_snd(void);
void FUN_8016617c(void);
uint get_pan_snd(Obj *obj);
uint get_vol_snd(Obj *param_1);
void PS1_SetSoundVolume(short param_1);
void PS1_SetStereoEnabled(short param_1);
void InitSnd(void);
void FUN_80166578(void);
int last_snd(short param_1);
int get_pile_obj(short param_1);
int FUN_80166724(short param_1);
int FUN_80166790(short param_1);
int get_voice_obj_snd(short param_1,short param_2);
void erase_pile_snd(short param_1);
void nettoie_pile_snd(void);
void FUN_80166d20(short param_1);
ushort FUN_80166d88(short param_1);
int vol_r(short param_1,short param_2);
int vol_l(short param_1,short param_2);
void PlaySnd(short snd,short obj_id);
void PlaySnd_old(short snd);
void setvol(ushort param_1,byte param_2);
void setpan(short param_1,byte param_2);
void FUN_80168f38(void);
void FUN_80168f40(void);
void FUN_80168f48(void);
void FUN_80169194(void);
void FUN_8016924c(void);
void PS1_OnPauseOn(void);
void PS1_OnPauseOff(void);
void FUN_80169420(Display *param_1);
void PS1_LightningLoop(uint param_1,short param_2);
void PS1_LightningDraw(short param_1);
void FUN_80169a3c(RGBAArray *param_1,int param_2);
void FUN_80169ac8(RGBAArray *param_1,int param_2);
void FUN_80169b54(void);
void FUN_80169b5c(void);
void INIT_FADE_OUT(void);
void INIT_FADE_IN(void);
void DO_FADE(void);
bool PS1_DO_FADE_OUT_PRG(void);
void DO_FADE_OUT(void);
void PS1_DO_PICTURE_IN_PICTURE(void);
bool PS1_InitPAD(void);
undefined4 PS1_TestSwCARD(void);
void PS1_TestSwCARDOnce(void);
undefined4 PS1_TestHwCARD(void);
void PS1_TestHwCARDOnce(void);
undefined4 PS1_TestCard(uint par_chan);
int PS1_GetNbreFiles(char *name_start,DIRENTRY *file);
int PS1_CardFilenameChecksum(uint chan);
void PS1_InitializeCard(undefined chan);
undefined4 PS1_FormatFs(uint param_1);
void PS1_InitSaveRayAndFilenames(uint param_1);
undefined4 PS1_WriteSave(byte chan_par,uint slot_par);
char * FUN_8016b2e8(uint param_1,char param_2,char *param_3);
byte SaveGameOnDisk(uint param_1);
int SaveFileRead(long fd,void *buf,short n);
void PS1_LoadSave(undefined4 param_1,char *param_2);
void LoadGameOnDisk(uint param_1);
undefined4 LoadInfoGame(uint slot);
void FUN_8016bbe4(void);
byte PS1_GetNbreSave3(uint param_1);
bool PS1_CardFilenameChecksumChanged(void);
bool PS1_TestCardZero(void);
bool PS1_CardUnformatted(void);
byte PS1_GetNbreSave2(void);
int FUN_8016be9c(void);
void FUN_8016bec0(void);
void fist_U_turn(Obj *poingObj,bool param_2);
void CALC_FIST_POS(void);
void RAY_THROW_FIST(void);
void RAY_PREPARE_FIST(void);
void RAY_GROW_FIST(void);
void fin_poing_follow(Obj *obj,bool param_2);
void POING_FOLLOW(Obj *obj);
void alter_fist_speed(Obj *obj);
void switch_off_fist(Obj *poingObj);
void DO_POING(Obj *obj);
void allocatePoingBoum(void);
void PS1_DisplayVRAM(void);
bool test_allowed(Obj *obj,short param_2,short param_3);
void obj_jump(Obj *obj);
void DO_ONE_PINK_CMD(Obj *obj);
void FUN_8016d418(Obj *obj);
void DO_SPIDER_COMMAND(Obj *param_1);
void DO_STONEMAN_COMMAND(Obj *obj);
void DO_STONEDOG_COMMAND(Obj *obj);
void DO_MOVING_PLATFORM_COMMAND(Obj *obj);
void DO_TRP_COMMAND(Obj *obj);
void DO_ONE_CMD_WAIT(Obj *obj);
void DO_ONE_CMD_LR_ATTENTE(Obj *obj);
void DO_ONE_CMD_UPDOWN(Obj *param_1);
void special_pour_liv(Obj *param_1);
void DO_ONE_CMD(Obj *obj);
void DO_ONE_STONECHIP_COMMAND(Obj *obj);
void DO_STONEBOMB_COMMAND(Obj *obj);
void DO_CYMBAL_COMMAND(Obj *obj);
void DO_2_PARTS_CYMBAL(Obj *param_1);
void DO_TEN_COMMAND(Obj *obj);
void mite_esquive_poing(Obj *obj,short *param_2);
undefined4 HAS_MIT_JUMP(Obj *obj);
undefined4 ray_over_mit(Obj *obj,int param_2);
void fix_mit_Xspeed(Obj *obj,short param_2);
void DO_MIT_ATTAK(Obj *obj);
undefined4 IS_MIT_PAF(Obj *obj);
void DO_MIT_COMMAND(Obj *obj);
void DO_MITE2_COMMAND(Obj *obj);
void DO_ROLL_EYES(Obj *obj);
bool FUN_801707cc(Obj *obj,short param_2);
void DO_BAG1_COMMAND(Obj *param_1);
void DO_CLOWN_TNT_COMMAND(Obj *obj);
void DO_CLOWN_TNT2_COMMAND(Obj *param_1);
void DO_CLOWN_TNT3_COMMAND(Obj *param_1);
void DO_ECLAIR_COMMAND(Obj *obj);
bool MarCoince(Obj *obj,short param_2);
void DO_MOVE_MARACAS_COMMAND(Obj *obj);
void DO_BB1_PLAT_CMD(Obj *obj);
void DO_FLASH_COMMAND(Obj *obj);
void DO_MST_SCROLL_COMMAND(Obj *param_1,short param_2);
void DO_MST_CHANGE_COMMAND(int hp);
void DO_CCL_COMMAND(Obj *obj);
void DO_WLKNOT_COMMAND(Obj *obj);
void ACTIVE_L_EAU(Obj *obj);
void DO_EAU_QUI_MONTE(Obj *obj);
void DO_PHOTOGRAPHE_CMD(Obj *obj);
void DO_REDUCTEUR(Obj *obj);
void wait_for_dialogue_fee(Obj *obj,short time);
void DO_FEE_ETAPE(Obj *obj);
void fee_gives_super_evts(void);
void DO_FEE(Obj *param_1);
undefined4 IS_STONEWOMAN_WAIT(Obj *obj);
void DO_STONEWOMAN_COMMAND(Obj *obj);
void DO_NOMOVE_STONEWOMAN_COMMAND(Obj *obj);
void allocateOtherPosts(Obj *obj);
void doHerseCommand(Obj *obj);
void DO_POISSON_VERT_CMD(Obj *obj);
void DO_POISSON_BLEU_CMD(Obj *param_1);
void doBlackRaymanCommand(Obj *obj);
void DO_POELLE_COMMAND(Obj *obj);
void DO_CORDE_COMMAND(Obj *obj);
void DO_PAC_COMMAND(Obj *obj);
void DO_CFUMEE_COMMAND(Obj *obj);
void DO_NOVA2_COMMAND(Obj *obj);
void DO_ENSEIGNE_COMMAND(Obj *obj);
void doShipCommand(Obj *param_1);
void DO_BOUEE_JOE_COMMAND(Obj *obj);
void DO_JOE_COMMAND(Obj *obj);
void DO_DROP_COMMAND(Obj *obj);
void move_fruit_in_water(Obj *obj);
void DO_FALLING_OBJ_CMD(Obj *obj);
void DO_MUSICIEN(Obj *obj);
void DO_TIRE_BOUCHON_COMMAND(Obj *param_1);
void DO_PETIT_COUTEAU_COMMAND(Obj *obj);
void DO_BLKTOON_EYES_CMD(Obj *param_1);
void INIT_SAXO(Obj *sax_obj);
void allocateNote2(Obj *param_1,short param_2);
void DO_EXPLOSE_NOTE2(Obj *param_1);
void DO_NOTE_CMD(Obj *obj);
void Cree_Eclat_Note(Obj *param_1,Obj *param_2,short param_3);
void DO_EXPLOSE_NOTE1(Obj *obj);
void BonneNote(Obj *param_1);
void DO_NOTE_TOUCHEE(Obj *obj);
void DO_NOTE_REBOND(Obj *param_1);
void allocateNote(Obj *obj);
byte PrepareAtak(void);
void SAXO_TIRE(Obj *obj);
void DO_SAXO_COUP(Obj *obj);
void DO_SAXO2_COUP(Obj *obj);
void SetSaxoCollNoteBox(Obj *obj);
void DO_SAXO_COMMAND(Obj *obj);
void DO_SAXO_ATTER(Obj *obj);
void DO_SAXO2_COMMAND(Obj *obj);
void DO_SAXO2_ATTER(Obj *param_1);
void DO_SAXO_MARCHE(short hp);
void DO_SAXO3_COMMAND(Obj *obj);
void DO_SAXO3_DEBUT(Obj *obj);
int saxo2_get_eject_sens(void);
void get_spi_zdc(Obj *param_1,short *param_2,short *param_3,undefined2 *param_4,undefined2 *param_5);
void DO_SPIDER_PLAFOND(Obj *obj);
void DO_SPIDER_PLAFOND_POING_COLLISION(Obj *obj);
void SPIDER_PLAFOND_REACT(Obj *obj);
void DO_DARD_PLAFOND_ALWAYS(Obj *obj);
void FUN_801790cc(Display *display);
void Display_and_free_luciole(void);
void PS1_PerfectBonusDrawBg(void);
void DISPLAY_FOND_MENU(void);
void FUN_8017b260(uint param_1);
void popCmdContext(Obj *obj);
int char2short(byte param_1);
undefined FUN_8017b330(undefined param_1);
undefined4 readNoArg(void);
int readOneArg(Obj *obj);
undefined4 readTestArgs(Obj *obj);
undefined4 readGoXYArgs(Obj *obj);
undefined4 readSpeedArgs(Obj *obj);
int readInvalidArg(Obj *obj);
undefined4 skipNoArg(void);
undefined4 skipOneArg(Obj *obj);
undefined4 skipTestArgs(Obj *obj);
undefined4 skipGoXYArgs(Obj *obj);
undefined4 skipSpeedArgs(Obj *obj);
undefined4 skipInvalidArg(Obj *obj);
undefined4 handle_GO_WAITSTATE(Obj *obj);
undefined4 handle_RESERVED_GO_GOSUB(Obj *obj);
undefined4 handle_RESERVED_GO_SKIP_and_RESERVED_GO_GOTO(Obj *obj);
undefined4 handle_RESERVED_GO_BRANCHTRUE(Obj *obj);
undefined4 handle_RESERVED_GO_BRANCHFALSE(Obj *obj);
undefined4 handle_RESERVED_GO_SKIPTRUE(Obj *obj);
undefined4 handle_RESERVED_GO_SKIPFALSE(Obj *obj);
undefined4 handle_SELF_HANDLED(void);
undefined4 handle_GO_X(Obj *obj);
undefined4 handle_GO_Y(Obj *obj);
undefined4 handle_GO_GOTO(Obj *param_1);
undefined4 handle_GO_STATE(Obj *obj);
undefined4 handle_GO_SUBSTATE(Obj *param_1);
bool handle_GO_SKIP(Obj *obj);
undefined4 handle_GO_LABEL(void);
undefined4 handle_GO_PREPARELOOP(Obj *obj);
undefined4 handle_GO_GOSUB(Obj *obj);
undefined4 handle_GO_RETURN(Obj *obj);
undefined4 handle_GO_DOLOOP(Obj *obj);
undefined4 handle_INVALID_CMD(Obj *obj);
bool handle_GO_BRANCHTRUE(Obj *obj);
bool handle_GO_BRANCHFALSE(Obj *param_1);
undefined4 handle_GO_SKIPTRUE(Obj *obj);
undefined4 handle_GO_SKIPFALSE(Obj *obj);
undefined4 handle_GO_SETTEST(Obj *obj);
undefined4 handle_GO_TEST(Obj *obj);
bool readOneCommand(Obj *obj);
bool skipOneCommand(Obj *obj);
void GET_OBJ_CMD(Obj *obj);
void pushCmdContext(Obj *obj,ushort count);
void skipToLabel(Obj *obj,byte label,bool param_3);
void pushToLabel(Obj *obj,byte label,bool param_3);
void DO_TOTEM_TOUCHE(Obj *obj,short param_2);
void DO_TOTEM_COMMAND(Obj *param_1);
void DO_TOTBT_REBOND(Obj *obj);
void DO_PI_EXPLOSION2(Obj *obj);
void DO_BBL_REBOND(Obj *obj);
void allocateDog(Obj *bb1Obj);
void allocateTir(Obj *param_1,short param_2);
void CreateFirstBBL(void);
void INIT_BBMONT(Obj *obj);
void DO_BBL_COMMAND(Obj *obj);
void BBMONT_ECLAIR(Obj *obj);
void BBMONT_ETINCELLES(Obj *param_1);
void BBMONT_TIRE(undefined4 param_1);
void Cree_BBL(undefined4 param_1);
void BB_Attaque(Obj *param_1);
void Fin_BB_Attaque(undefined4 param_1);
void BB_Atan(Obj *obj);
void DO_BBMONT_ATTER(Obj *obj);
void DO_BBMONT_COMMAND(Obj *obj);
void DO_BBMONT_TOUCHE(Obj *obj);
void DO_BBMONT2_COMMAND(Obj *obj);
void DO_BBMONT2_MARCHE(short hp);
void DO_BBMONT2_ATTER(Obj *obj);
void DO_BBMONT3_COMMAND(Obj *obj);
void DO_BBMONT3_ATTER(Obj *obj);
void DO_BBMONT4_COMMAND(Obj *obj);
void FUN_801802d8(void);
void SYNCHRO_LOOP(code *param_1);
void FUN_8018058c(u_long *param_1,undefined4 param_2,undefined4 param_3,short x,short y,short h,short w);
void DISPLAY_FOND3(void);
void FUN_80180804(u_long *param_1,undefined4 param_2,undefined4 param_3,short param_4,short param_5,short param_6,short param_7);
void FUN_801809fc(void);
void DISPLAY_FOND_CONTINUE(void);
void DISPLAY_FOND_SELECT(void);
void PS1_ClearScreen(void);
void FUN_80180b04(Obj *param_1,char param_2);
void guetteurFollowsShip(Obj *obj);
void DO_ONE_PAR_COMMAND(Obj *obj);
int hasGuetteurABomb(Obj *obj,int param_2);
void allocatePirateGuetteurBomb(Obj *param_1,undefined4 param_2,char param_3,byte param_4);
void DO_PAR_TIR(Obj *param_1);
void DO_PAR_POING_COLLISION(Obj *obj,short param_2);
void PAR_REACT_TO_RAY_IN_ZONE(Obj *obj);
void DO_PAR_BOMB_COMMAND(Obj *obj);
void allocateRayLandingSmoke(void);
void recale_ray_on_liane(void);
void calc_bhand_typ(Obj *param_1);
void IS_RAY_ON_LIANE(void);
void rayMayLandOnAnObject(undefined *param_1,short param_2);
void set_air_speed(byte mainEtat,byte subEtat,short param_3,byte param_4);
void Reset_air_speed(bool isRollingSpeed);
void determineRayAirInertia(void);
void ray_jump(void);
void ray_inertia_speed(uint param_1,short param_2,short prevSpeedX,short param_4);
void RAY_SWIP(void);
void RAY_STOP(void);
void RAY_HELICO(void);
void Make_Ray_Hang(short param_1,short param_2);
byte AIR(int param_1);
byte MUR(int param_1);
void CAN_RAY_HANG_BLOC(void);
void RAY_TOMBE(void);
void RAY_RESPOND_TO_DOWN(void);
void RAY_RESPOND_TO_UP(void);
void RAY_RESPOND_TO_DIR(uint param_1);
void RAY_RESPOND_TO_NOTHING(void);
void PS1_RespondShoulderR(void);
void PS1_RespondShoulderL(void);
void RAY_RESPOND_TO_BUTTON4(void);
void RAY_RESPOND_TO_BUTTON3(void);
void RAY_RESPOND_TO_FIRE0(void);
void RAY_RESPOND_TO_FIRE1(void);
int RAY_BALANCE_ANIM(short param_1);
void abs_sinus_cosinus(short param_1,short *param_2,short *param_3);
void SET_RAY_BALANCE(void);
void RAY_GOING_BALANCE(Obj *obj);
void RAY_BALANCE(void);
void RAY_FIN_BALANCE(void);
void RayTestBlocSH(void);
void remoteControlRay(void);
void STOPPE_RAY_CONTRE_PAROIS(uint param_1);
void RAY_IN_THE_AIR(void);
void terminateFistWhenRayDies(void);
void snifRayIsDead(Obj *rayObj);
void rayfallsinwater(void);
bool RAY_DEAD(void);
void RAY_HURT(void);
void RepousseRay(void);
undefined4 RayEstIlBloque(void);
void stackRay(void);
void RAY_SURF(void);
void DO_SURF_CHANGE_HAIRS(void);
void RAY_PREPARE_PIEDS(void);
void DO_PIEDS_RAYMAN(void);
void DO_PIEDS_COLLISION(void);
void allocatePiedBoum(void);
void DO_MORT_DE_RAY(void);
void findMereDenisWeapon(void);
void PS1_setBossScrollLimits_spacemama(Obj *param_1);
bool mereDenisCanAttak(Obj *param_1);
int setMereDenisAtScrollBorder(Obj *obj,char param_2);
void setCirclePointToReach(void);
void allocateMereDenisBombChips(Obj *param_1);
void mereDenisExplodeBombs(void);
void mereDenisDropBomb(Obj *obj);
void snapWeaponAnimState(Obj *obj,byte param_2);
void swapMereDenisCollZones(Obj *obj,bool param_2);
byte prepareNewMereDenisAttack(Obj *param_1);
void snapLaserToWeapon(Obj *param_1,char param_2);
void allocateSpaceMamaLaser(Obj *param_1);
void doMereDenisCommand(Obj *obj);
void changeMereDenisPhase(void);
void fitSaveCurrentAction(void);
void doMereDenisHit(Obj *obj,short sprite);
void mereDenisBigLaserCommand(Obj *obj);
void mereDenisBombCommand(Obj *obj);
void setBossReachingSpeeds(Obj *obj,uint param_2,uint param_3,uint param_4);
bool testActionEnd(Obj *obj);
void FUN_8018b78c(short *param_1,short *param_2,short *param_3,short *param_4,byte param_5);
int firstFloorBelow(Obj *obj);
void allocateBlacktoonEyes(Obj *param_1);
void DO_BLK_SPEED_COMMAND(Obj *param_1);
void DO_BLK_LR_COMMAND(Obj *param_1);
void DO_BLK_NOP_COMMAND(Obj *param_1);
void DO_BLKTOON_COMMAND(Obj *obj);
void CalcObjPosInWorldMap(Obj *obj);
void DoScrollInWorldMap(short param_1,short param_2);
void PS1_DisplayPts(short param_1,short param_2,short param_3,short param_4);
void DISPLAY_PLAT_WAY(void);
void PS1_DisplayPlateau(void);
void DO_MEDAILLONS(void);
void INIT_LEVEL_STAGE_NAME(void);
void INIT_WORLD_STAGE_NAME(void);
void INIT_STAGE_NAME(void);
void CHANGE_STAGE_NAMES(void);
void PS1_CardDisplayPassword(void);
void PS1_WorldMapMoveText(void);
void INIT_WORLD_INFO(void);
void INIT_LITTLE_RAY(void);
void RESTORE_RAY(void);
void INIT_CHEMIN(void);
void RESPOND_TO_UP(void);
void RESPOND_TO_DOWN(void);
void RESPOND_TO_RIGHT(void);
void RESPOND_TO_LEFT(void);
void MoveRayInWorldMap(void);
void DO_RAYMAN_IN_WLD_MAP(void);
void DO_CHEMIN(void);
void INIT_PASTILLES_SAUVE(void);
void PASTILLES_SAUVE_SAVED(short param_1);
void FIN_WORLD_CHOICE(void);
void DETER_WORLD_AND_LEVEL(void);
void INIT_NEW_GAME(void);
void POINTEUR_BOUTONS_OPTIONS_BIS(void);
void PS1_DisplayPadButton(short button,short param_2,short param_3,byte param_4);
void INIT_CONTINUE(void);
void CHEAT_MODE_CONTINUE(void);
void MAIN_CONTINUE_PRG(void);
void FIN_CONTINUE_PRG(void);
void MAIN_NO_MORE_CONTINUE_PRG(void);
void INIT_VIGNET(void);
void INIT_CREDITS(void);
void DO_CREDITS(void);
void INIT_LOADER_ANIM(void);
void DO_LOADER_ANIM(void);
void SPECIAL_INIT(void);
void swap(int param_1,int param_2);
void set_rubis_list(void);
void allocate_rayon(short param_1,short param_2);
void allocate_8_petits_rayons(short param_1,short param_2);
void do_sko_rayon(void);
void do_sko_rayon2(void);
void start_sko_rayon(int x,short y);
void start_sko_rayon2(int param_1,short param_2);
void lance_pince(Obj *param_1);
undefined4 sko_get_eject_sens(void);
void DO_SOL_ENFONCE(void);
void DO_SKO_PHASE_0(Obj *param_1);
void DO_SKO_PHASE_1(Obj *obj);
void DO_SKO_PHASE_2(Obj *obj);
void DO_SKO_PHASE_3(Obj *obj);
void DO_SKO_PINCE(Obj *obj);
void DO_SCORPION_COLLISION(Obj *param_1);
void DO_SCORPION_MORT(Obj *obj);
void DO_SKO(Obj *obj);
void SKO_ray_in_zone(Obj *obj);
void DO_SKO_HIT(Obj *obj);
bool MURDUR(short param_1,short param_2);
int dist_to_bloc_floor(ushort type,int x,int y);
int bloc_floor(ushort param_1,short param_2,short param_3);
undefined4 calc_typ_trav(Obj *obj,byte param_2);
undefined calc_typ_travd(Obj *obj,bool param_2);
void TEST_FIN_BLOC(Obj *obj);
undefined4 TEST_IS_ON_RESSORT_BLOC(Obj *obj);
int IS_ON_RESSORT_BLOC(Obj *obj);
void CALC_MOV_ON_BLOC(Obj *obj);
void recale_position(Obj *param_1);
void getIdealStingCoords(int param_1,short *param_2,short *param_3);
bool closeEnoughToSting(Obj *param_1,ushort param_2,ushort param_3);
void PS1_setBossScrollLimits_moskito(Obj *param_1);
bool moskitoCanAttak(Obj *obj);
int setMoskitoAtScrollBorder(Obj *obj,int param_2);
void prepareNewMoskitoAttack(Obj *obj);
Obj * allocateMoskitoFruit(Obj *param_1);
void moskitoDropFruitOnRay(Obj *param_1);
void doMoskitoCommand(Obj *obj);
byte tellNextMoskitoAction(void);
void changeMoskitoPhase(Obj *obj);
void doMoskitoHit(Obj *obj);
void DO_BAT_FLASH(int x,int y);
void DO_BAT_LEFT_FLASH(Obj *param_1);
void DO_BAT_RIGHT_FLASH(Obj *param_1);
void DO_BAT_LEFT_RIGHT_FLASH(Obj *param_1);
bool bat_dir(Obj *param_1);
void bat_init_scroll(Obj *param_1);
void bat_done_scroll(void);
void DO_BAT_COMMAND(Obj *obj);
void BAT_ray_in_zone(Obj *obj);
void DO_BAT_POING_COLLISION(Obj *obj);
int bat_get_eject_sens(Obj *param_1);
void DO_PIRATE_POELLE(Obj *obj);
void DO_PIRATE_POELLE_POING_COLLISION(Obj *obj);
void PIRATE_POELLE_REACT(Obj *obj);
void PlaceDarkPhase1et2(Obj *obj);
void dark_attaque_suivante(void);
void init_vitraux(void);
undefined4 poing_face_obj(Obj *obj);
void DARK_phase1(Obj *obj);
void DARK_phase3(Obj *obj);
void DO_DARK_COMMAND(Obj *obj);
void DO_DARK_POING_COLLISION(Obj *obj);
void DO_DARK_REACT(Obj *obj);
void DO_DARK_SORT_COMMAND(Obj *param_1,short param_2);
void DO_DARK_SORT_COLLISION(Obj *obj);
void allocate_DARK_SORT(short x,short y,undefined1 sub_etat,short iframes);
void corde_en_bas(void);
void corde_en_haut(bool param_1);
void init_corde(Obj *obj);
void goto_phase1(Obj *obj);
void goto_phase2(Obj *obj);
void goto_phase3(Obj *param_1);
void goto_phase5(Obj *obj);
void DO_VITRAIL_COMMAND(Obj *obj);
bool test_block_chdir(Obj *obj,short *param_2,short offX,short offY);
void DO_MOVING_WITH_INDICATOR_COMMAND(Obj *obj);
void DO_IDC_COMMAND(Obj *obj);
void DO_LEV_POING_COLLISION(Obj *obj);
void START_UFO(Obj *obj);
void allocateSTOSKO(void);
void allocateMOSKITOMAMA(void);
void allocateMOSKITOSAXO(void);
void doMOSAMScommand(Obj *obj);
void allocateStoskoClaw(Obj *param_1);
void doSTOSKOcommand(Obj *obj);
void doBBF2command(Obj *obj,ushort param_2);
void DO_HYB_BBF2_POING_COLLISION(Obj *obj);
void AllocateTirBBF2(Obj *obj);
void DO_HYB_BBF2_LAS(Obj *param_1);
int OBJ_IN_COL_ZDC(Obj *obj1,Obj *obj2);
void AllocateDarkPhase2(Obj *obj);
void DO_DARK2_AFFICHE_TEXT(void);
void DO_DARK_PHASE2_COMMAND(Obj *obj);
void DO_DARK2_SORT_COMMAND(Obj *param_1);
void allocate_DARK2_SORT(short param_1,short param_2,undefined1 param_3,short param_4);
void DoFlammeCommand(Obj *obj);
void AllocateFlammes(short param_1);
void AllocateToons(void);
void DO_DARK2_TOONS_COMMAND(Obj *obj);
void ToonDonnePoing(Obj *obj);
void ngaweFollowsShip(Obj *obj);
void ngaweTriesToGrabShip(Obj *obj);
void allocatePirateNgaweRing(Obj *param_1,short param_2,char param_3);
void DO_NGW_TIR(Obj *obj);
void NGW_REACT_TO_RAY_IN_ZONE(Obj *obj);
void DO_ONE_NGW_COMMAND(Obj *obj);
void DO_NGW_POING_COLLISION(Obj *obj);
void DO_ONE_NGW_RING_COMMAND(Obj *obj);
void PS1_Init_ImgLdrVdoTrk_Files(void);
void FUN_8019dd74(void);
void FUN_8019deac(void);
void FUN_8019df1c(int param_1);
void LOAD_BIG_RAYMAN(void);
void LOAD_ALL_FIX(void);
void load_world(short worldIndex);
void load_level(void);
void LOAD_FND(void);
void PS1_LoadImgWorld(void);
void PS1_LoadVideoTables(void);
void PS1_LoadFont(void);
void LOAD_SCREEN(void);
void FUN_8019e914(void);
void LOAD_CONTINUE_SCREEN(void);
void PS1_LoadImgSplash(void);
void LOAD_SAVE_SCREEN(void);
void FUN_8019eb30(void);
void FUN_8019ebc0(void);
void LOAD_CREDITS_VIGNET(void);
void LOAD_VIGNET_GAME(void);
void PS1_CheckPauseAndCheatInputs(void);
bool FUN_8019f848(void);
bool FUN_8019f88c(void);
void FUN_8019f8d0(void);
bool PS1_OldLoadingScreen(void);
void FUN_8019fa94(char param_1);
void FUN_8019fb84(void);
void FUN_8019fd40(void);
bool FUN_8019fda0(void);
void FUN_8019fdd0(void);
void FUN_8019fe8c(void);
void PS1_SetLevelto_4_1(void);
void FIRST_INIT(void);
void DEPART_WORLD(void);
void DEPART_LEVEL(void);
void DEPART_DEAD_LOOP(void);
void FIN_DEAD_LOOP(void);
void PS1_StopLevelMusic(void);
void PS1_InitDisplay(Display *display);
void FUN_801a0750(void);
void PS1_itoa(short param_1,char *param_2,byte param_3);
void FUN_801a07b0(void);
void PS1_PlayMapIntro(void);
void PS1_PromptCardInput(void);
bool PS1_PromptCardYesNo(void);
bool PS1_PromptCardContinue(void);
bool PS1_PleaseInsertPad(void);
void PS1_CheckCardChanged(void);
void FUN_801a0c68(void);
void PS1_SetNoCard(void);
void PS1_DoYouHaveCard(void);
void PS1_PromptCardFormat(void);
void PS1_GetNbreSave1(void);
void FUN_801a10a4(void);
bool PS1_ReadingMemoryCard(void);
void FUN_801a1110(void);
void PS1_PromptPad(void);
void PS1_PromptCardErase(void);
bool PS1_PromptSaveWldMap(void);
bool PS1_PromptQuit(void);
void PS1_EncryptPassword(void);
bool PS1_VerifyDecryptPassword(void);
void FUN_801a17c8(uint param_1);
char PS1_GetLevelFromPassword(void);
void PS1_GeneratePassword_LivesCount(uint livesCount);
char PS1_GetLivesFromPassword(void);
void PS1_GeneratePassword_nbContinue(uint param_1);
char PS1_GetContinuesFromPassword(void);
undefined PS1_ValidatePassword(void);
char PS1_GeneratePassword(void);
void PS1_LoadSaveFromPassword(void);
char PS1_AttemptLoadSaveFromPassword(void);
void PS1_UnusedGenerateAndPrintPassword(short param_1,short param_2,byte param_3,uint param_4);
void PS1_ClearPassword(void);
void FUN_801a2c78(void);
void FUN_801a2d40(void);
void FUN_801a3064(void);
undefined4 PS1_MenuPassword(void);
void FUN_801a3550(void);
void PS1_GenerateAndDisplayPassword(void);
void DEPART_INIT_LOOP(void);
void DO_MENU(void);
void PS1_ShowDemoText(void);
bool PS1_DemoLoop(void);
void PS1_PlayDemo(void);
void PS1_TextBoxCardOrPassword(void);
void PS1_InputCardOrPassword(void);
void PS1_DisplayCardOrPassword(void);
undefined4 PS1_MenuCardOrPassword(void);
void PS1_InitCardOrPassword(void);
undefined4 saisie_nom_prg(void);
undefined4 selection_save_option_prg(void);
void DO_SAVE_CHOICE(void);
void AFFICHE_ECRAN_SAVE(void);
undefined4 PS1_DoGameOptionsLoop(void);
void PS1_DoGameOptions(void);
void AFFICHE_PAD_SCREEN(void);
void INIT_SAVE_CHOICE(void);
void INIT_SAVE_CONTINUE(void);
void DO_COMMANDE_SAVE(void);
void SELECTION_SAVE_OPTION(void);
void INIT_AFFICHE_ECRAN_SAVE(void);
void SAISIE_NOM(void);
void REALISATION_ACTION(void);
void FUN_801a6808(void);
void FUN_801a6984(void);
void FUN_801a6a04(char param_1);
void DO_COMMANDE_PAD(void);
void FUN_801a76e4(void);
undefined4 PadInit(int param_1);
undefined4 FUN_801a798c(int param_1);
uint FUN_801a7a04(short param_1);
void PadStop(void);
char * FUN_801a7b04(void);
void FUN_801a7b10(void);
void _boot(void);
void * memset(void *ptr,int value,size_t num);
void * memcpy(void *destination,void *source,size_t num);
char * strcat(char *dest,char *src);
int printf(char *fmt,...);
int strlen(char *s);
int strcmp(char *s1,char *s2);
char * strcpy(char *dest,char *src);
void * memmove(void *destination,void *source,size_t num);
int sprintf(char *buffer,char *fmt,...);
void * memchr(void *ptr,int value,size_t num);
int strncmp(char *s1,char *s2,int n);
char * strncpy(char *dest,char *src,int n);
int rand(void);
void exit(void);
void CdReset(void);
int CdSync(int mode,u_char *result);
int CdReady(int mode,u_char *result);
int CdReadSync(int mode,u_char *result);
int CdSetDebug(int level);
char * CdComstr(u_char com);
void SYS_OBJ_C8(void);
char * CdIntstr(u_char intr);
void SYS_OBJ_100(void);
u_long CdSyncCallback(void *func);
u_long CdReadyCallback(void *func);
u_long CdReadCallback(void *func);
void cd_cw_lower(byte param_1,int param_2,undefined4 param_3,undefined4 param_4);
void SYS_OBJ_234(void);
void SYS_OBJ_248(void);
int CdControl(u_char com,u_char *param,u_char *result);
int CdControlF(u_char com,u_char *param);
int CdControlB(u_char com,u_char *param,u_char *result);
void SYS_OBJ_2F8(void);
int CdGetSector(void *madr,int size);
int CdRead(int sectors,u_long *buf,int mode);
undefined4 SYS_OBJ_36C(undefined4 param_1,undefined4 param_2,undefined param_3);
undefined4 SYS_OBJ_3D0(void);
void SYS_OBJ_3E0(void);
int CdMix(CdlATV *vol);
int CdRead2(long mode);
CdlLOC * CdIntToPos(int i,CdlLOC *p);
int CdPosToInt(CdlLOC *p);
void rescpy(undefined *param_1,undefined *param_2);
void set_alarm(void);
undefined4 get_alarm(void);
void BIOS_OBJ_D8(void);
void pollintr(void);
void callback(void);
void BIOS_OBJ_1E0(void);
undefined4 getintr(void);
void BIOS_OBJ_4A0(void);
void BIOS_OBJ_540(void);
void BIOS_OBJ_560(void);
void BIOS_OBJ_580(void);
void BIOS_OBJ_590(void);
void BIOS_OBJ_59C(void);
void BIOS_OBJ_5D0(void);
void BIOS_OBJ_640(void);
undefined4 CD_sync(int param_1,undefined4 param_2);
void BIOS_OBJ_6E4(void);
undefined4 CD_ready(int param_1,undefined4 param_2);
void BIOS_OBJ_774(void);
int CD_cw_upper(byte param_1,undefined *param_2,undefined4 param_3,int param_4);
void BIOS_OBJ_9F4(void);
undefined4 CD_vol(undefined *param_1);
int CD_init(void);
undefined4 CD_readm(undefined4 address,int size,undefined4 param_3);
undefined4 BIOS_OBJ_BFC(undefined4 param_1);
void BIOS_OBJ_CDC(void);
int CD_readsync(int param_1,undefined4 param_2);
void cb_read(int param_1,undefined4 param_2);
void BIOS_OBJ_E40(void);
undefined4 CD_read_upper(undefined4 param_1,uint param_2);
void CD_set_test_parmnum(undefined4 param_1);
void CdInit(void);
void EVENT_OBJ_78(void);
void CdInitFileSystem(void);
void def_cbsync(void);
void def_cbready(void);
void def_cbread(void);
void StSetRing(u_long *ring_addr,u_long ring_size);
void StClearRing(void);
void StUnSetRing(void);
void data_ready_callback(void);
void StSetStream(u_long mode,u_long start_frame,u_long end_frame,void *func1,void *func2);
void StSetEmulate(u_long *addr,u_long mode,u_long start_frame,u_long end_frame,void *func1,void *func2);
u_long StFreeRing(u_long *base);
void CDROM_OBJ_2E0(void);
void init_ring_status(int param_1,uint param_2);
u_long StGetNext(u_long **addr,u_long **header);
void StSetMask(u_long mask,u_long start,u_long end);
void StCdInterrupt(void);
void CDROM_OBJ_6CC(void);
void CDROM_OBJ_7F4(void);
void CDROM_OBJ_BEC(void);
void CDROM_OBJ_C8C(void);
void CDROM_OBJ_D4C(void);
void CDROM_OBJ_D9C(void);
void dma_execute(uint param_1,dword param_2,int param_3,uint param_4,dword param_5,int param_6,int param_7);
void CDROM_OBJ_E38(int param_1,undefined4 param_2);
void CDROM_OBJ_EB0(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void mem2mem(undefined4 *param_1,undefined4 *param_2,uint param_3);
undefined4 StSetChannel(uint param_1);
void CDROM_OBJ_F84(void);
undefined4 null(void);
void _96_vec(void);
void _96_CdSeekL(u_char *param_1);
void _96_CdStop(void);
void _96_CdGetStatus(u_char *param_1);
bool _96_CdRead(int param_1,u_long *param_2,int param_3);
CdlFILE * CdSearchFile(CdlFILE *$30,char *name);
undefined4 ISO9660_OBJ_F0(void);
void ISO9660_OBJ_2C4(void);
bool _cmp(char *param_1,char *param_2);
undefined4 CD_newmedia(void);
void ISO9660_OBJ_5E8(void);
undefined4 CD_searchdir(int param_1,char *param_2);
void ISO9660_OBJ_6A4(void);
undefined4 CD_cachefile(int param_1);
undefined4 ISO9660_OBJ_84C(void *param_1);
undefined4 ISO9660_OBJ_868(void);
void ISO9660_OBJ_96C(void);
void * memcpy(void *destination,void *source,size_t num);
bool cd_read_lower(int param_1,int param_2,u_long *param_3);
long _card_load(long chan);
long _card_info(long chan);
long _card_auto(long val);
long _card_write(long chan,long block,uchar *buf);
void InitCARD(long val);
long StartCARD(void);
void _new_card(void);
void __main(void);
uint start(void);
uint stup1(void);
uint stup0(void);
uint SpuVmAlloc(void);
void SpuVmKeyOnNow(undefined4 param_1,undefined2 param_2);
void FUN_801ac400(void);
byte FUN_801ac4d0(int param_1,int param_2);
void SpuVmDoAllocate(void);
void vmNoiseOn(uint param_1);
void vmNoiseOn2(uint param_1,undefined2 param_2,undefined2 param_3);
void FUN_801acc7c(uint param_1);
uint note2pitch(void);
uint note2pitch2(int param_1,uint param_2);
void FUN_801ace80(uint param_1,short param_2);
void FUN_801ad064(void);
void FUN_801ad06c(void);
void FUN_801ad07c(short param_1,short param_2,short param_3);
void FUN_801ad0b0(short param_1);
void SpuVmInit(byte param_1);
void SpuVmNoiseOnWithAdsr(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4);
void SpuVmNoiseOff(void);
void SpuVmNoiseOn(undefined2 param_1,undefined2 param_2);
int SpuVmPBVoice(ushort param_1,short param_2,short param_3,int param_4);
void SpuVmFlush(void);
uint SpuVmKeyOn(ushort param_1,short param_2,short param_3,undefined2 param_4,short param_5,undefined param_6);
char SpuVmKeyOff(short param_1,short param_2,short param_3,uint param_4);
void SpuVmSeKeyOn(short param_1,short param_2,undefined2 param_3,undefined4 param_4,ushort param_5,ushort param_6);
void SpuVmSeKeyOff(short param_1,short param_2,undefined2 param_3);
uint SpuVmSetSeqVol(uint param_1,short param_2,short param_3,short param_4);
int SpuVmGetSeqVol(uint param_1,undefined2 *param_2,undefined2 *param_3);
int FUN_801ae39c(uint param_1);
int FUN_801ae3d4(uint param_1);
int FUN_801ae40c(uint param_1,undefined2 *param_2);
void SpuVmSeqKeyOff(short param_1);
uint SpuVmSetProgVol(short param_1,short param_2,undefined param_3);
uint SpuVmGetProgVol(short param_1,short param_2);
uint SpuVmSetProgPan(short param_1,short param_2,undefined param_3);
uint SpuVmGetProgPan(short param_1,short param_2);
uint SsUtKeyOn(short vabId,short prog,short tone,short note,short fine,short voll,short volr);
undefined4 SsUtKeyOff(ushort param_1,short param_2,short param_3,short param_4,short param_5);
int SsUtKeyOnV(ushort param_1,short param_2,ushort param_3,byte param_4,short param_5,short param_6,short param_7,short param_8);
undefined4 FUN_801aefa4(ushort param_1);
int SsUtPitchBend(undefined4 param_1,short param_2,short param_3,undefined4 param_4,short param_5);
undefined4 SsUtChangePitch(ushort param_1,short param_2,short param_3,short param_4,undefined4 param_5,short param_6,short param_7);
undefined4 SsUtChangeADSR(ushort param_1,short param_2,short param_3,short param_4,undefined2 param_5,undefined2 param_6);
undefined4 SsUtGetDetVVol(ushort param_1,undefined2 *param_2,undefined2 *param_3);
undefined4 SsUtSetDetVVol(ushort param_1,undefined2 param_2,undefined2 param_3);
undefined4 SsUtGetVVol(ushort param_1,short *param_2,short *param_3);
undefined4 SsUtSetVVol(ushort param_1,short param_2,short param_3);
undefined4 FUN_801af4a8(ushort param_1);
undefined4 FUN_801af4c4(ushort param_1);
void SsUtAllKeyOff(void);
undefined4 SpuVmVSetUp(ushort param_1,short param_2);
void VM_VSU_OBJ_CC(void);
void SsSeqSetVol(short param_1,short param_2,short param_3);
void SsSepSetVol(short param_1,short param_2,short param_3,short param_4);
void Snd_SetVol(short param_1,short param_2,short param_3,short param_4);
void _SsInit(int param_1);
void SSINIT_OBJ_38(undefined4 param_1,undefined4 param_2,uint param_3);
void SsInit(void);
void SsInitHot(void);
void SsSetTableSize(char *param_1,short param_2,short param_3);
void SsSetTickMode(long param_1);
void SSINIT_OBJ_330(void);
void SSINIT_OBJ_3B0(void);
void _wait(void);
void _SsStart(int param_1);
void SSINIT_OBJ_550(void);
void SSINIT_OBJ_5F0(void);
void SSINIT_OBJ_62C(EvDesc param_1);
void SSINIT_OBJ_658(void);
void SsStart(void);
void SsStart2(void);
void SsEnd(void);
void SsQuit(void);
void SsSetMono(void);
void SsSetStereo(void);
void SsSetTempo(short param_1,short param_2,short param_3);
void SSADD_OBJ_14C(int param_1);
void SsSetLoop(short param_1,short param_2,short param_3);
short SsIsEos(short param_1,short param_2);
void SsSetMarkCallback(short param_1,short param_2,SsMarkCallbackProc param_3);
void SsUtReverbOn(void);
void SsUtReverbOff(void);
short SsUtSetReverbType(short param_1);
void UT_REV_OBJ_90(void);
short SsUtGetReverbType(void);
void SsUtSetReverbDepth(short param_1,short param_2);
void SsUtSetReverbFeedback(short param_1);
void SsUtSetReverbDelay(short param_1);
void SsSeqSetCrescendo(short param_1,short param_2,long param_3);
void SsSepSetCrescendo(short param_1,short param_2,short param_3,long param_4);
void Snd_setvol_data(int param_1,short param_2,short param_3,uint param_4);
void VOL_OBJ_C4(void);
short SsVabOpenHead(uchar *param_1,short param_2);
short SsVabOpenHeadSticky(uchar *param_1,short param_2,ulong param_3);
short SsVabFakeHead(uchar *param_1,short param_2,ulong param_3);
void SsVabOpenHeadWithMode(uint *param_1,ushort param_2,short param_3,long param_4);
void VS_VH_OBJ_19C(void);
void VS_VH_OBJ_1AC(void);
void VS_VH_OBJ_398(void);
void VS_VH_OBJ_460(uint param_1,int *param_2,int param_3,int param_4);
void VS_VH_OBJ_4A0(void);
void SsSetMVol(short param_1,short param_2);
short SsVabTransBody(uchar *param_1,short param_2);
void VS_VTB_OBJ_B4(void);
short SsSeqOpen(ulong *param_1,short param_2);
void SSOPEN_OBJ_A0(void);
short SsSepOpen(ulong *param_1,short param_2,short param_3);
void SSOPEN_OBJ_1AC(void);
int InitSoundSep(ushort param_1,short param_2,undefined2 param_3,int param_4);
int SEPINIT_OBJ_118(void);
int SEPINIT_OBJ_1D8(void);
int SEPINIT_OBJ_36C(void);
void InitSoundSeq(ushort param_1,undefined2 param_2,char *param_3);
void SEQINIT_OBJ_1DC(void);
void SEQINIT_OBJ_328(void);
void SEQINIT_OBJ_334(void);
void _SsSeqPlay(int param_1,short param_2);
void _SsGetSeqData(short param_1,short param_2);
void _SsNoteOn(short param_1,short param_2,undefined param_3,uint param_4);
void _SsSetProgramChange(short param_1,short param_2,undefined param_3);
void _SsSetControlChange(ushort param_1,short param_2,byte param_3);
void _SsContModulation(ushort param_1,short param_2,uchar param_3);
void _SsContPortaTime(ushort param_1,short param_2,uchar param_3);
void _SsContPortamento(ushort param_1,short param_2,byte param_3);
void _SsContResetAll(short param_1,short param_2);
void _SsContNrpn1(ushort param_1,short param_2,undefined param_3);
void _SsContNrpn2(short param_1,short param_2,char param_3);
void _SsContRpn1(short param_1,short param_2,undefined param_3);
void _SsContRpn2(short param_1,short param_2,undefined param_3);
void _SsContDataEntry(short param_1,short param_2,undefined param_3);
void _SsSndSetVabAttr(short param_1,short param_2,short param_3,undefined4 param_4);
void _SsSetPitchBend(short param_1,short param_2);
void _SsGetMetaEvent(short param_1,short param_2,char param_3);
int _SsReadDeltaValue(int param_1,short param_2);
void Snd_nextseq(short param_1,short param_2);
void SsUtResolveADSR(uint param_1,uint param_2,ushort *param_3);
void SsUtBuildADSR(ushort *param_1,ushort *param_2,ushort *param_3);
short SsUtGetVagAtr(short param_1,short param_2,short param_3,VagAtr *param_4);
void UT_GVA_OBJ_228(void);
short SsUtSetVagAtr(short param_1,short param_2,short param_3,VagAtr *param_4);
void UT_SVA_OBJ_1B4(void);
void SpuVmDamperOn(void);
short SsUtGetProgAtr(short param_1,short param_2,ProgAtr *param_3);
void UT_GPA_OBJ_F4(void);
void SpuVmDamperOff(void);
void SsSeqPlay(short param_1,char param_2,short param_3);
void SsSepPlay(short param_1,short param_2,char param_3,short param_4);
void SsPlayBack(short param_1,short param_2,short param_3);
void Snd_SetPlayMode(short param_1,short param_2,char param_3,undefined2 param_4);
void SSPLAY_OBJ_21C(void);
void SsSetSerialVol(char param_1,short param_2,short param_3);
short SsVabTransCompleted(short param_1);
void SsSeqStop(short param_1);
void SsSepStop(short param_1,short param_2);
void Snd_stop(short param_1,short param_2);
void SsSeqCalledTbyT(void);
void Snd_decrescendo(ushort param_1,short param_2);
void DECRE_OBJ_348(void);
void DECRE_OBJ_3B4(void);
void DECRE_OBJ_3C8(void);
void DECRE_OBJ_3D8(void);
void Snd_replay(int param_1,short param_2);
void Snd_play(short param_1,short param_2);
void Snd_crescendo(ushort param_1,short param_2);
void CRES_OBJ_348(void);
void CRES_OBJ_3B4(void);
void CRES_OBJ_3C8(void);
void CRES_OBJ_3D8(void);
void Snd_pause(short param_1,short param_2);
void Snd_nextpause(int param_1,short param_2);
void Snd_tempo(int param_1,short param_2);
void TEMPO_OBJ_D8(undefined4 param_1,short param_2,int param_3,int param_4);
void TEMPO_OBJ_E4(undefined4 param_1,short param_2,int param_3,int param_4);
void SsVabClose(short param_1);
short SsVabOpen(uchar *param_1,VabHdr *param_2);
void SsSeqClose(short param_1);
void SsSepClose(short param_1);
void SsSetSerialAttr(char param_1,char param_2,char param_3);
void _SpuInit(undefined4 param_1);
void SpuInit(void);
void SpuInitHot(void);
void SpuStart(void);
void SpuQuit(void);
void _spu_reset(void);
undefined4 _spu_init(int param_1);
undefined4 FUN_801b5660(void);
undefined4 FUN_801b5688(void);
void FUN_801b56b0(void);
void FUN_801b56e0(void);
undefined4 _spu_write(undefined4 param_1,undefined4 param_2);
void _spu_writeByIO(undefined2 *param_1,uint param_2);
undefined4 FUN_801b5978(undefined4 param_1,undefined4 param_2);
void FUN_801b5a2c(undefined4 param_1,uint param_2);
void _spu_r_(undefined4 param_1,uint param_2);
void _spu_t(undefined4 param_1,undefined2 param_2,int param_3);
bool FUN_801b5d30(undefined4 param_1,uint param_2,uint *param_3);
void FUN_801b6544(uint *param_1);
undefined4 FUN_801b66c8(uint *param_1);
undefined4 FUN_801b6b98(uint *param_1);
undefined4 FUN_801b6f30(int param_1);
undefined4 FUN_801b705c(int param_1,undefined2 param_2);
undefined2 FUN_801b7078(int param_1);
void _memcpy(void);
long SpuSetReverbModeParam(SpuReverbAttr *attr);
undefined4 S_SRMP_OBJ_1A0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5,undefined4 param_6);
undefined4 S_SRMP_OBJ_1B0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5,undefined4 param_6);
undefined4 S_SRMP_OBJ_2DC(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5);
void S_SRMP_OBJ_350(void);
undefined4 S_SRMP_OBJ_3AC(undefined4 param_1);
undefined4 S_SRMP_OBJ_460(void);
undefined4 S_SRMP_OBJ_484(void);
void S_SRMP_OBJ_4F0(void);
void _gcSPU(uint param_1,uint *param_2);
void S_M_INT_OBJ_50(uint param_1,uint *param_2,int param_3,uint *param_4);
void S_M_INT_OBJ_270(void);
long SpuInitMalloc(long num,char *top);
void S_M_INT_OBJ_364(void);
long SpuMalloc(long size);
uint S_M_INT_OBJ_3C8(int param_1);
undefined4 S_M_INT_OBJ_494(void);
void S_M_INT_OBJ_610(void);
int _SpuMallocSeparateTo3(int param_1,int param_2,uint param_3);
void S_M_INT_OBJ_69C(void);
void S_M_INT_OBJ_6B8(void);
void S_M_INT_OBJ_794(void);
void S_M_INT_OBJ_824(void);
void S_M_INT_OBJ_96C(void);
long SpuMallocWithStartAddr(ulong addr,long size);
undefined4 S_M_INT_OBJ_9D8(uint param_1,int param_2);
void S_M_INT_OBJ_AF8(void);
undefined4 S_M_INT_OBJ_B28(int param_1,undefined4 param_2,undefined4 param_3,uint param_4);
undefined4 S_M_INT_OBJ_C00(void);
void S_M_INT_OBJ_C0C(void);
void S_M_INT_OBJ_C18(void);
undefined4 _SpuIsInAllocateArea(uint param_1);
undefined4 S_M_INT_OBJ_C48(uint param_1,uint *param_2,uint param_3,uint param_4);
void _SpuIsInAllocateArea_(int param_1);
void SpuFree(ulong addr);
void S_M_INT_OBJ_D2C(void);
void _print(void);
long SpuClearReverbWorkArea(long mode);
undefined4 S_CRWA_OBJ_DC(void);
void S_CRWA_OBJ_124(void);
long SpuSetReverb(long on_off);
undefined4 S_SR_OBJ_7C(void);
undefined4 S_SR_OBJ_94(void);
long SpuIsTransferCompleted(long flag);
void S_ITC_OBJ_9C(void);
void _spu_setInTransfer(int param_1);
void S_ITC_OBJ_D4(void);
bool _spu_getInTransfer(void);
long SpuSetTransferMode(long mode);
void S_STM_OBJ_28(undefined4 param_1);
ulong SpuSetTransferStartAddr(ulong addr);
void S_STSA_OBJ_40(void);
ulong SpuRead(uchar *addr,ulong size);
long CloseEvent(ulong event);
void EnterCriticalSection(void);
int close(int fd);
int write(int fd,char *buf,int n);
long EnableEvent(ulong event);
long InitPAD(char *bufA,long lenA,char *bufB,long lenB);
long delete(char *name);
void StopPAD(void);
long format(char *fs);
long SetRCnt(ulong spec,ushort target,long mode);
undefined4 COUNTER_OBJ_74(void);
void COUNTER_OBJ_94(void);
long GetRCnt(ulong spec);
void COUNTER_OBJ_CC(void);
long StartRCnt(ulong spec);
long StopRCnt(ulong spec);
long ResetRCnt(ulong spec);
void COUNTER_OBJ_168(void);
long DisableEvent(long event);
void DeliverEvent(ulong ev1,ulong ev2);
long StartPAD(void);
void ChangeClearPAD(long val);
void InitHeap(ulong *head,ulong size);
void _bu_init(void);
DIRENTRY * nextfile(DIRENTRY *dir);
long OpenEvent(EvDesc desc,EvSpec spec,EvMode mode,long *func);
long read(long fd,void *buf,long n);
long TestEvent(long event);
void ExitCriticalSection(void);
long open(char *devname,ulong flag);
void _96_remove(void);
DIRENTRY * firstfile(char *name,DIRENTRY *dir);
void DecDCTinCallback(undefined4 param_1);
void DecDCToutCallback(undefined4 param_1);
void CdDataCallback(undefined4 param_1);
void SpuDataCallback(undefined4 param_1);
void PioDataCallback(undefined4 param_1);
void CdCallback(undefined4 param_1);
void SpuCallback(undefined4 param_1);
void PioCallback(undefined4 param_1);
code * VBLNKInit(void);
void VBLNKStop(void);
void intVBLNK(void);
int setVBLNKCallback(int param_1);
void ChangeClearRCnt(void);
void ResetCallback(void);
void InterruptCallback(void);
void DMACallback(void);
void VSyncCallback(void *func);
void StopCallback(void);
int CheckCallback(void);
void intInit(void);
void INTR_OBJ_298(void);
int setIntCallback(uint param_1,int param_2,undefined4 param_3,int param_4);
undefined4 INTR_OBJ_3BC(void);
void stopInit(void);
void setjmp(void);
void HookEntryInt(void);
void ReturnFromException(void);
code * DMAInit(void);
void DMAStop(void);
void intDMA(void);
int setDMACallback(uint param_1,int param_2,undefined4 param_3,int param_4);
undefined4 INTR_DMA_OBJ_29C(void);
uint VSync(int param_1);
void VSYNC_OBJ_F0(void);
void v_wait(int param_1);
void VSYNC_OBJ_17C(void);
MATRIX * CompMatrix(MATRIX *m0,MATRIX *m1,MATRIX *m2);
MATRIX * MulMatrix0(MATRIX *m0,MATRIX *m1,MATRIX *m2);
MATRIX * MulRotMatrix0(MATRIX *m0,MATRIX *m1);
MATRIX * MulMatrix(MATRIX *m0,MATRIX *m1);
MATRIX * MulMatrix2(MATRIX *m0,MATRIX *m1);
MATRIX * MulRotMatrix(MATRIX *m0);
MATRIX * SetMulMatrix(MATRIX *m0,MATRIX *m1);
VECTOR * ApplyMatrix(MATRIX *m,SVECTOR *$2,VECTOR *$3);
undefined2 * ApplyMatrixSV(undefined4 *param_1,SVECTOR *param_2,undefined2 *param_3);
VECTOR * ApplyMatrixLV(MATRIX *m,VECTOR *$2,VECTOR *$3);
VECTOR * ApplyRotMatrix(SVECTOR *$2,VECTOR *$3);
MATRIX * TransMatrix(MATRIX *m,VECTOR *v);
MATRIX * ScaleMatrix(MATRIX *m,VECTOR *v);
MATRIX * ScaleMatrixL(MATRIX *m,VECTOR *v);
void SetRotMatrix(MATRIX *m);
void SetLightMatrix(MATRIX *m);
void SetColorMatrix(MATRIX *m);
void SetTransMatrix(MATRIX *m);
void PushMatrix(void);
void PopMatrix(void);
void ReadRotMatrix(MATRIX *m);
void ReadLightMatrix(MATRIX *m);
void ReadColorMatrix(MATRIX *m);
long RotTransPers(SVECTOR *$2,long *sxy,long *p,long *flag);
long RotTransPers3(SVECTOR *$2,SVECTOR *$3,SVECTOR *v2,long *sxy0,long *sxy1,long *sxy2,long *p,long *flag);
void RotTrans(SVECTOR *$2,VECTOR *$3,long *flag);
void RotTrans0(SVECTOR *param_1,undefined4 param_2,undefined4 *param_3);
void LocalLight(SVECTOR *$2,VECTOR *$3);
void LightColor(VECTOR *$2,VECTOR *$3);
void DpqColorLight(VECTOR *$2,CVECTOR *$3,long p,CVECTOR *v2);
void DpqColor(CVECTOR *$2,long p,CVECTOR *$3);
void DpqColor3(CVECTOR *$2,CVECTOR *$3,CVECTOR *v2,long p,CVECTOR *v3,CVECTOR *v4,CVECTOR *v5);
void Intpl(VECTOR *$2,long p,CVECTOR *$3);
VECTOR * Square12(VECTOR *$2,VECTOR *$3);
VECTOR * Square0(VECTOR *$2,VECTOR *$3);
void NormalColor(SVECTOR *$2,CVECTOR *$3);
void NormalColor3(SVECTOR *$2,SVECTOR *$3,SVECTOR *v2,CVECTOR *v3,CVECTOR *v4,CVECTOR *v5);
void NormalColorDpq(SVECTOR *$2,CVECTOR *$3,long p,CVECTOR *v2);
void NormalColorDpq3(SVECTOR *$2,SVECTOR *$3,SVECTOR *v2,CVECTOR *v3,long p,CVECTOR *v4,CVECTOR *v5,CVECTOR *v6);
void NormalColorCol(SVECTOR *$2,CVECTOR *$3,CVECTOR *v2);
void NormalColorCol3(SVECTOR *$2,SVECTOR *$3,SVECTOR *v2,CVECTOR *v3,CVECTOR *v4,CVECTOR *v5,CVECTOR *v6);
void ColorDpq(VECTOR *$2,CVECTOR *$3,long p,CVECTOR *v2);
void ColorCol(VECTOR *$2,CVECTOR *$3,CVECTOR *v2);
long NormalClip(long sxy0,long sxy1,long sxy2);
undefined4 NormalClipS(void);
long AverageZ3(long sz0,long sz1,long sz2);
undefined4 AverageSZ3(void);
long AverageZ4(long sz0,long sz1,long sz2,long sz3);
undefined4 AverageSZ4(void);
void OuterProduct12(VECTOR *$2,VECTOR *$3,VECTOR *v2);
void OuterProduct0(VECTOR *$2,VECTOR *$3,VECTOR *v2);
long Lzc(long data);
void SetVertex0(SVECTOR *param_1);
void SetVertex1(SVECTOR *param_1);
void SetVertex2(SVECTOR *param_1);
void SetVertexTri(SVECTOR *param_1,SVECTOR *param_2,SVECTOR *param_3);
void SetRGBcd(CVECTOR *v);
void SetRGBfifo(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void SetIR123(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void SetIR0(undefined4 param_1);
void SetBackColor(long rbk,long gbk,long bbk);
void SetFarColor(long rfc,long gfc,long bfc);
void SetSZfifo3(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void SetSZfifo4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void SetSXSYfifo(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void SetRii(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void SetMAC123(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void SetData32(undefined4 param_1);
void SetGeomOffset(long ofx,long ofy);
void SetGeomScreen(long h);
void SetDQA(undefined4 param_1);
void SetDQB(undefined4 param_1);
undefined4 ReadOTZ(void);
undefined4 ReadIR0(void);
void ReadIR123(void);
void ReadSZ2(void);
void ReadSZfifo3(long *sz0,long *sz1,long *sz2);
void ReadSZfifo4(long *szx,long *sz0,long *sz1,long *sz2);
void ReadSXSYfifo(long *sxy0,long *sxy1,long *sxy2);
void ReadRGBfifo(CVECTOR *$2,CVECTOR *$3,CVECTOR *v2);
undefined4 ReadMac0(void);
void ReadMAC123(void);
void ReadORGB(uint *param_1);
undefined4 ReadLZC(void);
undefined4 ReadFLAG(void);
void ReadGeomOffset(long *ofx,long *ofy);
long ReadGeomScreen(void);
void InitGeom(void);
void LoadAverage12(VECTOR *$2,VECTOR *$3,long p0,long p1,VECTOR *v2);
void LoadAverage0(VECTOR *$2,VECTOR *$3,long p0,long p1,VECTOR *v2);
void LoadAverageShort12(SVECTOR *$2,SVECTOR *$3,long p0,long p1,SVECTOR *v2);
void LoadAverageShort0(SVECTOR *$2,SVECTOR *$3,long p0,long p1,SVECTOR *v2);
void LoadAverageByte(u_char *$2,u_char *$3,long p0,long p1,u_char *v2);
void LoadAverageCol(u_char *$2,u_char *$3,long p0,long p1,u_char *v2);
long VectorNormal(VECTOR *$2,VECTOR *$3);
void VectorNormalS(VECTOR *$2,SVECTOR *$3);
long SquareRoot0(long a);
long SquareRoot12(long a);
void InvSquareRoot(long a,long *b,long *c);
void gteMIMefunc(SVECTOR *otp,SVECTOR *dfp,long n,long p);
void InterpolShort(int *param_1,int *param_2,undefined4 param_3,uint *param_4);
void InterpolByte(byte *param_1,byte *param_2,undefined4 param_3,undefined *param_4);
MATRIX * TransposeMatrix(MATRIX *m0,MATRIX *m1);
MATRIX * RotMatrix(SVECTOR *r,MATRIX *m);
void FGO_OBJ_B4(int param_1,undefined2 *param_2);
void FGO_OBJ_11C(int param_1,undefined2 *param_2);
void FGO_OBJ_1B0(undefined4 param_1,undefined2 *param_2);
MATRIX * RotMatrixYXZ(SVECTOR *r,MATRIX *m);
void FGO_OBJ_344(int param_1,short *param_2);
void FGO_OBJ_3A8(int param_1,short *param_2);
void FGO_OBJ_43C(undefined4 param_1,short *param_2);
undefined2 * RotMatrixZYX(short *param_1,undefined2 *param_2);
void FGO_OBJ_5CC(int param_1,undefined2 *param_2);
void FGO_OBJ_634(int param_1,undefined2 *param_2);
void FGO_OBJ_6C8(undefined4 param_1,undefined2 *param_2);
MATRIX * RotMatrixX(long r,MATRIX *m);
void FGO_OBJ_858(undefined4 param_1,int param_2);
MATRIX * RotMatrixY(long r,MATRIX *m);
void FGO_OBJ_9F0(undefined4 param_1,short *param_2);
MATRIX * RotMatrixZ(long r,MATRIX *m);
void FGO_OBJ_B88(undefined4 param_1,short *param_2);
void FUN_801bc050(void);
int rsin(int a);
void GEO_OBJ_40(void);
uint sin_1(uint param_1);
void GEO_OBJ_100(void);
int rcos(int a);
void GEO_OBJ_1D4(void);
void SetFogFar(long a,long h);
void SetFogNear(long a,long h);
void EigenMatrix(short *param_1,undefined2 *param_2);
void GEO_OBJ_578(void);
void GEO_OBJ_598(void);
void GEO_OBJ_5AC(void);
void GEO_OBJ_5B8(long param_1);
void GEO_OBJ_5C8(long param_1,long param_2,long param_3,long param_4);
bool IsIdMatrix(short *param_1);
u_short GetTPage(int tp,int abr,int x,int y);
uint PRIM_OBJ_68(void);
u_short GetClut(int x,int y);
void DumpTPage(u_short tpage);
void PRIM_OBJ_114(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4);
void DumpClut(u_short clut);
void * NextPrim(void *p);
int IsEndPrim(void *p);
void AddPrim(void *ot,void *p);
void AddPrims(void *ot,void *p0,void *p1);
void CatPrim(void *p0,void *p1);
void TermPrim(void *p);
void SetSemiTrans(void *p,int abe);
void PRIM_OBJ_288(int param_1);
void SetShadeTex(void *p,int tge);
void PRIM_OBJ_2B0(int param_1);
void SetPolyF3(POLY_F3 *p);
void SetPolyFT3(POLY_FT3 *p);
void SetPolyG3(POLY_G3 *p);
void SetPolyGT3(POLY_GT3 *p);
void SetPolyF4(POLY_F4 *p);
void SetPolyFT4(POLY_FT4 *p);
void SetPolyG4(POLY_G4 *p);
void SetPolyGT4(POLY_GT4 *p);
void SetSprt8(SPRT_8 *p);
void SetSprt16(SPRT_16 *p);
void SetSprt(SPRT *p);
void SetTile1(TILE_1 *p);
void SetTile8(TILE_8 *p);
void SetTile16(TILE_16 *p);
void SetTile(TILE *p);
void SetBlockFill(BLK_FILL *p);
void SetLineF2(LINE_F2 *p);
void SetLineG2(LINE_G2 *p);
void SetLineF3(LINE_F3 *p);
void SetLineG3(LINE_G3 *p);
void SetLineF4(LINE_F4 *p);
void SetLineG4(LINE_G4 *p);
int MargePrim(void *p0,void *p1);
void PRIM_OBJ_4CC(void);
void DumpDrawEnv(DRAWENV *env);
void PRIM_OBJ_5F0(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4);
void DumpDispEnv(DISPENV *env);
void FUN_801bcf10(uint param_1);
uint ResetGraph(uint param_1);
undefined4 SetGraphReverse(int param_1);
undefined4 SetGraphDebug(int param_1);
undefined4 GetGraphType(void);
undefined4 GetGraphDebug(void);
undefined4 DrawSyncCallback(undefined4 param_1);
void SetDispMask(int param_1);
int DrawSync(int mode);
void ClearImage(RECT *rect,byte r,byte g,byte b);
void LoadImage(RECT *recp,u_long *p);
void StoreImage(undefined4 param_1,undefined4 param_2);
void MoveImage(undefined4 *param_1,uint vramX,int vramY);
uint * ClearOTag(uint *ot,int n);
undefined4 ClearOTagR(undefined4 param_1);
void DrawPrim(u_long *param_1);
void DrawOTag(u_long *param_1);
DRAWENV * PutDrawEnv(DRAWENV *param_1);
u_long * FUN_801bd63c(u_long *param_1);
DISPENV * PutDispEnv(DISPENV *param_1);
void GetDispEnv(undefined4 *param_1);
void SetTexWindow(int param_1,undefined4 param_2);
void SetDrawArea(int param_1,short *param_2);
void SetDrawOffset(int param_1,undefined2 *param_2);
void SetPriority(int param_1,int param_2,int param_3);
void SetDrawMode(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
void SetDrawEnv(DR_ENV *dr_env,DRAWENV *env);
uint get_mode(int param_1,int param_2,uint param_3);
uint get_cs(short param_1,uint param_2);
uint get_ce(short param_1,uint param_2);
uint get_ofs(uint param_1,uint param_2);
uint get_tw(byte *param_1);
uint get_dx(short *param_1);
undefined4 FUN_801be20c(void);
int _otc(int param_1,int param_2);
undefined4 _dws(short *param_1,undefined4 *param_2);
undefined4 _drs(undefined4 *param_1,undefined4 *param_2);
void FUN_801bead0(uint param_1);
uint FUN_801beb08(int param_1);
undefined4 _cwb(undefined4 *param_1,int param_2);
void _cwc(undefined4 param_1);
uint _param(uint param_1);
void FUN_801bebf8(undefined4 param_1,undefined4 param_2,undefined4 param_3);
uint FUN_801bec1c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);
undefined4 _exeque(void);
uint _reset(int param_1);
uint _sync(int param_1);
void set_alarm(void);
undefined4 SetGraphQueue(void);
void FUN_801bf470(undefined *param_1,undefined *param_2,int param_3);
void FUN_801bf4a0(undefined *param_1,undefined param_2,int param_3);
void GPU_cw(void);
u_short LoadTPage(u_long *pix,int tp,int abr,int x,int y,int w,int h);
u_short EXT_OBJ_A8(void);
u_short EXT_OBJ_AC(RECT *param_1);
u_short LoadClut(u_long *clut,int x,int y);
DRAWENV * SetDefDrawEnv(DRAWENV *env,int x,int y,int w,int h);
DISPENV * SetDefDispEnv(DISPENV *env,int x,int y,int w,int h);
void SetDumpFnt(int id);
void FntLoad(int tx,int ty);
int FntOpen(int x,int y,int w,int h,int isbg,int n);
void FONT_OBJ_378(void);
u_long * FntFlush(int id);
void * FONT_OBJ_500(void);
void * FONT_OBJ_550(void);
void * FONT_OBJ_560(void);
void FONT_OBJ_5D8(void);
int FntPrint(char *param_1,...);
undefined4 FONT_OBJ_784(undefined4 param_1,uint param_2,int param_3);
undefined4 FONT_OBJ_7D4(void);
undefined4 FONT_OBJ_854(void);
void FONT_OBJ_8C4(undefined4 param_1,undefined4 param_2);
void FONT_OBJ_8E8(void);
undefined4 FONT_OBJ_93C(undefined4 param_1,undefined4 param_2,int param_3);
undefined4 FONT_OBJ_940(undefined4 param_1,undefined4 param_2,int param_3);
void FONT_OBJ_9C8(void);
char * get_p_name(char param_1);
void OTAG_OBJ_64(void);
undefined4 get_p_size(char param_1);
void OTAG_OBJ_C0(void);
void DrawOTagIO(u_long *p);
void DumpOTag(u_long *p);
void OTAG_OBJ_244(void);
int CheckPrim(char *s,u_long *p);
void OTAG_OBJ_338(void);
void DecDCTReset(int mode);
int DecDCTBufSize(u_long *bs);
void DecDCTvlc(u_long *bs,u_long *buf);
void DecDCTin(u_long *buf,int mode);
void LIBPRESS_OBJ_B4(uint *param_1,uint param_2);
void LIBPRESS_OBJ_E0(undefined4 *param_1);
void DecDCTout(u_long *buf,int size);
int DecDCTinSync(int mode);
int DecDCToutSync(int mode);
void MDEC_reset(int param_1);
void LIBPRESS_OBJ_244(void);
void LIBPRESS_OBJ_25C(void);
void MDEC_in(undefined4 *param_1,uint param_2);
void MDEC_out(undefined4 param_1,uint param_2);
undefined4 MDEC_in_sync(void);
void LIBPRESS_OBJ_424(void);
undefined4 MDEC_out_sync(void);
void LIBPRESS_OBJ_4BC(void);
undefined4 MDEC_status(void);
undefined4 MDEC_report(void);
undefined4 timeout(undefined4 param_1);
undefined4 MDEC_vlc(undefined2 *param_1,undefined2 *param_2);
int VLC_OBJ_84(uint param_1,ushort *param_2,uint param_3,ushort param_4);
int VLC_OBJ_88(uint param_1,ushort *param_2,uint param_3);
int VLC_OBJ_8C(uint param_1,ushort *param_2,uint param_3);
int VLC_OBJ_90(uint param_1,ushort *param_2,uint param_3);
int VLC_OBJ_1C0(uint param_1,ushort *param_2,uint param_3,ushort *param_4);
int MDEC_vlc2(ushort *param_1,ushort *param_2);
int VLC2_OBJ_E4(ushort param_1,ushort *param_2);
int VLC2_OBJ_E8(undefined4 param_1,undefined2 *param_2);
int VLC2_OBJ_EC(void);
int VLC2_OBJ_260(undefined4 param_1,undefined4 param_2,ushort *param_3);
int VLC2_OBJ_30C(undefined4 param_1,undefined4 param_2,ushort *param_3);
void VLC2_OBJ_3D0(void);
void ivlc_dct_dc_size(void);
void VLC2_OBJ_42C(undefined4 param_1,undefined4 param_2,uint param_3);
int VLC2_OBJ_5AC(undefined4 param_1,undefined4 param_2,int param_3);
int VLC2_OBJ_5C8(undefined4 param_1,undefined4 param_2,int param_3);

#endif