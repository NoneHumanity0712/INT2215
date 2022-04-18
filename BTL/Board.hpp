#ifndef BOARD
#define BOARD

#include "Piece.hpp"
#include <vector>

using namespace std;

const int width_to_playfield = 242;     // in pixels
const int height_to_playfield = 34;     // in pixels
const int block_size = 16;              // in pixels
const int playfield_width = 10;         // in blocks
const int true_playfield_height = 20;   // in blocks
const int playfield_height = 22;        // The playfield+2 rows directly above it for spawning the Tetrominos
const int frame_width = 6;              // Frame that surrounds the playfield; in pixels
const int frame_sprite_size = 8;        // Size of each sprite clip for the playfield frame
const int board_height = 2;             // distance from botton where the playfield begins; in pixels
const int matrix_blocks = 5;

class Board
{
    //block status
    enum BlockStatus: int{empty, I, J, L, O, S, Z, T};
    
private:
    BlockStatus boardState[playfield_height][playfield_width];
    vector<Piece> pieces;

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