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
extern SDL_Renderer* gRenderer;
extern TTF_Font *gFont;

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
    bool success = true;
    free();
    //temporary surface
    SDL_Surface *temp = IMG_Load(path.c_str());
    if (temp == nullptr)
    {
        std::cout << "Texture error: Could not load image from path: " << path << std::endl;
        success = false;
    }
    else
    {
        mTexture = SDL_CreateTextureFromSurface(gRenderer, temp);
        width = temp->w;
        height = temp->h;
        SDL_FreeSurface(temp);
    }
}

void texture::loadText(std::string text, SDL_Color color)
{
    bool success = true;
    free();
    SDL_Surface *textSurface = TTF_RenderText_Blended_Wrapped(gFont, text.c_str(), color, windowWidth);
    if (textSurface = nullptr)
    {        
        std::cout << "SDL_ttf error: " << TTF_GetError() << std::endl; 
        success = false;
    }   
     else
    {
        mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (mTexture == nullptr)
            {
                std::cout << "SDL error: " << SDL_GetError() << std::endl;
                success = false;
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
    SDL_RenderCopy(gRenderer, mTexture, clip, &r);
}

void texture::renderCentered (int x, int y)
{
    SDL_Rect rect = {x - (width/2), y - (height/2), width, height};
    SDL_RenderCopy(gRenderer, mTexture, nullptr, &rect);
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