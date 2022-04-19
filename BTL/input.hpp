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

void input::clearQueueEvent()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {}
}

ACTION input::inputAction()
{
    return action;
}

bool input::ExitGame()
{
    return quit;
}

/*
- click quit/type escape: quit game
- down/right/left arrow key: move down/right/left
- space key: drop
- up arrow key: rotate
*/
void input::pollAction(SDL_Event e)
{
    if (e.type == SDL_QUIT) quit = true;
    else if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_ESCAPE: quit = true;
            break;
        case SDLK_DOWN: action = ACTION::down;
            break;
        case SDLK_LEFT: action = ACTION::left;
            break;
        case SDLK_RIGHT: action = ACTION::right;
            break;
        case SDLK_UP: action = ACTION::rotate;
            break;
        case SDLK_SPACE: action = ACTION::drop;
        }
    }
    else action = ACTION::stay;
}

void input::exit()
{
    quit = true;
}

#endif