#include "Game.h"

// In cazul in care, pe parcursul jocului, a fost folosita functia 50/50,
// functia rebuildQuestions asigura inlocuirea raspunsurilor eliminate
void rebuildQuestions(question *questions, question currentQuestions[], int n) {
    for (int i = 0; i < n; i++) {
        copyquestion(&currentQuestions[i], questions[i]);
    }
    return ;
}

// Inceperea jocului
void playGame(question *questions, int questionsNumber) {
    curs_set(0);

    int score = 0;
    int correctQuestions = 0;
    int wrongQuestions = 0;
    int helpers[2]; // helpers[0] - 50/50 |||| helpers[1] - skip question
    helpers[0] = 1;
    helpers[1] = 1;
    question currentQuestions[questionsNumber];
    initscr();
    int resultMenu; 
    // Afisarea meniului la inceperea jocului
    do {
        rebuildQuestions(questions, currentQuestions, questionsNumber);
        do {
            resultMenu = displayMenu(0);    
            if (resultMenu == 2) {
                return ;
            }
        } while (resultMenu == 1);
        refresh();
        // Parcurgerea intrebarilor
        for (int i = 0; i < questionsNumber; i++) {
            int resultQuestion = displayQuestion(currentQuestions[i], score, 
                                                helpers);
            if (resultQuestion == 1) { // Raspuns corect
                score += 10;
                correctQuestions++;
            } else if (resultQuestion == 0) { // Raspuns  gresit
                score -= 5;
                wrongQuestions++;
            } else if (resultQuestion == 2) { // Deschiderea meniului
                refresh();
                resultMenu = displayMenu();
                if (resultMenu == 0) { // New game
                    rebuildQuestions(questions, currentQuestions, 
                                    questionsNumber);
                    correctQuestions = 0;
                    wrongQuestions = 0;
                    score = 0;
                    i = 0;
                    helpers[0] = 1;
                    helpers[1] = 1;
                } else if (resultMenu == 1) { // Resume
                    i--;
                    continue;
                } else if (resultMenu == 2) { // Quit
                    endwin();
                    return ;
                }
            } else if (resultQuestion == 3) {
                helpers[0] = 0;
                int corr = currentQuestions[i].correctAnswer;
                int removeFirst = randomOutOfOne(corr, 4);
                int removeSecond = randomOutOfTwo(corr, removeFirst, 4);
                strcpy(currentQuestions[i].answers[removeFirst], "---");
                strcpy(currentQuestions[i].answers[removeSecond], "---");
                i--;
            } else if (resultQuestion == 4) { // Folosirea 'Skip question'
                helpers[1] = 0;
            }
        } 
        // Afiseaza scorul final, numarul de intrebari corecte si gresite
        // Poate trece in starea de adaugare Hall Of Fame
        displayScoreAndNumberOfQuestions(score, correctQuestions, 
                                            wrongQuestions);
        refresh();
        erase();
        score = 0;
        helpers[0] = 1;
        helpers[1] = 1;
        correctQuestions = 0;
        wrongQuestions = 0;
    } while (resultMenu != 2);

    endwin();
}


