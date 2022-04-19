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
        currentPiece.y++;
        if (!board->isMovePossible(currentPiece))
            currentPiece.y--;
    }
    //move pivot block into playfield
    if (currentPiece.type > 1)
    {
        currentPiece.y++;
        if (!board->isMovePossible(currentPiece))
            currentPiece.y--;
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

//handling event from keyboard
void Game::event(ACTION a)
{
    switch (a)
    {
        case ACTION::down:
        {
            currentPiece.y++;
            if (!board->isMovePossible(currentPiece))
            {
                currentPiece.y--;
                checkState(); //check if the piece is set
            }
            break;
        }
        
        case ACTION::left:
        {
            currentPiece.x--;
            if(!board->isMovePossible(currentPiece))
                currentPiece.x++;
            break;
        }

        case ACTION::right:
        {
            currentPiece.x++;
            if (!board->isMovePossible(currentPiece))
                currentPiece.x--;
            break;
        }

        case ACTION::drop:
        {
            while (board->isMovePossible(currentPiece))
                currentPiece.y++;
            currentPiece.y--;
            checkState();
            break;
        }

        case ACTION::rotate:
        {
            currentPiece.rotation = (currentPiece.rotation + 1) % 4; //(0, 3)
            if (!board->isMovePossible(currentPiece))
                currentPiece.rotation = (currentPiece.rotation + 3) % 4;
            break;
        }
    }
}

void Game::initializeScene()
{
    srand(time(0));
    nextPiece.type = getRandom(0, 6);
    nextPiece.rotation = 0;
    createNewPiece();
    
    nextPiece.x = x_nextPiece;
    nextPiece.y = y_nextPiece;

}

bool Game::gameOver()
{
    return board->gameOver();
}

void Game::pieceFalling()
{
    currentPiece.y++;
    if (!board->isMovePossible(currentPiece))
    {
        currentPiece.y--;
        checkState();
    }
}

void Game::drawBoard()
{
    //draw frame
    for (int i = 0; i < 2*true_playfield_height; i++)
    {
        
    }
}