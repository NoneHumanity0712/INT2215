#ifndef UTILITIES
#define UTILITIES

#include <SDL.h>
#include "texture.hpp"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "render.hpp"

extern SDL_Window *gWindow;
extern texture tetromino_graphic;
SDL_Window *gWindow = nullptr; //SDL_utils.hpp
texture tetromino_graphic; //SDL_utils.hpp

//close gWindow, free memory | SDL_utils.hpp
void close()
{
    TTF_CloseFont(gFont);
    gFont = nullptr;

    SDL_DestroyRenderer(gRenderer);
    gRenderer = nullptr;

    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    TTF_Quit();
    SDL_Quit();
}

//return true if initialize game successfully | SDL_utils.hpp
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
        gWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr) //error
        {
            std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == nullptr)
            {
                std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255); //white
                SDL_RenderClear(gRenderer);
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

//return true if load all graphics (image, gFont) successfully | SDL_utils.hpp
bool loadGraphic()
{
    bool success = true;
    gFont = TTF_OpenFont("BTL/CLASSIQUE-SAIGON_0.TTF", 28);
    if (gFont == nullptr)
    {
        std::cout << "SDL_tff error: " << TTF_GetError() << std::endl;
        success = false;
    }
    return success;
}

#endif