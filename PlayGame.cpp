#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "Ball.h"
#include "Paddle.h"
#include "GameManager.h"
using namespace std;



int main()
{
    GameManager game(40, 20);
    Sleep(1000);
    game.run();

    return 0;
}
