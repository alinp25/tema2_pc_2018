#include "HighScoreChecker.h"

// Citirea intrarilor din HighScore.txt - primii 10 utilizatori all-time
void readEntries(UserEntry entries[10]) {
    FILE *highScoreFileRead;
    FILE *highScoreFileWrite;
    int userScore;
    char userName[80];
    int i = 0;
    if ((highScoreFileRead = fopen("HighScore.txt", "r")) != NULL) {
        while (fscanf(highScoreFileRead, "%d %s", &userScore, userName) == 2) {
            entries[i].score = userScore;
            strcpy(entries[i].name, userName);
            i++;
        }
        while (i < 10) {
            entries[i].score = 0;
            strcpy(entries[i].name, "-");
            i++;
        }
        fclose(highScoreFileRead);
    } else {
        highScoreFileWrite = fopen("HighScore.txt", "w");
        for (i = 0; i < 10; i++) {
            entries[i].score = 0;
            strcpy(entries[i].name, "-");
            fprintf(highScoreFileWrite, "%d %s\n", entries[i].score, 
                entries[i].name);
        }
        fclose(highScoreFileWrite);
    }
    // free(highScoreFileWrite);
    // free(highScoreFileRead);
}

// Verifica daca utilizatorul are un scor demn de Hall of Fame
int shouldAddToAllTimeHighScores(int score) {
    UserEntry entries[10];
    
    readEntries(entries);

    for (int i = 0; i < 10; i++) {
        if (score > entries[i].score) {
            return 1;
        }
    }
    return 0;
}

// Adauga utilizatorul in Hall of Fame
void addToAllTimeHighScores(int score, char *name) {
    UserEntry entries[10];
    
    // Citirea celor 10 persoane existente pana in momentul de fata
    readEntries(entries);

    int hasBeenAdded = 0; // Contorizeaza daca user-ul a fost adaugat
    for (int i = 0; i < 10 && hasBeenAdded == 0; i++) {
        // Gasirea pozitiei pe care user-ul urmeaza sa fie inserat
        if (score > entries[i].score) { 
            // Mutarea celor de dupa el cu o pozitie mai jos
            for (int j = 9; j > i; j--) {
                entries[j].score = entries[j - 1].score;
                strcpy(entries[j].name, entries[j - 1].name);
            }
            // Adaugarea user-ului
            hasBeenAdded = 1;
            entries[i].score = score;
            strcpy(entries[i].name, name);
        }
    }

    // Rescrierea fisierului
    FILE *highScoreFileWrite;
    highScoreFileWrite = fopen("HighScore.txt", "w");
    for (int i = 0; i < 10; i++) {
        fprintf(highScoreFileWrite, "%d %s\n", entries[i].score, 
            entries[i].name);
    }
    fclose(highScoreFileWrite);
    // free(highScoreFileWrite);
}