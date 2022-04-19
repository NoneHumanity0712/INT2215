#ifndef TEXTURE
#define TEXTURE

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

const int windowWidth = 640;
const int windowHeight = 360;
const char title[] = "TETRIS GAME";

// SDL_Window *window;
SDL_Renderer* renderer;
TTF_Font *font;

class texture
{
private:
    SDL_Texture *mTexture;
    int width;
    int height;
public:
    texture();
    ~texture();
    void free();

    void loadImage(std::string path); //load image from file
    void loadText(std::string text, SDL_Color color);
    void render (int x, int y, SDL_Rect *clip = nullptr); //nullptr: null pointer
    void renderCentered (int x, int y);
    void setAlphaMode (Uint8 alpha);

    int getWidth();
    int getHeight();
};

texture::texture()
{
    mTexture = nullptr;
    width = 0;
    height = 0;
}

texture::~texture()
{
    free();
}

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

void texture::render (int x, int y, SDL_Rect *clip)
{
    SDL_Rect r = {x, y, width, height};
    if (clip != nullptr)
    {
        r.w = clip->w;
        r.h = clip->h;
    }
    SDL_RenderCopy(renderer, mTexture, clip, &r);
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

#endif