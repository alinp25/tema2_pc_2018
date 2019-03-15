#include "Utils.h"

// Copierea unei intrebari
void copyquestion(question *where, question what) {
    where->correctAnswer = what.correctAnswer;
    strcpy(where->question, what.question);
    strcpy(where->answers[0], what.answers[0]);
    strcpy(where->answers[1], what.answers[1]);
    strcpy(where->answers[2], what.answers[2]);
    strcpy(where->answers[3], what.answers[3]);
}

int readFiles(int argc, char **argv, question **questions, 
                int *questionsCapacity, int *questionsNumber) {
                    
    int BUFFER_MAX = 200;
    for (int i = 1; i < argc; i++) {
        FILE *fileInput;
        char buffer[BUFFER_MAX];
        question newquestion;

        fileInput = fopen(argv[i], "r");
        if (fileInput == NULL) {
            printf("[EROARE]: Fisierul %s nu poate fi deschis", argv[i]);
            return 1;
        }

        while (fgets(buffer, BUFFER_MAX, fileInput) != NULL) {
            strcpy(newquestion.question, buffer);
            for (int i = 0; i < 4; i++) {
                fgets(buffer, BUFFER_MAX, fileInput);
                strcpy(newquestion.answers[i], buffer);                
            }
            fgets(buffer, BUFFER_MAX, fileInput);
            newquestion.correctAnswer = (int)(buffer[0] - '0');

            if (*questionsCapacity == *questionsNumber) {
                *questionsCapacity = *questionsCapacity * 2;
                *questions = realloc(*questions, *questionsCapacity * 
                                    sizeof(question));
            }
            copyquestion(&(*questions)[*questionsNumber], newquestion);
            *questionsNumber = *questionsNumber + 1;
        }
    }

    return 0;
}
