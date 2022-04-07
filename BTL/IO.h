#ifndef _IO_
#define _IO_

#include <iostream>
#include <SDL.h>
#include "SDL_utils.h"
#include <time.h>

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 1000;
const char WINDOW_TITLE[] = "Game Tetris";

SDL_Window* window;
SDL_Renderer* renderer;

enum color{Black, Red, Green, Blue, Cyan, Magenta, Yellow, White, Color_Max};

const int color_code[Color_Max][3] = 
{
    //Black
    {0, 0, 0},
    //Red
    {255, 40, 0},
    //Green
    {0, 92, 21},
    //Blue
    {1, 110, 122},
    //Cyan
    {128, 255, 232},
    //Magenta
    {87, 1, 78},
    //Yellow
    {247, 255, 99},
    //White
    {255, 255, 255},
};

struct IO
{
    IO();

    void DrawRectangle(int X1, int Y1, int X2, int Y2, enum color C)
    {
        SDL_Rect smallBox;
        smallBox.x = X1;
        smallBox.y = Y1;
        smallBox.w = X2 - X1;
        smallBox.h = Y2 - Y1;

        int R, G, B;
        
        //get box color
        R = color_code[C][0];
        G = color_code[C][1];
        B = color_code[C][2];

        //draw small box
        SDL_SetRenderDrawColor(renderer, R, G, B, 255);
        SDL_RenderFillRect(renderer, &filled_rect);
        
    }

    void ClearScreen()
    {
        int R, G, B;

        //get background color codes
        R = color_code[Black][0];
        G = color_code[Black][1];
        B = color_code[Black][2];

        //draw background
        SDL_SetRenderDrawColor(renderer, R, G, B, 255); 
    }

    int GetScreenHeight();
    int InitGraph();
    int PollKey();
    int GetKey();
    int IsKeyDown(int key);
    void UpdateScreen();
};

#endif