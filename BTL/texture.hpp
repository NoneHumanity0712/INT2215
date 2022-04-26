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

    bool loadImage(std::string path); //load image from file
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

bool texture::loadImage (std::string path)
{
    //Get rid of preexisting texture
    free();

    //The final texture
	SDL_Texture* newTexture = NULL;

    //temporary surface
    SDL_Surface *temp = IMG_Load(path.c_str());
    if (temp == NULL)
    {
        std::cout << "Unable to load image ! SDL_image Error: " << path << IMG_GetError() << std::endl;
    }
    else
    {
        //Color key image
		SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB( temp->format, 255, 255, 255 ) );

        mTexture = SDL_CreateTextureFromSurface(gRenderer, temp);
        if (mTexture == NULL)
        {
            std::cout << "Unable to create texture from ! SDL Error: " << path.c_str() << SDL_GetError() << std::endl;
        }
        else 
        { 
            //Get image dimensions
            width = temp->w;
            height = temp->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(temp);
    }
    mTexture = newTexture;
    return (mTexture != NULL);

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
    //Set rendering space and render to screen
    SDL_Rect r = {x, y, width, height};

	//Set clip rendering dimensions
    if (clip != nullptr)
    {
        r.w = clip->w;
        r.h = clip->h;
    }
    
	//Render to screen
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