#ifndef PADDLE_H
#define PADDLE_H

#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
class Paddle
{
    private:
        Paddle();
        int x, y;
        int originalX, originalY;
    public:
        Paddle(int posX, int posY);
        void reset();
        int getX();
        int getY();
        void moveUp();
        void moveDown();
};

#endif // PADDLE_H
