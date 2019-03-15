#include "HighScoreForm.h"

// Afiseaza mesajul in care utilizatorul este anuntat de reusita sa, fiind
// demn de Hall Of Fame, urmand a fi adaugat in fereastra urmatoare
void printTextToHighScore(char *inputValue, int currentScore) {
    char inputText[] = "Introduceti un nume: ";
    char *greetText = "Felicitari! Ai intrat in Hall of Fame!";
    char scoreText[200] = "Scor: ";
    char scoreString[80];

    sprintf(scoreString, "%d", currentScore);
    strcat(scoreText, scoreString);

    mvprintw(5, COLS / 2 - strlen(greetText) / 2, "%s", greetText);
    mvprintw(6, COLS / 2 - strlen(scoreText) / 2, "%s", scoreText);
    mvprintw(LINES / 2, COLS / 2 - strlen(inputText) / 2, "%s", inputText);
    mvprintw(LINES / 2, COLS / 2 + strlen(inputText) / 2 + 3, "%s", inputValue);
}

// Adaugarea unui nou HighScore in Hall Of Fame
char* addNewHighScore(int currentScore) {
    char *inputValue;
    char charToString[2];
    int ch;

    // Citirea numelui utilizatorului
    inputValue = malloc(80 * sizeof(char));

    charToString[1] = '\0';
    strcpy(inputValue, "");

    erase();    

    printTextToHighScore(inputValue, currentScore);

    // Citirea numelui, tasta cu tasta
    do {
        ch = getch();
        if ((ch >= (int)'a' && ch <= (int)'z') || (ch >= (int)'A' && 
                ch <= (int)'Z')) {
            charToString[0] = (char)ch;
            strcat(inputValue, charToString);
        } else if (ch == KEY_BACKSPACE) {
            inputValue[strlen(inputValue) - 1] = '\0';
        }
        erase();

        printTextToHighScore(inputValue, currentScore);
    } while (ch != 10);

    // endwin();

    // Returnarea numelui, pentru a fi adaugat in HoF
    return inputValue;
}

