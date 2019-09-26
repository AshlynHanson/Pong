#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

enum eDir {STOP = 0, LEFT = 1, UPLEFT = 2,DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class Ball
{
    private:
        Ball();
        int x, y;
        int originalX, originalY;
        eDir direction;
    public:
        Ball(int posX, int posY);

        void reset();
        void changeDirection(eDir d);
        void randomDirection();
        int getX();
        int getY();
        eDir getDirection();

        void move();

};

#endif // BALL_H
