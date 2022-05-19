#ifndef GAME
#define GAME

#include <iostream>
#include <string>
#include <ctime>
#include <SDL.h>
#include <cstdlib>
#include <queue>
#include "board.hpp"
#include "piece.hpp"
#include "input.hpp"
#include "texture.hpp"
#include "render.hpp"
#include "theme.hpp"
#include "button.hpp"
#include "sound.hpp"

extern SDL_Renderer *gRenderer;

class Game
{
public:
    Game();
    ~Game();
    void checkState();
    void createNewPiece();
    void drawScene();
    void event(ACTION a);
    void initializeScene();

    void PauseButton(SDL_Event e);
    void ThemeSwitch(SDL_Event e);
    void MuteSound(SDL_Event e);

    bool gameOver();
    void pieceFalling();
    void swap(Piece &a, Piece &b);
    std::string clearedLines();
    bool isPause;
    bool isLightMode;
    bool isRestart;
    bool isMuteSound;
    int level();

    void YesButton(SDL_Event e);
    void NoButton(SDL_Event e, input *manager);

    SDL_Color text_color;

    double score;
private:
    bool first_time_hold;
    bool used_hold_block;
    Board* board;
    Piece currentPiece {0, 0};
    Piece ghostPiece {0, 0};
    Piece holdPiece {0, 0};
    Piece nextPiece {0, 0};
    std::queue<Piece> nextPieces;

    texture tetromino_graphic;
    texture tetromino_graphic_light;
    texture tetromino_graphic_dark;
    SDL_Rect tetrominoes[7];

    texture ghost_tetromino_graphic;
    texture ghost_tetromino_graphic_light;
    texture ghost_tetromino_graphic_dark;
    SDL_Rect ghost_tetrominoes[7];

    texture background;
    texture background_light;
    texture background_dark;
    SDL_Rect background_pic;
    
    texture pause_button_graphic;
    texture pause_button_graphic_light;
    texture pause_button_graphic_dark;
    SDL_Rect pause_button[6];

    texture theme_switch_graphic;
    texture theme_switch_graphic_light;
    texture theme_switch_graphic_dark;
    SDL_Rect theme_switch;

    texture gameover;
    texture gameover_light;
    texture gameover_dark;
    SDL_Rect gameoverRect;

    texture yes;
    texture yes_light;
    texture yes_dark;
    SDL_Rect yesButtonRect[2];

    texture no;
    texture no_light;
    texture no_dark;
    SDL_Rect noButtonRect[2];

    texture sound_button;
    texture sound_button_light;
    texture sound_button_dark;
    SDL_Rect soundButtonRect[6];

    void soundLoad();
    void drawBackground();
    void drawBoard();
    void drawCurrentPiece(Piece piece);
    void drawGhostPiece(Piece piece);
    void drawHoldPiece(Piece piece);
    void drawNextPiece(Piece piece);
    int getRandom(int min, int max);
    void gameoverDraw();

    sound MovePiece;
    sound ClearLine;
    sound Switch;
    sound DropPiece;
};

#endif