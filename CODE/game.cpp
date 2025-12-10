#include <ncurses/curses.h>
#include <string>
#include "bola.h"
#include "game.h"
#include "story.h"
#include "padel.h"
#include <fstream>
#include <windows.h>

int speed = 1;

void playmusic(const char *fileMusik, DWORD opsi = SND_ASYNC | SND_LOOP) {
    PlaySoundA(fileMusik, NULL, opsi);
}

void stopmusic() {
    PlaySoundA(NULL, 0, SND_PURGE);
}

const short tick_speed = 50;

void Game::game() {
    playmusic("Musik/gamepay.wav");
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
    int max_score = 21;
    int gx = speed;
    int gy = speed;

    while(run) {
       /* int total_score = bola.get_score_left() + bola.get_score_right();
        if (total_score > 0 && total_score % 10 == 0) {
        speed++;
        if (speed > 3) speed = 3; // optional
        }
        gx = gx>0 ? speed : -speed;
        gy = gy>0 ? speed : -speed;
        */
 

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

        gx = bola.updateposisi(gx, gy, left, right);
        erase();
        box(stdscr, 0, 0);
        int middle_x = getmaxx(stdscr) / 2;
        for (int i = 0; i < max_y; i++) {
            if (i % 2 == 1) mvprintw(i, middle_x, "|");
        }


        bola.tampilkan();
        left.tampilkan();
        right.tampilkan();
        bola.tampilkan_score();

        refresh();
        napms(16);
    }
    int skorKiri = bola.get_score_left();
    int skorKanan = bola.get_score_right();
    
    int pemenang = (skorKiri > skorKanan) ? 1 : 2;
    int skorPemenang = (skorKiri > skorKanan) ? skorKiri : skorKanan;
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << pemenang << " " << skorPemenang;
        file.close();
    }

    stopmusic();
}