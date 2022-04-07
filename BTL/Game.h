#ifndef _Game_
#define _Game_

#include "Board.h"
#include "Piece.h"
#include "IO.h"
#include <iostream>
#include <ctime>

const int WaitTime = 700;

struct Game
{
    Game (Board *pBoard, Piece *pPiece, IO *pIO, int pScreenHeight);

    void DrawScene()
    {
        DrawBoard();
        DrawPiece(mPosX, mPosY, mPiece);
        DrawPiece(mNextPosX, mNextPosY, mNextPiece);
    }

    void createNewPiece()
    {
        mPiece->Shape = mNextPiece->Shape;
        mPiece->Rotation = mNextPiece->Rotation;
        mPosX = (BoardWidth/2) + mPiece->getBeginXPos;
        mPosY = mPiece->getBeginYPos;

        mNextPiece->Shape = getRandom(0, 6);
        mNextPiece->Rotation = getRandom(0, 3);
    }

    int mPosX, mPosY;
    int mScreenHeight;
    int mNextPosX, mNextPosY;
    Board *mBoard;
    Piece *mPiece, *mNextPiece;
    IO *mIO;

    int getRandom (int pA, int pB)
    {
        return rand()%(pB - pA + 1) + pA;
    }
    
    void InitGame()
    {
        srand((unsigned int)time(NULL));

        mPiece->Shape = getRandom(0, 6);
        mPiece->Rotation = getRandom(0, 3);
        mPosX = (BoardWidth/2) + mPiece->getBeginXPos;
        mPosY = mPiece->getBeginYPos;

        mNextPiece->Shape = getRandom(0, 6);
        mNextPiece->Rotation = getRandom(0, 3);
        mNextPosX = BoardWidth + 5;
        mNextPosY = 5;
    }

    void DrawPiece (int pX, int pY, Piece *tetromino)
    {
        color mColor;
        int pixelsX = mBoard->GetXPosInPixels(pX);
        int pixelsY = mBoard->GetYPosInPixels(pY);

        for (int i = 0; i < PieceBlock; i++)
        {
            for (int j = 0; j < PieceBlock; j++)
            {
                switch (tetromino->getTetromino(j, i))
                {
                    case 1: mColor = Green;
                        break;
                    case 2: mColor = Blue;
                        break;
                }
                if (tetromino->getTetromino(j, i) != 0)
                {
                    mIO->DrawRectangle(pixelsX + i*BlockSize, pixelsY + j*BlockSize,
                        (pixelsX + i*BlockSize) + BlockSize - 1,
                        (pixelsY + j*BlockSize) + BlockSize - 1,
                        mColor);
                }
            }
        }
        
    }

    void DrawBoard()
    {
        int X1 = BoardPosition - (BlockSize*(BoardWidth/2)) - 1;
        int X2 = BoardPosition + (BlockSize*(BoardWidth/2));
        int Y = mScreenHeight - (BlockSize*BoardHeight);

        mIO->DrawRectangle(X1 - BoardLineWidth, Y, X1, mScreenHeight - 1, Blue);
        mIO->DrawRectangle(X2, Y, X2 + BoardLineWidth, mScreenHeight - 1, Blue);

        X1 += 1;
        for (int i = 0; i < BoardWidth; i++)
        {
            for (int j = 0; j < BoardHeight; j++)
            {
                if (mBoard->IsFreeBlock(i, j))
                {
                    mIO->DrawRectangle(X1 + i*BlockSize, Y + j*BlockSize,
                    (X1 + i*BlockSize) + BlockSize - 1,
                    (Y + j*BlockSize) + BlockSize - 1,
                    Red);
                }
            }
        }
    }
};

#endif