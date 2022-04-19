#ifndef RENDER
#define RENDER

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "texture.hpp"

SDL_Renderer *renderer;
TTF_Font *font;

struct render
{
    void clearScreen();
    void renderTexture (texture *rTexture, int x, int y);
    void updateScreen();
};

#endif