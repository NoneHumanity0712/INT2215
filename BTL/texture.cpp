#include <iostream>
#include "SDL.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "texture.h"

// SDL_Window *window;
SDL_Renderer* renderer;
TTF_Font *font;

// texture::texture()
// {
//     mTexture = nullptr;
//     width = 0;
//     height = 0;
// }

// texture::~texture()
// {
//     free();
// }

//free texture
void texture::free()
{
    if(mTexture != nullptr)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        width = 0;
        height = 0;
    }
}

void texture::loadImage (std::string path)
{
    free();

    //temporary surface
    SDL_Surface *temp = IMG_Load(path.c_str());
    if (temp = nullptr)
        std::cout << "Texture error: Could not load image from path: " << path << std::endl;
    else
    {
        mTexture = SDL_CreateTextureFromSurface(renderer, temp);
        width = temp->w;
        height = temp->h;
        SDL_FreeSurface(temp);
    }
}

void texture::loadText(std::string text, SDL_Color color)
{
    free();
    SDL_Surface *textSurface = TTF_RenderText_Blended_Wrapped(font, text.c_str(), color, windowWidth);
    if (textSurface = nullptr)
    {
        std::cout << "SDL_ttf error: could not create surface from text!" << std::endl;
        std::cout << TTF_GetError() << std::endl;
    } 
    else
    {
        mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (mTexture == nullptr)
        {
            std::cout << "SDL error: could not create texture from text! " << std::endl;
            std::cout << SDL_GetError() << std::endl;
        }
        else
        {
            width = textSurface->w;
            height = textSurface->h;
        }
    }
    SDL_FreeSurface(textSurface);
}

void texture::renderCentered (int x, int y)
{
    SDL_Rect rect = {x - (width/2), y - (height/2), width, height};
    SDL_RenderCopy(renderer, mTexture, nullptr, &rect);
}

void texture::setAlphaMode(Uint8 alpha)
{
    SDL_SetTextureAlphaMod (mTexture, alpha);
}

int texture::getWidth()
{
    return width;
}

int texture::getHeight()
{
    return height;
}

// int main(int argv, char** args) { }