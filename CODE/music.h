#ifndef MUSIK_HPP
#define MUSIK_HPP

#include <windows.h>
#include <mmsystem.h>
#include <ncurses/curses.h>
#pragma comment(lib, "winmm.lib")

// Mainkan musik
void playmusic(const char * musicFile, DWORD flags = SND_ASYNC | SND_LOOP) {
    PlaySoundA(musicFile, NULL, flags);
}


// Stop musik
void stopmusic() {
  PlaySoundA(NULL, 0, SND_PURGE);
}

#endif