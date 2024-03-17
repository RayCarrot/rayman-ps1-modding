unsigned char dyingSequence[5] = 
{ 
    0x10, 
    0x0b, // This also sets bossSafeTimer to 0, hoping it doesn't break anything compared to https://github.com/RayCarrot/rayman-ps1-modding/blob/53f04b8fbf5a1ec9d9df9deea8207c7efee16da0/mods/Kaizoman/buildList.txt#L31
    0x19, // Change from 0x17 to 0x19 to change level before the cutscene plays (fixes solftlock) 
    0x16, 
    0x19, 
};