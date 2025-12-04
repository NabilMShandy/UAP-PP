#include <ncurses/curses.h>
#include "bola.h"
#include "game.h"
#include "story.h"
#include "padel.h"


const short tick_speed = 50; //jangan diubah



bool Game::input(Paddle &left, Paddle &right) {
    auto ch = getch();

    if (ch == 'q') return false;
    if (ch == 'w') left.gerakUp();
    if (ch == 's') left.gerakDown();
    if (ch == KEY_UP) right.gerakUp();
    if (ch == KEY_DOWN) right.gerakDown();
    
    return true;
}

void Game::game() {
    int speed = 1;
    int gx = speed;
    int gy = speed;
    const int turner = -1;

    curs_set(0);
    nodelay(stdscr, TRUE);
    clear();
    box(stdscr, 0, 0);

    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    Bola bola(max_x / 2, max_y / 2);
    Paddle left(speed + 4, max_y / 2 - 2);
    Paddle right(max_x - speed - 4, max_y / 2 - 2);

    bool run = true;
    refresh();
   
    while(run) {
   //input gw pindahin ke loop sekalian biar ga berat amat
    int ch = getch();
    if (ch == 'q') run = false;
    if (ch == 'w') left.gerakUp();
    if (ch == 's') left.gerakDown();
    if (ch == KEY_UP) right.gerakUp();
    if (ch == KEY_DOWN) right.gerakDown();

    // update bola dan cek tabrakan
    gx = bola.updateposisi(gx, gy, left, right);

    // Clear and redraw only the content, not the border
    erase();
    box(stdscr, 0, 0);

    // tampilkan semua objek
    bola.tampilkan();
    left.tampilkan();
    right.tampilkan();
    bola.tampilkan_score();

    refresh();
    napms(16); // ~60 FPS
}


}
