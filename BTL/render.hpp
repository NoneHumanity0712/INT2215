#ifndef RENDER
#define RENDER

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "texture.hpp"

SDL_Renderer *gRenderer = nullptr;
TTF_Font *gFont = nullptr;

struct render
{
    void initialize (SDL_Window *window);
    ~render();
    void clearScreen();
    void renderTexture (texture *rTexture, int x, int y);
    void updateScreen();

    SDL_Renderer *mSDLRenderer = nullptr;
    TTF_Font *bigFont;
    TTF_Font *mediumFont;
};

const Uint8 backgroundColor_R = 249; //Red channel color for background
const Uint8 backgroundColor_G = 230; //Green channel color for background
const Uint8 backgroundColor_B = 207; //Blue channel color for background 

void render::initialize(SDL_Window *window)
{
    mediumFont = TTF_OpenFont("BTL/CLASSIQUE-SAIGON_0.TTF", 30);
    bigFont = TTF_OpenFont("BTL/CLASSIQUE-SAIGON_0.TTF", 50);
    if (mediumFont == nullptr || bigFont == nullptr)
        std::cout << "SDL_ttf error: " << TTF_GetError() << std::endl;
    mSDLRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    clearScreen();
}

render::~render ()
{
    SDL_DestroyRenderer(mSDLRenderer);
    mSDLRenderer = nullptr;
}

void render::clearScreen()
{
    SDL_SetRenderDrawColor(gRenderer, backgroundColor_R, backgroundColor_G, backgroundColor_B, 255);
    SDL_RenderClear(gRenderer);
}

void render::renderTexture(texture *rTexture, int x, int y)
{
    rTexture->renderCentered(x, y);
}

void render::updateScreen()
{
    SDL_RenderPresent(mSDLRenderer);
}

#endif