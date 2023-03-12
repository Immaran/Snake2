#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
    srand(time(NULL));

    const char leftTopCorner = 201, rightTopCorner = 187, leftBottomCorner = 200, rightBottomCorner = 188, horizontalWall = 205, verticalWall = 186;

    const int boardSize = 10;

    while (true)
    {
        int gameArray[boardSize][boardSize] = {{0}};

        int headX = boardSize / 2;
        int headY = boardSize / 2;
        int moveVectorX = 0;
        int moveVectorY = 0;

        int fruitX = headX, fruitY = headY;

        int points = -1;

        while (true)
        {
            Sleep(300);

            if (_kbhit())
            {
                switch (toupper(_getch()))
                {
                    case 'W':
                        moveVectorY = -1, moveVectorX = 0;
                        break;
                    case 'S':
                        moveVectorY = 1, moveVectorX = 0;
                        break;
                    case 'A':
                        moveVectorY = 0, moveVectorX = -1;
                        break;
                    case 'D':
                        moveVectorY = 0, moveVectorX = 1;
                        break;
                }
            }

            headX += moveVectorX;
            headY += moveVectorY;

            if (headX == -1 || headX == boardSize || headY == -1 || headY == boardSize) break;

            if (gameArray[headY][headX] > 0) break;

            if (headX == fruitX && headY == fruitY)
            {
                points++;

                do
                {
                    fruitX = rand() % boardSize;
                    fruitY = rand() % boardSize;
                } while (gameArray[fruitY][fruitX] > 0 || (fruitX == headX && fruitY == headY));
            }

            gameArray[headY][headX] = points + 1;

            system("cls");

            cout << leftTopCorner;

            for (int i = 0; i < boardSize * 2 - 1; i++) cout << horizontalWall;

            cout << rightTopCorner << endl;

            for (int i = 0; i < boardSize; i++)
            {
                cout << verticalWall;

                for (int j = 0; j < boardSize; j++)
                {
                    if (gameArray[i][j] > 0) cout << 'O';
                    else if (i == fruitY && j == fruitX) cout << '%';
                    else cout << ' ';

                    if (j < boardSize - 1) cout << ' ';

                    gameArray[i][j]--;
                }

                cout << verticalWall << endl;
            }

            cout << leftBottomCorner;

            for (int i = 0; i < boardSize * 2 - 1; i++) cout << horizontalWall;

            cout << rightBottomCorner << endl << points << ' ';
        }

        cout << "restart [R] ";

        while (toupper(_getch()) != 'R'){}
    }
}