#ifndef GAME
#define GAME

#include <iostream>
#include <ctime>
#include <SDL.h>
#include <cstdlib>
#include <queue>
#include "board.hpp"
#include "piece.hpp"
#include "input.hpp"
#include "texture.hpp"

const int x_nextPiece = 410;
const int y_nextPiece = 10;
const Uint8 transparency = 100; //set transparency for ghost piece

extern SDL_Renderer *gRenderer; 

class Game
{
public:
    Game();
    void checkState();
    void createNewPiece();
    void drawScene();
    void event(ACTION a);
    void initializeScene();
    bool gameOver();
    void pieceFalling();

private:
    Board* board;
    Piece currentPiece{ 0, 0 };
    Piece ghostPiece{ 0, 0 };
    Piece nextPiece{ 0, 0 };
    std::queue<Piece> nextPieces;
    texture tetromino_graphic;
    SDL_Rect tetromino_graphic_boxes[7];
    texture frame;
    SDL_Rect Frames[4];

    void drawBoard();
    void drawCurrentPiece(Piece piece);
    void drawGhostPiece(Piece piece);
    void drawNextPiece(Piece piece);
    int getRandom(int min, int max);

};
#endif