#include <iostream>
#include <ctime>
#include "Game.hpp"

using namespace std;

int main()
{
    IO mIO;
    int mScreenHeight = mIO.GetScreenHeight();

    Piece piece;

    Board board(piece, mScreenHeight);

    Game game (&board, &piece, &mIO, mScreenHeight);

    unsigned long time = SDL_GetTicks();

    while (!mIO.IsKeyDown(SDLK_ESCAPE))
    {
        mIO.ClearScreen(); //clear screen
        game.DrawScene(); //draw
        mIO.UpdateScreen(); //put graphic in the screen

        int key = mIO.PollKey();

        switch (key)
        {
        case (SDLK_RIGHT):
            {
                if (board.IsPossibleMovement())
            }
            break;
        
        default:
            break;
        }
    }
}