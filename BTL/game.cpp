#include <iostream>
#include <ctime>
#include "Piece.h"

using namespace std;

int board[20][10] = {0};

void getNewPiece(Piece &newPiece)
{
    int Shape = rand()%7;
    int Rotation = rand()%4;
    int X = 0;
    int Y = 0;
    newPiece.getTetromino(Shape, Rotation, X, Y);
    newPiece.getBeginXPos(Shape, Rotation);
    newPiece.getBeginYPos(Shape, Rotation);
}

bool GameOver();

void GameInit()
{
}

void UpdateGame(Piece newPiece)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            /* code */
        }
        
    }
    
}

void PrintMap(Piece newPiece)
{

}

int main()
{
    srand(time(0));

    while (!GameOver)
    {
        Piece newPiece;
        getNewPiece(newPiece);
        GameInit();
        
        UpdateGame(newPiece);
        PrintMap(newPiece);
    }
    return 0;
}