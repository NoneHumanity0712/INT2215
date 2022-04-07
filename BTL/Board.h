#ifndef _BOARD_
#define _BOARD_

#include "Piece.h"

const int BoardLineWidth = 6;
const int BlockSize = 16;
const int BoardPosition = 200;
const int BoardWidth = 15;
const int BoardHeight = 20;
const int minVerMargin = 20;
const int minHorMargin = 20;
const int PieceBlock = 5;

struct Board
{
    enum {PosFree, PosFilled};
    int board[BoardWidth][BoardHeight];
    Piece *mPiece;
    int mScreenHeight;

    void InitBoard()
    {
        for (int i = 0; i < BoardWidth; i++)
        {
            for (int j = 0; j < BoardHeight; j++)
            {
                board[i][j] = PosFree;
            }
        }
    }

    void DeleteLine(int pY)
    {
        for (int j = pY; j > 0; j--)
        {
            for (int i = 0; i < BoardWidth; i++)
            {
                board[i][j] = board[i][j-1];
            }
        }
    }

    Board(Piece *pPiece, int ScreenHeight);

    int pX, pY;

    int GetXPosInPixels(int pPos)
    {
        return ((BoardPosition - (BlockSize * (BoardWidth/2))) + (pPos * BlockSize));
    } 

    int GetYPosInPixels(int pPos)
    {
        return ((mScreenHeight - (BlockSize * BoardHeight)) + (pPos * BlockSize));
    } 

    bool IsFreeBlock(int posX, int posY)
    {
        return (board[pX][pY] == PosFree);
    } 

    bool IsPossibleMovement (int pPiece, int pRotation)
    {
        for (int i1 = pX, i2 = 0; i1 < pX + PieceBlock; i1++, i2++)
        {
            for (int j1 = pX, j2 = 0; j1 < pY + PieceBlock; j1++, j2++)
            {
                if (i1 < 0 || i1 > BoardWidth - 1 || i1 > BoardHeight - 1)
                {
                    if (mPiece->getTetromino(j2, i2) != 0) return 0;
                }

                if (j1 >= 0)
                {
                    if ((mPiece->getTetromino(j2, i2) != 0) && (!IsFreeBlock(i1, j1))) 
                        return false;
                }
                
            }
        }
        return true;
    }

    void StorePiece(int pPiece, int pRotation)
    {
        for (int i1 = pX, i2 = 0; i1 < pX + PieceBlock; i1++, i2++)
        {
            for (int j1 = pY, j2 = 0; j1 < pY + PieceBlock; j1++, j2++)
            {
                Piece newPiece(pPiece, pRotation);
                if (newPiece.getTetromino(j2, i2) != 0) board[i1][j1] = PosFilled;
            }
        }
    }

    void DeleteCompleteLine()
    {
        for (int j = 0; j < BoardHeight; j++)
        {
            int i = 0;
            while (i < BoardWidth)
            {
                if (board[i][j] != PosFilled) break;
                i++;
            }
            if (i == BoardWidth) DeleteLine(j);
        }
    }

    bool IsGameOver()
    {
        for (int i = 0; i < BoardWidth; i++)
            if (board[i][0] == PosFilled) return true;
        return false;
    }
};

#endif