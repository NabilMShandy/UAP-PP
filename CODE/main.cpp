
#include <ncurses/curses.h>
#include <windows.h>
#include "story.h"
#include "game.h"
using namespace std;

int main() {
    system("color 78");
    box(stdscr, 0, 0);
    initscr();           
    curs_set(0);
    noecho();
    nodelay(stdscr, FALSE);
       
    Story story;
    story.Title();
    story.Loading();
    story.Intro();

    clear();
    refresh();

    Game start_game;
    start_game.game();

    endwin();             
    
    return 0;
}
