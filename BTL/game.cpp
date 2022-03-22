#include <iostream>
#include <ctime>
#include "Piece.h"

using namespace std;

const int boardHeight = 20;
const int boardWidth = 10;

int board[boardHeight][boardWidth] = {0};

void getNewPiece(Piece &newPiece)
{
    newPiece.Shape = rand()%7;
    newPiece.Rotation = rand()%4;
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
            getNewPiece(newPiece);
            board[i][j] = newPiece.positionValue[i][j];
        } 
    }
}

void PrintMap()
{
    for (int i = 0; i < boardHeight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            if (board[i][j] == 0) cout << "-";
            else cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));

    while (!GameOver)
    {
        Piece newPiece;
        GameInit();
        
        UpdateGame(newPiece);
        PrintMap();
    }
    return 0;
}