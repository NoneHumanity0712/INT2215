#include <iostream>
#include <SDL.h>
// #include "SDL_utils.h"
#include <time.h>
#include "IO.hpp"

using namespace std;

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 1000;
const char WINDOW_TITLE[] = "Game Tetris";

static SDL_Surface *screen;

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
    //Orange
    {255, 51, 0},
    //White
    {255, 255, 255},
};

IO::IO()
{
    InitGraph ();
}

void IO::DrawRectangle(int X1, int Y1, int X2, int Y2, enum color C)
{
    SDL_Rect smallBox;
    smallBox.x = X1;
    smallBox.y = Y1;
    smallBox.w = X2 - X1;
    smallBox.h = Y2 - Y1;

    //color codes
    int R, G, B;
    
    //get box color
    R = color_code[C][0];
    G = color_code[C][1];
    B = color_code[C][2];

    //draw small box
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    SDL_RenderFillRect(renderer, &smallBox);

    SDL_RenderPresent(renderer);
}

void IO::ClearScreen()
{
    //color codes
    int R, G, B;

    //get background color codes
    R = color_code[Black][0];
    G = color_code[Black][1];
    B = color_code[Black][2];

    //draw background
    SDL_SetRenderDrawColor(renderer, R, G, B, 255); 

    SDL_RenderPresent(renderer);
}

int IO::GetScreenHeight()
{
    return screen->h;
}

void IO::UpdateScreen()
{
    SDL_Flip(screen);
};

//keyboard input
int PollKey()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_KEYDOWN:
            return e.key.keysym.sym;
        case SDL_QUIT:
            exit(3);  
        }
    }
    return -1;
}

int GetKey()
{
    SDL_Event e;
    while(true)
    {
        SDL_WaitEvent(&e);
        if (e.type == SDL_KEYDOWN) break;
        if (e.type == SDL_QUIT) exit(3);
    }
    return e.key.keysym.sym;
}

int IsKeyDown(int key)
{
    unsigned int keyTable;
    int numKeys;
    SDL_PumpEvents();
    keyTable = SDL_GetKeyState(&numKeys);
    return keyTable[key];
}

int InitGraph();