#include <ncurses/curses.h>
#include <windows.h>
#include "menu.h"
using namespace std;

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

void MENU::tampilanMenu(int pilihan) {
    short int kolom_kiriAtas = 48;
    short int baris_kiriAtas = 14;
    short int kolom_kananBawah = 75;
    short int baris_kananBawah = 20;
    short int kolom, baris;

    attron(COLOR_PAIR(1));

    mvaddch(baris_kiriAtas, kolom_kiriAtas, ACS_ULCORNER);

    for (kolom = kolom_kiriAtas + 1;  kolom < kolom_kananBawah; kolom++) {
        mvaddch(baris_kiriAtas, kolom, ACS_HLINE);
    }

    mvaddch(baris_kiriAtas, kolom_kananBawah, ACS_URCORNER);

    for (baris = baris_kiriAtas + 1;  baris < baris_kananBawah; baris++) {
        mvaddch(baris, kolom_kananBawah, ACS_VLINE);
    }
    
    mvaddch(baris_kananBawah, kolom_kananBawah, ACS_LRCORNER);

    for (kolom = kolom_kananBawah - 1;  kolom > kolom_kiriAtas; kolom--) {
        mvaddch(baris_kananBawah, kolom, ACS_HLINE);
    }

    mvaddch(baris_kananBawah, kolom_kiriAtas, ACS_LLCORNER);

    for (baris = baris_kananBawah - 1;  baris > baris_kiriAtas; baris--) {
        mvaddch(baris, kolom_kiriAtas, ACS_VLINE);
    }

    attroff(COLOR_PAIR(1));

    if (pilihan == 0) {
        attron(COLOR_PAIR(3));
        mvprintw(baris_kiriAtas + 2, kolom_kiriAtas + 2, "     >    PLAY    <     ");
        attroff(COLOR_PAIR(3));
    } else {
        attron(COLOR_PAIR(4));
        mvprintw(baris_kiriAtas + 2, kolom_kiriAtas + 2, "          PLAY          ");
        attroff(COLOR_PAIR(4));
    }

    if (pilihan == 1) {
        attron(COLOR_PAIR(3) | A_BOLD);
        mvprintw(baris_kiriAtas + 4, kolom_kiriAtas + 2, "     >    EXIT    <     ");
        attroff(COLOR_PAIR(3) | A_BOLD);
    } else {
        attron(COLOR_PAIR(4));
        mvprintw(baris_kiriAtas + 4, kolom_kiriAtas + 2, "          EXIT          ");
        attroff(COLOR_PAIR(4));
    }
}

void MENU::menu() {
    // initGame() should be called by the caller (main) once.
    // Use blocking input for the menu so it doesn't spin and redraw continuously.
    nodelay(stdscr, FALSE);

    int pilihan = 0;
    int ch;

    while (true) {
        clear();

        tampilanBintang();

        tampilanJudul();

        tampilanMenu(pilihan);

        refresh();

        ch = getch();

        if (ch == KEY_UP) {
            pilihan = pilihan - 1;
            if (pilihan < 0) {
                pilihan = 1;
            }
        } else if (ch == KEY_DOWN) {
            pilihan = pilihan + 1;
            if (pilihan > 1) {
                pilihan = 0;
            }
        } else if (ch == 10) {
            if (pilihan == 0) {
                return;
            } 
            else{
                endwin();
                exit(0);
            }
        }
    }
    refresh();
}
