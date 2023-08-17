# Files

### fix_numlevel.c
This is a re-implementation of the `fix_numlevel` function in the game. It's used to determine which level to load after the player finishes a level or enters a bonus level. Copy this into your mod if you want to change the level order!

### INIT_WORLD_STAGE_NAME.c
This is a re-implementation of the `INIT_WORLD_STAGE_NAME` function in the game. It's used by the worldmap code to get the correct world name to show. This version of the function uses 1704 fewer bytes than the original, meaning that this can also be used to make space for additional code.

### t_world_info.c
This is a re-implementation of the `t_world_info` table in the game. It stores data for all of the 24 medallions on the world map and determine how they behave and link together. Copy this into your mod if you want to modify the world map! Keep in mind that the game hard-codes certain behaviors based on the indexes of the items in the table.

### credits.c
This is a re-implementation of the `credits` table in the game.

### IS_ON_RESSORT_BLOC.c
This is a re-implementation of the `IS_ON_RESSORT_BLOC` function in the game.
