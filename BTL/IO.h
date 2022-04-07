#ifndef _IO_
#define _IO_

#include <iostream>
#include <SDL.h>

enum color {Black, Red, Green, Blue, Cyan, Magenta, Yellow, White, Color_Max};

struct IO
{
    IO();

    void DrawRectangle(int X1, int Y1, int X2, int Y2, enum color C);
    void ClearScreen();
    int GetScreenHeight();
    int InitGraph();
    int PollKey();
    int GetKey();
    int IsKeyDown(int key);
    void UpdateScreen();
};

#endif