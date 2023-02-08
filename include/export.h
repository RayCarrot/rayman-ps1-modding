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
typedef unsigned int    undefined4;
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

typedef struct MATRIX MATRIX, *PMATRIX;

struct MATRIX {
    short m[3][3];
    long t[3];
};

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

typedef struct CVECTOR CVECTOR, *PCVECTOR;

struct CVECTOR {
    u_char r;
    u_char g;
    u_char b;
    u_char cd;
};

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

typedef void (* SsMarkCallbackProc)(short, short, short);

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

typedef struct CdlFILE CdlFILE, *PCdlFILE;

struct CdlFILE {
    struct CdlLOC pos;
    u_long size;
    char name[16];
};

typedef struct OptionsJeu OptionsJeu, *POptionsJeu;

struct OptionsJeu {
    undefined * Fire1ButtonFunc;
    undefined * Fire0ButtonFunc;
    undefined * Button4Func;
    undefined * Button3Func;
    ushort field4_0x10;
    ushort field5_0x12;
    ushort field6_0x14;
    ushort field7_0x16;
    ushort field8_0x18;
    ushort field9_0x1a;
    ushort field10_0x1c;
    ushort field11_0x1e;
};

typedef struct TextToDisplay TextToDisplay, *PTextToDisplay;

struct TextToDisplay {
    char Text[48];
    short ActualXPos;
    short ActualYPos;
    short XRelated;
    short YRelated;
    short XPos;
    short YPos;
    byte FontSize;
    bool field8_0x3d;
    bool IsFond;
    byte field10_0x3f;
};

typedef struct Record Record, *PRecord;

struct Record {
    int current_offset;
    int repeat_length;
    int repeat_index;
    int length;
    byte * data;
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
    Invalid=255
} ObjType;

typedef struct AnimationLayer AnimationLayer, *PAnimationLayer;

typedef struct AnimationFrame AnimationFrame, *PAnimationFrame;

struct Font {
    struct Sprite * sprites;
    undefined * img_buffer;
    int nb_sprites;
};

struct Obj {
    struct Sprite * sprites;
    struct Animation * animations;
    undefined * img_buffer;
    struct ObjState * * eta;
    undefined * cmds;
    undefined * cmd_labels;
    undefined4 field6_0x18;
    short x_pos;
    short y_pos;
    short id;
    short screen_x_pos;
    short screen_y_pos;
    undefined field12_0x26;
    undefined field13_0x27;
    short init_x_pos;
    short init_y_pos;
    short speed_x;
    short speed_y;
    ushort nb_sprites;
    short cmd_offset;
    short nb_cmd;
    short field21_0x36;
    short field22_0x38;
    short field23_0x3a;
    short field24_0x3c;
    short field25_0x3e;
    short field26_0x40;
    short field27_0x42;
    short field28_0x44;
    short field29_0x46;
    ushort zdc;
    short field31_0x4a;
    byte btypes[5];
    undefined field33_0x51;
    byte offset_bx;
    byte offset_by;
    byte anim_index;
    byte anim_frame;
    byte main_etat;
    byte init_main_etat;
    byte sub_etat;
    byte init_sub_etat;
    enum ObjCommand cmd;
    byte field43_0x5b;
    byte field44_0x5c;
    undefined field45_0x5d;
    byte offset_hy;
    byte follow_sprite;
    byte hit_points;
    byte init_hit_points;
    byte unused_display_prio;
    enum ObjType type;
    byte hit_sprite;
    undefined field53_0x65;
    undefined field54_0x66;
    undefined field55_0x67;
    undefined field56_0x68;
    byte field57_0x69;
    byte display_prio;
    byte timer;
    uint flags;
};

struct AllFixData {
    struct Font alpha;
    struct Font alpha2;
    struct Obj objects[29];
};

struct ObjState {
    sbyte field0_0x0;
    sbyte field1_0x1;
    byte AnimIndex;
    byte LinkedEtat;
    byte LinkedSubEtat;
    byte AnimSpeed;
    byte SoundIndex;
    byte Flags;
};

struct Sprite {
    int img_buffer_offset;
    byte id;
    byte width;
    byte height;
    byte col_width;
    byte col_height;
    byte col_pos;
    byte field7_0xa;
    byte field8_0xb;
    ushort clut;
    ushort tpage;
    byte page_x;
    byte page_y;
    undefined field13_0x12;
    undefined field14_0x13;
};

struct Animation {
    struct AnimationLayer * layers;
    struct AnimationFrame * frames;
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
    bool flipped_x;
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
    INPUT_UNUSED_0F=15,
    INPUT_UNUSED_10=16,
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
    INPUT_END=255
} Input;

typedef struct MapData MapData, *PMapData;

struct MapData {
    short width;
    short height;
    int length;
    short * map;
};

typedef struct WorldInfo WorldInfo, *PWorldInfo;

struct WorldInfo {
    short XPos;
    short YPos;
    byte UpIndex;
    byte DownIndex;
    byte LeftIndex;
    byte RightIndex;
    byte State;
    byte Cages;
    byte World;
    byte Level;
    undefined4 field10_0xc;
    undefined * LevelName;
};

typedef struct LevelData LevelData, *PLevelData;

struct LevelData {
    struct Obj * objects;
    byte nb_objects;
};

typedef struct LoadInfoRay LoadInfoRay, *PLoadInfoRay;

struct LoadInfoRay {
    byte LivesCount;
    byte TingsCount;
    byte Cages;
    byte Continues;
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
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined2 field48_0x30;
    undefined2 field49_0x32;
    undefined2 XMap;
    undefined2 YMap;
    ushort field52_0x38;
    short RayXPos;
    short RayYPos;
    short RayScreenXPos;
    short RayScreenYPos;
    ushort field57_0x42;
    short ObjIndex;
    short ObjXPos;
    short ObjYPos;
    byte ObjLinks[256];
    undefined field62_0x14a;
    byte field63_0x14b;
    byte RayCollisionTypes[5]; // Created by retype action
    byte RayAnimIndex;
    byte RayAnimFrame;
    byte RayEtat;
    byte RaySubEtat;
    byte PoingSubEtat;
    byte field70_0x156;
    byte field71_0x157;
    byte field72_0x158;
    sbyte DeadTime;
    byte field74_0x15a;
    byte TingsCount;
};

typedef enum Video {
    VIDEO_NONE=0,
    VIDEO_PRES=1,
    VIDEO_INTRO_1=2,
    VIDEO_DEMO=3,
    VIDEO_INTRO_2=4,
    VIDEO_WIN=5
} Video;

typedef struct Credit Credit, *PCredit;

struct Credit {
    undefined * text;
    short x_pos;
    short y_pos;
    byte font;
    byte cmd;
    byte color;
};

typedef struct Poing Poing, *PPoing;

struct Poing {
    int Int_00;
    short field1_0x4;
    short SpeedX;
    short Charge;
    short field4_0xa;
    byte PoingSubEtat;
    bool IsReturning;
    bool IsActive;
    byte Damage;
    bool IsChargingFist;
    bool IsDoingBoum;
    undefined field11_0x12;
    undefined field12_0x13;
};

typedef struct SoundTableEntry SoundTableEntry, *PSoundTableEntry;

struct SoundTableEntry {
    byte field0_0x0;
    byte field1_0x1;
    byte field2_0x2;
    byte field3_0x3;
    byte field4_0x4;
};

typedef struct VoiceTableEntry VoiceTableEntry, *PVoiceTableEntry;

struct VoiceTableEntry {
    short field0_0x0;
    short field1_0x2;
    short field2_0x4;
};

typedef struct PS1_FileInfo PS1_FileInfo, *PPS1_FileInfo;

struct PS1_FileInfo {
    undefined * path;
    undefined * dest;
    undefined * dest_debug;
    struct CdlFILE file;
};

typedef struct PS1_VRAMRegion PS1_VRAMRegion, *PPS1_VRAMRegion;

struct PS1_VRAMRegion {
    short X;
    short Y;
    short W;
    short H;
};

typedef struct SaxNoteEntry SaxNoteEntry, *PSaxNoteEntry;

struct SaxNoteEntry {
    byte field0_0x0;
    undefined field1_0x1;
    short field2_0x2;
    short field3_0x4;
    short field4_0x6;
    undefined field5_0x8;
    undefined field6_0x9;
};

typedef struct BBAttackEntry BBAttackEntry, *PBBAttackEntry;

struct BBAttackEntry {
    short field0_0x0;
    byte field1_0x2;
    undefined field2_0x3;
};

typedef struct SaxAttackEntry SaxAttackEntry, *PSaxAttackEntry;

struct SaxAttackEntry {
    byte NextNote;
    byte Time;
    short field2_0x2;
};

typedef struct CommandTableEntry CommandTableEntry, *PCommandTableEntry;

struct CommandTableEntry {
    undefined * ReadArguments;
    undefined * SkipArguments;
    undefined * HandleCommand;
};

typedef struct ObjFlag ObjFlag, *PObjFlag;

struct ObjFlag {
    byte FlagByte_0;
    byte FlagByte_1;
    char FlagByte_2;
    byte FlagByte_3;
};

typedef struct ActiveObjects ActiveObjects, *PActiveObjects;

struct ActiveObjects {
    short objects[100];
    short num_active_objects;
    undefined field2_0xca;
    undefined field3_0xcb;
    undefined field4_0xcc;
    undefined field5_0xcd;
    undefined field6_0xce;
    undefined field7_0xcf;
    short field8_0xd0;
    undefined field9_0xd2;
    undefined field10_0xd3;
    undefined field11_0xd4;
    undefined field12_0xd5;
    undefined field13_0xd6;
    undefined field14_0xd7;
    short div_obj;
    undefined field16_0xda;
    undefined field17_0xdb;
    undefined field18_0xdc;
    undefined field19_0xdd;
    undefined field20_0xde;
    undefined field21_0xdf;
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

typedef struct POLY_G3 POLY_G3, *PPOLY_G3;

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

typedef struct POLY_F4 POLY_F4, *PPOLY_F4;

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

typedef struct POLY_FT4 POLY_FT4, *PPOLY_FT4;

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

typedef struct DR_ENV DR_ENV, *PDR_ENV;

struct DR_ENV {
    u_long tag;
    u_long _code[15];
};

typedef struct POLY_G4 POLY_G4, *PPOLY_G4;

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

typedef struct TILE TILE, *PTILE;

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

typedef struct DISPENV DISPENV, *PDISPENV;

typedef struct RECT RECT, *PRECT;

struct RECT {
    short x;
    short y;
    short w;
    short h;
};

struct DISPENV {
    struct RECT disp;
    struct RECT screen;
    u_char isinter;
    u_char isrgb24;
    u_char pad0;
    u_char pad1;
};

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

typedef struct SPRT_8 SPRT_8, *PSPRT_8;

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

typedef struct SPRT SPRT, *PSPRT;

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

typedef struct TILE_1 TILE_1, *PTILE_1;

struct TILE_1 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char _code;
    short x0;
    short y0;
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

typedef struct DRAWENV DRAWENV, *PDRAWENV;

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
void FUN_8012d030(undefined4 param_1,undefined4 param_2,short param_3,short param_4,short param_5);
void FUN_8012d27c(void);
void FUN_8012d2b0(undefined2 param_1);
void FUN_8012d4c0(short param_1,short param_2);
undefined4 continue_fonction(void);
void FUN_8012dc9c(void);
undefined4 select_level_prg(void);
int SELECT_LEVEL(short param_1);
void FUN_8012df9c(void);
undefined4 WORLD_CHOICE(void);
void DO_WORLD_MAP(void);
void DISPLAY_TXT_VIGNET(void);
bool display_vignet_prg(void);
void DISPLAY_GAME_VIGNET(void);
void DISPLAY_TXT_CREDITS(void);
undefined4 display_credits_prg(void);
void DISPLAY_CREDITS(void);
void DISPLAY_PROTOON_BACK(void);
void DO_VICTOIRE(void);
void InitDemoJeu(void);
void FinDemoJeu(void);
bool loader_anim_prg(void);
void FUN_8012ec94(void);
void FUN_8012ece8(void);
void FUN_8012ecf0(void);
void PS1_ShowPauseScreen(void);
int FUN_8012eda4(int param_1,short param_2);
int PS1_LoadToVRAM(short width,short height,short x,short y,undefined4 data);
void FUN_8012ee64(uint param_1,uint param_2,int param_3,int param_4,undefined4 param_5,int param_6);
void DO_GROS_MOTEUR_NORMAL(void);
void doMainLoopUpdate(void);
void main(void);
void FUN_8013045c(void);
void FUN_80130514(short param_1);
void FUN_80130560(void);
void FUN_801305b4(void);
void FUN_801305ec(void);
void FUN_8013061c(void);
void FUN_8013066c(void);
undefined4 FUN_801309b8(uint param_1,uint param_2,byte *param_3,uint param_4);
void FUN_80130a98(undefined *param_1,undefined *param_2,undefined *param_3);
void FUN_80130b18(uint param_1,char *param_2);
int FUN_80130bc4(uint param_1);
int FUN_80130c58(int param_1);
int FUN_80130d00(uint param_1,uint param_2);
void FUN_80130dc0(void);
bool FUN_80131474(short *param_1,uint param_2,uint param_3);
void FUN_801314c4(void);
void FUN_80131678(void);
void playLevelMusic(undefined2 world,undefined2 level);
void FUN_80131c28(void);
void start_cd_suspence(void);
void FUN_80131c70(void);
void FUN_80131c94(void);
void start_cd_gagne(void);
void FUN_80131d18(void);
void PS1_PlayCDTrack_0_3(void);
void FUN_80131d70(void);
void FUN_80131d94(void);
int FUN_80131db8(void);
void FUN_80131dc8(void);
void FUN_80131df0(void);
void FUN_80131e18(void);
void FUN_80131e40(void);
void FUN_80131e5c(void);
void FUN_80131e94(void);
void FUN_8013202c(void);
void change_audio_track_moskito_acc(void);
void FUN_80132098(void);
void FUN_801320d0(void);
void FUN_80132110(void);
void FUN_80132168(short param_1);
void PS1_LoadLevelMapBlock(MapData *mp);
void FUN_80132304(undefined4 param_1,ushort height);
void FUN_8013234c(undefined4 *param_1);
void FUN_80132424(void);
void PS1_LoadAllFixData(void);
void PS1_LoadLevelEventBlock(void);
void PS1_PlayVideo(Video video);
void PS1_PlayVideoFile(Video video);
void FUN_80132d74(undefined4 *param_1);
void FUN_80132e04(CdlLOC *lba,u_long param_2);
void FUN_80132ea0(u_long *param_1,Video video);
void FUN_80133018(void);
void FUN_80133048(undefined4 param_1,int param_2,byte param_3);
undefined4 FUN_8013319c(void);
int FUN_801331a4(PS1_FileInfo *param_1,int param_2,undefined4 param_3);
int PS1_LoadFiles(PS1_FileInfo *files,int fileIndex,int count);
int FUN_80133498(undefined *param_1,uchar *param_2,undefined *param_3,undefined4 param_4);
int readinput(void);
int upjoy(void);
int leftjoy(void);
int rightjoy(void);
int downjoy(void);
int but0pressed(void);
int but1pressed(void);
int but2pressed(void);
int but3pressed(void);
undefined4 FUN_80133984(void);
undefined4 FUN_801339f4(void);
bool FUN_80133a64(void);
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
int SelectButPressed(void);
void FUN_80134610(uint param_1);
byte FUN_8013491c(void);
void PS1_DoDemo(Record *record);
undefined * TOUCHE(Input param_1);
undefined4 PS1_SpecialTOUCHE(uint param_1);
void PS1_LoadBGBlock(void);
void FUN_801356e0(void);
void FUN_80135930(void);
void FUN_80135ab0(short param_1,int param_2);
void FUN_80135d5c(int param_1,int param_2,int param_3,short param_4);
void FUN_8013613c(ushort param_1,uint param_2,ushort param_3,uint param_4);
void FUN_80136340(int param_1,uint param_2);
void FUN_801366ac(void);
void FUN_8013733c(void);
uint FUN_80137998(byte param_1,uint param_2,uint param_3);
uint FUN_801379f8(byte param_1,uint param_2,uint param_3);
int FUN_80137a4c(uint param_1);
void DRAW_MAP(void);
void FUN_80137cc8(int param_1,int param_2);
void allume_vitraux(undefined4 *param_1);
void FUN_80138360(int param_1);
void FUN_80138718(char param_1);
void FUN_80138b84(short param_1,int param_2,short param_3,short param_4);
void FUN_80139014(ushort param_1,ushort param_2,short param_3,short param_4,undefined2 param_5,short param_6);
void FUN_801392d8(int param_1,short *param_2,ushort *param_3);
void FUN_80139330(uint param_1,short *param_2,undefined2 *param_3);
void FUN_801393c8(int param_1);
void PS1_LoadAllFixTextures(int length);
void FUN_8013948c(int param_1);
void FUN_80139514(int param_1);
void FUN_801395a8(int param_1);
void FUN_80139624(int param_1);
void FUN_80139688(int param_1);
void FUN_801397f4(Sprite *sprite,short x,short y,undefined displayMode);
void DrawSpriteNormalEtX(Sprite *sprite,short x,short y,undefined1 param_4);
void FUN_80139b70(int param_1,short param_2,short param_3,char param_4,ushort param_5);
void FUN_80139d5c(short *param_1,short *param_2,short param_3,short param_4,short param_5);
void FUN_80139f04(int param_1,short param_2,short param_3,char param_4,short param_5);
void display_sprite_NoClip(Obj *param_1,uint sprite,short x,short y,undefined1 param_5);
void display2(Obj *obj);
void DISPLAY_POING(void);
void DISPLAY_CLING(void);
void display_bar_boss(Obj *bossObj);
void DISPLAY_FIXE(short leftTime);
void FUN_8013aeac(undefined2 param_1,undefined2 param_2);
void FUN_8013af14(void);
void FUN_8013af90(int param_1,int param_2,int param_3,int param_4,short param_5);
void FUN_8013b020(void);
void FUN_8013b040(undefined2 param_1,undefined2 param_2);
void FUN_8013b0c0(undefined2 param_1,undefined2 param_2);
void FUN_8013b144(undefined2 param_1,undefined2 param_2);
void FUN_8013b1b4(undefined2 param_1,undefined2 param_2);
void FUN_8013b224(undefined2 param_1,undefined2 param_2);
void FUN_8013b294(undefined2 param_1,undefined2 param_2);
void FUN_8013b304(undefined2 param_1,undefined2 param_2);
void FUN_8013b374(undefined2 param_1,undefined2 param_2);
void FUN_8013b3f8(undefined2 param_1,undefined2 param_2);
void FUN_8013b464(undefined2 param_1,undefined2 param_2);
void FUN_8013b4d4(undefined2 param_1,undefined2 param_2);
void display_flocons_behind(void);
void display_flocons_before(void);
void display_pix_gerbes(void);
void DISPLAY_CYMBALE(int *param_1,char param_2);
void DISPLAY_ALL_OBJECTS(void);
undefined FUN_8013c9a4(short param_1,char param_2);
int FUN_8013ca14(undefined param_1,short param_2);
void DrawFondBoxNormal(short param_1,short param_2,short param_3,short param_4,char param_5);
void DrawBlackBoxNormal(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,char param_5);
void DISPLAY_BLACKBOX(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,byte param_5,char param_6);
void display_text_sin(char *param_1,ushort param_2,short param_3,short param_4,byte param_5,byte param_6);
void display_text(char *text,ushort xPos,short yPos,byte fontSize,uint param_5);
void display_box_text(int param_1);
void FUN_8013e238(void);
void display_etoile(int param_1,int param_2);
void display_grp_stars(void);
void DISPLAY_TEXT_FEE(void);
void FUN_8013e84c(void);
void FUN_8013eb38(short param_1,short param_2,short param_3,short param_4);
void FUN_8013eb88(int param_1,short param_2);
void FUN_8013f0c0(void);
void display_time(short param_1);
void FUN_8013f460(void);
void DISPLAY_CONTINUE_SPR(void);
void FUN_8013f8f8(void);
void FUN_8013f950(void);
ushort get_nb_zdc(int param_1);
ushort get_zdc_index(int param_1);
int get_zdc(undefined4 param_1,short param_2);
bool in_coll_sprite_list(int param_1,ushort param_2);
bool inter_box(int param_1,int param_2,int param_3,int param_4,short param_5,short param_6,int param_7,int param_8);
void GET_OBJ_ZDC(Obj *obj,short *x,short *y,short *w,short *h);
int GET_SPRITE_ZDC(Obj *param_1,short param_2,short *param_3,short *param_4,short *param_5,short *param_6);
int BOX_HIT_SPECIAL_ZDC(short param_1,short param_2,short param_3,short param_4,Obj *param_5);
int BOX_IN_COLL_ZONES(short param_1,short param_2,short param_3,short param_4,short param_5,Obj *param_6);
uint COLL_BOX_SPRITE(short param_1,short param_2,short param_3,short param_4,Obj *param_5);
int CHECK_BOX_COLLISION(short param_1,short x,short y,short w,short h,Obj *obj);
int FUN_80141708(int param_1,int param_2);
int setToleranceDist(int param_1,int param_2,short param_3);
void FUN_80141a28(Obj *param_1);
void SET_RAY_DIST_PI(Obj *param_1);
void SET_RAY_DIST_BAG(Obj *param_1);
void SET_RAY_DIST(Obj *obj);
void do_boum(void);
void DO_PNG_COLL_STONEMAN(Obj *param_1);
void DO_PNG_COLL_STONEWOMAN(Obj *param_1);
void DO_POING_COLLISION(void);
bool COLL_RAY_PIC(void);
void COLL_RAY_BLK_MORTEL(void);
void RAY_KO(void);
void RAY_HIT(char param_1,Obj *obj);
void standard_frontZone(int param_1,short *param_2,short *param_3);
void SET_DETECT_ZONE_FLAG(Obj *param_1);
void goToRay(Obj *param_1);
void unleashMonsterHost(int param_1);
void DO_COLL_RAY_CYMBALE(Obj *param_1);
void FUN_8014501c(void);
void PS1_ObjectCollisions(void);
void DO_COLLISIONS(void);
void DO_OBJ_COLLISIONS(Obj *param_1,short param_2);
void set2bits(uint *param_1,uint param_2,int param_3);
void FUN_80146564(uint *param_1,uint param_2,int *param_3,uint *param_4);
void save_objects_flags(void);
void restore_objects_flags(void);
void snapToSprite(int param_1,Obj *param_2,uint param_3,int param_4,ushort param_5);
Obj * findfirstObject(ObjType objType);
Obj * FUN_80146bb8(ObjType param_1);
void FUN_80146c2c(int param_1,uint param_2);
uint getbit(int param_1,uint param_2);
int cosinus(short param_1);
int sinus(short param_1);
int sinYspeed(int param_1,int param_2,short param_3,ushort *param_4);
int ashl16(ushort param_1,uint param_2);
int ashr16(ushort param_1,uint param_2);
int ashr32(uint param_1,uint param_2);
void set_proj_center(undefined2 param_1,undefined2 param_2);
int FUN_80146f6c(short param_1,ushort param_2);
int get_proj_dist2(short param_1,short param_2);
int get_proj_x(short param_1,short param_2);
int get_proj_y(short param_1,short param_2);
void set_zoom_mode(undefined zoomMode);
int inverse_proj_x(short param_1,short param_2);
int inverse_proj_y(short param_1,short param_2);
int vblToEOA(int param_1,uint param_2);
void GET_ANIM_POS(Obj *param_1,short *x,short *y,ushort *w,ushort *h);
undefined4 FUN_801473d4(void);
undefined4 FUN_801473dc(void);
undefined BTYP_0(int param_1,int param_2);
void set_sub_etat(Obj *obj,byte subEtat);
void set_main_etat(int param_1,undefined param_2);
void set_main_and_sub_etat(Obj *obj,byte main_etat,byte sub_etat);
short get_center_x(int param_1);
short get_center_y(int param_1,int param_2);
byte on_block_chdir(Obj *obj,short param_2,short param_3);
void CALC_FOLLOW_SPRITE_SPEED(Obj *obj,Animation *anim1,Animation *anim2,short param_4);
undefined4 GET_SPRITE_POS(Obj *obj,int param_2,short *param_3,short *param_4,ushort *param_5,ushort *param_6);
void GET_RAY_ZDC(Obj *ray,short *x,short *y,short *w,short *h);
void GET_BB1_ZDCs(Obj *param_1,short *param_2,short *param_3,short *param_4,short *param_5,short *param_6,short *param_7,short *param_8,short *param_9);
int myRand(int param_1);
void calc_obj_dir(Obj *obj);
bool OBJ_IN_ZONE(int param_1);
void calc_obj_pos(Obj *obj);
void makeUturn(Obj *param_1);
ushort BTYP_1(short xPos,short yPos);
void calc_btyp_square(int param_1);
uint calc_btyp(Obj *obj);
void FUN_80148bb8(int param_1);
void FUN_80148bc4(Obj *param_1,short param_2);
void allocate_toons(Obj *param_1,uint param_2);
void special_flags_init(void);
void FUN_80149094(Obj *param_1);
void obj_hurt(Obj *obj);
void Projectil_to_RM(Obj *obj,short *param_2,short *param_3,short param_4,short param_5);
void INIT_TEXT_TO_DISPLAY(void);
char deter_num_let(byte param_1);
void calc_num_let_spr(char param_1,char *param_2);
int calc_largmax_text(int param_1,int param_2,short param_3,short param_4,undefined param_5);
void INIT_TXT_BOX(undefined4 *param_1);
void Deter_Option_Caract(char *param_1,short param_2,uint param_3);
void SwapAB(undefined2 *param_1,undefined2 *param_2);
void Bresenham(code *param_1,short param_2,short param_3,short param_4,short param_5,short param_6,short param_7);
void LOAD_CONFIG(void);
void init_finBossLevel(void);
void Change_Wait_Anim(void);
void FUN_8014a32c(void);
void PS1_CopySauveRayEvts(void);
void FUN_8014a54c(int param_1);
void FUN_8014a5b0(void);
void reset_couteaux(void);
bool check_couteaux(void);
byte FUN_8014a7d4(int param_1);
int FUN_8014a7f4(ushort param_1,uint param_2);
int FUN_8014a890(int param_1,short param_2);
int FUN_8014a8bc(ushort param_1,uint param_2);
void init_move_couteau(void);
void FUN_8014abe8(uint param_1);
uint couteau_frame(ushort param_1,uint param_2);
void FUN_8014b0ac(int param_1);
void get_cou_zdc(Obj *param_1,short *param_2,short *param_3,short *param_4,short *param_5);
void FUN_8014b498(void);
int convertspeed(short param_1);
void lance_couteau_parabolique(int param_1);
void lance_couteau_droit(int param_1);
void retour_couteau(int param_1);
void lance_couteau_lineaire(int param_1);
void FUN_8014ce94(int param_1);
void FUN_8014d778(Obj *param_1);
void FUN_8014d85c(void);
void FUN_8014d8ac(Obj *param_1);
undefined4 pma_get_eject_sens(void);
void DO_COU_ATTER(Obj *param_1);
void DO_PMA_ATTER(Obj *param_1);
void _card_clear(long param_1);
void INIT_HORLOGES(void);
void horloges(void);
void PS1_InitAllowedTime(void);
int get_allowed_time(void);
void calc_left_time(void);
void fades(void);
void FUN_8014e27c(void);
int FUN_8014e35c(int param_1);
void FUN_8014e398(void);
void FUN_8014e414(void);
void FUN_8014e47c(void);
void DO_SCROLL(ushort *param_1,short *param_2);
void allocateLandingSmoke(int param_1);
int Prio(Obj *event);
void first_obj_init(int param_1);
void obj_init(Obj *obj);
void INIT_OBJECTS(char newLevel);
int instantSpeed(short param_1);
void SET_X_SPEED(Obj *obj);
void REINIT_OBJECT(Obj *obj);
void make_active(Obj *obj,bool doNova);
bool in_action_zone(short param_1,short param_2,int param_3,char param_4);
void FUN_80150638(int param_1);
void SET_ACTIVE_FLAG(short param_1,short param_2,Obj *param_3);
undefined4 DO_PESANTEUR(int param_1);
void FUN_80150c5c(int param_1,uint param_2);
void DO_ANIM(Obj *obj);
int prof_in_bloc(int param_1);
void do_boing(Obj *param_1,char param_2,undefined1 param_3);
byte underSlope(int param_1);
void DO_STONEBOMB_REBOND(int param_1);
void DO_THROWN_BOMB_REBOND(Obj *param_1,short param_2,ushort param_3);
void DO_FRUIT_REBOND(Obj *param_1,short param_2,ushort param_3);
void Drop_Atter(Obj *param_1);
void BadGuyAtter(Obj *param_1);
void MiteAtter(int param_1);
void Clown_Music_Atter(Obj *param_1);
void LidolPinkAtter(int param_1);
void stoneDogAtter(int param_1);
void stoneDogBounces(int param_1);
void Spider_Atter(Obj *param_1);
void trompetteAtter(undefined4 param_1);
void NormalAtter(Obj *param_1);
void OBJ_IN_THE_AIR(Obj *param_1);
void test_fall_in_water(Obj *obj);
void MOVE_OBJECT(Obj *obj);
void FUN_80153060(Obj *obj);
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
undefined4 linkListHoldsAGendoor(int param_1);
undefined4 FUN_8015666c(int param_1);
undefined4 FUN_80156710(int param_1);
void correct_gendoor_link(void);
void suppressFromLinkList(int param_1);
void correct_link(void);
void INIT_RAY_BEGIN(void);
void INIT_RAY(char newLevel);
byte is_icy_pente(uint param_1);
void STOPPE_RAY_EN_XY(void);
void RAY_RESPOND_TO_ALL_DIRS(void);
void DO_RAYMAN(void);
void DO_RAY_ON_MS(void);
void DO_PLACE_RAY(void);
void DO_AUTO_SCROLL(void);
bool do_perfect_bonus(void);
void INIT_MOTEUR(undefined newLevel);
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
undefined get_bonus_map_complete(int param_1,int param_2);
void FUN_8015a7ec(int param_1,int param_2);
void FUN_8015a824(void);
void FUN_8015a8c8(void);
void init_bonus_perfect(void);
void FUN_8015a9a0(Obj *obj);
void new_level_init(void);
void fix_numlevel(Obj *obj);
void TEST_SIGNPOST(void);
void DO_WIZARD(Obj *obj);
undefined4 get_next_bonus_level(byte param_1);
void TEST_WIZARD(Obj *obj);
void allocate_splash(Obj *baseObj);
undefined4 can_free_fish(int param_1);
void FUN_8015c4b8(int param_1);
void DO_PYRANHA(Obj *obj);
void DO_BALLE(int param_1);
void setStoneChipPos(Obj *param_1,Obj *param_2,char *param_3);
void allocateStoneChips(Obj *obj);
void DO_STONE_EXPLOSION(Obj *obj);
void DO_TIR(Obj *param_1);
void allocateStonemanStone(Obj *param_1,short param_2,char param_3);
void DO_STONEMAN1_TIR(int param_1);
void DO_STONEMAN2_TIR(int param_1);
void allocateStonewomanStone(Obj *param_1,short param_2);
void DO_STONEWOMAN_TIR(int param_1);
void allocateDard(Obj *param_1);
void DO_SPIDER_TIR(int param_1);
void DO_INTERACT_PLAT(Obj *param_1);
void FUN_8015e0e8(Obj *param_1);
Obj * oldest_planted(void);
void DO_GROWING_PLATFORM(void);
void DO_BIG_CLOWN_ATTAK(Obj *obj);
void allocatedrop(Obj *param_1);
void DO_WAT_CLOWN_ATTAK(Obj *obj);
void FUN_8015e804(Obj *obj,char param_2);
void FUN_8015e9cc(Obj *obj);
void FUN_8015ea7c(int param_1,short param_2);
void FUN_8015ebe0(Obj *param_1);
void DO_CLOWN_TNT_ATTACK(Obj *param_1);
void allocate_badguy(Obj *param_1,short param_2,short param_3,short param_4);
Obj * allocateExplosion(int param_1);
void FUN_8015f320(int param_1);
void MARACAS_GO(Obj *param_1);
int FUN_8015f488(int param_1);
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
void FUN_80160ba8(short param_1,short param_2,undefined2 param_3);
void calc_esquive_poing(int param_1,short *param_2,short *param_3,short *param_4);
void DO_PTI_ESQUIVE(Obj *param_1);
void DO_MITE2_ESQUIVE(Obj *param_1);
int allocate_gerbe(void);
void start_pix_gerbe(int param_1,int param_2);
void do_pix_gerbes(void);
void START_2_PARTS_CYMBAL_ACTION(int param_1);
void FUN_80161708(Obj *param_1);
void FUN_80161718(Obj *param_1);
void DO_MEDAILLON_TOON_GELE(void);
void ALLOCATE_MEDAILLON_TOON(void);
void INIT_LUCIOLE(void);
void DO_LUCIOLE(void);
void ChangeLevel(void);
void INIT_TXT_FEE(void);
void allocate_poing_or_fee(void);
void init_moustique(void);
void init_fee(void);
void FUN_80163350(Obj *obj);
void FUN_80163484(short param_1,short param_2);
int FUN_80163510(int param_1);
void FUN_801636cc(int param_1);
void allocatePaillette(int param_1);
void test_fin_cling(void);
void initGameSave(void);
void doneGameSave(void);
void saveGameState(Obj *obj,SaveState *state);
void restoreGameState(SaveState *param_1);
void PS1_PhotographerCollision(void);
int get_offset_in_save_zone(short eventIndex);
void reset_save_zone_level(void);
void take_bonus(ushort eventIndex);
byte bonus_taken(ushort param_1);
void FUN_801645fc(void);
void FUN_801646d4(void);
void DO_SPECIAL_PLATFORM(Obj *param_1);
void FUN_80165884(void);
void FUN_80165990(int param_1);
void PS1_LoadAllFixSound(void);
void FUN_80165c5c(ushort param_1);
void FUN_80165eb4(short param_1,short param_2);
void FUN_80165f78(short param_1);
int FUN_80165fcc(int param_1);
void FUN_80166018(void);
void FUN_80166060(short param_1);
void FUN_801660ac(void);
void FUN_801660e8(void);
void FUN_80166124(void);
void FUN_8016617c(void);
uint get_pan_snd(Obj *obj);
uint get_vol_snd(Obj *param_1);
void FUN_8016633c(short param_1);
void FUN_8016639c(short param_1);
void FUN_801663d4(void);
int last_snd(short param_1);
int get_pile_obj(short param_1);
int FUN_80166724(short param_1);
int get_voice_obj_snd(short param_1,short param_2);
void erase_pile_snd(short param_1);
void nettoie_pile_snd(void);
void FUN_80166d20(short param_1);
int FUN_80166e1c(short param_1,short param_2);
int FUN_80166e58(short param_1,short param_2);
void PlaySnd(short snd,short objId);
void PlaySnd_old(short snd);
void setvol(ushort param_1);
void setpan(short param_1);
void FUN_80168f38(void);
void FUN_80168f40(void);
void FUN_80168f48(void);
void FUN_80169194(void);
void FUN_8016924c(void);
void FUN_8016929c(void);
void FUN_80169350(void);
void FUN_80169420(int param_1);
void FUN_80169564(uint param_1,short param_2);
void FUN_801695ec(short param_1);
void FUN_80169a3c(undefined *param_1,int param_2);
void INIT_FADE_OUT(void);
void INIT_FADE_IN(void);
void FUN_80169be4(void);
void DO_FADE_OUT(void);
void FUN_80169e50(void);
bool PS1_HasMemoryCard(void);
undefined4 FUN_8016a304(void);
void FUN_8016a384(void);
undefined4 FUN_8016a3dc(void);
void FUN_8016a45c(void);
undefined4 FUN_8016a4b4(uint param_1);
int FUN_8016a634(char *param_1,undefined4 *param_2);
int FUN_8016a790(uint param_1);
void FUN_8016a87c(undefined param_1);
undefined4 FUN_8016aa70(uint param_1);
void FUN_8016aaf4(uint param_1);
undefined4 PS1_WriteSave(byte param_1,uint param_2);
byte SaveGameOnDisk(uint param_1);
int SaveFileRead(long param_1,void *param_2,short param_3);
void PS1_LoadSave(undefined4 param_1,char *param_2);
void LoadGameOnDisk(uint param_1);
undefined4 LoadInfoGame(uint save);
void FUN_8016bbe4(void);
byte FUN_8016bc88(uint param_1);
bool FUN_8016bdc4(void);
bool FUN_8016bdf4(void);
bool FUN_8016be18(void);
undefined FUN_8016be7c(void);
int FUN_8016be9c(void);
void FUN_8016bec0(void);
void fist_U_turn(Obj *poingObj,bool param_2);
void CALC_FIST_POS(void);
void RAY_THROW_FIST(void);
void RAY_PREPARE_FIST(void);
void RAY_GROW_FIST(void);
void fin_poing_follow(Obj *obj,char param_2);
void FUN_8016c71c(Obj *param_1);
void alter_fist_speed(int param_1);
void switch_off_fist(Obj *poingObj);
void DO_POING(Obj *param_1);
void allocatePoingBoum(void);
bool test_allowed(int param_1,short param_2,short param_3);
void FUN_8016d00c(Obj *param_1);
void DO_ONE_PINK_CMD(Obj *obj);
void DO_SPIDER_COMMAND(Obj *param_1);
void DO_STONEMAN_COMMAND(Obj *param_1);
void FUN_8016d890(Obj *obj);
void DO_MOVING_PLATFORM_COMMAND(Obj *obj);
void FUN_8016dbe0(Obj *obj);
void DO_ONE_CMD_WAIT(Obj *obj);
void DO_ONE_CMD_LR_ATTENTE(Obj *obj);
void DO_ONE_CMD_UPDOWN(Obj *param_1);
void special_pour_liv(Obj *param_1);
void DO_ONE_CMD(Obj *obj);
void FUN_8016e274(Obj *obj);
void DO_TEN_COMMAND(Obj *obj);
void FUN_8016f05c(int param_1,short *param_2);
undefined4 HAS_MIT_JUMP(int param_1);
undefined4 FUN_8016f2cc(int param_1,int param_2);
void FUN_8016f30c(Obj *param_1,short param_2);
void FUN_8016f4fc(Obj *param_1);
undefined4 FUN_8016f954(Obj *param_1);
void DO_MITE2_COMMAND(Obj *param_1);
void DO_CLOWN_TNT_COMMAND(Obj *param_1);
void DO_CLOWN_TNT2_COMMAND(int param_1);
bool FUN_80171388(int param_1,short param_2);
void FUN_80171dac(int param_1);
void FUN_80172108(int param_1);
void DO_PHOTOGRAPHE_CMD(Obj *obj);
void FUN_801727d0(int param_1,short param_2);
void FUN_80172820(int param_1);
void FUN_801729b4(void);
void DO_FEE(Obj *param_1);
undefined4 FUN_80172fdc(int param_1);
void allocateOtherPosts(Obj *obj);
void doHerseCommand(Obj *obj);
void DO_POISSON_VERT_CMD(Obj *param_1);
void doBlackRaymanCommand(Obj *obj);
void FUN_80174358(Obj *obj,undefined4 param_2,uint param_3,undefined param_4);
void FUN_801745f4(Obj *param_1);
void DO_ENSEIGNE_COMMAND(Obj *obj);
void FUN_801749fc(Obj *param_1);
void DO_JOE_COMMAND(Obj *obj);
void move_fruit_in_water(Obj *obj);
void DO_FALLING_OBJ_CMD(Obj *obj);
void FUN_801754dc(Obj *param_1);
void FUN_8017557c(int param_1,short param_2);
void DO_EXPLOSE_NOTE2(Obj *param_1);
void Cree_Eclat_Note(Obj *param_1,int param_2,short param_3);
void DO_EXPLOSE_NOTE1(int param_1);
void FUN_80175cf4(int param_1);
void FUN_80175eb4(int param_1);
void DO_NOTE_REBOND(Obj *param_1);
void allocateNote(int param_1);
byte PrepareAtak(void);
void SAXO_TIRE(int param_1);
void FUN_80176380(Obj *param_1);
void FUN_8017647c(Obj *param_1);
void FUN_8017657c(Obj *param_1);
void DO_SAXO_ATTER(Obj *param_1);
void DO_SAXO2_ATTER(Obj *param_1);
void FUN_80177c48(short param_1);
void FUN_80177f58(Obj *param_1);
undefined4 FUN_80177f9c(void);
void get_spi_zdc(int param_1,short *param_2,short *param_3,undefined2 *param_4,undefined2 *param_5);
void FUN_80178640(Obj *param_1);
void FUN_80178830(Obj *param_1);
void FUN_80178938(int param_1);
void FUN_801790cc(int param_1);
void FUN_80179218(void);
void FUN_8017a6f8(void);
void FUN_8017ab8c(void);
void FUN_8017b260(uint param_1);
void FUN_8017b2f0(int param_1);
int FUN_8017b314(byte param_1);
undefined4 readOneArg(int param_1);
undefined4 skipOneArg(int param_1);
undefined4 handle_SELF_HANDLED(void);
undefined4 handle_GO_SUBSTATE(Obj *param_1);
undefined4 handle_GO_SKIP(int param_1);
undefined readOneCommand(Obj *param_1);
undefined skipOneCommand(int param_1);
void GET_OBJ_CMD(Obj *obj);
void FUN_8017bebc(int param_1,ushort param_2);
void skipToLabel(Obj *obj,char label,bool param_3);
void FUN_8017bfec(undefined4 param_1,undefined1 param_2,bool param_3);
void FUN_8017c03c(Obj *param_1,short param_2);
void DO_TOTBT_REBOND(int param_1);
void DO_PI_EXPLOSION2(Obj *param_1);
void DO_BBL_REBOND(int param_1);
void FUN_8017c8f8(int param_1);
void FUN_8017ca78(Obj *param_1,short param_2);
void FUN_8017ce44(void);
void FUN_8017cf84(Obj *param_1);
void FUN_8017d304(Obj *param_1);
void FUN_8017d4c4(Obj *param_1);
void BB_Attaque(Obj *param_1);
void Fin_BB_Attaque(undefined4 param_1);
void FUN_8017d998(Obj *param_1);
void DO_BBMONT_ATTER(Obj *param_1);
void FUN_8017ea60(Obj *param_1);
void FUN_8017fb88(undefined2 param_1);
void DO_BBMONT2_ATTER(Obj *param_1);
void DO_BBMONT3_ATTER(Obj *param_1);
void SYNCHRO_LOOP(code *param_1);
void FUN_8018058c(undefined4 param_1,undefined4 param_2,undefined4 param_3,short param_4,short param_5,short param_6,short param_7);
void DISPLAY_FOND3(void);
void FUN_80180804(undefined4 param_1,undefined4 param_2,undefined4 param_3,short param_4,short param_5,short param_6,short param_7);
void FUN_801809fc(void);
void FUN_80180a7c(void);
void DISPLAY_FOND_SELECT(void);
void FUN_80180abc(void);
void FUN_80180b04(int param_1,char param_2);
void guetteurFollowsShip(int param_1);
void DO_ONE_PAR_COMMAND(Obj *param_1);
int FUN_80181020(int param_1,int param_2);
void allocatePirateGuetteurBomb(Obj *param_1,short param_2,char param_3,byte param_4);
void DO_PAR_TIR(int param_1);
void DO_PAR_POING_COLLISION(Obj *param_1,short param_2);
void FUN_80181844(Obj *param_1);
void allocateRayLandingSmoke(void);
void recale_ray_on_liane(ushort param_1);
void calc_bhand_typ(Obj *param_1);
void IS_RAY_ON_LIANE(void);
void rayMayLandOnAnObject(undefined *param_1,short param_2);
void set_air_speed(uint param_1,uint param_2,short param_3,byte param_4);
void Reset_air_speed(char param_1);
void determineRayAirInertia(void);
void ray_jump(void);
void ray_inertia_speed(uint param_1,short param_2,short param_3,short param_4);
void RAY_SWIP(void);
void RAY_STOP(void);
void RAY_HELICO(void);
void Make_Ray_Hang(short param_1,short param_2);
byte FUN_80183e80(int param_1);
byte FUN_80183ec0(int param_1);
void CAN_RAY_HANG_BLOC(void);
void RAY_TOMBE(void);
void RAY_RESPOND_TO_DOWN(void);
void RAY_RESPOND_TO_UP(void);
void RAY_RESPOND_TO_DIR(uint param_1);
void RAY_RESPOND_TO_NOTHING(void);
void FUN_80185a54(void);
void FUN_80185bd8(void);
void RAY_RESPOND_TO_BUTTON4(void);
void RAY_RESPOND_TO_BUTTON3(void);
void RAY_RESPOND_TO_FIRE0(void);
void RAY_RESPOND_TO_FIRE1(void);
int FUN_80185fc0(short param_1);
void FUN_80186070(short param_1,short *param_2,undefined2 *param_3);
void FUN_8018611c(void);
void FUN_801861c0(int param_1);
void FUN_80186448(void);
void RAY_FIN_BALANCE(void);
void RayTestBlocSH(void);
void FUN_80186b84(void);
void STOPPE_RAY_CONTRE_PAROIS(uint param_1);
void RAY_IN_THE_AIR(void);
void terminateFistWhenRayDies(void);
void snifRayIsDead(undefined4 rayPtr);
void rayfallsinwater(void);
bool RAY_DEAD(void);
void RAY_HURT(void);
void RepousseRay(void);
undefined4 RayEstIlBloque(void);
void stackRay(void);
void RAY_SURF(void);
void FUN_80188570(void);
void DO_MORT_DE_RAY(void);
void findMereDenisWeapon(void);
void setBossScrollLimits(Obj *param_1);
bool FUN_80188ac0(int param_1);
int FUN_80188c18(int param_1,char param_2);
void setCirclePointToReach(void);
void FUN_80188df4(int param_1);
void FUN_80189010(void);
void mereDenisDropBomb(int param_1);
void FUN_80189548(Obj *param_1,uint param_2);
void swapMereDenisCollZones(Obj *obj,bool param_2);
byte prepareNewMereDenisAttack(Obj *param_1);
void FUN_8018a99c(int param_1,char param_2);
void allocateSpaceMamaLaser(Obj *param_1,ObjType param_2);
void doMereDenisCommand(int param_1);
void changeMereDenisPhase(void);
void fitSaveCurrentAction(void);
void doMereDenisHit(Obj *param_1,short param_2);
void setBossReachingSpeeds(int param_1,uint param_2,uint param_3,uint param_4);
bool testActionEnd(int param_1);
int firstFloorBelow(Obj *obj);
void FUN_8018b930(int param_1);
void FUN_8018ba1c(Obj *param_1,int param_2);
void FUN_8018bb2c(Obj *param_1);
void FUN_8018bd3c(Obj *param_1);
void CalcObjPosInWorldMap(Obj *obj);
void DoScrollInWorldMap(short param_1,short param_2);
void FUN_8018c0dc(short param_1,short param_2,short param_3,short param_4);
void FUN_8018c1d4(void);
void FUN_8018c30c(void);
void DO_MEDAILLONS(void);
void INIT_LEVEL_STAGE_NAME(void);
void INIT_WORLD_STAGE_NAME(void);
void INIT_STAGE_NAME(void);
void CHANGE_STAGE_NAMES(void);
void FUN_8018d6f4(void);
void FUN_8018d9e0(void);
void INIT_WORLD_INFO(void);
void INIT_LITTLE_RAY(void);
void RESTORE_RAY(void);
void INIT_CHEMIN(void);
void RESPOND_TO_UP(void);
void RESPOND_TO_DOWN(void);
void RESPOND_TO_RIGHT(void);
void RESPOND_TO_LEFT(void);
void FUN_8018e1a4(void);
void FUN_8018e1fc(void);
void DO_CHEMIN(void);
void INIT_PASTILLES_SAUVE(void);
void PASTILLES_SAUVE_SAVED(short param_1);
void FIN_WORLD_CHOICE(void);
void DETER_WORLD_AND_LEVEL(void);
void INIT_NEW_GAME(void);
void POINTEUR_BOUTONS_OPTIONS_BIS(void);
void FUN_8018f090(short param_1,short param_2,short param_3,undefined param_4);
void INIT_CONTINUE(void);
void CHEAT_MODE_CONTINUE(void);
void MAIN_CONTINUE_PRG(void);
void FIN_CONTINUE_PRG(void);
void MAIN_NO_MORE_CONTINUE_PRG(void);
void INIT_VIGNET(void);
void INIT_CREDITS(void);
void DO_CREDITS(void);
void FUN_80190998(void);
void DO_LOADER_ANIM(void);
void SPECIAL_INIT(void);
void FUN_80190ee4(int param_1,int param_2);
void set_rubis_list(void);
void allocate_rayon(short param_1,short param_2);
void allocate_8_petits_rayons(short param_1,short param_2);
void FUN_801913f4(void);
void do_sko_rayon2(void);
void FUN_801919d0(int param_1,short param_2);
void start_sko_rayon2(int param_1,short param_2);
void lance_pince(int param_1);
undefined4 sko_get_eject_sens(void);
void DO_SOL_ENFONCE(void);
void DO_SKO_PHASE_0(Obj *param_1);
void DO_SKO_PHASE_1(int param_1);
void DO_SKO_PHASE_2(Obj *param_1);
void DO_SKO_PHASE_3(Obj *param_1);
void DO_SKO_PINCE(Obj *param_1);
void DO_SCORPION_COLLISION(Obj *param_1);
void DO_SCORPION_MORT(int param_1);
void DO_SKO(Obj *param_1);
void FUN_80192bf0(Obj *param_1);
void DO_SKO_HIT(Obj *param_1);
bool MURDUR(short param_1,short param_2);
int FUN_80192e18(undefined2 param_1,int param_2,int param_3);
int FUN_80192ebc(ushort param_1,short param_2,short param_3);
undefined4 calc_typ_trav(Obj *obj,char param_2);
undefined calc_typ_travd(Obj *param_1,char param_2);
void TEST_FIN_BLOC(Obj *obj);
undefined4 TEST_IS_ON_RESSORT_BLOC(int param_1);
undefined4 FUN_8019395c(int param_1);
void CALC_MOV_ON_BLOC(Obj *obj);
void recale_position(int param_1);
void getIdealStingCoords(int param_1,short *param_2,short *param_3);
bool closeEnoughToSting(int param_1,uint param_2,uint param_3);
void FUN_8019423c(Obj *param_1);
bool moskitoCanAttak(int param_1);
int setMoskitoAtScrollBorder(int param_1,char param_2);
void prepareNewMoskitoAttack(Obj *param_1);
Obj * allocateMoskitoFruit(Obj *param_1,uint param_2,undefined4 param_3,ObjType param_4);
void moskitoDropFruitOnRay(Obj *param_1,uint param_2);
void doMoskitoCommand(Obj *param_1);
byte tellNextMoskitoAction(void);
void changeMoskitoPhase(int param_1);
void doMoskitoHit(Obj *obj);
void FUN_80195e80(int param_1,int param_2);
void DO_BAT_LEFT_FLASH(Obj *param_1);
void DO_BAT_RIGHT_FLASH(Obj *param_1);
void DO_BAT_LEFT_RIGHT_FLASH(Obj *param_1);
bool bat_dir(int param_1);
void bat_init_scroll(int param_1);
void DO_BAT_COMMAND(Obj *obj);
void FUN_80196a24(Obj *param_1);
void DO_BAT_POING_COLLISION(Obj *bat);
int bat_get_eject_sens(void);
void DO_PIRATE_POELLE_POING_COLLISION(Obj *param_1);
void FUN_80197124(Obj *param_1);
void PlaceDarkPhase1et2(Obj *param_1);
void FUN_80197238(void);
void init_vitraux(void);
undefined4 poing_face_obj(int param_1);
void DARK_phase1(Obj *param_1);
void DARK_phase3(undefined4 param_1);
void DO_DARK_COMMAND(Obj *obj);
void FUN_80198438(Obj *param_1);
void FUN_801984b0(Obj *param_1);
void DO_DARK_SORT_COMMAND(Obj *param_1,short param_2);
void FUN_801988d4(int param_1);
void allocate_DARK_SORT(short param_1,short param_2,undefined1 param_3,short param_4);
void FUN_80198b9c(void);
void corde_en_haut(char param_1);
void init_corde(int param_1);
void goto_phase1(Obj *param_1);
void goto_phase2(int param_1);
void goto_phase3(Obj *param_1);
void goto_phase5(int param_1);
void DO_VITRAIL_COMMAND(Obj *obj);
bool FUN_80199154(int param_1,short *param_2,short param_3,short param_4);
void FUN_80199680(Obj *param_1);
void START_UFO(Obj *param_1);
void allocateSTOSKO(void);
void allocateMOSKITOMAMA(void);
void FUN_80199aec(void);
void FUN_80199be8(Obj *obj);
void FUN_80199e00(int param_1);
void FUN_8019a314(Obj *param_1,ushort param_2);
void FUN_8019ab00(Obj *param_1);
void FUN_8019acb4(Obj *param_1);
void FUN_8019adb8(Obj *param_1);
int FUN_8019b070(Obj *param_1,Obj *param_2);
void AllocateDarkPhase2(int param_1);
void DO_DARK2_AFFICHE_TEXT(void);
void DO_DARK_PHASE2_COMMAND(Obj *obj);
void DO_DARK2_SORT_COMMAND(Obj *param_1);
void FUN_8019c464(short param_1,short param_2,undefined1 param_3,short param_4);
void AllocateFlammes(short param_1);
void FUN_8019c804(void);
void ToonDonnePoing(int param_1);
void FUN_8019d188(undefined4 param_1);
void FUN_8019d1dc(Obj *param_1);
void FUN_8019d294(Obj *param_1,short param_2,char param_3);
void FUN_8019d4a4(int param_1);
void FUN_8019d558(Obj *param_1);
void FUN_8019d950(Obj *param_1);
void FUN_8019dcdc(void);
void FUN_8019dd74(void);
void FUN_8019df1c(int param_1);
void FUN_8019e01c(void);
void LOAD_ALL_FIX(void);
void load_world(short worldIndex);
void load_level(void);
void FUN_8019e694(void);
void FUN_8019e770(void);
void PS1_LoadVideoTables(void);
void PS1_LoadFont(void);
void LogoInit(void);
void FUN_8019e994(void);
void FUN_8019ea10(void);
void LOAD_SAVE_SCREEN(void);
void FUN_8019eb30(void);
void LOAD_CREDITS_VIGNET(void);
void LOAD_VIGNET_GAME(void);
void PS1_CheckPauseAndCheatInputs(void);
void FUN_8019f8d0(void);
void FUN_8019fa94(char param_1);
void FUN_8019fb84(void);
void FUN_8019fd40(void);
void FUN_8019fdd0(void);
void FUN_8019fe8c(void);
void FUN_8019fecc(void);
void FUN_8019feec(void);
void DEPART_WORLD(void);
void DEPART_LEVEL(void);
void FUN_801a027c(void);
void FUN_801a02bc(void);
void FUN_801a0328(void);
void FUN_801a03c4(int param_1);
void PS1_sprintf(short param_1,char *param_2);
void FUN_801a07ec(void);
void FUN_801a0828(void);
bool FUN_801a0964(void);
bool FUN_801a0b38(void);
void FUN_801a0be0(void);
void FUN_801a0c68(void);
void FUN_801a0c98(void);
void FUN_801a0cd8(void);
void FUN_801a0e08(void);
void FUN_801a0ef0(void);
void FUN_801a1110(void);
void PS1_PromptMemoryCard(void);
void FUN_801a1324(void);
bool FUN_801a1398(void);
bool FUN_801a141c(void);
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
void PS1_UnusedGenerateAndPrintPassword(short param_1,short param_2,undefined param_3,undefined param_4);
void PS1_ClearPassword(void);
void FUN_801a2c78(void);
void FUN_801a2d40(void);
void FUN_801a3064(void);
void FUN_801a3550(void);
void PS1_GenerateAndDisplayPassword(void);
void FUN_801a36b4(void);
void DO_MENU(void);
void FUN_801a391c(void);
void FUN_801a39ec(void);
void PS1_ShowDemoText(void);
bool PS1_DemoLoop(void);
void PS1_PlayDemo(void);
void FUN_801a3cb4(void);
void FUN_801a3f54(void);
void FUN_801a42e8(void);
void FUN_801a44ec(void);
undefined4 FUN_801a453c(void);
undefined4 selection_save_option_prg(void);
void DO_SAVE_CHOICE(void);
void AFFICHE_ECRAN_SAVE(void);
undefined4 FUN_801a4d38(void);
void FUN_801a4e90(void);
void FUN_801a4ee8(void);
void INIT_SAVE_CHOICE(void);
void INIT_SAVE_CONTINUE(void);
void DO_COMMANDE_SAVE(void);
void SELECTION_SAVE_OPTION(void);
void FUN_801a5f94(void);
void FUN_801a6034(void);
void REALISATION_ACTION(void);
void FUN_801a6808(void);
void FUN_801a6984(void);
void FUN_801a6a04(char param_1);
void FUN_801a6a68(void);
void FUN_801a76e4(void);
undefined4 PS1_PadInit(int param_1);
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
void cd_cw(byte param_1,int param_2,undefined4 param_3,undefined4 param_4);
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
int CD_cw(byte param_1,undefined *param_2,undefined4 param_3,int param_4);
void BIOS_OBJ_9F4(void);
undefined4 CD_vol(undefined *param_1);
int CD_init(void);
undefined4 CD_readm(undefined4 address,int size,undefined4 param_3);
undefined4 BIOS_OBJ_BFC(undefined4 param_1);
void BIOS_OBJ_CDC(void);
int CD_readsync(int param_1,undefined4 param_2);
void cb_read(int param_1,undefined4 param_2);
void BIOS_OBJ_E40(void);
undefined4 CD_read(undefined4 param_1,uint param_2);
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
bool cd_read(int param_1,int param_2,u_long *param_3);
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
uint FUN_801abd78(void);
void FUN_801abfd0(undefined4 param_1,undefined2 param_2);
void FUN_801ac400(void);
byte FUN_801ac4d0(int param_1,int param_2);
void SpuVmDoAllocate(void);
void FUN_801ac7b0(uint param_1);
void FUN_801acb4c(uint param_1,undefined2 param_2,undefined2 param_3);
void FUN_801acc7c(uint param_1);
uint FUN_801accc0(void);
uint note2pitch2(int param_1,uint param_2);
void FUN_801ace80(uint param_1,short param_2);
void FUN_801ad064(void);
void FUN_801ad06c(void);
void FUN_801ad07c(short param_1,short param_2,short param_3);
void FUN_801ad0b0(short param_1);
void FUN_801ad0d4(byte param_1);
void FUN_801ad3e0(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4);
void FUN_801ad470(void);
void FUN_801ad504(undefined2 param_1,undefined2 param_2);
int FUN_801ad530(ushort param_1,short param_2,short param_3,int param_4);
void SpuVmFlush(void);
uint SpuVmKeyOn(ushort param_1,short param_2,short param_3,undefined2 param_4,short param_5,undefined param_6);
char SpuVmKeyOff(short param_1,short param_2,short param_3,uint param_4);
void SpuVmSeKeyOn(short param_1,short param_2,undefined2 param_3,undefined4 param_4,ushort param_5,ushort param_6);
void FUN_801ae138(short param_1,short param_2,undefined2 param_3);
uint SpuVmSetSeqVol(uint param_1,short param_2,short param_3,short param_4);
int SpuVmGetSeqVol(uint param_1,undefined2 *param_2,undefined2 *param_3);
int FUN_801ae39c(uint param_1);
int FUN_801ae3d4(uint param_1);
int FUN_801ae40c(uint param_1,undefined2 *param_2);
void SpuVmSetProgVol(short param_1);
uint FUN_801ae4e8(short param_1,short param_2,undefined param_3);
uint SpuVmGetProgVol(short param_1,short param_2);
uint SpuVmSetProgPan(short param_1,short param_2,undefined param_3);
uint SpuVmGetProgPan(short param_1,short param_2);
uint SsUtKeyOn(short param_1,ushort param_2,byte param_3,short param_4,short param_5,short param_6,short param_7);
undefined4 SsUtKeyOff(ushort param_1,short param_2,short param_3,short param_4,short param_5);
int SsUtKeyOnV(ushort param_1,short param_2,ushort param_3,byte param_4,short param_5,short param_6,short param_7,short param_8);
undefined4 FUN_801aefa4(ushort param_1);
int FUN_801af018(undefined4 param_1,short param_2,short param_3,undefined4 param_4,short param_5);
undefined4 SsUtChangePitch(ushort param_1,short param_2,short param_3,short param_4,undefined4 param_5,short param_6,short param_7);
undefined4 SsUtChangeADSR(ushort param_1,short param_2,short param_3,short param_4,undefined2 param_5,undefined2 param_6);
undefined4 FUN_801af294(ushort param_1,undefined2 *param_2,undefined2 *param_3);
undefined4 FUN_801af2ec(ushort param_1,undefined2 param_2,undefined2 param_3);
undefined4 FUN_801af360(ushort param_1,short *param_2,short *param_3);
undefined4 FUN_801af410(ushort param_1,short param_2,short param_3);
undefined4 FUN_801af4a8(ushort param_1);
undefined4 FUN_801af4c4(ushort param_1);
void FUN_801af4e0(void);
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
void SSINIT_OBJ_62C(ulong param_1);
void SSINIT_OBJ_658(void);
void SsStart(void);
void SsStart2(void);
void SsEnd(void);
void SsQuit(void);
void FUN_801aff20(void);
void FUN_801aff34(void);
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
void _SsSetControlChange(ushort param_1,short param_2,undefined param_3);
void FUN_801b1b9c(ushort param_1,short param_2,uchar param_3);
void FUN_801b1cbc(ushort param_1,short param_2,uchar param_3);
void _SsContPortamento(ushort param_1,short param_2,byte param_3);
void _SsContResetAll(short param_1,short param_2);
void FUN_801b2034(ushort param_1,short param_2,undefined param_3);
void _SsContNrpn2(short param_1,short param_2,char param_3);
void _SsContRpn1(short param_1,short param_2,undefined param_3);
void _SsContRpn2(short param_1,short param_2,undefined param_3);
void _SsContDataEntry(short param_1,short param_2,undefined param_3);
void _SsSndSetVabAttr(short param_1,short param_2,short param_3,uint param_4);
void _SsSetPitchBend(short param_1,short param_2);
void FUN_801b2d1c(short param_1,short param_2,char param_3);
int ReadDeltaValue(int param_1,short param_2);
void Snd_nextseq(short param_1,short param_2);
void SsUtResolveADSR(uint param_1,uint param_2,ushort *param_3);
void SsUtBuildADSR(ushort *param_1,ushort *param_2,ushort *param_3);
short SsUtGetVagAtr(short param_1,short param_2,short param_3,VagAtr *param_4);
void UT_GVA_OBJ_228(void);
short SsUtSetVagAtr(short param_1,short param_2,short param_3,VagAtr *param_4);
void UT_SVA_OBJ_1B4(void);
void FUN_801b3744(void);
short SsUtGetProgAtr(short param_1,short param_2,ProgAtr *param_3);
void UT_GPA_OBJ_F4(void);
void FUN_801b3860(void);
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
void FUN_801b53a0(void);
undefined4 _spu_init(int param_1);
undefined4 FUN_801b5660(void);
undefined4 FUN_801b5688(void);
void FUN_801b56b0(void);
void FUN_801b56e0(void);
undefined4 _spu_write(undefined4 param_1,undefined4 param_2);
void _spu_writeByIO(undefined2 *param_1,uint param_2);
undefined4 FUN_801b5978(undefined4 param_1,undefined4 param_2);
void _spu_t(undefined4 param_1,uint param_2);
void FUN_801b5b60(undefined4 param_1,uint param_2);
void FUN_801b5c70(undefined4 param_1,undefined2 param_2,int param_3);
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
undefined4 SetRCnt(uint param_1,undefined2 param_2,uint param_3);
undefined4 COUNTER_OBJ_74(void);
void COUNTER_OBJ_94(void);
undefined4 GetRCnt(ushort param_1);
void COUNTER_OBJ_CC(void);
bool StartRCnt(uint param_1);
undefined4 StopRCnt(uint param_1);
undefined4 ResetRCnt(uint param_1);
void COUNTER_OBJ_168(void);
long DisableEvent(long event);
void DeliverEvent(ulong ev1,ulong ev2);
long StartPAD(void);
void ChangeClearPAD(long val);
void InitHeap(ulong *head,ulong size);
void _bu_init(void);
void nextfile(void);
long OpenEvent(ulong desc,long spec,long mode,long *func);
long read(long fd,void *buf,long n);
long TestEvent(long event);
void ExitCriticalSection(void);
long open(char *devname,ulong flag);
void _96_remove(void);
void firstfile(void);
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
undefined4 FUN_801bd104(int param_1);
undefined4 SetGraphDebug(int param_1);
undefined4 GetGraphType(void);
undefined4 FUN_801bd248(void);
undefined4 FUN_801bd258(undefined4 param_1);
void FUN_801bd270(int param_1);
int DrawSync(int mode);
void FUN_801bd2e0(undefined4 param_1,uint param_2,uint param_3,uint param_4);
void LoadImage(undefined4 param_1,undefined4 param_2);
void StoreImage(undefined4 param_1,undefined4 param_2);
void FUN_801bd3a8(undefined4 *param_1,uint vramX,int vramY);
uint * FUN_801bd414(uint *param_1,int param_2);
undefined4 ClearOTagR(undefined4 param_1);
void DrawPrim(u_long *param_1);
void FUN_801bd524(u_long *param_1);
undefined4 * FUN_801bd57c(undefined4 *param_1);
undefined4 * FUN_801bd63c(undefined4 *param_1);
undefined4 * FUN_801bd69c(undefined4 *param_1);
void FUN_801bda18(undefined4 *param_1);
void SetTexWindow(int param_1,undefined4 param_2);
void SetDrawArea(int param_1,short *param_2);
void SetDrawOffset(int param_1,undefined2 *param_2);
void FUN_801bdb64(int param_1,int param_2,int param_3);
void SetDrawMode(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
void SetDrawEnv(int param_1,undefined4 *param_2);
uint get_mode(int param_1,int param_2,uint param_3);
uint get_cs(short param_1,uint param_2);
uint get_ce(short param_1,uint param_2);
uint get_ofs(uint param_1,uint param_2);
uint get_tw(byte *param_1);
uint FUN_801be134(short *param_1);
undefined4 FUN_801be20c(void);
int _otc(int param_1,int param_2);
undefined4 _dws(short *param_1,undefined4 *param_2);
undefined4 _drs(undefined4 *param_1,undefined4 *param_2);
void FUN_801bead0(uint param_1);
uint FUN_801beb08(int param_1);
undefined4 _cwb(undefined4 *param_1,int param_2);
void FUN_801beb74(undefined4 param_1);
uint FUN_801bebc4(uint param_1);
void FUN_801bebf8(undefined4 param_1,undefined4 param_2,undefined4 param_3);
uint FUN_801bec1c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);
undefined4 FUN_801bee08(void);
uint _reset(int param_1);
uint _sync(int param_1);
void set_alarm(void);
undefined4 SetGraphQueue(void);
void FUN_801bf470(undefined *param_1,undefined *param_2,int param_3);
void FUN_801bf4a0(undefined *param_1,undefined param_2,int param_3);
void GPU_cw(void);
u_short LoadTPage(u_long *pix,int tp,int abr,int x,int y,int w,int h);
u_short EXT_OBJ_A8(void);
u_short EXT_OBJ_AC(void);
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
int MDEC_vlc(ushort *param_1,ushort *param_2);
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