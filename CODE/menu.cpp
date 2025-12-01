#include <ncurses/curses.h>
#include <windows.h>
using namespace std;

void initGame() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
}

void tampilanBintang() {
    mvprintw(1, 0, " *    .        *          *        .         *         *        .        *      ");
    mvprintw(2, 0, "  *          .                                      .        *               *  ");
    mvprintw(3, 0, "      .  *           .      *             .      *               *              ");
    mvprintw(4, 0, "*           .          *          *                       .              *      ");
    mvprintw(5, 0, "      *                     .                 *                   *          .  ");
    mvprintw(6, 0, " *    .        *       *        .         *        *        .         *        *");
    mvprintw(7, 0, "  *          .                                  .        *                *     ");
    mvprintw(8, 0, " *    .        *                .         *         *       .         *        *");
    mvprintw(9, 0, "  *          .                                  .        *                *     ");
    mvprintw(10, 0, "      .  *           .       *         .      *               *               * ");
    mvprintw(11, 0, "*           .          *                              .               *         ");
    mvprintw(12, 0, "      *                                                       *           .     ");
    mvprintw(13, 0, " *    .        *                                            .         *        *");
    mvprintw(14, 0, "  *          .                                           *                *     ");
    mvprintw(15, 0, "      .  *           .                                        *               * ");
    mvprintw(16, 0, "*           .          *                              .               *         ");
    mvprintw(17, 0, "      *                                                       *           .     ");
    mvprintw(18, 0, " *    .        *          *         .               *       .         *        *");
    mvprintw(19, 0, "  *          .                                  .        *                *     ");
    mvprintw(20, 0, "      .  *           .      *             .                   *               * ");
    mvprintw(21, 0, "*           .          *          *                   .               *         ");
    mvprintw(22, 0, "      *                     .                                 *           .     ");
    mvprintw(23, 0, " *    .        *          *        .         *         *       .         *      ");
    mvprintw(24, 0, "  *          .                                     .        *                *  ");
}

void tampilanJudul() {
    int awalX = 4;
    int awalY = 80 / 2;

    attron(COLOR_PAIR(2));

    mvprintw(awalX, awalY - 25, " #### #####  ##   ###     ####   ###  #     #  #### ");
    mvprintw(awalX + 1, awalY - 25, "#       #   #  #  #  #    #   # #   # # #   # #     ");
    mvprintw(awalX + 2, awalY - 25, " ###    #  #    # ####    ####  #   # #  #  # # ### ");
    mvprintw(awalX + 3, awalY - 25, "    #   #  ###### #  #    #     #   # #   # # #    #");
    mvprintw(awalX + 4, awalY - 25, "####    #  #    # #   #   #      ###  #     #  #### ");

    attroff(COLOR_PAIR(2));
}

void tampilanMenu(int pilihan) {
    short int kolom_kiriAtas = 26;
    short int baris_kiriAtas = 11;
    short int kolom_kananBawah = 54;
    short int baris_kananBawah = 17;
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
        mvprintw(baris_kiriAtas + 4, kolom_kiriAtas + 3, "    >    EXIT    <     ");
        attroff(COLOR_PAIR(3) | A_BOLD);
    } else {
        attron(COLOR_PAIR(4));
        mvprintw(baris_kiriAtas + 4, kolom_kiriAtas + 3, "         EXIT          ");
        attroff(COLOR_PAIR(4));
    }
}

int main() {
    initGame();

    int pilihan = 0;
    int ch;
    int running = 1;
    
    while (running == 1) {
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
                
            } else if (pilihan == 1) {
                running = 0;
            }
        }
    }

    refresh();
    endwin();

    return 0;
}
