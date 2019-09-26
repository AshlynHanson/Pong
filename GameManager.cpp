#include "GameManager.h"

GameManager::GameManager()
{

}
GameManager::GameManager(int w, int h)
{
    srand(time(NULL));
    quit = false;
    score1 = 0; score2 = 0;
    width = w; height = h;
    ball = new Ball((w/2),(h/2));
    p1 = new Paddle(1, (h/2) -3);
    p2 = new Paddle(w -2, (h/2) -3);
}
GameManager::~GameManager()
{
    delete ball, p1, p2;
}
void GameManager::increaseScore(Paddle *player)
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
void GameManager::draw()
{
    Sleep(90);
    system("cls");

    /*
    * Draws the top wall
    */
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
            /*
            * Makes the player bar 4 blocks long
            */
            else if ( player1x == j && (player1y == i || player1y +1 == i || player1y +2 == i || player1y +3 == i))
            {
                   cout << "\xDB"; //player 1
            }
            else if ( player2x == j && (player2y == i|| player2y +1 == i || player2y +2 == i || player2y +3 == i))
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
    /*
    * creates and draws the bottom wall
    */
    for (int i = 0; i < width +2 ; i++)
    {
        cout << "\xB2";
    }

    cout << endl;

    cout << "Score1: " <<score1 <<" Score 2: "<<score2<<endl;
}
/**
 Registers if a button was pressed on the keyboard.
      - Player 1 uses 'w' to go UP and 's' to go DOWN
      - Player 2 used 'i' to go UP and 'k' to go DOWN
      - 'q' quits the game
*/
void GameManager::input()
{
    ball->move();

    if (_kbhit())
    {
        char current = _getch();
        if(current == UP_PLAYER_1) {
            if((p1->getY()) >0) {
                p1->moveUp();
            }
        }
        if(current == UP_PLAYER_2) {
            if(p2->getY() >0) {
                p2->moveUp();
            }
        }
        if(current == DOWN_PLAYER_1) {
            if((p1->getY()) +4 < height) {
                p1->moveDown();
            }
        }
        if(current == DOWN_PLAYER_2) {
            if((p2->getY()) +4 < height) {
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
/**
 Handles the logical movements during the game.
 Changes the ball's direction if it hits a paddle or a wall.
 Increases the score if the ball hits the opponent's wall.
*/
void GameManager::logic()
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
        increaseScore(p1);
    }
    //left wall
    if (ballX == 0) {
        increaseScore(p2);
    }
}
void GameManager::run()
{
    while(!quit)
    {
        draw();
        input();
        logic();
    }
}

