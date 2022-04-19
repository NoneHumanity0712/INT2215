#include "render.h"
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

SDL_Renderer *renderer = nullptr;
TTF_Font *font = nullptr;

const Uint8 backgroundColor_R = 249; //Red channel color for background
const Uint8 backgroundColor_G = 230; //Green channel color for background
const Uint8 backgroundColor_B = 207; //Blue channel color for background 

void render::clearScreen()
{
    SDL_SetRenderDrawColor(renderer, backgroundColor_R, backgroundColor_G, backgroundColor_B, 255);
    SDL_RenderClear(renderer);
}

void render::renderTexture(texture *rTexture, int x, int y)
{
    texture->renderCentered(x, y);
}

void render::updateScreen()
{
    SDL_RenderPresent(renderer);
}