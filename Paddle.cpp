#include "Paddle.h"

Paddle::Paddle()
{
    x = y = 0;
}
Paddle::Paddle(int posX, int posY)
{
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
}
void Paddle::reset() { x = originalX; y = originalY; }
int Paddle::getX() {return x; }
int Paddle::getY() { return y; }
void Paddle::moveUp() { y--; }
void Paddle::moveDown() { y++; }


