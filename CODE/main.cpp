#include "ncurses/curses.h"
#include "game.h";

int main () {
initscr();

Game start_game;

 start_game.game();

 endwin();
}