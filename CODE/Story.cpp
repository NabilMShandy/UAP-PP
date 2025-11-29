// #ifndef STORY_H
// #define STORY_H

#include <ncurses/curses.h>
#include <windows.h>

// Judul game
void Title(){
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
void Loading(){
    curs_set(0);
    
    for(int i = 0; i < 3; i++){
        mvprintw(15, 56, "      Loading...");
        mvprintw(16, 56, "--------------------");
        mvprintw(17, 56, "|                  |");
        mvprintw(18, 56, "--------------------");
        mvprintw(19, 56, "     Please wait");

        for(int f = 1; f <= 18; f++){
            mvprintw(17, 56 + f, "|");
            refresh();
            napms(50);
        }
    }
    

}

// Story
void Intro(){
    clear();
    refresh();

    mvprintw(5, 25, "                 o                                         .o          +        ");
    mvprintw(6, 35, "         .                                      '                             . ");
    mvprintw(7, 35, "      '                         .                                   '           ");
    mvprintw(8, 35, "          '          .                                 .                    .   ");
    mvprintw(9, 35, ".                '                   .:'                           .            ");
    mvprintw(10, 35, "                           '.    _.::'                        .     o           ");
    mvprintw(11, 35, "               .   +            (_.'                               |     +      ");
    mvprintw(12, 35, "           o                                                     --o--          ");
    mvprintw(13, 35, "                    '              .-.           +                 |      .     ");
    mvprintw(14, 35, "                .  +      .         ) )                        .          +   ' ");
    mvprintw(15, 35, "            .  .                   '-    .      ' +                            ");
    mvprintw(16, 35, "             o                               '+*              '       '       + ");
    mvprintw(17, 35, "     .                        o*    +                                           ");
    mvprintw(18, 35, "                  '      .   |                 . '                              ");
    mvprintw(19, 35, "                       o   --o--   .  _|_'   .                                  ");
    mvprintw(20, 35, "                             |  +~~    |                             *          ");
    mvprintw(21, 35, "           .         . o              '   +                                     ");
    mvprintw(22, 35, " .                                        .     '                     *         ");
    mvprintw(23, 35, "  +~~   .             o       *       o*                               *+      ");
    mvprintw(24, 35, "                   '   '                      o  +                  . ");
    refresh();

    napms(300);

    mvprintw(26, 35, "Pada abad ke-75, berjarak ribuan tahun cahaya dari bumi.");
    refresh();
    napms(300);

    mvprintw(27, 35, "Jauh di dalam Supergugus Laniakea XZ-4, terdapat arena angkasa kuno,");
    refresh();
    napms(300);

    mvprintw(28, 35, "yang disebut sebagai THE RESONANCE CHAMBER.");
    refresh();
    napms(300);

    mvprintw(29, 35, "Peninggalan peradaban kosmik yang telah musnah ribuan tahun lalu.");
    refresh();
    napms(300);

    clear();

    mvprintw(5, 35, "           . - ~ ~ ~ - .");
    mvprintw(6, 35, "        ,'               ',");
    mvprintw(7, 35, "      ,'    O       O      ',");
    mvprintw(8, 35, "     /          O            \\");
    mvprintw(9, 35, "    :    O              O     :");
    mvprintw(10, 35, "    :                     O    :");
    mvprintw(11, 35, "    \\     O       O          //");
    mvprintw(12, 35, "      `.        O           .'");
    mvprintw(13, 35, "        ` - . _ _ _ _ . - '");
    refresh();
    napms(250);

    mvprintw(15, 40, "Di dalam arena itu, terdapat sebuah bola energi yang terus berdenyut,");
    refresh();
    napms(300);

    mvprintw(16, 40, "yang dikenal sebagai The Astral Core.");
    refresh();
    napms(300);

    mvprintw(17, 40, "Bola misterius ini memiliki kekuatan besar, dengan satu getaran yang mampu menstabilkan alam semesta,");
    refresh();
    napms(300);

    mvprintw(18, 40, "atau menghancurkan.");
    refresh();
    napms(300);
    clear();

    mvprintw(5, 35, "+-------------------------------------------------------------+");
    mvprintw(6, 35, "|                                                             |");
    mvprintw(7, 35, "|    |                                                 |      |");
    mvprintw(8, 35, "|    |                     *                           |      |");
    mvprintw(9, 35, "|    |                (Astral Core)                    |      |");
    mvprintw(10, 35,"|    |                                                 |      |");
    mvprintw(11, 35,"|                                                             |");
    mvprintw(12, 35,"+-------------------------------------------------------------+");
    refresh();
    napms(1000);

}

int main(){
    initscr();

    Title();
    Loading();
    Intro();
    
    endwin();
}

// #endif