#include <iostream>
#include <ctime>
#include "Piece.h"

using namespace std;

int board[20][10] = {0};

void getNewPiece(Piece &newPiece)
{
    int Shape = rand()%7;
    int Rotation = rand()%4;
    int X;
    int Y;
    newPiece.getTetromino(Shape, Rotation, X, Y);
    newPiece.getBeginXPos(Shape, Rotation);
    newPiece.getBeginYPos(Shape, Rotation);
}

bool GameOver();

void GameInit()
{
}

void UpdateGame(Piece newPiece);

void PrintMap();

int main()
{
    srand(time(0));

    while (!GameOver)
    {
        Piece newPiece;
        getNewPiece(newPiece);
        GameInit();
        
        UpdateGame(newPiece);
        PrintMap();
    }
    return 0;
}