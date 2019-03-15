#ifndef SCOREPRINTER_H
#define SCOREPRINTER_H

#include <ncurses.h>
#include <string.h>
#include "Utils.h"
#include "HighScoreChecker.h"
#include "HighScoreForm.h"
#include "HallOfFamePrinter.h"

void displayScoreAndNumberOfQuestions(int score, int correctQuestions, 
        int wrongQuestions);

#endif