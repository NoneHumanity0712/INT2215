#include <iostream>
#include <ctime>
#include "Game.hpp"
#include <SDL.h>
#include <cstdlib>

extern SDL_Renderer* gRenderer;

Game::Game()
{
    board = new Board;
}

void Game::checkState()
{
    board->storePiece(currentPiece); //store current block
    board->deleteFullLine(); //delete filled line
    if (!board->gameOver())
    {
        createNewPiece();
    }
    used_hold_block = false;
}

void Game::swap(Piece &a, Piece &b)
{
    Piece temp = currentPiece;
    currentPiece = holdPiece;
    holdPiece = temp;

}

void Game::createNewPiece()
{
    currentPiece.type = nextPiece.type;
    currentPiece.rotation = nextPiece.rotation;
    currentPiece.y = currentPiece.getBeginYPos();
    currentPiece.x = playfield_width/2 + currentPiece.getBeginXPos();

    //move new normal and null blocks into playfield
    for (int i = 0; i < 2; i++)
    {
        currentPiece.y++;
        if (!board->isMovePossible(currentPiece))
            currentPiece.y--;
    }

    //move pivot block into playfield
    if (currentPiece.type > 1)
    {
        currentPiece.y++;
        if (!board->isMovePossible(currentPiece))
            currentPiece.y--;
    }
    
    //randomly create new piece
    nextPiece.type = getRandom(0, 6);
    nextPiece.rotation = 0;
}

void Game::drawScene()
{
    drawBoard();
    drawCurrentPiece(currentPiece);
    if (!first_time_hold) drawHoldPiece(holdPiece);
    if (!board->gameOver()) drawGhostPiece(currentPiece);
    drawNextPiece(nextPiece);
}

//handling event from keyboard
void Game::event(ACTION a)
{
    switch (a)
    {
        case ACTION::down:
        {
            currentPiece.y++;
            if (!board->isMovePossible(currentPiece))
            {
                currentPiece.y--;
                checkState(); //check if the piece is set
            }
            break;
        }
        
        case ACTION::left:
        {
            currentPiece.x--;
            if(!board->isMovePossible(currentPiece))
                currentPiece.x++;
            break;
        }

        case ACTION::right:
        {
            currentPiece.x++;
            if (!board->isMovePossible(currentPiece))
                currentPiece.x--;
            break;
        }

        case ACTION::drop:
        {
            while (board->isMovePossible(currentPiece))
                currentPiece.y++;
            currentPiece.y--;
            checkState();
            break;
        }

        case ACTION::rotate:
        {
            currentPiece.rotation = (currentPiece.rotation + 1) % 4; //(0, 3)
            if (!board->isMovePossible(currentPiece))
                currentPiece.rotation = (currentPiece.rotation + 3) % 4;
            break;
        }

        case ACTION::hold:
        {
            if (first_time_hold)
            {
                holdPiece = Piece(currentPiece);
                holdPiece.rotation = 0;
                createNewPiece();
                first_time_hold = false;
                used_hold_block = true;
            }
            else if (!used_hold_block)
            {
                swap(currentPiece, holdPiece);
                holdPiece.rotation = 0;
                currentPiece.y = currentPiece.getBeginYPos();
                currentPiece.x = playfield_width/2 + currentPiece.getBeginXPos();
            }

            for (int i = 0; i < 2; i++)
            {
                currentPiece.y++;
                if (!board->isMovePossible(currentPiece))
                    currentPiece.y--;
            }

            if (currentPiece.type > 1)
            {
                currentPiece.y++;
                if (!board->isMovePossible(currentPiece))
                    currentPiece.y--;
            }

            used_hold_block = true;
        }
    }
}

void Game::initializeScene()
{
    srand(time(0));
    first_time_hold = true;
    used_hold_block = false;
    nextPiece.type = getRandom(0, 6);
    nextPiece.rotation = 0;
    createNewPiece();
    
    nextPiece.x = x_nextPiece;
    nextPiece.y = y_nextPiece;

    tetromino_graphic.loadImage("C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/tetrominoSprites.png");
    frame.loadImage("C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/playfieldFrame.png");

    for (int i = 0; i < 7; i++)
    {
        tetromino_graphic_boxes[i].x = 16*i;
        tetromino_graphic_boxes[i].y = 0;
        tetromino_graphic_boxes[i].w = 16;
        tetromino_graphic_boxes[i].h = 16;
    }

    for (int i = 0; i < 4; i++)
    {
        Frames[i].x = frame_sprite_size*i;
        Frames[i].y = 0;
        Frames[i].w = frame_sprite_size;
        Frames[i].h = frame_sprite_size;
    }
}

bool Game::gameOver()
{
    return board->gameOver();
}

void Game::pieceFalling()
{
    currentPiece.y++;
    if (!board->isMovePossible(currentPiece))
    {
        currentPiece.y--;
        checkState();
    }
}

//void Game::drawBackground()
//{
//    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);   // blue
//    SDL_RenderClear(gRenderer);
//}

void Game::drawBoard()
{
    //draw frame
    for (int i = 0; i < 2*true_playfield_height; i++)
    {
        //left
        frame.render(width_to_playfield - frame_sprite_size,
            height_to_playfield + i*frame_sprite_size, &Frames[0]);

        //right
        frame.render(width_to_playfield + block_size*playfield_width - (frame_sprite_size -frame_width), 
            height_to_playfield + i*frame_sprite_size, &Frames[0]);
    }

    //draw corners
    frame.render(width_to_playfield - frame_sprite_size, height_to_playfield + 
        block_size*true_playfield_height - (frame_sprite_size - frame_width), &Frames[2]);
    frame.render(width_to_playfield + block_size * playfield_width, height_to_playfield + 
        block_size*true_playfield_height - (frame_sprite_size - frame_width), &Frames[3]);
    
    //draw bottom frame
    for (int i = 0; i < 2*playfield_width; i++)
    {
        frame.render(width_to_playfield + i*frame_sprite_size, height_to_playfield +
            block_size*true_playfield_height, &Frames[1]);
    }

    //draw placed blocks
    for (int row = 0; row < playfield_height; row++)
    {
        for (int col = 0; col < playfield_width; col++)
        {
            if (!board->isBlockFree(row, col))
            {
                tetromino_graphic.render(width_to_playfield + col*block_size,
                    height_to_playfield + (row - (playfield_height - true_playfield_height))*block_size,
                    &tetromino_graphic_boxes[board->getTetromino(row, col)]);
            }
        }
    }
}

void Game::drawCurrentPiece (Piece piece)
{
    for (int row = 0; row < matrix_blocks; row++)
    {
        for (int col = 0; col < matrix_blocks; col++)
        {
            if (piece.getTetromino(row, col) != 0)
            {
                tetromino_graphic.render(width_to_playfield +( col + piece.x)*block_size,
                height_to_playfield + (row + piece.y - (playfield_height - true_playfield_height))*block_size,
                &tetromino_graphic_boxes[piece.type]);
                std::cout << piece.type << " " << piece.x << " " << piece.y << std::endl;
            }
        }
    }
}

void Game::drawGhostPiece (Piece piece)
{
    ghostPiece = piece;
    while (board->isMovePossible(ghostPiece) && ghostPiece.y <= height_to_playfield) ghostPiece.y++;
    ghostPiece.y--;

    tetromino_graphic.setAlphaMode(transparency); 

    for (int row = 0; row < matrix_blocks; row++)
    {
        for (int col = 0; col < matrix_blocks; col++)
        {
            if (ghostPiece.getTetromino(row, col) != 0)
            {
                tetromino_graphic.render(width_to_playfield + (col + ghostPiece.x)*block_size,
                height_to_playfield + (row + ghostPiece.y - (playfield_height - true_playfield_height))*block_size,
                &tetromino_graphic_boxes[ghostPiece.type]);
                std::cout << piece.type << " " << piece.x << " " << piece.y << std::endl;
            }
        }
    }
}

void Game::drawHoldPiece (Piece piece)
{
    for (int row = 0; row < matrix_blocks; row++)
    {
        for (int col = 0; col < matrix_blocks; col++)
        {
            if (piece.getTetromino(row, col) != 0)
            {
                tetromino_graphic.render(hold_box_x + col+block_size,
                hold_box_y + row*block_size, &tetromino_graphic_boxes[piece.type]);
                std::cout << piece.type << " " << piece.x << " " << piece.y << std::endl;
            }
        }
    }
}

void Game::drawNextPiece (Piece piece)
{
    for (int row = 0; row < matrix_blocks; row++)
    {
        for (int col = 0; col < matrix_blocks; col++)
        {
            if (piece.getTetromino(row, col) != 0)
            {
                tetromino_graphic.render(x_nextPiece + col*block_size,
                    y_nextPiece + row*block_size, &tetromino_graphic_boxes[piece.type]);
                std::cout << piece.type << " " << piece.x << " " << piece.y << std::endl;
            }
        }
    }
}

int Game::getRandom (int min, int max)
{
    return rand() % (max - min + 1) + min;
}