#include <ncurses/curses.h>
#include "Story.h"
#include "menu.h"
#include <iostream>
using namespace std;

// non-blocking check for skip key; requires caller to set nodelay(stdscr, TRUE)
bool Story::input() {
    int ch = getch();
    if (ch != ERR && (ch == 's' || ch == 'S')) {
        _skipped = true;
        return true;
    }
    return false;
}

void Story::reciter (string text, int delay){
    for (char c : text) {
        addch(c);
        refresh();
        napms(delay);
        if (input()) return; // stop reciting when user requested skip
    }
}
// Judul game

void Story::Title(){
    curs_set(0);

    mvprintw(5, 25,  " /$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$$        /$$$$$$$   /$$$$$$  /$$   /$$  /$$$$$$ ");
    mvprintw(6, 25,  " /$$__  $$|__  $$__//$$__  $$| $$__  $$      | $$__  $$ /$$__  $$| $$$ | $$ /$$__  $$");
    mvprintw(7, 25,  "| $$  \\__/   | $$  | $$  \\ $$| $$  \\ $$      | $$  \\ $$| $$  \\ $$| $$$$| $$| $$  \\__/");
    mvprintw(8, 25,  "| $$  \\__/   | $$  | $$  \\ $$| $$  \\ $$      | $$  \\ $$| $$  \\ $$| $$$$| $$| $$  \\__/");
    mvprintw(9, 25,  "|  $$$$$$    | $$  | $$$$$$$$| $$$$$$$/      | $$$$$$$/| $$  | $$| $$ $$ $$| $$ /$$$$");
    mvprintw(10, 25, " \\____  $$   | $$  | $$__  $$| $$__  $$      | $$____/ | $$  | $$| $$  $$$$| $$|_  $$");
    mvprintw(11, 25, " /$$  \\ $$   | $$  | $$  | $$| $$  \\ $$      | $$      | $$  | $$| $$\\  $$$| $$  \\ $$");
    mvprintw(12, 25, "|  $$$$$$/   | $$  | $$  | $$| $$  | $$      | $$      |  $$$$$$/| $$ \\  $$|  $$$$$$/");
    mvprintw(13, 25, " \\______/    |__/  |__/  |__/|__/  |__/      |__/       \\______/ |__/  \\__/ \\______/");
    
    refresh();
    napms(3000);

}


// Tampilan loading
void Story::Loading(){
    curs_set(0);
    
    for(int i = 0; i < 3; i++){
        mvprintw(15, 56, "      Loading...");
        mvprintw(16, 56, "--------------------");
        mvprintw(17, 56, "|                   |");
        mvprintw(18, 56, "--------------------");
        mvprintw(19, 56, "     Please wait");

         for(int f = 1; f <= 20; f++){
            mvprintw(17, 56 + f, "|");
            refresh();
            napms(50);
        }
    }
}

// Story
void Story::Intro(){
    // Ini manggil musiknya, musiknya entar ditambah lagi
    // Ini ngikutin local path gw
    // entar coba biar semua bisa play lagunya
    //playmusic("D:\\DEV\\UAP-PP\\CODE\\Musik\\Epic Intro.wav");

    curs_set(0);
    
    clear();
    refresh();

    mvprintw(5, 35,  "        .        *           .              +         *        .           ");
    mvprintw(6, 35,  "                      .             *              .        +              ");
    mvprintw(7, 35,  "    +        .              .              .              *        .       ");
    mvprintw(8, 35,  "         *         +              *              .              +         ");
    mvprintw(9, 35,  "  .              .        *    .:'        .              *                ");
    mvprintw(10, 35, "       *              .     _.::'    *         .              .      +    ");
    mvprintw(11, 35, "            .    +         (_.'           .         *        | .           ");
    mvprintw(12, 35, "  *                  .              *              +       --*--          ");
    mvprintw(13, 35, "         .                 .-.           .                   |      .     ");
    mvprintw(14, 35, "    +         *    .        ) )      +         .         *        .       ");
    mvprintw(15, 35, "         .              .   '-    .        +         .              *     ");
    mvprintw(16, 35, "              *                        .        *         .      +        ");
    mvprintw(17, 35, "  .                  +         *              .              .            ");
    mvprintw(18, 35, "       +      .            .              *         .              *      ");
    mvprintw(19, 35, "         .         *    .        *    .              +         .         ");
    mvprintw(20, 35, "              .              +         .       *              .      +    ");
    mvprintw(21, 35, "   *                  .              .              .    *                ");
    mvprintw(22, 35, "         .      +         .              *              .         .       ");
    mvprintw(23, 35, "              .       *         .              +         *        .       ");
    mvprintw(24, 35, "    +              .        *         .              .         +          ");
    refresh();

    // make long waits responsive to skip
    for (int t = 0; t < 2000; t += 100) { napms(100); if (input()) return; }

    move(26, 35);
    reciter("Pada abad ke-75, berjarak ribuan tahun cahaya dari bumi.");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }
    
    move(27, 35);
    reciter("Jauh di dalam Supergugus Laniakea XZ-4, terdapat arena angkasa kuno,");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }


    move(28, 35);
    reciter("yang disebut sebagai THE RESONANCE CHAMBER.");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(29, 35);
    reciter("Peninggalan peradaban kosmik yang telah musnah ribuan tahun lalu.");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    clear();
    napms(200);

    mvprintw(5, 45, "          .-~~~~~~~~~-.");
    mvprintw(6, 45, "      .-'               '-.");
    mvprintw(7, 45, "    ,'     O       O       ',");
    mvprintw(8, 45, "   /         O       O       \\");
    mvprintw(9, 45, "  /    O          O      O    \\");
    mvprintw(10, 45, " |        O           O        |");
    mvprintw(11, 45, " |   O         O          O    |");
    mvprintw(12, 45, "  \\      O          O       O /");
    mvprintw(13, 45, "   \\        O            O   /");
    mvprintw(14, 45, "    '.      O       O       ,'");
    mvprintw(15, 45, "      '-.               .-'");
    mvprintw(16, 45, "          '-._______.-'");
    refresh();
    for (int t = 0; t < 2000; t += 100) { napms(100); if (input()) return; }

    move(18, 35);
    reciter("Di dalam arena itu, terdapat sebuah bola energi yang terus berdenyut,");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(19, 35);
    reciter("yang dikenal sebagai The Astral Core.");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(20, 35);
    reciter("Bola misterius ini memiliki kekuatan besar, ");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(21, 35);
    reciter("dengan satu getaran yang mampu menstabilkan alam semesta,");
    refresh();
    napms(25);
   for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(22, 35);
    reciter("atau menghancurkan.");
    refresh();
    napms(25);
   for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    clear();
    napms(200);

    mvprintw(15, 40, "+-------------------------------------------------------------+");
    mvprintw(16, 40, "|                                                             |");
    mvprintw(17, 40, "|    |                                                 |      |");
    mvprintw(18, 40, "|    |                       0                         |      |");
    mvprintw(19, 40, "|    |                (Astral Core)                    |      |");
    mvprintw(20, 40, "|    |                                                 |      |");
    mvprintw(21, 40, "|                                                             |");
    mvprintw(22, 40, "+-------------------------------------------------------------+");
    refresh();
    for (int t = 0; t < 2000; t += 100) { napms(100); if (input()) return; }

    move(24, 40);
    reciter("Dua fraksi terbesar di galaksi, FRAKSI PROXIMA dan FRAKSI CENTAURI,");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(25, 40);
    reciter("kini bersaing untuk menguasai Astral Core tersebut.");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(26, 40);
    reciter("Perang besar dilarang, karena energi Laniakea XZ-4 terlalu rapuh.");
    refresh();
    napms(25);
   for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }
    move(27, 40);
    reciter("Satu letupan dari getaran Astral Core saja dapat membuat semesta kembali ke titik nol.");
    refresh();
    napms(25);
   for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }
    clear();
    napms(200);

// Langit penuh bintang dengan bintang raksasa
    mvprintw(5, 45,  "        *           .        |            *        .        *    ");
    mvprintw(6, 45,  "    .       *                |                *           .      ");
    mvprintw(7, 45,  "         .            *     \\|/        .            *           ");
    mvprintw(8, 45,  "   *          .           ---*---   *        .                  ");
    mvprintw(9, 45,  "         *                  /|\\          *        .        *    ");
    mvprintw(10, 45, "    .            *           |      .                *          ");
    mvprintw(11, 45, "              .      *       |   *          ....--==-.      .   ");
    mvprintw(12, 45, "  *     *         .          |      .--==***#########*     *    ");
    mvprintw(13, 45, "            .   *            |  .=*#####******###**###  *       ");
    mvprintw(14, 45, "      *              .      *|* =####***##*##****####**     .   ");
    mvprintw(15, 45, "  .         *    .=*.    *   | *.=###**##****##*#*###**    *    ");
    mvprintw(16, 45, "       *       .     -*###*#*.####**###****###*####*        .   ");
    mvprintw(17, 45, "            *        =#*.#*####*###*#*...*****#*..*###. -#   *  ");
    mvprintw(18, 45, "  *  .=====----------=###**#########*#*######*###*####* *#.     ");
    mvprintw(19, 45, "          *       .   *####*##*###*####*#  *           .  *     ");
    mvprintw(20, 45, "      .       ...   =###*####*#**##**#=    *  #*     ###    *   ");
    mvprintw(21, 45, "  *         ..=*#*    *   =####*##*###**   ....#     *    .     ");
    mvprintw(22, 45, "       *  .=###*        .        =####*#*#    *####*      *     ");
    mvprintw(23, 45, "    .    .=*#*       *      ..=####*  *  #*   ##* *#     .   *  ");
    mvprintw(24, 45, "  *    .=*#*         .  ..=####**        ##*       *            ");
    mvprintw(25, 45, "      =#*       *    .=####**     *      ###     .         *    ");
    mvprintw(26, 45, "  .  #*     .  .===**##**       .        #**       *       .    ");
    mvprintw(27, 45, "     #*  ...===**      *    .            ##    .        *       ");
    mvprintw(28, 45, "  *  ****       .                 *      *#         .       *   ");
    mvprintw(29, 45, "           *          .   *              ##    *         .      ");
    mvprintw(30, 45, "      .         *                  .     #*         *           ");
    mvprintw(31, 45, "  *        .              *     .        **    .         *      ");
    refresh();
    for (int t = 0; t < 2000; t += 100) { napms(100); if (input()) return; }

    move(33, 45);
    reciter("Seluruh galaksi sepakat, satu-satunya cara,");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(34, 45);
    reciter("untuk untuk menyelesaikan sengketa perebutan benda misterius tersebut,");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(35, 45);
    reciter("hanyalah dengan PERTARUNGAN DI ARENA RESONANSI.");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    clear();
    napms(200);

    mvprintw(1, 40, "        .        *           .                    *         .              *        ");
    mvprintw(2, 40, "  *          .       *    .         *    .              .         *            .   ");
    mvprintw(2, 40, "     .   *       .            .  *          .    *           .         .    *      ");
    mvprintw(3, 40, " .        ####      *     .            *         .                *         .      ");
    mvprintw(4, 40, "    *    ######  .      *     .   *         .         *    .            *         ");
    mvprintw(5, 40, "  .     ########            .                                  .      .       *    ");
    mvprintw(6, 40, "    *  ##########    .   *        .    *         .      *          .              ");
    mvprintw(7, 40, " .    ############                         *              .    *       .    *     ");
    mvprintw(8, 40, "  *  ##############==\\       .    *    .         .    *            .             ");
    mvprintw(9, 40, "    ################==\\___                  .               *          .      *   ");
    mvprintw(10, 40, " . |##################===\\________    *          .    *          .               ");
    mvprintw(11, 40, "   |####################|==========\\=======\\       .      *    .      *    .     ");
    mvprintw(12, 40, "*  |##[]####[]####[]####|###########|#######|\\   *    .       .            *     ");
    mvprintw(13, 40, "  /|====================|===========|========|=\\        .   *       .            ");
    mvprintw(14, 40, " |=|[]##[]##[]##[]##[]##|[]##[]##[]##[]##[]##|#\\    *         .       *    .    ");
    mvprintw(15, 40, " |#|====================|=======================|=\\       .        *          .   ");
    mvprintw(16, 40, " |=|[]##[]##[]##[]##[]##|[]##[]##[]##[]##[]##[]|##\\   *      .          *        ");
    mvprintw(17, 40, " |#|====================|=======================|###|     .      *    .      .    ");
    mvprintw(18, 40, " |=|[]##[]##[]##[]##[]##|[]##[]##[]##[]##[]##|###|  *         .           *     ");
    mvprintw(19, 40, " |#|====================|=======================|##/    .   *        .            ");
    mvprintw(20, 40, "  \\|[]##[]##[]##[]##[]##|[]##[]##[]##[]##[]##|#/   *         .    *        .    ");
    mvprintw(21, 40, "   |####################|===========|========|/       .   *           .      *    ");
    mvprintw(22, 40, " . |##################===/____|     \\=======/ *  .             *                 ");
    mvprintw(23, 40, "    ################==/      |      \\               *    .         .      .   *   ");
    mvprintw(24, 40, "  * ##############==/   *    |   .   \\    *    .            *                    ");
    mvprintw(25, 40, " .  ############==/          |        \\        .     *   .         .        *    ");
    mvprintw(26, 40, "    ##########==/       .    |    *    \\  *        .          *                  ");
    mvprintw(27, 40, "  * ########==/              |          \\      .         *            .      *   ");
    mvprintw(28, 40, " .  ######==/           *    |       .   \\|||     *    .         *               ");
    mvprintw(29, 40, "    ####==/     .            |            ||||  .          .              *    .  ");
    mvprintw(30, 40, "  * ##==/               *    |    *       ||||     *   .        .                ");
    mvprintw(31, 40, " .   ==/       *    .        |        .   ||||~~~        *           *      .    ");
    mvprintw(32, 40, "     =/              .       |            ||||~~~~~~  .         *                 ");
    mvprintw(33, 40, "  * /    .    *          .   |    *       |||~~~~~~~~      .          *      .   ");
    mvprintw(34, 40, " .    *         .            |        .   ||~~~~~~~~~~~~        .                 ");
    mvprintw(35, 40, "         .             *     |            |~~~~~~~~~~~~~~    *       .       *    ");
    refresh();
    napms(2000);

    move(36, 40);
    reciter("Kamu adalah pilot terpilih, yang ditakdirkan untuk kelak akan menyelamatkan semesta.");
    refresh();
    napms(25);
   for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(37, 40);
    reciter("Gunakan kemampuanmu dengan baik.");
    refresh();
    napms(25);
   for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(38, 40);
    reciter("Kapalmu akan memasuki arena kosmik berbahaya, di mana pantulan energi kosmik,");
    refresh();
    napms(25);
   for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(39, 40);
    reciter("akan menentukan masa depan alam semesta.");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }
    clear();
    napms(200);

    mvprintw(9, 25,  "       //\\\\       ");
    mvprintw(10, 25, "      //  \\\\      ");
    mvprintw(11, 25, "     //    \\\\     ");
    mvprintw(12, 25, "    //______\\\\    ");
    mvprintw(13, 25, "   |||########|||  ");
    mvprintw(14, 25, "   |||########|||  ");
    mvprintw(15, 25, "   |||########|||  ");
    mvprintw(16, 25, "===|||########|||>>~~~~");
    mvprintw(17, 25, "===|||########|||>>~~~~");
    mvprintw(18, 25, "===|||########|||>>~~~~");
    mvprintw(19, 25, "   |||########|||  ");
    mvprintw(20, 25, "   |||########|||  ");
    mvprintw(21, 25, "   |||########|||  ");
    mvprintw(22, 25, "    ///######\\\\\\   ");
    mvprintw(23, 25, "     ///####\\\\\\    ");
    mvprintw(24, 25, "      ///##\\\\\\     ");
    mvprintw(25, 25, "       ///\\\\\\      ");
    mvprintw(26, 25, "      ()(((()))     ");
    mvprintw(27, 25, "      ()(((()))     ");
    refresh();
    napms(2000);

    move(29, 25);
    reciter("Setiap pantulan adalah gema sejarah.");
    refresh();
    napms(25);
   for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }
    move(30, 25);
    reciter("Setiap gema adalah penentu takdir.");
    refresh();
    napms(25);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    mvprintw(9, 100,  "                 //\\\\       ");
    mvprintw(10, 100, "                //  \\\\      ");
    mvprintw(11, 100, "               //    \\\\     ");
    mvprintw(12, 100, "              //______\\\\    ");
    mvprintw(13, 100, "             |||########|||  ");
    mvprintw(14, 100, "             |||########|||  ");
    mvprintw(15, 100, "             |||########|||  ");
    mvprintw(16, 100, "       ~~~~<<|||########|||===");
    mvprintw(17, 100, "       ~~~~<<|||########|||===");
    mvprintw(18, 100, "       ~~~~<<|||########|||===");
    mvprintw(19, 100, "             |||########|||  ");
    mvprintw(20, 100, "             |||########|||  ");
    mvprintw(21, 100, "             |||########|||  ");
    mvprintw(22, 100, "             ///######\\\\\\   ");
    mvprintw(23, 100, "               ///####\\\\\\    ");
    mvprintw(24, 100, "                ///##\\\\\\     ");
    mvprintw(25, 100, "                 ///\\\\\\      ");
    mvprintw(26, 100, "                ()(((()))     ");
    mvprintw(27, 100, "                ()(((()))     ");
    refresh();
    napms(2000);

    move(29, 100);
    reciter("Dan setiap kekalahan,");
    refresh();
    napms(10);
   for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }
    move(30, 100);
    reciter("artinya adalah akhir.");
    refresh();
    napms(10);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    clear();

    mvprintw(5, 35,  "        .        *           .              +         *        .           ");
    mvprintw(6, 35,  "                      .             *              .        +              ");
    mvprintw(7, 35,  "    +        .              .              .              *        .       ");
    mvprintw(8, 35,  "         *         +              *              .              +          ");
    mvprintw(9, 35,  "  .              .        *              .              *                   ");
    mvprintw(10, 35, "       *              .              *         .              .      +      ");
    mvprintw(11, 35, "            .    +                 .         *                .             ");
    mvprintw(12, 35, "  *                  .              *              +                        ");
    mvprintw(13, 35, "         .                 .                .                        .      ");
    mvprintw(14, 35, "    +         *    .                +         .         *        .          ");
    mvprintw(15, 35, "         .              .          .        +         .              *      ");
    mvprintw(16, 35, "              *                        .        *         .      +          ");
    mvprintw(17, 35, "  .                  +         *              .              .              ");
    mvprintw(18, 35, "       +      .            .              *         .              *        ");
    mvprintw(19, 35, "         .         *    .        *    .              +         .            ");
    mvprintw(20, 35, "              .              +         .       *              .      +      ");
    mvprintw(21, 35, "   *                  .              .              .    *                  ");
    mvprintw(22, 35, "         .      +         .              *              .         .         ");
    mvprintw(23, 35, "              .       *         .              +         *        .         ");
    mvprintw(24, 35, "    +              .        *         .              .         +            ");
    mvprintw(25, 35, "         .                      *              .                    .       ");
    mvprintw(26, 35, "              *         .              +              *         .           ");
    mvprintw(27, 35, "    .                        .              .              .                ");
    mvprintw(28, 35, "         +         *              .              *         .         +      ");
    mvprintw(29, 35, "              .              .         *              .              .      ");
    mvprintw(30, 35, "   *              .    +         .              .              *            ");
    refresh();
    napms(2000);

    move(32, 35);
    reciter("Pertahankan orbitmu.");
    refresh();
    napms(10);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }
    
    move(33, 35);
    reciter("jangan biarkan kekuatan Astral Core jatuh ke tangan musuh.");
    refresh();
    napms(10);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(34, 35);
    reciter("Buktikan fraksimu layak memegang cahaya kosmos.");
    refresh();
    napms(10);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }


    clear();
    napms(2000);
    //stopmusic();

    move(30, 40);
    reciter("> Ini bukan hanya sekedar pertempuran.");
    refresh();
    napms(10);
    for (int t = 0; t < 3000; t += 100) { napms(25); if (input()) return; }

    move(32, 40);
    reciter("> Ini adalah legenda yang ditulis dalam kehampaan gugus bintang.");
    refresh();
    napms(10);

    for (int t = 0; t < 3000; t += 100) { napms(100); if (input()) return; }
    clear();

}