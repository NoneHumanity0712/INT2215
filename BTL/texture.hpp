#ifndef TEXTURE
#define TEXTURE

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

const int windowWidth = 960;
const int windowHeight = 720;
const char title[] = "TETRIS GAME";

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

    bool loadImage(std::string path);
    bool loadText(std::string text, SDL_Color color);
    void render (int x, int y, SDL_Rect *clip); 
    void renderCentered (int x, int y);
    void setAlphaMode (Uint8 alpha);

    int getWidth();
    int getHeight();
};

#endif