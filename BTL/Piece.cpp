#include "Piece.hpp"

Piece::Piece(int piece_type, int piece_rotation)
{
    piece_type = type;
    piece_rotation = rotation;
}

Piece::Piece (const Piece &piece)
{
    type = piece.type;
    rotation = piece.rotation;
    x = piece.x;
    y = piece.y;
}

unsigned int Piece::getTetromino (int x_index, int y_index)
{
    return tetrominoes_type[type][rotation][y][x];
}

int Piece::getBeginXPos()
{
    return beginPosition[type][rotation][0];
}

int Piece::getBeginYPos()
{
    return beginPosition[type][rotation][1];
}

