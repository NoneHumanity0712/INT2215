#include <iostream>

using namespace std;

int a[10][10] = {0};

bool GameOver();

void GameInit();

void UpdateGame(int newPiece);

void PrintMap();

int main()
{
    while (!GameOver)
    {
         GameInit();
        int newPiece;
        UpdateGame(newPiece);
        PrintMap();
    }
    return 0;
}