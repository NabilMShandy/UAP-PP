#include <ncurses/curses.h>
#include <windows.h>
#include "story.h"
#include "game.h"
#include "menu.h"
using namespace std;

bool skip() {
    int ch = getch();
    if (ch == 'q' || ch == 'Q') return false;
    return true;
}

int main() {
    //system("color 78");
    MENU main_menu;
    main_menu.menu();
    initscr();
    box(stdscr, 0, 0);
    curs_set(0);
    noecho();
    nodelay(stdscr, TRUE);

    clear();
    refresh();

    Game start_game;
    start_game.game();

    endwin();
    return 0;
}
