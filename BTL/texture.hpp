#ifndef TEXTURE
#define TEXTURE

#include <string>
#include <SDL.h>

using namespace std;

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

    void loadImage(string path); //load image from file
    void loadText(string text, SDL_Color color);
    void render (int x, int y, SDL_Rect *clip = nullptr); //nullptr: null pointer
    void renderCentered (int x, int y);
    void setAlphaMode (Uint8 alpha);

    int getWidth();
    int getHeight();
};

#endif