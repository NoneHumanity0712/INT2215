#ifndef INPUT
#define INPUT

#include <SDL.h>

enum ACTION{stay, down, left, right, drop, rotate};

class input
{
private:
    bool quit = false;
    ACTION action = ACTION::stay;
public:
    void clearQueueEvent();
    ACTION inputAction();
    bool ExitGame();
    void pollAction(SDL_Event e);
    void exit();
};

#endif