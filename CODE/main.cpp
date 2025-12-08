#include <ncurses/curses.h>
#include <windows.h>
#include "story.h"
#include "game.h"
#include "menu.h"
using namespace std;

int main() {
    int pilihan;
    
    //system("color 78");       
    initscr();    
    curs_set(0);
    noecho();

    // Panggil class story
    Story story;    
    story.Title();
    story.Loading();
    clear();
    refresh();

    do{
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
    box(stdscr, 0, 0); 
    story.Intro();
    system("color 3d");
    start_game.game();
    } while (true);
    endwin();             
    
    return 0;
}