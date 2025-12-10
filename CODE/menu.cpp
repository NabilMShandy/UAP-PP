#include <ncurses/curses.h>
#include <windows.h>
#include <fstream>
#include "menu.h"
using namespace std;

void playmusicc(const char *musik, DWORD mode = SND_ASYNC | SND_LOOP) {
    PlaySoundA(musik, NULL, mode);
}

void stopmusicc() {
    PlaySoundA(NULL, 0, SND_PURGE);
}

void MENU::initGame() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
}

// Bintang
void MENU::tampilanBintang() {
    mvprintw(2, 22, " *    .        *          *        .         *         *        .        *      ");
    mvprintw(3, 22, "  *          .                                      .        *               *  ");
    mvprintw(4, 22, "      .  *           .      *             .      *               *              ");
    mvprintw(5, 22, "*           .          *          *                       .              *      ");
    mvprintw(6, 22, "      *                     .                 *                   *          .  ");
    mvprintw(7, 22, " *    .        *       *        .         *        *        .         *        *");
    mvprintw(8, 22, "  *          .                                  .        *                *     ");
    mvprintw(9, 22, " *    .        *                .         *         *       .         *        *");
    mvprintw(10, 22, "  *          .                                  .        *                *     ");
    mvprintw(11, 22, "      .  *           .       *         .      *               *               * ");
    mvprintw(12, 22, "*           .          *                              .               *         ");
    mvprintw(13, 22, "      *                          .          *                 *           .     ");
    mvprintw(14, 22, " *    .        *    .       *          .         *          .         *        *");
    mvprintw(15, 22, "  *          .        *                                  *                *     ");
    mvprintw(16, 22, "      .  *           .                                        *               * ");
    mvprintw(17, 22, "*           .     *                                        .          *         ");
    mvprintw(18, 22, "      *               .                                       *           .     ");
    mvprintw(19, 22, " *    .        *                                            .         *        *");
    mvprintw(20, 22, "  *          .      *                                    *                *     ");
    mvprintw(21, 22, "      .  *           .                                        *               * ");
    mvprintw(22, 22, "*           .          *          *          *        .               *         ");
    mvprintw(23, 22, "      *                     .                                 *           .     ");
    mvprintw(24, 22, " *    .        *          *        .         *         *       .         *      ");
    mvprintw(25, 22, "  *          .                                     .        *                *  ");
}

// Judul
void MENU::tampilanJudul() {
    int awalX = 6;
    int awalY = 120 / 2;

    attron(COLOR_PAIR(2));

    mvprintw(awalX, awalY - 24, " #### #####  ##   ###     ####   ###  #     #  #### ");
    mvprintw(awalX + 1, awalY - 24, "#       #   #  #  #  #    #   # #   # # #   # #     ");
    mvprintw(awalX + 2, awalY - 24, " ###    #  #    # ####    ####  #   # #  #  # # ### ");
    mvprintw(awalX + 3, awalY - 24, "    #   #  ###### #  #    #     #   # #   # # #    #");
    mvprintw(awalX + 4, awalY - 24, "####    #  #    # #   #   #      ###  #     #  #### ");

    attroff(COLOR_PAIR(2));
}

// Menu
void MENU::tampilanMenu(int pilihan) {
    short int kolom_kiriAtas = 48;
    short int baris_kiriAtas = 14;
    short int kolom_kananBawah = 75;
    short int baris_kananBawah = 20;
    short int kolom, baris;

    attron(COLOR_PAIR(1));

    mvaddch(baris_kiriAtas, kolom_kiriAtas, ACS_ULCORNER);
    for (kolom = kolom_kiriAtas + 1;  kolom < kolom_kananBawah; kolom++) mvaddch(baris_kiriAtas, kolom, ACS_HLINE);
    mvaddch(baris_kiriAtas, kolom_kananBawah, ACS_URCORNER);

    for (baris = baris_kiriAtas + 1;  baris < baris_kananBawah; baris++) mvaddch(baris, kolom_kananBawah, ACS_VLINE);
    mvaddch(baris_kananBawah, kolom_kananBawah, ACS_LRCORNER);
    for (kolom = kolom_kananBawah - 1;  kolom > kolom_kiriAtas; kolom--) mvaddch(baris_kananBawah, kolom, ACS_HLINE);
    mvaddch(baris_kananBawah, kolom_kiriAtas, ACS_LLCORNER);
    for (baris = baris_kananBawah - 1;  baris > baris_kiriAtas; baris--) mvaddch(baris, kolom_kiriAtas, ACS_VLINE);

    attroff(COLOR_PAIR(1));
    const char* menuOpsi[2] = { "PLAY", "EXIT" }; //DIKASIH ARRAY.

    for (int i = 0; i < 2; i++) {
    if (pilihan == i) {
        attron(COLOR_PAIR(3));
        mvprintw(baris_kiriAtas + 2 + i*2, kolom_kiriAtas + 2, "     >    %s    <     ", menuOpsi[i]);
        attroff(COLOR_PAIR(3));
    } 
    else {
        attron(COLOR_PAIR(4));
        mvprintw(baris_kiriAtas + 2 + i*2, kolom_kiriAtas + 2, "          %s          ", menuOpsi[i]);
        attroff(COLOR_PAIR(4));
    }
}

}

// HIGH SCORE
void MENU::tampilkanHighScore() {
    ifstream file("highscore.txt");

    int player = 0, skor = 0;

    if(file.is_open()) {
        file >> player >> skor;
        file.close();
    }

    int max_x = getmaxx(stdscr);
    mvprintw(1, max_x/2 - 20, "Skor tertinggi saat ini: Pemain %d -> %d", player, skor);
}

// Menu utama
void MENU::menu() {
    nodelay(stdscr, FALSE);
    playmusicc("Musik/lobby.wav");

    int pilihan = 0;
    int ch;

    while (true) {
        clear();
        tampilanBintang();
        tampilanJudul();
        tampilkanHighScore(); // <-- highscore ditampilkan di sini
        tampilanMenu(pilihan);
        refresh();

        ch = getch();
        if (ch == KEY_UP) {
            pilihan--;
            if (pilihan < 0) pilihan = 1;

        } 
        else if (ch == KEY_DOWN) {
            pilihan++;
            if (pilihan > 1) pilihan = 0;
        } 
        else if (ch == 10) {
            if (pilihan == 0) {
                stopmusicc();
                return;
            } 
        else {
            stopmusicc();
            endwin();
            exit(0);
            }
        }
    }
    refresh();
}
