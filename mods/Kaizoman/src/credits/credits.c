#include <export.h>
#include "credits_strings.h"

// 109 are defined originally. We add 9 more and modify the first.
Credit credits[118] =
{
    {
        .text = (char *)&credits_kaizoman_header,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 1, .cmd = 4, .color = 0
    },
    {
        .text = (char *)&credits_design_subheader,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 2
    },
    {
        .text = (char *)&credits_destabilize,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 2
    },
    {
        .text = (char *)&credits_eightsixthree,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 2
    },
    {
        .text = (char *)&credits_kronkie,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 2
    },
    {
        .text = (char *)&credits_thextera,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 2
    },
    {
        .text = (char *)&credits_wordofwind,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 3, .color = 2
    },
    {
        .text = (char *)&credits_programming_subheader,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 7
    },
    {
        .text = (char *)&credits_raycarrot,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 5, .color = 7
    },

    {
        .text = (char *)&credits_originalcredits_header,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 1, .cmd = 4, .color = 0
    },

    {
        .text = (char *)0x80125C10,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 2
    },
    {
        .text = (char *)0x80125C00,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 2
    },
    {
        .text = (char *)0x80125BEC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 3, .color = 2
    },
    {
        .text = (char *)0x80125BD4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 0
    },
    {
        .text = (char *)0x80125BC0,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 3, .color = 0
    },
    {
        .text = (char *)0x80125BB4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 7
    },
    {
        .text = (char *)0x80125C00,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 7
    },
    {
        .text = (char *)0x80125BA4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 7
    },
    {
        .text = (char *)0x801CEE54,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 7
    },
    {
        .text = (char *)0x80125B94,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 7
    },
    {
        .text = (char *)0x80125B80,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 7
    },
    {
        .text = (char *)0x80125B70,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 7
    },
    {
        .text = (char *)0x80125B58,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 3, .color = 7
    },
    {
        .text = (char *)0x80125B48,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 11
    },
    {
        .text = (char *)0x80125BC0,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x801CEE54,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125B34,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125B24,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125B10,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125AFC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125AEC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125AD4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125AC0,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125AAC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125A94,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 3, .color = 11
    },
    {
        .text = (char *)0x80125A7C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 14
    },
    {
        .text = (char *)0x80125A6C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 14
    },
    {
        .text = (char *)0x80125A58,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 3, .color = 14
    },
    {
        .text = (char *)0x80125A40,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 13
    },
    {
        .text = (char *)0x80125A20,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 13
    },
    {
        .text = (char *)0x80125A10,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 13
    },
    {
        .text = (char *)0x801259F8,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 13
    },
    {
        .text = (char *)0x801259E4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 13
    },
    {
        .text = (char *)0x801259D0,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 13
    },
    {
        .text = (char *)0x801259BC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 3, .color = 13
    },
    {
        .text = (char *)0x801259AC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 8
    },
    {
        .text = (char *)0x8012599C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125988,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125978,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x801CEE54,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125964,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125950,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x8012593C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x8012592C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125918,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125904,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x801258F0,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x801258DC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125BEC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x801258C8,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x801258B4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x8012589C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125888,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125878,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125864,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125850,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 8
    },
    {
        .text = (char *)0x80125838,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 3, .color = 8
    },
    {
        .text = (char *)0x80125820,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 11
    },
    {
        .text = (char *)0x80125808,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x801257F8,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x801CEE54,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x801257E4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x801257D0,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x801257BC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x801257AC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x8012579C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125788,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125770,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x8012575C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125748,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125734,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125720,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125710,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 11
    },
    {
        .text = (char *)0x80125700,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 4, .color = 11
    },
    {
        .text = (char *)0x801256F4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 2
    },
    {
        .text = (char *)0x801256E4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 2
    },
    {
        .text = (char *)0x801256D0,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 2
    },
    {
        .text = (char *)0x801256C0,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 2
    },
    {
        .text = (char *)0x801256AC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 4, .color = 2
    },
    {
        .text = (char *)0x801256A0,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 1
    },
    {
        .text = (char *)0x80125BA4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x801CEE54,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125690,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x8012567C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x801259F8,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125B94,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125664,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125650,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125B80,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125640,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125B70,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125630,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125620,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125608,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x80125B58,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x801255F4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 3, .color = 1
    },
    {
        .text = (char *)0x801255DC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 3
    },
    {
        .text = (char *)0x801255CC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 3, .color = 3
    },
    {
        .text = (char *)0x801255BC,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 7
    },
    {
        .text = (char *)0x8012559C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 2, .color = 7
    },
    {
        .text = (char *)0x8012558C,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 8
    },
    {
        .text = (char *)0x80125568,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 2, .color = 8
    },
    {
        .text = (char *)0x80125558,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 102, .color = 9
    },
    {
        .text = (char *)0x80125538,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 4, .color = 9
    },
    {
        .text = (char *)0x80125510,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 0, .color = 2
    },
    {
        .text = (char *)0x801254F4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 2, .cmd = 6, .color = 2
    },
    {
        .text = (char *)0x801254E4,
        .x_pos = 0xA0, .y_pos = 0x0,
        .font = 1, .cmd = 0, .color = 1
    },
    {
        .text = (char *)0x801CEE4C,
        .x_pos = 0xC8, .y_pos = 0x0,
        .font = 2, .cmd = 255, .color = 0
    },
};
