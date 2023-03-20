#include <export.h>

#define RAND_MAX 0x7FFF
#define NUM_ELEMENTS(x)  (sizeof(x) / sizeof((x)[0]))

#define DEBUG // Debug features, remove this for builds

// Extern variables
extern LevelData level;
extern bool PS1_Ingame;
extern Obj ray;

#ifdef DEBUG
    extern short ray_mode;
    extern ushort RayEvts;
#endif

// Function prototypes
void srand(int seed);

// Variables
uint frames = 0;

void init()
{
    srand(frames);
}

void update_timer()
{
    frames++;
}

void check_inputs()
{
    if (PS1_Ingame && PS1_SpecialTOUCHE(INPUT_TRIANGLE))
    {
        //RAY_HURT();
        RAY_HIT(1, (Obj *)0x00);
        //shuffle_objects();
    }

    #ifdef DEBUG
    if (PS1_Ingame && PS1_SpecialTOUCHE(INPUT_SELECT))
    {
        // Unlock powers
        RayEvts |= 1 << 0; // fist
        RayEvts |= 1 << 1; // hang
        RayEvts |= 1 << 2; // helico
        RayEvts |= 1 << 7; // grab
        RayEvts |= 1 << 8; // run
        // Toggle noclip
        ray_mode = -ray_mode;
    }
    #endif
}

#define shuffle_objects_of_types(a) shuffle_objects_of_types_func(NUM_ELEMENTS(a), a)

typedef struct Position {
    short x;
    short y;
} Position;

#define FLAG_ISALIVE 0x400

void shuffle_objects_of_types_func(int numObjectTypes, enum ObjType objectTypes[]) {
        Obj *src;
    Obj *dst;
    byte validObjs[256];
    int validObjsCount = 0;
    byte shuffledObjs[256];
    Position preShuffleCoords[256];

    // Get valid objects
    for (int i = 0; i < level.nb_objects; i++) 
    {
        if (/*(level.objects[i].flags & FLAG_ISALIVE!=0) && */level.objects[i].x_pos > 0 && level.objects[i].y_pos > 0)
        {
            // Check if the object type list contains this object's type
            for(int j=0;j<numObjectTypes;j++) {

                if (level.objects[i].type == objectTypes[j]) {

                    validObjs[validObjsCount] = i;
                    validObjsCount++;
                    break;
                }
            }
        }
    }

    // Set indexes
    for (int i = 0; i < validObjsCount; i++)
    {
        shuffledObjs[i] = i;
    }
    
    // Shuffle
    for (int i = 0; i < validObjsCount - 1; i++) 
    {
        size_t j = i + rand() / (RAND_MAX / (validObjsCount - i) + 1);
        byte t = shuffledObjs[j];
        shuffledObjs[j] = shuffledObjs[i];
        shuffledObjs[i] = t;
    }
    
    // Store pre-shuffle coordinates
    for (int i = 0; i < validObjsCount; i++) 
    {
        src = &level.objects[validObjs[i]];
        preShuffleCoords[i].x = src->init_x_pos;
        preShuffleCoords[i].y = src->init_y_pos;
    }

    // Set positions
    for (int i = 0; i < validObjsCount; i++) 
    {
        src = &level.objects[validObjs[i]];
        dst = &level.objects[validObjs[shuffledObjs[i]]];

        short newX = preShuffleCoords[i].x + src->offset_bx - dst->offset_bx;
        short newY = preShuffleCoords[i].y + src->offset_by - dst->offset_by;

        if (newX < 0)
            newX = 0;

        if (newY < 0)
            newY = 0;

        dst->init_x_pos = dst->x_pos = newX;
        dst->init_y_pos = dst->y_pos = newY;

        // Calculate the screen position
        calc_obj_pos(dst);
        // Check if object on screen
        //if (in_action_zone(dst->screen_x_pos,dst->screen_y_pos,dst, (dst->flags >> 0xb & 1))) {
            make_active(dst, 1);
        //}
    }
}

void shuffle_objects()
{
    init();

    ObjType objectTypesDefault[] = {
        //TYPE_ANNULE_SORT_DARK,
        //TYPE_AUDIOSTART,
        TYPE_BADGUY1,
        TYPE_BADGUY2,
        TYPE_BADGUY3,
        TYPE_BAG1,
        TYPE_BAG3,
        //TYPE_BALLE1,
        //TYPE_BATEAU,
        TYPE_BATTEUR_FOU,
        //TYPE_BB1,
        //TYPE_BB1_VIT,
        //TYPE_BB12,
        //TYPE_BBL,
        TYPE_BIG_CLOWN,
        //TYPE_BLACK_FIST,
        //TYPE_BLACK_RAY,
        //TYPE_BLACKTOON_EYES,
        TYPE_BLACKTOON1,
        TYPE_BNOTE,
        TYPE_BONNE_NOTE,
        //TYPE_BOUM,
        //TYPE_BOUT_TOTEM,
        TYPE_BULLET,
        TYPE_CAGE,
        //TYPE_CAGE2,
        TYPE_CAISSE_CLAIRE,
        //TYPE_CFUMEE,
        TYPE_CHASSEUR1,
        TYPE_CHASSEUR2,
        //TYPE_CLASH,
        TYPE_CLE_SOL,
        TYPE_CLOWN_TNT,
        TYPE_CLOWN_TNT2,
        TYPE_CLOWN_TNT3,
        //TYPE_CORDE,
        //TYPE_CORDE_DARK,
        //TYPE_CORDEBAS,
        //TYPE_COUTEAU,
        TYPE_COUTEAU_SUISSE,
        TYPE_CRAYON_BAS,
        TYPE_CRAYON_HAUT,
        //TYPE_DARD,
        //TYPE_DARD_PLAFOND,
        TYPE_DARK,
        //TYPE_DARK_PHASE2,
        //TYPE_DARK_SORT,
        //TYPE_DARK2_PINK_FLY,
        //TYPE_DARK2_SORT,
        //TYPE_DEMI_RAYMAN,
        TYPE_DESTROYING_DOOR,
        //TYPE_DROP,
        TYPE_DUNE,
        //TYPE_EAU,
        //TYPE_ECLAIR,
        TYPE_ENS,
        //TYPE_ETINC,
        //TYPE_EXPLOSION,
        TYPE_FALLING_CRAYON,
        TYPE_FALLING_OBJ,
        TYPE_FALLING_OBJ2,
        TYPE_FALLING_OBJ3,
        TYPE_FALLING_YING,
        TYPE_FALLING_YING_OUYE,
        TYPE_FEE,
        //TYPE_FIRE_LEFT,
        //TYPE_FIRE_RIGHT,
        TYPE_FISH,
        TYPE_FLAMME2,
        //TYPE_FLASH,
        TYPE_FOURCHETTE,
        TYPE_GENEBADGUY,
        TYPE_GENERATING_DOOR,
        //TYPE_GRAINE,
        TYPE_GROSPIC,
        TYPE_HERSE_BAS,
        TYPE_HERSE_BAS_NEXT,
        TYPE_HERSE_HAUT,
        TYPE_HERSE_HAUT_NEXT,
        //TYPE_HYB_BBF2_D,
        //TYPE_HYB_BBF2_G,
        //TYPE_HYB_BBF2_LAS,
        //TYPE_HYBRIDE_MOSAMS,
        //TYPE_HYBRIDE_STOSKO,
        //TYPE_INDICATOR,
        TYPE_INST_PLAT,
        TYPE_JAUGEUP,
        TYPE_JOE,
        TYPE_KILLING_EYES,
        //TYPE_LANDING_SMOKE,
        //TYPE_LAVE,
        TYPE_LEVIER,
        //TYPE_LIDOLPINK,
        //TYPE_MAMA_PIRATE,
        //TYPE_MEDAILLON_TOON,
        TYPE_MITE,
        TYPE_MITE2,
        TYPE_MORNINGSTAR,
        TYPE_MORNINGSTAR_MOUNTAI,
        //TYPE_MOSKITO,
        //TYPE_MOSKITO2,
        TYPE_MOVE_OUYE,
        //TYPE_MST_COPAIN,
        //TYPE_MST_FRUIT1,
        //TYPE_MST_FRUIT2,
        //TYPE_MST_SCROLL,
        TYPE_MST_SHAKY_FRUIT,
        TYPE_MUS_WAIT,
        TYPE_NEIGE,
        //TYPE_NEN_GRAINE,
        TYPE_NEUTRAL,
        TYPE_NOTE0,
        TYPE_NOTE1,
        TYPE_NOTE2,
        TYPE_NOTE3,
        //TYPE_NOVA2,
        TYPE_ONEUP,
        //TYPE_ONEUP_ALWAYS,
        TYPE_OUYE,
        //TYPE_PAILLETTE,
        //TYPE_PALETTE_SWAPPER,
        //TYPE_PANCARTE,
        TYPE_PETIT_COUTEAU,
        TYPE_PHOTOGRAPHE,
        TYPE_PI,
        //TYPE_PI_BOUM,
        TYPE_PI_MUS,
        //TYPE_PIEDS_RAYMAN,
        //TYPE_PIERREACORDE,
        //TYPE_PIRATE_BOMB,
        //TYPE_PIRATE_GUETTEUR,
        //TYPE_PIRATE_NGAWE,
        TYPE_PIRATE_P_45,
        TYPE_PIRATE_P_D_45,
        TYPE_PIRATE_POELLE,
        TYPE_PIRATE_POELLE_D,
        TYPE_POELLE,
        //TYPE_POELLE_ALWAYS,
        TYPE_POI1,
        TYPE_POI2,
        TYPE_POI3,
        //TYPE_POING,
        //TYPE_POING_FEE,
        TYPE_POING_POWERUP,
        TYPE_POWERUP,
        TYPE_PRI,
        TYPE_PUNAISE2,
        TYPE_PUNAISE3,
        TYPE_PUNAISE4,
        TYPE_PUNAISE5,
        //TYPE_RAY_ETOILES,
        //TYPE_RAY_POS,
        //TYPE_RAYMAN,
        //TYPE_RAYON,
        TYPE_REDUCTEUR,
        //TYPE_RIDEAU,
        //TYPE_RING,
        TYPE_ROLLING_EYES,
        TYPE_ROULETTE,
        TYPE_ROULETTE2,
        TYPE_ROULETTE3,
        //TYPE_SAXO,
        //TYPE_SAXO2,
        //TYPE_SAXO3,
        //TYPE_SCORPION,
        //TYPE_SCROLL,
        //TYPE_SCROLL_SAX,
        //TYPE_SIGNPOST,
        //TYPE_SKO_PINCE,
        //TYPE_SMA_BOMB,
        //TYPE_SMA_BOMB_CHIP,
        //TYPE_SMA_GRAND_LASER,
        //TYPE_SMA_PETIT_LASER,
        //TYPE_SMA_WEAPON,
        //TYPE_SPACE_MAMA2,
        TYPE_SPIDER,
        TYPE_SPIDER_PLAFOND,
        //TYPE_SPLASH,
        TYPE_STALAG,
        TYPE_STONEBOMB,
        TYPE_STONEBOMB2,
        TYPE_STONEBOMB3,
        //TYPE_STONECHIP,
        TYPE_STONEDOG,
        TYPE_STONEDOG2,
        TYPE_STONEMAN1,
        TYPE_STONEMAN2,
        TYPE_STONEWOMAN,
        TYPE_STONEWOMAN2,
        //TYPE_STOSKO_PINCE,
        //TYPE_SUPERHELICO,
        TYPE_TAMBOUR1,
        TYPE_TAMBOUR2,
        //TYPE_TARZAN,
        TYPE_TIBETAIN,
        TYPE_TIBETAIN_2,
        TYPE_TIBETAIN_6,
        TYPE_TIRE_BOUCHON,
        //TYPE_TNT_BOMB,
        //TYPE_TOTEM,
        TYPE_TROMPETTE,
        //TYPE_UFO_IDC,
        //TYPE_VAGUE_DERRIERE,
        //TYPE_VAGUE_DEVANT,
        TYPE_WALK_NOTE_1,
        TYPE_WALK_NOTE_2,
        //TYPE_WASHING_MACHINE,
        TYPE_WAT_CLOWN,
        TYPE_WIZ,
        TYPE_WIZARD1
    };
    
    ObjType objectTypesPlatforms[] = {
        TYPE_AUTOJUMP_PLAT,
        //TYPE_BB1_PLAT,
        TYPE_BOING_PLAT,
        TYPE_BON3,
        TYPE_BOUEE_JOE,
        TYPE_CRUMBLE_PLAT,
        TYPE_CYMBAL1,
        TYPE_CYMBALE,
        TYPE_FALLPLAT,
        TYPE_GOMME,
        TYPE_LIFTPLAT,
        TYPE_MARK_AUTOJUMP_PLAT,
        TYPE_MARTEAU,
        TYPE_MOVE_AUTOJUMP_PLAT,
        TYPE_MOVE_MARTEAU,
        TYPE_MOVE_PLAT,
        TYPE_MOVE_RUBIS,
        TYPE_MOVE_START_NUA,
        TYPE_MOVE_START_PLAT,
        TYPE_ONOFF_PLAT,
        TYPE_PLATFORM,
        TYPE_PT_GRAPPIN, // rings
        TYPE_PUNAISE1,
        TYPE_RUBIS,
        TYPE_SLOPEY_PLAT,
        TYPE_SWING_PLAT,
        TYPE_MARACAS,
        //TYPE_MARACAS_BAS
    };
    
    shuffle_objects_of_types(objectTypesDefault);
    shuffle_objects_of_types(objectTypesPlatforms);
}
