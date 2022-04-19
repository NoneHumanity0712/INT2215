#include "SDL_utils.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "render.h"
#include "texture.h"

using namespace std;

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL_Error: " << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
        if (window == nullptr) //error
        {
            cout << "SDL_Error: " << SDL_GetError() << endl;
            success = false;
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == nullptr)
            {
                cout << "SDL_Error: " << SDL_GetError() << endl;
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //white
                SDL_RenderClear(renderer);
                if (IMG_Init(IMG_INIT_PNG) == 0 || IMG_Init(IMG_INIT_JPG) == 0)
                {
                    cout << "SDL_image error: " << IMG_GetError() << endl;
                    success = false;
                }
                if (TTF_Init() == -1)
                {
                    cout << "SDL_ttf error: " << TTF_GetError() << endl;
                    success = false;
                }
            }
        }
    }
    return success;
}

bool loadMedia()
{
    bool success = true;
    font = TTF_OpenFont("BTL\\CLASSIQUE-SAIGON_0.TTF", 28);
    if (font == nullptr)
    {
        cout << "SDL_tff error: " << TTF_GetError() << endl;
        success = false;
    }
    return success;
}