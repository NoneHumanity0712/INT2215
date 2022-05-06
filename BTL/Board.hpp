#ifndef BOARD
#define BOARD

#include "Piece.hpp"
#include <vector>

const int width_to_playfield = 340;     // in pixels
const int height_to_playfield = 124;     // in pixels
const int block_size = 28;              // in pixels
const int playfield_width = 10;         // in blocks
const int true_playfield_height = 15;   // in blocks
const int playfield_height = 17;       // The playfield + 2 rows directly above it for spawning the Tetrominos
const int board_height = 4;             // distance from botton where the playfield begins; in pixels
const int matrix_blocks = 5;            //5 x 5 matrix for each piece

//block status
enum BlockStatus: int {empty, I, J, L, O, S, Z, T};

class Board
{ 
private:
    BlockStatus boardState[playfield_height][playfield_width];
    std::vector<Piece> pieces;
    void deleteLine (int yPos);

public:
    Board();
    int getTetromino(int x, int y);
    bool isBlockFree(int x, int y);
    bool isMovePossible(Piece piece);
    void storePiece(Piece piece);
    void deleteFullLine();
    bool gameOver();
};

#endif