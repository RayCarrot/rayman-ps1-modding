#include <export.h>
#include "t_world_info_strings.h"

// Modified the positions, paths and level names

WorldInfo t_world_info[24] =
{
    // Pink Plant Woods
    {
        .x_pos = 0x1D, .y_pos = 0x108,
        .index_up = 18, .index_down = 0, .index_left = 0, .index_right = 1,
        .state = 1, .nb_cages = 0,
        .world = 1, .level = 1,
        .color = 0, .level_name = (char *)&level_name_01
    },
    // Anguish Lagoon
    {
        .x_pos = 0x47, .y_pos = 0x104,
        .index_up = 2, .index_down = 1, .index_left = 0, .index_right = 1,
        .state = 0, .nb_cages = 0,
        .world = 1, .level = 5,
        .color = 12, .level_name = (char *)&level_name_02
    },
    // The Swamps of Forgetfulness
    {
        .x_pos = 0x3D, .y_pos = 0xDA,
        .index_up = 2, .index_down = 1, .index_left = 2, .index_right = 3,
        .state = 0, .nb_cages = 0,
        .world = 1, .level = 9,
        .color = 3, .level_name = (char *)&level_name_03
    },
    // Moskito's Nest
    {
        .x_pos = 0x76, .y_pos = 0xEE,
        .index_up = 4, .index_down = 3, .index_left = 2, .index_right = 3,
        .state = 0, .nb_cages = 0,
        .world = 1, .level = 12,
        .color = 2, .level_name = (char *)&level_name_04
    },
    // Bongo Hills
    {
        .x_pos = 0x7F, .y_pos = 0xC2,
        .index_up = 4, .index_down = 3, .index_left = 4, .index_right = 5,
        .state = 0, .nb_cages = 0,
        .world = 2, .level = 1,
        .color = 3, .level_name = (char *)&level_name_05
    },
    // Allegro Presto
    {
        .x_pos = 0xAB, .y_pos = 0xD1,
        .index_up = 5, .index_down = 19, .index_left = 4, .index_right = 8,
        .state = 0, .nb_cages = 0,
        .world = 2, .level = 7,
        .color = 10, .level_name = (char *)&level_name_06
    },
    // Gong Heights
    {
        .x_pos = 0x6D, .y_pos = 0x8E,
        .index_up = 7, .index_down = 6, .index_left = 20, .index_right = 10,
        .state = 0, .nb_cages = 0,
        .world = 2, .level = 12,
        .color = 3, .level_name = (char *)&level_name_07
    },
    // Mr Sax's Hullaballoo
    {
        .x_pos = 0x90, .y_pos = 0x4F,
        .index_up = 7, .index_down = 6, .index_left = 7, .index_right = 11,
        .state = 0, .nb_cages = 0,
        .world = 2, .level = 14,
        .color = 5, .level_name = (char *)&level_name_08
    },
    // Twilight Gulch
    {
        .x_pos = 0xDC, .y_pos = 0xCA,
        .index_up = 9, .index_down = 8, .index_left = 5, .index_right = 8,
        .state = 0, .nb_cages = 0,
        .world = 3, .level = 1,
        .color = 14, .level_name = (char *)&level_name_09
    },
    // The Hard Rocks
    {
        .x_pos = 0xD1, .y_pos = 0xA1,
        .index_up = 10, .index_down = 8, .index_left = 10, .index_right = 9,
        .state = 0, .nb_cages = 0,
        .world = 3, .level = 3,
        .color = 12, .level_name = (char *)&level_name_10
    },
    // Mr Stone's Peaks
    {
        .x_pos = 0xA9, .y_pos = 0x90,
        .index_up = 10, .index_down = 10, .index_left = 6, .index_right = 9,
        .state = 0, .nb_cages = 0,
        .world = 3, .level = 6,
        .color = 15, .level_name = (char *)&level_name_11
    },
    // Eraser Plains
    {
        .x_pos = 0xFC, .y_pos = 0x8B,
        .index_up = 21, .index_down = 12, .index_left = 7, .index_right = 11,
        .state = 0, .nb_cages = 0,
        .world = 4, .level = 1,
        .color = 1, .level_name = (char *)&level_name_12
    },
    // Pencil Pentathlon
    {
        .x_pos = 0x105, .y_pos = 0xBD,
        .index_up = 11, .index_down = 12, .index_left = 12, .index_right = 13,
        .state = 0, .nb_cages = 0,
        .world = 4, .level = 5,
        .color = 9, .level_name = (char *)&level_name_13
    },
    // Space Mama's Crater
    {
        .x_pos = 0x12C, .y_pos = 0x95,
        .index_up = 22, .index_down = 13, .index_left = 12, .index_right = 14,
        .state = 0, .nb_cages = 0,
        .world = 4, .level = 8,
        .color = 15, .level_name = (char *)&level_name_14
    },
    // Crystal Palace
    {
        .x_pos = 0x14B, .y_pos = 0xBB,
        .index_up = 13, .index_down = 15, .index_left = 13, .index_right = 14,
        .state = 0, .nb_cages = 0,
        .world = 5, .level = 1,
        .color = 10, .level_name = (char *)&level_name_15
    },
    // Eat at Joe's
    {
        .x_pos = 0x130, .y_pos = 0xE5,
        .index_up = 14, .index_down = 23, .index_left = 15, .index_right = 16,
        .state = 0, .nb_cages = 0,
        .world = 5, .level = 3,
        .color = 7, .level_name = (char *)&level_name_16
    },
    // Mr Skops' Stalactites
    {
        .x_pos = 0x168, .y_pos = 0xDB,
        .index_up = 17, .index_down = 16, .index_left = 15, .index_right = 16,
        .state = 0, .nb_cages = 0,
        .world = 5, .level = 9,
        .color = 3, .level_name = (char *)&level_name_17
    },
    // Mr Dark's Dare
    {
        .x_pos = 0x165, .y_pos = 0x50,
        .index_up = 17, .index_down = 16, .index_left = 17, .index_right = 17,
        .state = 0, .nb_cages = 0,
        .world = 6, .level = 1,
        .color = 0, .level_name = (char *)&level_name_18
    },
    // Save
    {
        .x_pos = 0x0A, .y_pos = 0xD4,
        .index_up = 18, .index_down = 0, .index_left = 18, .index_right = 18,
        .state = 0, .nb_cages = 0,
        .world = 7, .level = 20,
        .color = 7, .level_name = (char *)0x801CEE10
    },
    // Save
    {
        .x_pos = 0xA7, .y_pos = 0x105,
        .index_up = 5, .index_down = 19, .index_left = 19, .index_right = 19,
        .state = 0, .nb_cages = 0,
        .world = 7, .level = 20,
        .color = 4, .level_name = (char *)0x801CEE10
    },
    // Save
    {
        .x_pos = 0x47, .y_pos = 0x80,
        .index_up = 20, .index_down = 20, .index_left = 20, .index_right = 6,
        .state = 0, .nb_cages = 0,
        .world = 7, .level = 20,
        .color = 13, .level_name = (char *)0x801CEE10
    },
    // Save
    {
        .x_pos = 0xFD, .y_pos = 0x5E,
        .index_up = 21, .index_down = 11, .index_left = 21, .index_right = 21,
        .state = 0, .nb_cages = 0,
        .world = 7, .level = 20,
        .color = 0, .level_name = (char *)0x801CEE10
    },
    // Save
    {
        .x_pos = 0x12F, .y_pos = 0x65,
        .index_up = 22, .index_down = 13, .index_left = 22, .index_right = 22,
        .state = 0, .nb_cages = 0,
        .world = 7, .level = 20,
        .color = 2, .level_name = (char *)0x801CEE10
    },
    // Save
    {
        .x_pos = 0x132, .y_pos = 0x10B,
        .index_up = 15, .index_down = 23, .index_left = 23, .index_right = 23,
        .state = 0, .nb_cages = 0,
        .world = 7, .level = 20,
        .color = 1, .level_name = (char *)0x801CEE10
    },
};
