#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "Ball.h"
#include "Paddle.h"
class GameManager
{
    private:
        int width, height;
        int score1, score2;
        const char UP_PLAYER_1 = 'w', DOWN_PLAYER_1 = 's', UP_PLAYER_2='i', DOWN_PLAYER_2='k';
        bool quit;
        Ball * ball;
        Paddle *p1;
        Paddle *p2;
    public:
        GameManager();
        GameManager(int w, int h);
        ~GameManager();
        void increaseScore(Paddle *player);
        void draw();
        void input();
        void logic();
        void run();

};

#endif // GAMEMANAGER_H
