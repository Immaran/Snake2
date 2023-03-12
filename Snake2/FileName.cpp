//#include <iostream>
//#include <time.h>
//#include <cstdlib>
//#include <conio.h>
//#include <windows.h>
//
//using namespace std;
//
//int N[15][15] = { 0 }, headX = 9, headY = 7, fruitX, fruitY, fruitExist = 1, points = 1, s, r = 0, g = 1, moveVectorY = 0, moveVectorX = 0, y, x, e;
//
//char W[15][15] = { 0 }, key;
//
//const char leftTopCorner = 201, rightTopCorner = 187, leftBottomCorner = 200, rightBottomCorner = 188, verticalWall = 205, horizontalWall = 186;
//
//void wygrana()
//{
//    system("cls");
//    cout << "brawo";
//    Sleep(2000);
//    g = 0;
//}
//void przegrana()
//{
//    system("cls");
//    cout << "dramat i wstyd       " << points - 1 << " pkt";
//    Sleep(2000);
//    g = 0;
//}
//void ruch()
//{
//    Sleep(300);
//    if (_kbhit())
//    {
//        switch (key = _getch())
//        {
//        case 'w':
//            moveVectorY = -1, moveVectorX = 0;
//            break;
//        case 's':
//            moveVectorY = 1, moveVectorX = 0;
//            break;
//        case 'a':
//            moveVectorY = 0, moveVectorX = -1;
//            break;
//        case 'd':
//            moveVectorY = 0, moveVectorX = 1;
//            break;
//        }
//    }
//
//    if (headX + moveVectorX == 0 || headX + moveVectorX == 14 || headY + moveVectorY == 0 || headY + moveVectorY == 14)
//    {
//        przegrana();
//    }
//    if (N[headX + moveVectorX][headY + moveVectorY] > 1)
//    {
//        przegrana();
//    }
//
//    headX = headX + moveVectorX;
//    headY = headY + moveVectorY;
//}
//void wyswietlanie()
//{
//    system("cls");
//
//    cout << leftTopCorner;
//
//    for (e = 0; e < 13; e++)
//    {
//        cout << verticalWall << verticalWall;
//    }
//
//    cout << rightTopCorner << endl;
//
//    for (y = 1; y < 14; y++)
//    {
//        cout << horizontalWall;
//
//        for (x = 1; x < 14; x++)
//        {
//            cout << W[x][y] << " ";
//        }
//
//        cout << horizontalWall << endl;
//    }
//
//    cout << leftBottomCorner;
//
//    for (e = 0; e < 13; e++)
//    {
//        cout << verticalWall << verticalWall;
//    }
//
//    cout << rightBottomCorner << endl << endl << points - 1;
//
//    ruch();
//}
//void owoc()
//{
//    srand(time(NULL));
//
//    if (fruitExist == 0)
//    {
//        do
//        {
//            fruitX = rand() % 13 + 1;
//
//            fruitY = rand() % 13 + 1;
//        } while (N[fruitX][fruitY] > 0 || fruitX != headX && fruitY != headY);
//
//
//        fruitExist++;
//    }
//}
//void obraz()
//{
//    for (y = 0; y < 15; y++)
//    {
//        for (x = 0; x < 15; x++)
//        {
//            W[x][y] = ' ';
//        }
//    }
//
//    if (headX == fruitX && headY == fruitY)
//    {
//        W[headX][headY] = 'O';
//
//        fruitExist--;
//        points++;
//
//        if (points == 169)
//        {
//            wygrana();
//        }
//
//        owoc();
//    }
//    else
//    {
//        W[headX][headY] = 'G';
//
//        W[fruitX][fruitY] = '*';
//    }
//
//    for (y = 0; y < 15; y++)
//    {
//        for (x = 0; x < 15; x++)
//        {
//            if (N[x][y] > 0)
//            {
//                N[x][y]--;
//            }
//        }
//    }
//    for (y = 0; y < 15; y++)
//    {
//        for (x = 0; x < 15; x++)
//        {
//            if (N[x][y] > 0)
//            {
//                W[x][y] = 'o';
//            }
//        }
//    }
//    N[headX][headY] = points;
//
//    wyswietlanie();
//}
//void gra()
//{
//    while (g == 1)
//    {
//        obraz();
//        gra();
//    }
//
//    if (g == 0)
//    {
//        system("cls");
//    }
//}
//int main()
//{
//    for (y = 0; y < 15; y++)
//    {
//        for (x = 0; x < 15; x++)
//        {
//            N[x][y] = 0;
//        }
//    }
//    headX = 9, headY = 7, fruitExist = 1, points = 1, g = 1, moveVectorY = 0, moveVectorX = 0;
//
//    cout << endl << "      Nacisnij 1, aby zagrac." << endl << endl << "      Nacisnij 2, aby wyjsc." << endl << endl << endl << "      Sterowanie W,S,A,D.";
//
//    switch (key = _getch())
//    {
//    case '1':
//        srand(time(NULL));
//
//        fruitX = rand() % 13 + 1;
//        fruitY = rand() % 13 + 1;
//
//        gra();
//        system("cls");
//        main();
//    case '2':
//        system("cls");
//        return 0;
//    }
//}