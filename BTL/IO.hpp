#ifndef _IO_
#define _IO_

#include <SDL.h>
#include "SDL_utils.hpp"
#include <time.h>

//colors: Black, Red, Green, Blue, Cyan, Magenta, Yellow, Orange, White
enum color{Black, Red, Green, Blue, Cyan, Magenta, Yellow, Orange, White, Color_Max};

struct IO
{
    IO();
 
    void DrawRectangle(int X1, int Y1, int X2, int Y2, color C);

    void ClearScreen();

    int GetScreenHeight();

    int InitGraph();

    int PollKey();

    int GetKey();

    int IsKeyDown(int key);

    void UpdateScreen();
};

#endif