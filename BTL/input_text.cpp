#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "texture.hpp"

texture PromptTextTexture;
texture InputTextTexture;

std::string text_input(SDL_Event e, SDL_Color textColor)
{
    std::string inputText = "";
    InputTextTexture.loadText(inputText.c_str(), textColor);

    SDL_StartTextInput();
    
}