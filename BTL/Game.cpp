#include <iostream>
#include <ctime>
#include "Game.hpp"
#include <SDL.h>

using namespace std;

SDL_Renderer* renderer;

Game::Game()
{
    board = new Board;
}

void Game::checkState()
{
    board->storePiece(currentPiece); //store current block
    board->deleteFullLine(); //delete filled line
    if (!board->gameOver())
    {
        createNewPiece();
    }
}

void Game::createNewPiece()
{
    currentPiece.type = nextPiece.type;
    currentPiece.rotation = nextPiece.rotation;
    currentPiece.x = nextPiece.x;
    currentPiece.y = nextPiece.y;

    //move new normal and null blocks into playfield
    for (int i = 0; i < 2; i++)
    {
        currentPiece.x++;
        if (!board->isMovePossible(currentPiece))
            currentPiece.x--;
    }
    //move pivot block into playfield
    if (currentPiece.type > 1)
    {
        currentPiece.x++;
        if (!board->isMovePossible(currentPiece))
            currentPiece.x--;
    }
    
    //randomly create new piece
    nextPiece.type = getRandom(0, 6);
    nextPiece.rotation = 0;
}

void Game::drawScene()
{
    drawBoard();
    drawCurrentPiece(currentPiece);
    if (!board->gameOver()) drawGhostPiece();
    drawNextPiece(nextPiece);
}

void Game::event()
{
    SDL_Event e;
}