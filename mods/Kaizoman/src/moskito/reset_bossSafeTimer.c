#include <export.h>

extern byte bossSafeTimer;

void reset_bossSafeTimer()
{
    // Due to us skipping the end animation for the Bzzit it causes the
    // safe timer (the hit cooldown) to not have time to go down to 0.
    // The side effect of this is that it stays at 255 when you reach
    // Moskito and you then have to wait 255 frames before being able to
    // hit him, making the first hit impossible to perform. This solves
    // that by always resetting the value to 0 on a level load.
    bossSafeTimer = 0;
}
