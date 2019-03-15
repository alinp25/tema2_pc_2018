#include "Menu.h"

// Afisarea meniului in centrul ecranului
void printMiddleMenu(WINDOW *win, int starty, int startx, int width,
                    char *string, chtype color) {
    int length, x, y;
    float temp;
    if (win == NULL) {
        win = stdscr;
    }
    getyx(win, y, x);
    if (startx != 0) {
        x = startx;
    }
    if (starty != 0) {
        y = starty;
    }
    if (width == 0) {
        width = 80;
    }
    length = strlen(string);
    temp = (width - length) / 2;
    x = startx + (int)temp;
    wattron(win, color);
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, color);
    refresh();
}

int displayMenu() {
    // Variantele oferite in meniu
    char *menuChoices[] = {
        "New Game",
        "Resume Game",
        "Quit"
    };

    curs_set(0);

    ITEM **menuItems;
    int choice;
    MENU *mainMenu;
    WINDOW *mainMenuWindow;
    int numberOfChoices;
    ITEM *currentItem;

    start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
    init_pair(1, COLOR_RED, COLOR_BLACK);

    numberOfChoices = sizeof(menuChoices) / sizeof(menuChoices[0]);

    menuItems = (ITEM **)calloc(numberOfChoices + 1, sizeof(ITEM *));

    for (int i = 0; i < numberOfChoices; i++) {
        menuItems[i] = new_item(menuChoices[i], "");
    }
    menuItems[numberOfChoices] = (ITEM *)NULL;

    mainMenu = new_menu((ITEM **)menuItems);
    mainMenuWindow = newwin(10, 40, LINES / 2 - 5, COLS / 2 - 20);
    
    keypad(mainMenuWindow, TRUE);
    set_menu_win(mainMenu, mainMenuWindow);
    set_menu_sub(mainMenu, derwin(mainMenuWindow, 6, 38, 3, 1));
    set_menu_mark(mainMenu, " * ");
    box (mainMenuWindow, 0, 0);
    printMiddleMenu(mainMenuWindow, 1, 0, 40, "TRIVIA", COLOR_PAIR(1));
    mvwaddch(mainMenuWindow, 2, 0, ACS_LTEE);
    mvwhline(mainMenuWindow, 2, 1, ACS_HLINE, 38);
    mvwaddch(mainMenuWindow, 2, 39, ACS_RTEE);
    refresh();

    post_menu(mainMenu);
    wrefresh(mainMenuWindow);

    int loopMenu = 1;
    int menuResult = -1;
    do {
        choice = getch();
        switch(choice) {
            case KEY_DOWN:
                menu_driver(mainMenu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(mainMenu, REQ_UP_ITEM);
                break;
            case 10:
                loopMenu = 0;
                currentItem = current_item(mainMenu);
                menuResult = item_index(currentItem);
                break;
            default:
                break;
        }
        wrefresh(mainMenuWindow);
    } while (loopMenu == 1);

    unpost_menu(mainMenu);
    for (int i = 0; i < numberOfChoices; i++) {
        free_item(menuItems[i]);
    }
    free_menu(mainMenu);
    refresh();
    delwin(mainMenuWindow);
    return menuResult;
}