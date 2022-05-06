#include "render.hpp"
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

const Uint8 backgroundColor_R = 239; //Red channel color for background
const Uint8 backgroundColor_G = 255; //Green channel color for background
const Uint8 backgroundColor_B = 253; //Blue channel color for background 

SDL_Renderer *gRenderer = nullptr;
TTF_Font *gFont = nullptr;

render::~render()
{
    SDL_DestroyRenderer(gRenderer);
    gRenderer = nullptr;
}

void render::clearScreen()
{
    SDL_SetRenderDrawColor(gRenderer, backgroundColor_R, backgroundColor_G, backgroundColor_B, 255);
    SDL_RenderClear(gRenderer);
}

void render::renderTexture(texture *Texture, int x, int y)
{
    Texture->renderCentered(x, y);
}

void render::updateScreen()
{
    SDL_RenderPresent(gRenderer);
}