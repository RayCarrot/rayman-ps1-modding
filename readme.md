# Rayman PS1 Modding
This project is made to help with modding the PS1 version of Rayman 1 using the [PSX Modding Toolchain](https://github.com/mateusfavarin/psx-modding-toolchain). Currently only the NTSC version is supported. Included in here are several mods, some of which are made to be examples. Feel free to submit your own mods through pull requests!

*NOTE: This project is still a work in process. As such changes may be made at any point, especially to the exported symbols. Keep this in mind if you're going to work on a mod.*

## Instructions

### Getting started
- Download and set up the [PSX Modding Toolchain](https://github.com/mateusfavarin/psx-modding-toolchain).
- Clone or download this repo and add it to a new folder under `games`.

Each mod folder has a `MOD.BAT` which allows building the mod.

### Symbols
Every mod will include the files under the `include` folder. For this project this contains the `export.h` file which is a header file exported from Ghidra. The `resources` folder includes additional reusable files which can be copied into and modified for your mods.

### Creating a mod
To create a mod the easiest to do is to first run the clean command on an existing mod and then copy its folder. The most important thing to keep in mind is to not make your code too big or else it can overwrite existing code in the game.

Generally the easiest way to hook in your code is to extend an existing function by replacing its return instruction with a jump `j`. Another easy option is to replace a function call `jal` with your own one and then have your custom function also call the original function.

Once you've added a hook you also need a place to write your custom code. Generally any unused space in the exe will do. One option used in some examples here is to truncate the `FntPrint` function and overwrite the remaining part of it with your own code.