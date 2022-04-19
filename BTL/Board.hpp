#ifndef BOARD
#define BOARD

#include "Piece.hpp"
#include <vector>

const int width_to_playfield = 242;     // in pixels
const int height_to_playfield = 34;     // in pixels
const int block_size = 16;              // in pixels
const int playfield_width = 10;         // in blocks
const int true_playfield_height = 20;   // in blocks
const int playfield_height = 22;        // The playfield + 2 rows directly above it for spawning the Tetrominos
const int frame_width = 6;              // Frame that surrounds the playfield; in pixels
const int frame_sprite_size = 8;        // Size of each sprite clip for the playfield frame
const int board_height = 2;             // distance from botton where the playfield begins; in pixels
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

Board::Board()
{
    for (int row = 0; row < playfield_height; row++)
    {
        for (int col = 0; col < playfield_width; col++)
        {
            boardState[row][col] = BlockStatus::empty;
        }
    }
}

int Board::getTetromino(int x, int y)
{
    return int(boardState[y][x]) - 1;
}

//return true if the block is empty
bool Board::isBlockFree(int x, int y)
{
    return (boardState[y][x] == BlockStatus::empty) ? true : false;
}

bool Board::isMovePossible(Piece piece)
{
    for (int row = piece.y; row < piece.x+matrix_blocks; row++)
    {
        for (int col = piece.x; col < piece.y + matrix_blocks; col++)
        {
            //if outside of playfield
            if (col < 0 || col > playfield_width - 1 || row > playfield_height-1)
            {
                if (piece.getTetromino(row-piece.y, col-piece.x) != 0)
                    return false;
            }

            //if the block is already filled
            if (row >= 0)
            {
                if (piece.getTetromino(row-piece.y, col-piece.x) != 0 && !isBlockFree(row, col))
                    return false;
            }
        }
    }
    return true;
}

void Board::storePiece (Piece piece)
{
    for (int row = piece.y; row < piece.y + matrix_blocks; row++)
    {
        for (int col = piece.x; col < piece.x + matrix_blocks; col++)
        {
            if (piece.getTetromino(row - piece.y, col - piece.x) != 0)
            {
                boardState[row][col] = static_cast<BlockStatus>(1+piece.type); 
            }
        }
    }
    pieces.push_back(piece);
}

void Board::deleteFullLine()
{
    for (int row = 0; row < playfield_height; row++)
    {
        bool isFilled = true;
        for (int col = 0; col < playfield_width; col++)
        {
            if (isBlockFree(row, col)) isFilled = false;
        }
        if (isFilled) deleteLine(row);
    }
}

bool Board::gameOver()
{
    bool isOver = false;

    //if the first two lines have filled block, game over
    for (int col = 0; col < playfield_width; col++)
    {
        if (boardState[0][col] != BlockStatus::empty ||
            boardState[1][col] != BlockStatus::empty)
        {
            isOver = true;
            break;
        }
    }
    
    return isOver;
}

void Board::deleteLine(int yPos)
{
    for (int row = yPos; row > 0; row--)
    {
        for (int col = 0; col < playfield_width; col++)
        {
            boardState[row][col] = boardState[row-1][col];
        }
    }
}

#endif