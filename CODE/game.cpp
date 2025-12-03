#include <ncurses/curses.h>
#include "bola.h"
#include "game.h"
#include "story.h"


const short tick_speed = 50; //jangan diubah

bool Game::input() {
    auto ch = getch();
    if (ch == 'q') return false;
    return true;
}

void Game::game() {
    box(stdscr, 0, 0);
    initscr();
    curs_set(0);
    nodelay(stdscr, TRUE);     

    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    Bola bola(max_x / 2, max_y / 2);

    int speed = 3;
    int gx = speed;
    int gy = speed;
    const int turner = -1;

    bool run = true;
    Story story;
    story.Title();
    story.Loading();
    story.Intro();

    while(run) {
        run = input();
        clear();

        bola.gerak(gx, gy);
        bola.tampilkan();

        if (bola.x <= 1 || bola.x >= max_x - 2) gx *= turner;
        if (bola.y <= 1 || bola.y >= max_y - 2) gy *= turner;

        refresh();
        napms(tick_speed);
    }

}
