#ifndef STORY_H
#define STORY_H

#include <ncurses/curses.h>
#include <windows.h>
#include <string>

class Story {
    public:
    void reciter(std::string text, int delay = 50);
    bool input();
    void Title();
    void Loading();
    void Intro();
    bool skipped() const { return _skipped; }
    void reset_skipped() { _skipped = false; }
    
    private:
    bool _skipped = false;
};
#endif