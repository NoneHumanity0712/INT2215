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

void logSDLError(std::ostream& os, const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void logSDL_ttf_Error(std::ostream& os, const std::string &msg, bool fatal)
{
    os << msg << " Error: " << TTF_GetError() << std::endl;
    if (fatal) {
        TTF_Quit();
        exit(1);
    }
}

void logSDL_image_Error(std::ostream& os, const std::string &msg, bool fatal)
{
    os << msg << " Error: " << IMG_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

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
bool initSDL()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        logSDLError(std::cout, "SDL_Init", true);
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr) //error
        {    
            logSDLError(std::cout, "CreateWindow", true);
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == nullptr)
            {
                logSDLError(std::cout, "CreateRenderer", true);
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255); //white
                SDL_RenderClear(gRenderer);
                if (IMG_Init(IMG_INIT_PNG) == 0 || IMG_Init(IMG_INIT_JPG) == 0)
                {
                    logSDL_image_Error(std::cout, "Could not initialize SDL_image", true);
                    success = false;
                }
                if (TTF_Init() == -1)
                {
                    logSDL_ttf_Error(std::cout, "Could not initialize SDL_ttf", true);
                    success = false;
                }
                SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
                SDL_RenderSetLogicalSize(gRenderer, windowWidth, windowHeight);
            }
        }
    }
    return success;
}

//return true if load all graphics (image, gFont) successfully | SDL_utils.hpp
void loadGraphic()
{
    gFont = TTF_OpenFont("BTL/CLASSIQUE-SAIGON_0.TTF", 28);
    if (gFont == nullptr)
        logSDL_ttf_Error(std::cout, "Could not load font", true);
}

#endif