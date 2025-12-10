#ifndef BOLA_H
#define BOLA_H

#include <cstdint>
#include <cstdlib>
#include "padel.h"

class Bola {
    public: 
    int x;
    int y;
    Bola(int begin_x, int begin_y);
    void gerak (int gx, int gy);
    void tampilkan();
    int get_speed();
    int updateposisi(int gx, int &gy, Paddle &left, Paddle &right);
    void tampilkan_score();
    int get_score_left() const { return score_left; }
    int get_score_right() const { return score_right; }
    
    private:
    int max_x, max_y;
    int score_left;
    int score_right;
};
#endif 

