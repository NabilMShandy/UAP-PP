#ifndef BOLA_H
#define BOLA_H

#include <cstdint>
#include <cstdlib>


class Bola {
    public: 
    int x;
    int y;
    Bola(int begin_x, int begin_y);
    void gerak (int gx, int gy);
    void tampilkan();
    void updateposisi(int gx, int gy);
    
    
};
#endif // BOLA_H

