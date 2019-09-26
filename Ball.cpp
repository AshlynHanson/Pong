#include "Ball.h"

Ball::Ball()
{
}
Ball::Ball(int posX, int posY)
{
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
    direction = STOP;
}
void Ball::reset()
{
    x = originalX;
    y = originalY;
    direction = STOP;
}
void Ball::changeDirection(eDir d) {
    direction = d;
}
void Ball::randomDirection(){
    direction = (eDir)((rand()%6) +1);
}
int Ball::getX(){ return x;}
int Ball::getY() {return y;}
eDir Ball::getDirection() {return direction;}

void Ball::move()
{
    switch (direction)
    {
    case STOP:
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UPLEFT:
        x--; y--;
        break;
    case DOWNLEFT:
        x--;y++;
        break;
    case UPRIGHT:
        x++; y--;
        break;
    case DOWNRIGHT:
        x--;y++;
        break;
    default:
        break;
    }
}

