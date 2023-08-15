#include "PS1_LoadSave_dec.h"

/*
testing method:
copy slot with 01-09 number pattern over itself
*/
void PS1_LoadSave_dec(undefined4 param_1,char *param_2)
{
    undefined4 uVar1;
    long file;
    byte fileBuffer [128];

    vis_type=Read;
    vis_reset();

    file = open(param_2,1);
    if (file == -1) {
        FntPrint("\nCan\'t open file\n");
    }
    else {
        vis_fd=file;
        vis_buf=(char *)&fileBuffer;
        vis_n=0x80;

        SYNCHRO_LOOP(vis);
        SYNCHRO_LOOP(vis);
        SYNCHRO_LOOP(vis);
        SYNCHRO_LOOP(vis);
        SYNCHRO_LOOP(vis);
        SYNCHRO_LOOP(vis);
        nb_continue = fileBuffer[0];
        SYNCHRO_LOOP(vis);
        memcpy(&wi_save_zone, &fileBuffer, sizeof(wi_save_zone));
        SYNCHRO_LOOP(vis);
        RayEvts.flags0 = fileBuffer[0];
        RayEvts.flags1 = fileBuffer[1];
        SYNCHRO_LOOP(vis);
        memcpy(&poing, &fileBuffer, sizeof(poing));
        SYNCHRO_LOOP(vis);
        memcpy(&status_bar, &fileBuffer, sizeof(status_bar));
        SYNCHRO_LOOP(vis);
        ray.hit_points = fileBuffer[0];
        vis_buf=(char *)&save_zone;
        vis_n=0xa80;
        SYNCHRO_LOOP(vis);
        vis_buf=(char *)&fileBuffer;
        vis_n=0x80;
        SYNCHRO_LOOP(vis);
        memcpy(&bonus_perfect, &fileBuffer, sizeof(bonus_perfect));
        SYNCHRO_LOOP(vis);
        memcpy((byte *)(&options_jeu)+16, (byte *)(&fileBuffer)+16, 22);
        SYNCHRO_LOOP(vis);
        world_index = fileBuffer[0];
        SYNCHRO_LOOP(vis);
        memcpy(&xwldmapsave, &fileBuffer, sizeof(xwldmapsave));
        SYNCHRO_LOOP(vis);
        memcpy(&ywldmapsave, &fileBuffer, sizeof(ywldmapsave));
        SYNCHRO_LOOP(vis);
        dir_on_wldmap = fileBuffer[0];
        SYNCHRO_LOOP(vis);
        finBosslevel[0] = fileBuffer[0];
        finBosslevel[1] = fileBuffer[1];
        close(file);
        PS1_LoadWiSaveZone();
        POINTEUR_BOUTONS_OPTIONS_BIS();
        SYNCHRO_LOOP(vis_continue);
    }
}