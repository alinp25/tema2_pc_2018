#include "HallOfFamePrinter.h"

// Afiseaza Hall of Fame || Primii 10 utilizatori
void printHallOfFame() {
    UserEntry entries[10];

    // Citirea intrarilor din Hall of Fame
    readEntries(entries);

    int scorePadding = COLS / 2 - 4;
    int rankPadding = scorePadding - 10;
    int namePadding = scorePadding + 10;
    int linesRankingTopPadding = 6;

    char *continueText = "Apasa ENTER pentru a continua.";
    char *scoreText = "SCOR";
    char *rankText = "RANK";
    char *nameText = "NUME";

    char *hallOfFameText = "HALL OF FAME";

    erase();

    // Afisarea titlului
    start_color();	
    init_pair(1, COLOR_RED, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    mvprintw(4, COLS / 2 - strlen(hallOfFameText) / 2, "%s", 
                hallOfFameText);
    attroff(COLOR_PAIR(1));

    // Afisarea textului pentru iesire din fereastra
    mvprintw(LINES - 4, COLS / 2 - strlen(continueText) / 2, "%s", 
        continueText);

    // Afisarea utilizatorilor
    mvprintw(linesRankingTopPadding, rankPadding, "%s", rankText);
    mvprintw(linesRankingTopPadding, scorePadding, "%s", scoreText);
    mvprintw(linesRankingTopPadding, namePadding, "%s", nameText);

    for (int i = 0; i < 10; i++) {
        mvprintw(linesRankingTopPadding + 2 + i, rankPadding, "%d", i + 1);
        mvprintw(linesRankingTopPadding + 2 + i, scorePadding, "%d", 
            entries[i].score);
        mvprintw(linesRankingTopPadding + 2 + i, namePadding, "%s", 
            entries[i].name);
    }

    int ch;
    do {
        ch = getch();
    } while (ch != 10);
}