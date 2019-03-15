#ifndef HIGHSCOREFORM_H
#define HIGHSCOREFORM_H

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

char* addNewHighScore(int currentScore);
void printTextToHighScore(char *inputValue, int currentScore);

#endif