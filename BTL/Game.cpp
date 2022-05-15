#include <iostream>
#include <ctime>
#include "Game.hpp"
#include <SDL.h>
#include <cstdlib>

extern SDL_Renderer* gRenderer;

Pause pauseButton(pause_x, button_y);

Game::Game()
{
    board = new Board;
}

void Game::checkState()
{
    board->storePiece(currentPiece); //store current block
    board->deleteFullLine(); //delete full line
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

std::string Game::clearedLines()
{
    std::string temp = "Lines: " + std::to_string(board->line_cleared);
    return temp;
}

int Game::falling_speed()
{
    int speed = 1000 - (board->line_cleared/10)*100;
    if (speed < 100) speed = 50;
    return speed;
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
        if (!board->isMovePossible(currentPiece)) currentPiece.y--;
    }

    //move pivot block into playfield
    if (currentPiece.type > 1)
    {
        currentPiece.y++;
        if (!board->isMovePossible(currentPiece)) currentPiece.y--;
    }
    
    //randomly create new piece
    while (nextPiece.type == currentPiece.type) nextPiece.type = getRandom(0, 6);
    nextPiece.rotation = 0;
}

void Game::drawScene()
{
    drawBackground();
    drawBoard();
    if (!first_time_hold) drawHoldPiece(holdPiece);
    if (!board->gameOver()) drawGhostPiece(currentPiece);
    drawCurrentPiece(currentPiece);
    drawNextPiece(nextPiece);
}

//handling event from keyboard
void Game::event(ACTION a)
{
    switch (a)
    {
        case ACTION::down:
        {
            if (!isPause)
            {
                currentPiece.y++;
                if (!board->isMovePossible(currentPiece))
                {
                    currentPiece.y--;
                    checkState();
                }
                std::cout << "Action: Soft Drop" << std::endl;
            }
            break;
        }
        
        case ACTION::left:
        {
            if (!isPause)
            {
                currentPiece.x--;
                if(!board->isMovePossible(currentPiece))
                    currentPiece.x++;
                std::cout << "Action: Move Left" << std::endl;

            }
            break;
        }

        case ACTION::right:
        {
            if (!isPause)
            {
                currentPiece.x++;
                if (!board->isMovePossible(currentPiece))
                    currentPiece.x--;
                std::cout << "Action: Move Right" << std::endl;
            }
            break;
        }

        case ACTION::drop:
        {
            if (!isPause)
            {
                while (board->isMovePossible(currentPiece))
                    currentPiece.y++;
                currentPiece.y--;
                checkState();
                std::cout << "Action: Hard Drop" << std::endl;
            }
            break;
        }

        case ACTION::rotate:
        {
            if (!isPause)
            {
                currentPiece.rotation = (currentPiece.rotation + 1) % 4; //(0, 3)
                if (!board->isMovePossible(currentPiece))
                {
                    //if (currentPiece.x < 0) currentPiece.x++;
                    //else if (currentPiece.x >= playfield_width - 1) currentPiece.x--;
                    currentPiece.rotation = (currentPiece.rotation + 3) % 4;
                }
                std::cout << "Action: Rotate" << std::endl;
            }
            break;
        }

        case ACTION::hold:
        {
            if (!isPause)
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
                std::cout << "Action: Hold" << std::endl;
            }
            break;
        }
    }
}

void Game::PauseButton(SDL_Event e)
{
    pauseButton.handleEvent(&e);

    isPause = pauseButton.pause_game;

    //draw pause button
    //SDL_RenderPresent( gRenderer );
}

void Game::initializeScene()
{
    srand(time(0));
    first_time_hold = true;
    used_hold_block = false;
    isLightMode = true;

    nextPiece.type = getRandom(0, 6);
    nextPiece.rotation = 0;
    createNewPiece();
    
    nextPiece.x = x_nextPiece;
    nextPiece.y = y_nextPiece;


    if (isLightMode)
    {
        minoes_path = minoes_path_light;
        background_path = background_path_light;
        text_color = text_color_light;
        ghost_minoes_path = ghost_minoes_path_light;
    }
    else
    {
        minoes_path = minoes_path_dark;
        background_path = background_path_dark;
        text_color = text_color_dark;
        ghost_minoes_path = ghost_minoes_path_dark;
    }

    tetromino_graphic.loadImage(minoes_path);
    for (int i = 0; i < 7; i++)
    {
        tetrominoes[i].x = block_size*i;
        tetrominoes[i].y = 0;
        tetrominoes[i].w = block_size;
        tetrominoes[i].h = block_size;
    }

    ghost_tetromino_graphic.loadImage(ghost_minoes_path);
    for (int i = 0; i < 7; i++)
    {
        ghost_tetrominoes[i].x = block_size*i;
        ghost_tetrominoes[i].y = 0;
        ghost_tetrominoes[i].w = block_size;
        ghost_tetrominoes[i].h = block_size;
    }

    background.loadImage(background_path);
    background_pic.x = 0;
    background_pic.y = 0;
    background_pic.w = windowWidth;
    background_pic.h = windowHeight;

    
    pause_button_graphic.loadImage(button_path_light);
    for (int i = 0; i < 6; i++)
    {
        pause_button[i].x = button_sprite_size*i;
        pause_button[i].y = 0;
        pause_button[i].w = button_sprite_size;
        pause_button[i].h = button_sprite_size;
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

void Game::drawBackground()
{
    background.render(0, 0, &background_pic);
    pause_button_graphic.render(pause_x, button_y, &pause_button[pauseButton.CurrentSprite]);
}

void Game::drawBoard()
{
    for (int row = playfield_height - true_playfield_height; row < playfield_height; row++)
    {
        for (int col = 0; col < playfield_width; col++)
        {
            if (!board->isBlockFree(row, col))
            {
                tetromino_graphic.render(width_to_playfield + col*block_size,
                height_to_playfield + (row -(playfield_height-true_playfield_height))*block_size,
                &tetrominoes[board->getTetromino(row,col)]);
            }
        }
    }
}

void Game::drawCurrentPiece (Piece piece)
{
    tetromino_graphic.setAlphaMode(255);

    for (int row = 0; row < matrix_blocks; row++)
    {
        for (int col = 0; col < matrix_blocks; col++)
        {
            if (piece.getTetromino(row, col) != 0 && (row + piece.y + 1) > (playfield_height - true_playfield_height))
            {
                tetromino_graphic.render(width_to_playfield + (col + piece.x)*block_size,
                height_to_playfield + (row + piece.y - (playfield_height - true_playfield_height))*block_size,
                &tetrominoes[piece.type]);
            }
        }
    }
    //std::cout << "current: " << piece.type << " " << piece.x << " " << piece.y << std::endl;
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
            if (ghostPiece.getTetromino(row, col) != 0 && (row + ghostPiece.y + 1) > (playfield_height - true_playfield_height))
            {
                ghost_tetromino_graphic.render(width_to_playfield + (col + ghostPiece.x)*block_size,
                height_to_playfield + (row + ghostPiece.y - (playfield_height - true_playfield_height))*block_size,
                &ghost_tetrominoes[ghostPiece.type]);
            }
        }
    }
    //std::cout << "ghost: " << ghostPiece.type << " " << ghostPiece.x << " " << ghostPiece.y << std::endl;

}

void Game::drawHoldPiece (Piece piece)
{
    tetromino_graphic.setAlphaMode(255);

    for (int row = 0; row < matrix_blocks; row++)
    {
        for (int col = 0; col < matrix_blocks; col++)
        {
            if (piece.getTetromino(row, col) != 0)
            {
                tetromino_graphic.render(hold_box_x + col*block_size,
                hold_box_y + row*block_size, &tetrominoes[piece.type]);
            }
        }
    }

    //std::cout << "hold: " << piece.type << " " << piece.x << " " << piece.y << std::endl;
}

void Game::drawNextPiece (Piece piece)
{
    tetromino_graphic.setAlphaMode(255);
    
    for (int row = 0; row < matrix_blocks; row++)
    {
        for (int col = 0; col < matrix_blocks; col++)
        {
            if (piece.getTetromino(row, col) != 0)
            {
                tetromino_graphic.render(x_nextPiece + col*block_size,
                    y_nextPiece + row*block_size, &tetrominoes[piece.type]);
            }
        }
    }
    //std::cout << "next: " << piece.type << " " << piece.x << " " << piece.y << std::endl;
}

int Game::getRandom (int min, int max)
{
    return rand() % (max - min + 1) + min;
}