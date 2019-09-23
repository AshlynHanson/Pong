#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

enum eDir {STOP = 0, LEFT = 1, UPLEFT = 2,DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class cBall
{
private:
    int x, y;
    int originalX, originalY;
    eDir direction;
public:
    cBall(int posX, int posY)
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
        direction = STOP;
    }
    void reset()
    {
        x = originalX;
        y = originalY;
        direction = STOP;
    }
    void changeDirection(eDir d)
    {
        direction = d;
    }
    void randomDirection()
    {
        direction = (eDir)((rand()%6) +1);
    }
    inline int getX()
    {
        return x;
    }
    inline int getY()
    {
        return y;
    }
    inline eDir getDirection()
    {
        return direction;
    }
    void move()
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
    friend ostream & operator<<(ostream & o, cBall c)
    {
        o << "Ball [" <<c.x << "," << c.y <<"][" << c.direction << "]" <<endl;
        return o;
    }
};
class cPaddle
{
private:
    int x, y;
    int originalX, originalY;
public:
    cPaddle()
    {
        x = y = 0;
    }
    cPaddle(int posX, int posY)
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }
    inline void reset() { x = originalX; y = originalY; }
    inline int getX() {return x; }
    inline int getY() { return y; }
    inline void moveUp() { y--; }
    inline void moveDown() { y++; }
    friend ostream & operator<<(ostream & o, cPaddle c)
    {
        o << "Paddle [" << c.x << "," << c.y << "]" <<endl;
    }
};
class cGameManager
{
private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    cBall * ball;
    cPaddle *p1;
    cPaddle *p2;
public:
    cGameManager(int w, int h)
    {
        srand(time(NULL));
        quit = false;
        up1 = 'w'; up2 = 'i';
        down1 = 's'; down2 ='k';
        score1 = 0; score2 = 0;
        width = w; height = h;
        ball = new cBall((w/2),(h/2));
        p1 = new cPaddle(1, (h/2) -3);
        p2 = new cPaddle(w -2, (h/2) -3);
    }
    ~cGameManager()
    {
        delete ball, p1, p2;
    }
    void scoreUp(cPaddle *player)
    {
        if (player == p1)
        {
            score1++;
        }
        else if (player == p2)
        {
            score2++;
        }
        ball->reset();
        p1->reset();
        p2->reset();
    }
    void draw()
    {
        Sleep(90);
        system("cls");
        for (int i = 0; i < width +2 ; i++)
        {
            cout << "\xB2";
        }
        cout << endl;
        for ( int i = 0; i < height; i++)
        {
            for (int j = 0; j < width +2 ; j++)
            {
                int ballX = ball->getX();
                int ballY = ball->getY();
                int player1x = p1->getX();
                int player1y = p1->getY();
                int player2x = p2->getX();
                int player2y = p2->getY();
                /*
                * creates the left wall
                */
                if(j==0)
                {
                    cout << "\xB2";
                }

                if(ballX == j && ballY == i)
                {
                    cout << "0"; //ball
                }
                else if ( player1x == j && player1y == i)
                {
                    cout << "\xDB"; //player 1
                }
                else if ( player2x == j && player2y == i)
                {
                    cout << "\xDB"; //player 2
                }



                else if ( player1x == j && player1y +1 == i)
                {
                    cout << "\xDB"; //player 1
                }
                else if ( player1x == j && player1y +2 == i)
                {
                    cout << "\xDB"; //player 1
                }
                else if ( player1x == j && player1y +3 == i)
                {
                    cout << "\xDB"; //player 1
                }

                else if ( player2x == j && player2y +1 == i)
                {
                    cout << "\xDB"; //player 1
                }
                else if ( player2x == j && player2y +2 == i)
                {
                    cout << "\xDB"; //player 2
                }
                else if ( player2x == j && player2y +3 == i)
                {
                    cout << "\xDB"; //player 2
                }

                /*
                * creates the empty space where there is no wall, player, or ball
                */
                else
                {
                    cout << " ";
                }
                /*
                * creates the right wall
                */
                if(j == width-1)
                {
                    cout << "\xB2";
                }
            }
            cout<<endl;
        }
        for (int i = 0; i < width +2 ; i++)
        {
            cout << "\xB2";
        }

        cout << endl;

        cout << "Score1: " <<score1 <<"Score 2: "<<score2<<endl;
    }
    void input()
    {
        ball->move();
        int ballX = ball->getX();
        int ballY = ball->getY();
        int player1x = p1->getX();
        int player1y = p1->getY();
        int player2x = p2->getX();
        int player2y = p2->getY();

        if (_kbhit())
        {
            char current = _getch();
            if(current == up1) {
                if(player1y >0) {
                    p1->moveUp();
                }
            }
            if(current == up2) {
                if(player2y >0) {
                    p2->moveUp();
                }
            }
            if(current == down1) {
                if(player1y +4 < height) {
                    p1->moveDown();
                }
            }
            if(current == down2) {
                if(player2y +4 < height) {
                    p2->moveDown();
                }
            }
            if ( ball->getDirection()==STOP) {
                ball->randomDirection();
            }
            if(current == 'q'){
                quit = true;
            }
        }
    }
    void logic()
    {
        int ballX = ball->getX();
        int ballY = ball->getY();
        int player1x = p1->getX();
        int player1y = p1->getY();
        int player2x = p2->getX();
        int player2y = p2->getY();

        //left paddle
        for (int i = 0; i <4; i++) {
            if(ballX == player1x +1 ||ballX == player1x) {
                if(ballY == player1y + i){
                    ball->changeDirection((eDir)((rand() % 3)+4));
                }
            }
        }

        //right paddle
        for (int i = 0; i <4; i++) {
            if(ballX == player2x - 1 || ballX == player2x) {
                if(ballY == player2y + i){
                    ball->changeDirection((eDir)((rand() % 3)+ 1));
                }
            }
        }
        //bottom wall
        if (ballY == height - 1) {
            ball->changeDirection(ball->getDirection()==DOWNRIGHT ? UPRIGHT:UPLEFT);
        }
        //top wall
        if (ballY ==0) {
            ball->changeDirection(ball->getDirection()==UPRIGHT? DOWNLEFT:DOWNRIGHT);
        }
        //right wall
        if (ballX == width - 1) {
            scoreUp(p1);
        }
        //left wall
        if (ballX == 0) {
            scoreUp(p2);
        }
    }
    void run()
    {
        while(!quit)
        {
            draw();
            input();
            logic();
        }
    }
};
int main()
{
    cGameManager c(40, 20);
    Sleep(1000);
    c.run();

    return 0;
}
