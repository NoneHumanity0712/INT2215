#ifndef INPUT
#define INPUT

#include <SDL.h>

enum class ACTION{stay, down, left, right, drop, rotate, hold}; //input.hpp

class input
{
private:
    bool quit = false;
    ACTION action = ACTION::stay; 
public:
    void clearQueueEvent(); //input.hpp
    ACTION inputAction(); //input.hpp
    bool ExitGame(); //input.hpp
    void pollAction(SDL_Event e); //input.hpp
    void exit(); //input.hpp
};

#endif