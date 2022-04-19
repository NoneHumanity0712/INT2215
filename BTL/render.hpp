#ifndef RENDER
#define RENDER

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "texture.hpp"

SDL_Renderer *pRenderer = nullptr;
TTF_Font *pFont = nullptr;

struct render
{
    void clearScreen();
    void renderTexture (texture *rTexture, int x, int y);
    void updateScreen();
};

const Uint8 backgroundColor_R = 249; //Red channel color for background
const Uint8 backgroundColor_G = 230; //Green channel color for background
const Uint8 backgroundColor_B = 207; //Blue channel color for background 

void render::clearScreen()
{
    SDL_SetRenderDrawColor(pRenderer, backgroundColor_R, backgroundColor_G, backgroundColor_B, 255);
    SDL_RenderClear(pRenderer);
}

void render::renderTexture(texture *rTexture, int x, int y)
{
    rTexture->renderCentered(x, y);
}

void render::updateScreen()
{
    SDL_RenderPresent(pRenderer);
}

#endif