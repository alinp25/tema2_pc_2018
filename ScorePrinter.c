#include "ScorePrinter.h"

// Afiseaza scorul si numarul de intrebari corecte si gresite
void displayScoreAndNumberOfQuestions(int score, int correctQuestions, 
        int wrongQuestions) {

    curs_set(0);
    erase();

    int totalQuestions = correctQuestions + wrongQuestions;
    char correctQuestionsText[] = "Numar intrebari corecte: ";
    char wrongQuestionsText[] = "Numar intrebari gresite: ";
    char scoreText[100] = "Score: ";
    char pressEnterText[] = "Apasa ENTER pentru a continua.";
    char dash[] = "/";
    char newHighScoreText[] = "Ai intrat in Hall of Fame!";

    int wrongQuestionsPadding, correctQuestionsPadding;
    int questionsLine = LINES / 2 + 1;
    char scoreString[10];
    char correctQuestionsString[10];
    char wrongQuestionsString[10];
    char totalQuestionsString[10];

    // Transforma int-uri in string-uri
    // Concateneaza string-urile cu valorile aferente
    sprintf(totalQuestionsString, "%d", totalQuestions);
    sprintf(scoreString, "%d", score);
    strcat(scoreText, scoreString);
    sprintf(correctQuestionsString, "%d", correctQuestions);
    strcat(correctQuestionsText, correctQuestionsString);
    strcat(correctQuestionsText, dash);
    sprintf(wrongQuestionsString, "%d", wrongQuestions);
    strcat(wrongQuestionsText, wrongQuestionsString);
    strcat(wrongQuestionsText, dash);
    strcat(correctQuestionsText, totalQuestionsString);
    strcat(wrongQuestionsText, totalQuestionsString);

    // In cazul in care scorul intra in HoF
    int addedToAllTime;
    if ((addedToAllTime = shouldAddToAllTimeHighScores(score)) == 1) {
        start_color();	
        init_pair(1, COLOR_RED, COLOR_BLACK);

        // Anunta utilizatorul ca a atins un scor capabil de HoF
        attron(COLOR_PAIR(1));
        mvprintw(4, COLS / 2 - strlen(newHighScoreText) / 2, "%s", 
                    newHighScoreText);
        attroff(COLOR_PAIR(1));
    }

    wrongQuestionsPadding =  COLS / 2 - strlen(wrongQuestionsText) / 2;
    correctQuestionsPadding = COLS / 2 - strlen(correctQuestionsText) / 2;

    mvprintw(questionsLine, correctQuestionsPadding, correctQuestionsText);
    mvprintw(questionsLine + 1, wrongQuestionsPadding, wrongQuestionsText);

    mvprintw(LINES / 2 - 1, COLS / 2 - strlen(scoreText) / 2, scoreText);
    mvprintw(LINES - 4, COLS / 2 - strlen(pressEnterText) / 2, pressEnterText);
    // Asteapta apasarea tastei ENTER pentru a trece mai departe
    int choice;
    do {
        choice = (int)getch();
    } while(choice != 10);

    refresh();

    if (addedToAllTime == 1) {
        char *username = addNewHighScore(score);
        addToAllTimeHighScores(score, username);
        free(username);
    }

    printHallOfFame();
} 