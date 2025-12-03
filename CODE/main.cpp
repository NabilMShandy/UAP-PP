#include <ncurses/curses.h>
#include <windows.h>
#include "story.h"
#include "game.h"
#include "menu.h"
using namespace std;

int main() {
    int pilihan;
    system("color 78");       
    box(stdscr, 0, 0);
    initscr();    
    curs_set(0);
    noecho();

    // Panggil class story
    Story story;    
    story.Title();
    story.Loading();
    clear();
    refresh();

    // Panggil class menu
    MENU menu;
    menu.initGame();
    menu.tampilanBintang();
    menu.tampilanJudul();
    menu.tampilanMenu(pilihan);
    menu.menu();
    clear();
    refresh();

    // Panggil class game
    Game start_game;
    nodelay(stdscr, TRUE);    
    story.Intro();
    start_game.game();

    endwin();             
    
    return 0;
}
