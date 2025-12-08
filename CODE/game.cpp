#include <ncurses/curses.h>
#include <string>
#include "bola.h"
#include "game.h"
#include "story.h"
#include "padel.h"

void mainkanmusik(const char *fileMusik, DWORD opsi = SND_ASYNC | SND_LOOP) {
    PlaySoundA(fileMusik, NULL, opsi);
}

void stopmusik() {
    PlaySoundA(NULL, 0, SND_PURGE);
}

const short tick_speed = 50; //jangan diubah
void Game::game() {
    mainkanmusik("Musik/gamepay.wav");
    int speed = 1;
    int gx = speed;
    int gy = speed;
    const int turner = -1;

    curs_set(false);
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    Bola bola(max_x / 2, max_y / 2);
    Paddle left(speed + 4, max_y / 2 - 2);
    Paddle right(max_x - speed - 4, max_y / 2 - 2);

    bool run = true;
    refresh();
    keypad(stdscr, TRUE);
    int max_score = 10;
    while(run) {
   //input gw pindahin ke loop sekalian biar ga berat amat
    int ch;
    while ((ch = getch()) != ERR) {
        if (ch == 'q') run = false;
        if (ch == 'w') left.gerakUp();
        if (ch == 's') left.gerakDown();
        if (ch == KEY_UP) right.gerakUp();
        if (ch == KEY_DOWN) right.gerakDown();
    }
    if (bola.get_score_left() >= max_score) {
        mvprintw(max_y / 2, max_x / 2 - 5, "Pemain 1 menang!!");
        refresh();
        napms(4000);
        break;
    }
    else if (bola.get_score_right() >= max_score) {
        mvprintw(max_y / 2, max_x / 2 - 5, "Pemain 2 menang!");
        refresh();
        napms(2000);
        break;
    }

    // update bola dan cek tabrakan
    gx = bola.updateposisi(gx, gy, left, right);
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

    stopmusik();
}


