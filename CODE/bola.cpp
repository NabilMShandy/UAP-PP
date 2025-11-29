#include "bola.h"
#include <ncurses/curses.h>

const int turner = -1;

Bola::Bola(int begin_x, int begin_y) {
    this->x = begin_x;
    this->y = begin_y;
}

void Bola::gerak (int gx, int gy) {
    x += gx;
    y += gy;
}

void Bola::tampilkan() {
    mvprintw(y, x, "O");
}

void Bola::updateposisi(int gx, int gy) {
 gerak(gx, gy);
 int max_x, max_y;
 getmaxyx(stdscr, max_y, max_x);
 if (x<=1 || x>=max_x-2) {
     gx *= turner;

 }
    if (y<=1 || y>=max_y-2) {
        gy *= turner;
    
    }
}