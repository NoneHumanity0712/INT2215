#ifndef GAME
#define GAME

#include <queue>
#include "board.hpp"
#include "piece.hpp"

using namespace std;

class Game
{
public:
    Game();
    void checkState();
    void createNewPiece();
    void drawScene();
    void event();
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