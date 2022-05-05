#include "render.hpp"
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

const Uint8 backgroundColor_R = 239; //Red channel color for background
const Uint8 backgroundColor_G = 255; //Green channel color for background
const Uint8 backgroundColor_B = 253; //Blue channel color for background 

void render::initialize (SDL_Window *window)
{
    medium = TTF_OpenFont("C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/Classique-Saigon_0.ttf", 28);
    big = TTF_OpenFont("C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/Classique-Saigon_0.ttf", 42);

    if (medium == nullptr || big == nullptr)
    {
        std::cout << "Could not load font! SDL_ttf error: " << TTF_GetError() << std::endl;
    }
    SDLrenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    clearScreen();
}

render::~render()
{
    SDL_DestroyRenderer(SDLrenderer);
    SDLrenderer = nullptr;
}

void render::clearScreen()
{
    SDL_SetRenderDrawColor(SDLrenderer, backgroundColor_R, backgroundColor_G, backgroundColor_B, 255);
    SDL_RenderClear(SDLrenderer);
}

void render::renderTexture(texture *Texture, int x, int y)
{
    Texture->renderCentered(x, y);
}

void render::updateScreen()
{
    SDL_RenderPresent(SDLrenderer);
}