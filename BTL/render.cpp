#include "render.hpp"
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "details.hpp"

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