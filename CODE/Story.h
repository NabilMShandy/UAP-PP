#ifndef STORY_H
#define STORY_H

#include <ncurses/curses.h>
#include <windows.h>
#include <string>

class Story {
    public:
    void reciter(std::string text, int delay = 50);
    void input();
    
        void Title();
        void Loading();
        void Intro();

};
#endif
