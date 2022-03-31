#include <iostream>
#include <ctime>
#include "Piece.h"
#include "Board.h"

using namespace std;

bool GameOver()
{
    return false;
}

void GameInit()
{  
}

void UpdateGame(Piece newPiece)
{
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         board[i][j] = newPiece.getTetromino(i, j);
    //     } 
    // }
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

    // cout << index << endl;
    // cout << shapeIndex << " " << rotationIndex << endl;
    while (!GameOver())
    {
        Piece newPiece (shapeIndex, rotationIndex);
        cout << tetrominoes_name[shapeIndex] << endl;
        // GameInit();
        UpdateGame(newPiece);
        PrintMap();
        break;
    }
    return 0;
}