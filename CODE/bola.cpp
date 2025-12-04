#include "bola.h"
#include <ncurses/curses.h>
#include "padel.h"

Bola::Bola(int begin_x, int begin_y) {
    this->x = begin_x;
    this->y = begin_y;
    this->score_left = 0;
    this->score_right = 0;
    getmaxyx(stdscr, max_y, max_x);
}

void Bola::gerak (int gx, int gy) {
    x += gx;
    y += gy;
}

void Bola::tampilkan() {
    mvprintw(y, x, "O");
}

int Bola::updateposisi(int gx, int &gy, Paddle &left, Paddle &right) {
    // Collision dengan paddle kiri
    if (x + gx <= left.x + 1 && x + gx >= left.x) {
        if (y >= left.y && y <= left.y + left.height - 1) {
            gx *= -1;
        }
    }

    // Collision dengan paddle kanan
    if (x + gx >= right.x - 1 && x + gx <= right.x) {
        if (y >= right.y && y <= right.y + right.height - 1) {
            gx *= -1;
        }
    }

    // Now move the ball after collision check
    gerak(gx, gy);

    getmaxyx(stdscr, max_y, max_x);
    
    if (x <= 1 || x >= max_x - 1) {
        if (x <= 1) score_right++;
        else score_left++;
        x = max_x / 2;
        y = max_y / 2;
        int random = (rand() % 2) ? 1 : -1;
        return gx * random;  
    }
    
  
    if (y <= 1 || y >= max_y - 2) {
        gy *= -1;
    }

    return gx;
}

void Bola::tampilkan_score() {
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(0, 2, "Score Left: %d", score_left);
    mvprintw(0, max_x - 15, "Score Right: %d", score_right);
}