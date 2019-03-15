#ifndef HIGHSCORECHEKER_H
#define HIGHSCORECHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"

int shouldAddToAllTimeHighScores(int score);
void addToAllTimeHighScores(int score, char *name);
void readEntries(UserEntry entries[10]);

#endif
