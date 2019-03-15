#include "Utils.h"
#include "Game.h"

int main(int argc, char **argv) {
    
    question *questions;
    int questionsCapacity = 32, questionsNumber = 0;
    questions = malloc(questionsCapacity * sizeof(question));

    if (argc < 2) {
        printf("[EROARE]: Nu s-au dat argumente in linia de comanda.\n");
        return 1;
    }

    // Citirea intrebarilor
    if (readFiles(argc, argv, 
            &questions, &questionsCapacity, &questionsNumber) == 1) {
        return 1;
    }
    
    // Inceperea jocului
    playGame(questions, questionsNumber);

    free(questions);
    return 0;
}
