# Rayman PS1 Modding
This project provides an easy way for modding the PS1 version of Rayman 1 using the [PSX Modding Toolchain](https://github.com/mateusfavarin/psx-modding-toolchain). It includes symbols exported from the game, allowing mods to directly access its functions and data. Currently the NTSC and PAL versions are supported by this project, though not all mods have been updated to work for the PAL version.

Included in here are several mods as well as an [example](mods/HelloWorld). Feel free to submit your own mods through pull requests!

## Usage

### Getting started
- Download and set up the [PSX Modding Toolchain](https://github.com/mateusfavarin/psx-modding-toolchain).
- Clone or download this repo and add it to a new folder under `games`.

Each mod folder has a `MOD.BAT` file which allows building the mod and accessing other options from the toolchain.

### Symbols
Every mod will include the files under the `include` folder. For this project this contains the `export.h` file which is a header file exported from Ghidra. Symbols are named from the Android version of Rayman 1 and from the PSYQ SDK. If a symbol name is not known then it is prefixed with `PS1_` to indicate it uses a custom name.

The `resources` folder includes additional reusable files which can be copied into and modified for your mods. Usually these are re-implementations of game functions which can then be used to more easily rewrite them.

### Versions
Currently the NTSC and PAL versions are supported. In the future it is planned to add support for the remaining versions (DemoDemo vol. 3, DemoDemo vol. 6, NTSC-J and Rayman 2 2D prototype). Once they are added they will use separate `export.h` files and thus any mod that targets them alongside other versions will require conditional compilation based on version. Many functions are however the same across them making it not too difficult to multi-target your mods. In cases were structs are changes many of the fields still remain the same.

### Creating a mod
To create a mod the easiest to do is to first run the clean command on an existing mod and then copy its folder. The most important thing to keep in mind is to not make your code too big or else it can overwrite existing code in the game.

Generally the easiest way to hook in your code is to extend an existing function by replacing its return instruction with a jump `j`. Another easy option is to replace a function call `jal` with your own one and then have your custom function also call the original function.

Once you've added a hook you also need a place to write your custom code. Generally any unused space in the exe will do. One option used in some examples here is to truncate the `FntPrint` function and overwrite the remaining part of it with your own code.

## Related projects
* [BinarySerializer.Ray1](https://github.com/BinarySerializer/BinarySerializer.Ray1) - a C# library for serializing the game data from all versions of the game
* [rayman-ps1-decomp](https://github.com/fuerchter/rayman-ps1-decomp) - a matching decompilation of the PS1 version
* [Ray1Editor](https://github.com/RayCarrot/Ray1Editor) - a level editor for the PS1 and PC versions
