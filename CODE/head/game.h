#ifndef GAME_H
#define GAME_H
#include "padel.h"

class Game {
    public:
    bool input(Paddle &left, Paddle &right);
    void game();
};

#endif 