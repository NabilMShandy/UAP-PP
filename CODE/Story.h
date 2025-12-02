#ifndef STORY_H
#define STORY_H

#include <ncurses/curses.h>
#include <windows.h>
#include <string>

class Story {
    public:
<<<<<<< HEAD
    void reciter(std::string text, int delay = 40);
    void input();
=======
    void reciter(std::string text, int delay = 50);
    bool input();
    void Title();
    void Loading();
    void Intro();
    // returns true if story was skipped by user
    bool skipped() const { return _skipped; }
    // reset skipped flag (if you want to reuse Story instance)
    void reset_skipped() { _skipped = false; }
>>>>>>> ebd005e275d0ee96ea27444f3fede89c4fb3251c
    
    private:
    bool _skipped = false;
};
#endif
