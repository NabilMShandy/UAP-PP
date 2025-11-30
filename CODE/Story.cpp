#include <ncurses/curses.h>
#include <windows.h>
#include "story.h"
#include <iostream>
#include "music.h"

// Ini storynya udah gw tes sama kecepatannya udah disesuaiin
// mungkin bakal ada penyesuaian lagi, kaya posisi gambar sama delay teks

void Story::reciter (std::string text, int delay){
    for (char c : text) {
        addch(c);
        refresh();
        napms(delay);
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
            napms(100);
        }
    }
}

// Story
void Intro(){

    // Ini manggil musiknya, musiknya entar ditambah lagi
    // Ini ngikutin local path gw
    // entar coba biar semua bisa play lagunya

    playmusic("D:\\DEV\\UAP-PP\\Musik\\Epic Intro.wav");
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
    napms(4500);

    mvprintw(26, 35, "Pada abad ke-75, berjarak ribuan tahun cahaya dari bumi.");
    refresh();
    napms(3000);

    mvprintw(27, 35, "Jauh di dalam Supergugus Laniakea XZ-4, terdapat arena angkasa kuno,");
    refresh();
    napms(3000);

    mvprintw(28, 35, "yang disebut sebagai THE RESONANCE CHAMBER.");
    refresh();
    napms(3000);

    mvprintw(29, 35, "Peninggalan peradaban kosmik yang telah musnah ribuan tahun lalu.");
    refresh();
    napms(3000);

    clear();


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
    napms(3500);

    mvprintw(17, 35, "Di dalam arena itu, terdapat sebuah bola energi yang terus berdenyut,");
    refresh();
    napms(3000);

    mvprintw(18, 35, "yang dikenal sebagai The Astral Core.");
    refresh();
    napms(3000);

    mvprintw(19, 35, "Bola misterius ini memiliki kekuatan besar, ");
    refresh();
    napms(3000);

    mvprintw(20, 35, "dengan satu getaran yang mampu menstabilkan alam semesta,");
    refresh();
    napms(3000);

    mvprintw(21, 35, "atau menghancurkan.");
    refresh();
    napms(3000);
    clear();

    mvprintw(5, 40, "+-------------------------------------------------------------+");
    mvprintw(6, 40, "|                                                             |");
    mvprintw(7, 40, "|    |                                                 |      |");
    mvprintw(8, 40, "|    |                       0                         |      |");
    mvprintw(9, 40, "|    |                (Astral Core)                    |      |");
    mvprintw(10, 40,"|    |                                                 |      |");
    mvprintw(11, 40,"|                                                             |");
    mvprintw(12, 40,"+-------------------------------------------------------------+");
    refresh();
    napms(3500);

    mvprintw(15, 35, "Dua fraksi terbesar di galaksi, FRAKSI PROXIMA dan FRAKSI CENTAURI,");
    refresh();
    napms(3000);

    mvprintw(16, 35, "kini bersaing untuk menguasai Astral Core tersebut.");
    refresh();
    napms(3000);

    mvprintw(17, 35, "Perang besar dilarang, karena energi Laniakea XZ-4 terlalu rapuh.");
    refresh();
    napms(3000);

    mvprintw(18, 35, "Satu letupan dari getaran Astral Core saja dapat membuat semesta kembali ke titik nol.");
    refresh();
    napms(3000);

    clear();

// Langit penuh bintang dengan bintang raksasa
    mvprintw(5, 55,  "        *           .        |            *        .        *    ");
    mvprintw(6, 55,  "    .       *                |                *           .      ");
    mvprintw(7, 55,  "         .            *     \\|/        .            *           ");
    mvprintw(8, 55,  "   *          .           ---*---   *        .                  ");
    mvprintw(9, 55,  "         *                  /|\\          *        .        *    ");
    mvprintw(10, 55, "    .            *           |      .                *          ");
    mvprintw(11, 55, "              .      *       |   *          ....--==-.      .   ");
    mvprintw(12, 55, "  *     *         .          |      .--==***#########*     *    ");
    mvprintw(13, 55, "            .   *            |  .=*#####******###**###  *       ");
    mvprintw(14, 55, "      *              .      *|* =####***##*##****####**     .   ");
    mvprintw(15, 55, "  .         *    .=*.    *   | *.=###**##****##*#*###**    *    ");
    mvprintw(16, 55, "       *       .     -*###*#*.####**###****###*####*        .   ");
    mvprintw(17, 55, "            *        =#*.#*####*###*#*...*****#*..*###. -#   *  ");
    mvprintw(18, 55, "  *  .=====----------=###**#########*#*######*###*####* *#.     ");
    mvprintw(19, 55, "          *       .   *####*##*###*####*#  *           .  *     ");
    mvprintw(20, 55, "      .       ...   =###*####*#**##**#=    *  #*     ###    *   ");
    mvprintw(21, 55, "  *         ..=*#*    *   =####*##*###**   ....#     *    .     ");
    mvprintw(22, 55, "       *  .=###*        .        =####*#*#    *####*      *     ");
    mvprintw(23, 55, "    .    .=*#*       *      ..=####*  *  #*   ##* *#     .   *  ");
    mvprintw(24, 55, "  *    .=*#*         .  ..=####**        ##*       *            ");
    mvprintw(25, 55, "      =#*       *    .=####**     *      ###     .         *    ");
    mvprintw(26, 55, "  .  #*     .  .===**##**       .        #**       *       .    ");
    mvprintw(27, 55, "     #*  ...===**      *    .            ##    .        *       ");
    mvprintw(28, 55, "  *  ****       .                 *      *#         .       *   ");
    mvprintw(29, 55, "           *          .   *              ##    *         .      ");
    mvprintw(30, 55, "      .         *                  .     #*         *           ");
    mvprintw(31, 55, "  *        .              *     .        **    .         *      ");
    refresh();
    napms(3000);

    mvprintw(32, 55, "Seluruh galaksi sepakat, satu satunya cara,");
    refresh();
    napms(2000);

    mvprintw(33, 55, "untuk untuk menyelesaikan sengketa perebutan benda misterius tersebut");
    refresh();
    napms(3000);

    mvprintw(34, 55, "hanyalah dengan PERTARUNGAN DI ARENA RESONANSI.");
    refresh();
    napms(3000);

    clear();

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

    mvprintw(36, 40, "Kamu adalah pilot terpilih, yang ditakdirkan untuk kelak akan menyelamatkan semesta.");
    refresh();
    napms(3000);

    mvprintw(37, 40, "Gunakan kemampuanmu dengan baik.");
    refresh();
    napms(3000);

    mvprintw(38, 40, "Kapalmu akan memasuki arena kosmik berbahaya, di mana pantulan energi kosmik");
    refresh();
    napms(3000);

    mvprintw(39, 40, "akan menentukan masa depan alam semesta.");
    refresh();
    napms(3000);

    clear();

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

    mvprintw(29, 25, "Setiap pantulan adalah gema sejarah.");
    mvprintw(30, 25, "Setiap gema adalah penentu takdir.");
    refresh();
    napms(2000);

    mvprintw(9, 70,  "                 //\\\\       ");
    mvprintw(10, 70, "                //  \\\\      ");
    mvprintw(11, 70, "               //    \\\\     ");
    mvprintw(12, 70, "              //______\\\\    ");
    mvprintw(13, 70, "             |||########|||  ");
    mvprintw(14, 70, "             |||########|||  ");
    mvprintw(15, 70, "             |||########|||  ");
    mvprintw(16, 70, "       ~~~~<<|||########|||===");
    mvprintw(17, 70, "       ~~~~<<|||########|||===");
    mvprintw(18, 70, "       ~~~~<<|||########|||===");
    mvprintw(19, 70, "             |||########|||  ");
    mvprintw(20, 70, "             |||########|||  ");
    mvprintw(21, 70, "             |||########|||  ");
    mvprintw(22, 70, "             ///######\\\\\\   ");
    mvprintw(23, 70, "               ///####\\\\\\    ");
    mvprintw(24, 70, "                ///##\\\\\\     ");
    mvprintw(25, 70, "                 ///\\\\\\      ");
    mvprintw(26, 70, "                ()(((()))     ");
    mvprintw(27, 70, "                ()(((()))     ");
    refresh();
    napms(2000);

    mvprintw(29, 70, "Dan setiap kekalahan, ");
    mvprintw(30, 70, "artinya adalah akhir.");
    refresh();
    napms(2000);

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

    napms(3000);

    mvprintw(31, 35, "Pertahankan orbitmu.");
    napms(1500);
    mvprintw(32, 35, "Jangan biarkan kekuatan Astral Core jatuh ke tangan musuh");
    napms(1000);
    refresh();

    mvprintw(33, 35, "Buktikan fraksimu layak memegang cahaya kosmos");
    napms(2000);
    refresh();

    clear();

    napms(3000);

    stopmusic();

    mvprintw(20, 50, "> Ini bukan hanya sekedar pertempuran.");
    mvprintw(23, 50, "> Ini adalah legenda yang ditulis dalam kehampaan gugus bintang.");
    refresh();
    napms(5000);
    
    clear();
}

// FUNGSI MAIN INI HANYA UNTUK TES SAJA
// int main(){

//     initscr();
//     Story story;
//     story.Title();
//     story.Loading();
    
//     Intro();
    
//     endwin();
// }