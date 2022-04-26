#ifndef UTILITIES
#define UTILITIES

#include <SDL.h>
#include "texture.hpp"

extern SDL_Window *gWindow;
extern texture tetromino_graphic;
extern TTF_Font* gFont;
extern SDL_Renderer* gRenderer;
SDL_Window *gWindow = nullptr; //SDL_utils.hpp
texture tetromino_graphic; //SDL_utils.hpp


void logSDLError(std::ostream& os, const std::string &msg, bool fatal);

void logSDL_ttf_Error(std::ostream& os, const std::string &msg, bool fatal);

void logSDL_image_Error(std::ostream& os, const std::string &msg, bool fatal);

void close();

bool initSDL();

void loadGraphic();

#endif