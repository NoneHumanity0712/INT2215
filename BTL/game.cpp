#include <iostream>
#include <ctime>
#include "Piece.h"

using namespace std;

const int boardHeight = 20;
const int boardWidth = 10;

int board[boardHeight][boardWidth] = {0};

bool GameOver()
{
    return false;
}

void GameInit()
{  
}

void UpdateGame(Piece newPiece, int shapeIndex, int rotationIndex)
{
    newPiece.Shape = shapeIndex;
    newPiece.Rotation = rotationIndex;
    for (int i = 0; i < 5 + newPiece.getBeginYPos; i++)
    {
        for (int j = 0; j < 5 + newPiece.getBeginXPos; j++)
        {
            board[i][j] = newPiece.getTetromino(i - newPiece.getBeginYPos, j - newPiece.getBeginXPos);
        } 
    }
}

void PrintMap()
{
    for (int i = 0; i < boardHeight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl << endl;
    }
}

int main()
{
    srand(static_cast <unsigned int> (time(0)));
    unsigned int index = rand();
    int shapeIndex = index%7;
    int rotationIndex = index%4;

    cout << index << endl;
    cout << shapeIndex << " " << rotationIndex << endl;
    while (!GameOver())
    {
        Piece newPiece;
        // GameInit();
        UpdateGame(newPiece, shapeIndex, rotationIndex);
        PrintMap();
        break;
    }
    return 0;
}