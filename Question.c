#include "Question.h"

// Afiseaza intrebarea si returneaza o valoare in functie de care se continua
// jocul
int displayQuestion(question currentQuestion, int score, int helpers[2]) {
    erase();
    curs_set(0);
    mvprintw(LINES / 2 - 4, COLS / 2 - strlen(currentQuestion.question) / 2,
                currentQuestion.question);
    int scorePaddingLeft = 5;
    char scoreText[100] = "SCORE: ";
    char scoreString[12];

    // Transformare int in string
    sprintf(scoreString, "%d", score);
    strcat(scoreText, scoreString);

    mvprintw(4, scorePaddingLeft, scoreText);
    mvprintw(LINES / 2, COLS / 4, "A.");
    mvprintw(LINES / 2, COLS / 4 + 4, currentQuestion.answers[0]);
    mvprintw(LINES / 2 + 2, COLS / 4, "B.");
    mvprintw(LINES / 2 + 2, COLS / 4 + 4, currentQuestion.answers[1]);
    mvprintw(LINES / 2 + 4, COLS / 4, "C.");
    mvprintw(LINES / 2 + 4, COLS / 4 + 4, currentQuestion.answers[2]);
    mvprintw(LINES / 2 + 6, COLS / 4, "D.");
    mvprintw(LINES / 2 + 6, COLS / 4 + 4, currentQuestion.answers[3]);

    char *fifty = "Apasa 'O' pentru varianta ajutatoare 50/50";
    char *skipper = "Apasa 'P' pentru varianta ajutatoare Skip the question.";
    if (helpers[0] == 1) {
        mvprintw(LINES - 4, COLS - strlen(fifty) - 5, fifty);
    }
    if (helpers[1] == 1) {
        mvprintw(LINES - 3, COLS - strlen(skipper) - 5, skipper);
    }

    char *currentTime = getCurrentTime();
    mvprintw(4, COLS - 10 - strlen(currentTime), currentTime);

    int choice;
    while ((choice = getch())) {
        switch(choice) {
            // Returnam daca raspunsul este corect sau gresit
            case (int)'a':
                return currentQuestion.correctAnswer == 0;
            case (int)'b':
                return currentQuestion.correctAnswer == 1;                
            case (int)'c':
                return currentQuestion.correctAnswer == 2;
            case (int)'d':
                return currentQuestion.correctAnswer == 3;
            // Returnam 2 -> ne intoarcem la meniu
            case (int)'q':
                erase();
                return 2;
            // Returnam 3 -> a fost aleasa varianta 50/50
            case (int)'o':
                if (helpers[0] == 1) {
                    return 3;
                }
                break;
            // Returnam 4 -> a fost aleasa varianta Skip question
            case (int)'p':
                if (helpers[1] == 1) {
                    return 4;
                }
                break;
            // Daca este apasata orice alta tasta, actualizam data si ora
            default:
                currentTime = getCurrentTime();
                mvprintw(4, COLS - 10 - strlen(currentTime), currentTime);
                // free(currentTime);
                break;
        }
    }
    free(currentTime);
    return -1;
}