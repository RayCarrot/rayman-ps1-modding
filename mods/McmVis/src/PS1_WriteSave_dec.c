#include "PS1_WriteSave_dec.h"

undefined4 PS1_WriteSave_dec(byte chan_par,uint slot_par)
{
    byte *wi_save;
    int event_res;
    long fd;
    undefined4 succ;
    int cnt;
    char *devname;
    long chan_local;
    uint slot_local;
    CardFrame0 card_frame0;
    byte dir_ray_flags;

    vis_type=Write;
    vis_reset();

    chan_local = (long)chan_par;
    _card_info(chan_local);
    event_res = PS1_TestSwCARD();
    if (event_res - 1U < 2) {
        FntPrint("\nCannot create file\n");
        succ = 0xfc;
    }
    else {
        if (event_res == 3) {
            PS1_TestHwCARDOnce();
            _card_clear(chan_local);
            PS1_TestHwCARD();
        }
        slot_local = slot_par & 0xff;
        PS1_TestSwCARDOnce();
        _card_load(chan_local);
        PS1_TestSwCARD();
        FntPrint("\nSaving file\n");
        devname = (char *)0x801f6100 + slot_local * 0x20;
        if (*devname == 0) {
            sprintf(devname,"bu%02x:%s%s%4u",chan_local,"BISLUS-00005",save_ray[slot_local],
                    (uint)(ushort)PS1_GlobalTimer);
        }
        fd = open(devname,0x10200);
        if (fd == -1) {
            FntPrint("\nCan\'t open file\n");
            succ = 0xfd;
        }
        else {
            PS1_WriteWiSaveZone();
            event_res = slot_local - 1;
            loadInfoRay[event_res].num_cages = 0;
            cnt = 0;
            do {
                wi_save = wi_save_zone + cnt;
                cnt = cnt + 1;
                loadInfoRay[event_res].num_cages = loadInfoRay[event_res].num_cages + (*wi_save >> 2 & 7);
            } while (cnt < 24);
            card_frame0.sc_magic[0] = 'S';
            card_frame0.sc_magic[1] = 'C';
            card_frame0.icon_display_flag = 0x13;
            card_frame0.block_num = 1;
            sprintf(card_frame0.save_title,"Rayman %s %03d%%",save_ray[slot_local],
                    (int)(short)(((uint)loadInfoRay[(slot_local) - 1].num_cages * 100) / 102));
            char *s_Maga = (char *)0x801cf050;
            strncpy(card_frame0.unused,s_Maga,0x1c);
            memcpy(card_frame0.icon_palette, PS1_SaveIconPalette, 0x20);

            vis_fd = fd;
            vis_n = 0x80;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)card_frame0.sc_magic;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)PS1_SaveIcon1;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)PS1_SaveIcon2and3;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)PS1_SaveIcon2and3;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)&nb_continue;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)wi_save_zone;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)&RayEvts;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)&poing;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)&status_bar;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)&ray.hit_points;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)save_zone;
            vis_n = 0xa80;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)bonus_perfect;
            vis_n = 0x80;
            SYNCHRO_LOOP(vis);
            vis_buf = (char *)&options_jeu;
            SYNCHRO_LOOP(vis);
            if (dans_la_map_monde == FALSE) {
                vis_buf = (char *)&world_index;
                SYNCHRO_LOOP(vis);
                vis_buf = (char *)&xwldmapsave;
                SYNCHRO_LOOP(vis);
                vis_buf = (char *)&ywldmapsave;
                SYNCHRO_LOOP(vis);
                vis_buf = (char *)&dir_on_wldmap;
                SYNCHRO_LOOP(vis);
            }
            else {
                vis_buf = (char *)&num_world_choice;
                SYNCHRO_LOOP(vis);
                vis_buf = (char *)&xmap;
                SYNCHRO_LOOP(vis);
                vis_buf = (char *)&ymap;
                SYNCHRO_LOOP(vis);
                dir_ray_flags = (byte)(ray.flags >> 0xe) & 1;
                vis_buf = (char *)&dir_ray_flags;
                SYNCHRO_LOOP(vis);
            }
            vis_buf = (char *)finBosslevel;
            SYNCHRO_LOOP(vis);

            close(fd);
            CHANGE_STAGE_NAMES();
            if(vis_interr){ PS1_Checksum = 0x014b7d69; } //what would be set here, if card was removed
            else{ PS1_Checksum = PS1_CardFilenameChecksum(chan_par); }
            succ = 1;
            SYNCHRO_LOOP(vis_continue);
        }
    }
    return succ;
}