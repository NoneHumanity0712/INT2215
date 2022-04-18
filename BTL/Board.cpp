#include "Board.hpp"

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
    return int(boardState[x][y]) - 1;
}

//return true if the block is empty
bool Board::isBlockFree(int x, int y)
{
    return (boardState[x][y] == BlockStatus::empty) ? true : false;
}

bool Board::isMovePossible(Piece piece)
{
    for (int row = piece.x; row < piece.x+matrix_blocks; row++)
    {
        for (int col = piece.y; col < piece.y + matrix_blocks; col++)
        {
            //if outside of playfield
            if (col < 0 || col > playfield_width - 1 || row > playfield_height-1)
            {
                if (piece.getTetromino(row-piece.x, col-piece.y) != 0)
                    return false;
            }

            //if the block is already filled
            if (row >= 0)
            {
                if (piece.getTetromino(row-piece.x, col-piece.y) != 0 && !isBlockFree(row, col))
                    return false;
            }
        }
    }
    return true;
}

void Board::storePiece (Piece piece)
{
    for (int row = piece.x; row < piece.x + matrix_blocks; row++)
    {
        for (int col = piece.y; col < piece.y + matrix_blocks; col++)
        {
            if (piece.getTetromino(row - piece.x, col - piece.y) != 0)
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