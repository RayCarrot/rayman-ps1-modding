#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <export.h>

//https://benpfaff.org/writings/clc/shuffle.html
/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */
void shuffle(char *array, int n);

#endif