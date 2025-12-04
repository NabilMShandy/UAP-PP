#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
public:
    int x;
    int y;
    int height;

    Paddle(int begin_x, int begin_y);
    void tampilkan();
    void gerakUp();
    void gerakDown();
};

#endif
