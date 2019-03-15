#ifndef RNG_H
#define RNG_H

#include <time.h>
#include <stdlib.h>

// Obtine un numar intreg mai mic decat n
int getRandomNumber(int n);
// Obtine un numar intreg mai mic decat n, diferit de a
int randomOutOfOne(int a, int x); 
// Obtine un numar intreg mai mic decat n, diferit de a si b
int randomOutOfTwo(int a, int b, int x);

#endif