#ifndef INPUT
#define INPUT

#include <SDL.h>
#include "button.hpp"

enum ACTION{stay, down, left, right, drop, rotate, hold, pause, menu};

//button pauseButton, menuButton;

class input
{
private:
    bool quit = false;
    ACTION action = ACTION::stay;
    //void setButtonPos();

public:
    bool isPause = false;
    void clearQueueEvent();
    ACTION inputAction();
    bool ExitGame();
    void pollAction(SDL_Event e);
    void exit(); 
};

#endif