#ifndef UTILITIES
#define UTILITIES

#include <SDL.h>
#include "texture.h"

SDL_Window *window;
texture tetromino_graphic;

//return true if initialize game successfully
bool init();

//return true if load all graphics (image, font) successfully
bool loadGraphic();

//close window, free memory
void close();

#endif