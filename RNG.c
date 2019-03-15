#include "RNG.h"

// Generator de numere intregi mai mici decat n
int getRandomNumber(int n) {
    srand(time(NULL));
    return (rand() % n);
}

// Obtine un numar mai mic decat x, diferit de a
int randomOutOfOne(int a, int x) {
    int randomNumber;
    do {
        randomNumber = getRandomNumber(x);
    } while (randomNumber == a);
    return randomNumber;
}

// Obtine un numar mai mic decat x, diferit de a si b
int randomOutOfTwo(int a, int b, int x) {
    int randomNumber;
    do {
        randomNumber = getRandomNumber(x);
    } while (randomNumber == a || randomNumber == b);
    return randomNumber;
} 