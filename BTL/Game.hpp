#ifndef GAME
#define GAME

#include <queue>
#include "board.hpp"
#include "piece.hpp"
#include "input.hpp"

using namespace std;

const int x_nextPiece = 400;
const int y_nextPiece = 10;

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
    Board *board;
    Piece currentPiece {0, 0};
    Piece ghostPiece {0, 0};
    Piece nextPiece {0, 0};
    queue<Piece> nextPieces;

    void drawBoard();
    void drawCurrentPiece (Piece piece);
    void drawGhostPiece (Piece piece);
    void drawNextPiece (Piece piece);
    int getRandom (int min, int max);
};

#endif