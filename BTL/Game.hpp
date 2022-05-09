#ifndef GAME
#define GAME

#include <iostream>
#include <string>
#include <ctime>
#include <SDL.h>
#include <cstdlib>
#include <queue>
#include "board.hpp"
#include "piece.hpp"
#include "input.hpp"
#include "texture.hpp"
#include "render.hpp"

const int x_nextPiece = 704;
const int y_nextPiece = 124;
const Uint8 transparency = 100; //set transparency for ghost piece

const int hold_box_x = 104;            // Horizontal distance from top left corner; in pixels
const int hold_box_y = 124;            // Vertical distance from top left corner; in pixels

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
    void swap(Piece &a, Piece &b);
    std::string clearedLines();

private:
    bool first_time_hold;
    bool used_hold_block;
    Board* board;
    Piece currentPiece {0, 0};
    Piece ghostPiece {0, 0};
    Piece holdPiece {0, 0};
    Piece nextPiece {0, 0};
    std::queue<Piece> nextPieces;
    texture tetromino_graphic;
    SDL_Rect tetromino_graphic_boxes[7];
    texture background;
    SDL_Rect background_pic;

    void drawBackground();
    void drawBoard();
    void drawCurrentPiece(Piece piece);
    void drawGhostPiece(Piece piece);
    void drawHoldPiece(Piece piece);
    void drawNextPiece(Piece piece);
    int getRandom(int min, int max);
};

#endif