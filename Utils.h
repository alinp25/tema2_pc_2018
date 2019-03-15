#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structura intrebarii
typedef struct {
    char question[200];
    char answers[4][200];
    int correctAnswer; // ID-ul raspunsului corect
} question;

typedef struct {
    char name[80];
    int score;
} UserEntry;

void copyquestion(question *where, question what);

int readFiles(int argc, char **argv, question **questions, 
                int *questionsCapacity, int *questionsNumber);


#endif