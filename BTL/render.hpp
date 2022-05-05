#ifndef RENDER
#define RENDER

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "texture.hpp"

extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;

struct render
{
    void initialize (SDL_Window *window);
    ~render();

    void clearScreen ();
    void renderTexture (texture *texture, int x, int y);
    void updateScreen ();

    SDL_Renderer *SDLrenderer = nullptr;

    TTF_Font *medium;
    TTF_Font *big;
};

#endif