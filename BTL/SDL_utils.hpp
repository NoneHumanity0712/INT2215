#ifndef UTILITIES
#define UTILITIES

#include <SDL.h>
#include "texture.hpp"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "render.hpp"

SDL_Window *window;
texture tetromino_graphic;

//return true if load all graphics (image, font) successfully
bool loadGraphic();

//close window, free memory
void close()
{
    TTF_CloseFont(font);
    font = nullptr;

    SDL_DestroyRenderer(renderer);
    renderer = nullptr;

    SDL_DestroyWindow(window);
    window = nullptr;

    TTF_Quit();
    SDL_Quit();
}

//return true if initialize game successfully
bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
        if (window == nullptr) //error
        {
            std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == nullptr)
            {
                std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //white
                SDL_RenderClear(renderer);
                if (IMG_Init(IMG_INIT_PNG) == 0 || IMG_Init(IMG_INIT_JPG) == 0)
                {
                    std::cout << "SDL_image error: " << IMG_GetError() << std::endl;
                    success = false;
                }
                if (TTF_Init() == -1)
                {
                    std::cout << "SDL_ttf error: " << TTF_GetError() << std::endl;
                    success = false;
                }
            }
        }
    }
    return success;
}

bool loadGraphic()
{
    bool success = true;
    font = TTF_OpenFont("BTL\\CLASSIQUE-SAIGON_0.TTF", 28);
    if (font == nullptr)
    {
        std::cout << "SDL_tff error: " << TTF_GetError() << std::endl;
        success = false;
    }
    return success;
}

#endif