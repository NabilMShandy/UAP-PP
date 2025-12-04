#include <ncurses/curses.h>
#include "bola.h"
#include "padel.h"

Paddle::Paddle(int begin_x, int begin_y) {
    x = begin_x;
    y = begin_y;
    height = 6;
}

void Paddle::tampilkan() {
    for (int i = 0; i < height; i++) {
        mvprintw(y + i, x, "|");
    }
}

void Paddle::gerakUp() {
    if (y > 0) {
        y-=2;
    }
}

void Paddle::gerakDown() {
    if (y + height < getmaxy(stdscr) + 1) {
        y+=2;
    }
}