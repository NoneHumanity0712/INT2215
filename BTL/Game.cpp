#include <iostream>
#include <ctime>
#include "Game.hpp"
#include <SDL.h>
#include <cstdlib>

extern SDL_Renderer* gRenderer;

Pause pauseButton(pauseButtonPos.x, pauseButtonPos.y);
theme themeSwitch(themeSwitchRect.x, themeSwitchRect.y);
button restartYes(yesButtonPos.x, yesButtonPos.y, yesButtonPos.w, yesButtonPos.h);
button restartNo(noButtonPos.x, noButtonPos.y, noButtonPos.w, noButtonPos.h);

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

void Game::gameoverDraw()
{
    if (isLightMode)
    {
        gameover = gameover_light;
        yes = yes_light;
        no = no_light;
    } else
    {
        gameover = gameover_dark;
        yes = yes_dark;
        no = no_dark;
    }

    gameover.render(340, 300, &gameoverRect);
    yes.render(yesButtonPos.x, yesButtonPos.y, &yesButtonRect[restartYes.CurrentSprite]);
    no.render(noButtonPos.x, noButtonPos.y, &noButtonRect[restartNo.CurrentSprite]);
}

void Game::YesButton(SDL_Event e)
{
    restartYes.handleEvent(&e);
    if (restartYes.click)
    {
        isRestart = true;
        std::cout << "Action: Restart" << std::endl;
    }
}

void Game::NoButton(SDL_Event e, input *manager)
{
    restartNo.handleEvent(&e);
    if (restartNo.click)
    {
        isRestart = false;
        manager->exit();
        std::cout << "Action: Quit" << std::endl;
    }
}

void Game::drawScene()
{
    if (isLightMode)
    {
        tetromino_graphic = tetromino_graphic_light;
        background = background_light;
        text_color = text_color_light;
        ghost_tetromino_graphic = ghost_tetromino_graphic_light;
        pause_button_graphic= pause_button_graphic_light;
        theme_switch_graphic = theme_switch_graphic_light;
    }
    else
    {
        tetromino_graphic = tetromino_graphic_dark;
        background = background_dark;
        text_color = text_color_dark;
        ghost_tetromino_graphic = ghost_tetromino_graphic_dark;
        pause_button_graphic = pause_button_graphic_dark;
        theme_switch_graphic = theme_switch_graphic_dark;
    }

    drawBackground();
    drawBoard();
    if (!first_time_hold) drawHoldPiece(holdPiece);
    if (!board->gameOver()) drawGhostPiece(currentPiece);
    drawCurrentPiece(currentPiece);
    drawNextPiece(nextPiece);

    if (gameOver()) gameoverDraw();
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
}

void Game::ThemeSwitch(SDL_Event e)
{
    themeSwitch.handleEvent(&e);

    isLightMode = themeSwitch.lightMode;
}

void Game::initializeScene()
{
    srand(time(0));
    first_time_hold = true;
    used_hold_block = false;
    isLightMode = true;
    isRestart = false;

    themeSwitch.lightMode = true;
    pauseButton.pause_game = false;
    restartNo.click = false;
    restartYes.click = false;

    nextPiece.type = getRandom(0, 6);
    nextPiece.rotation = 0;
    createNewPiece();
    
    nextPiece.x = nextPiecePos.x;
    nextPiece.y = nextPiecePos.y;

    tetromino_graphic_light.loadImage(minoes_path_light);
    tetromino_graphic_dark.loadImage(minoes_path_dark);
    for (int i = 0; i < 7; i++)
    {
        tetrominoes[i].x = block_size*i;
        tetrominoes[i].y = 0;
        tetrominoes[i].w = block_size;
        tetrominoes[i].h = block_size;
    }

    ghost_tetromino_graphic_light.loadImage(ghost_minoes_path_light);
    ghost_tetromino_graphic_dark.loadImage(ghost_minoes_path_dark);
    for (int i = 0; i < 7; i++)
    {
        ghost_tetrominoes[i].x = block_size*i;
        ghost_tetrominoes[i].y = 0;
        ghost_tetrominoes[i].w = block_size;
        ghost_tetrominoes[i].h = block_size;
    }

    background_light.loadImage(background_path_light);
    background_dark.loadImage(background_path_dark);
    background_pic = {0, 0, windowWidth, windowHeight};
    
    pause_button_graphic_light.loadImage(button_path_light);
    pause_button_graphic_dark.loadImage(button_path_dark);
    for (int i = 0; i < 6; i++)
    {
        pause_button[i].x = button_sprite_size*i;
        pause_button[i].y = 0;
        pause_button[i].w = button_sprite_size;
        pause_button[i].h = button_sprite_size;
    }

    theme_switch_graphic_light.loadImage(switch_path_light);
    theme_switch_graphic_dark.loadImage(switch_path_dark);
    theme_switch = {0, 0, themeSwitchRect.w, themeSwitchRect.h};

    gameover_light.loadImage(gameover_path_light);
    gameover_dark.loadImage(gameover_path_dark);
    gameoverRect = {0, 0, 278, 130};

    yes_light.loadImage(yes_path_light);
    yes_dark.loadImage(yes_path_dark);
    for (int i = 0; i < 2; i++)
    {
        yesButtonRect[i].x = yesButtonPos.w*i;
        yesButtonRect[i].y = 0;
        yesButtonRect[i].w = yesButtonPos.w;
        yesButtonRect[i].h = yesButtonPos.h;
    }

    no_light.loadImage(no_path_light);
    no_dark.loadImage(no_path_dark);
    for (int i = 0; i < 2; i++)
    {
        noButtonRect[i].x = noButtonPos.w*i;
        noButtonRect[i].y = 0;
        noButtonRect[i].w = noButtonPos.w;
        noButtonRect[i].h = noButtonPos.h;
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
    pause_button_graphic.render(pauseButtonPos.x, pauseButtonPos.y, &pause_button[pauseButton.CurrentSprite]);
    theme_switch_graphic.render(themeSwitchRect.x, themeSwitchRect.y, &theme_switch);
}

void Game::drawBoard()
{
    for (int row = playfield_height - true_playfield_height; row < playfield_height; row++)
    {
        for (int col = 0; col < playfield_width; col++)
        {
            if (!board->isBlockFree(row, col))
            {
                tetromino_graphic.render(playfield.x + col*block_size,
                playfield.y + (row -(playfield_height-true_playfield_height))*block_size,
                &tetrominoes[board->getTetromino(row,col)]);
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
            if (piece.getTetromino(row, col) != 0 && (row + piece.y + 1) > (playfield_height - true_playfield_height))
            {
                tetromino_graphic.render(playfield.x + (col + piece.x)*block_size,
                playfield.y + (row + piece.y - (playfield_height - true_playfield_height))*block_size,
                &tetrominoes[piece.type]);
            }
        }
    }
    //std::cout << "current: " << piece.type << " " << piece.x << " " << piece.y << std::endl;
}

void Game::drawGhostPiece (Piece piece)
{
    ghostPiece = piece;
    while (board->isMovePossible(ghostPiece) && ghostPiece.y <= playfield.y) ghostPiece.y++;
    ghostPiece.y--;

    for (int row = 0; row < matrix_blocks; row++)
    {
        for (int col = 0; col < matrix_blocks; col++)
        {
            if (ghostPiece.getTetromino(row, col) != 0 && (row + ghostPiece.y + 1) > (playfield_height - true_playfield_height))
            {
                ghost_tetromino_graphic.render(playfield.x + (col + ghostPiece.x)*block_size,
                playfield.y + (row + ghostPiece.y - (playfield_height - true_playfield_height))*block_size,
                &ghost_tetrominoes[ghostPiece.type]);
            }
        }
    }
    //std::cout << "ghost: " << ghostPiece.type << " " << ghostPiece.x << " " << ghostPiece.y << std::endl;

}

void Game::drawHoldPiece (Piece piece)
{
    for (int row = 0; row < matrix_blocks; row++)
    {
        for (int col = 0; col < matrix_blocks; col++)
        {
            if (piece.getTetromino(row, col) != 0)
            {
                tetromino_graphic.render(holdBoxPos.x + col*block_size,
                holdBoxPos.y + row*block_size, &tetrominoes[piece.type]);
            }
        }
    }

    //std::cout << "hold: " << piece.type << " " << piece.x << " " << piece.y << std::endl;
}

void Game::drawNextPiece (Piece piece)
{
    for (int row = 0; row < matrix_blocks; row++)
    {
        for (int col = 0; col < matrix_blocks; col++)
        {
            if (piece.getTetromino(row, col) != 0)
            {
                tetromino_graphic.render(nextPiecePos.x + col*block_size,
                    nextPiecePos.y + row*block_size, &tetrominoes[piece.type]);
            }
        }
    }
    //std::cout << "next: " << piece.type << " " << piece.x << " " << piece.y << std::endl;
}

int Game::getRandom (int min, int max)
{
    return rand() % (max - min + 1) + min;
}