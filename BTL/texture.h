#ifndef TEXTURE
#define TEXTURE

#include <string>
#include <SDL.h>

const int windowWidth = 640;
const int windowHeight = 360;
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

#endif