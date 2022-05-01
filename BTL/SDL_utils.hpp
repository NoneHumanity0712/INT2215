#ifndef UTILITIES
#define UTILITIES

#include <SDL.h>
#include "texture.hpp"

void logSDLError(std::ostream& os, const std::string &msg, bool fatal);

void logSDL_ttf_Error(std::ostream& os, const std::string &msg, bool fatal);

void logSDL_image_Error(std::ostream& os, const std::string &msg, bool fatal);

void close();

bool initSDL();

void loadGraphic();

#endif