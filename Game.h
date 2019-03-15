#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include "Utils.h"
#include "Menu.h"
#include "Question.h"
#include "RNG.h"
#include "ScorePrinter.h"

void playGame(question *questions, int questionsNumber);

#endif