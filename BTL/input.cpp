#include "input.hpp"

void input::clearQueueEvent()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {}
}

ACTION input::inputAction()
{
    return action;
}

void input::setButtonPos()
{
    Buttons[0].setPosition(780, 50); //pause button
    Buttons[1].setPosition(820, 50); //menu button
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
        case SDLK_F1:
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
            break;
            
        case SDLK_c:
        case SDLK_LSHIFT:
        case SDLK_RSHIFT: action = ACTION::hold;
            break;
        }
    }
    else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        for (int i = 0; i < TOTAL_BUTTONS; i++)
        {
            if (x >= Buttons[i].Position.x && x <= Buttons[0].Position.x + BUTTON_WIDTH
                && y >= Buttons[i].Position.y && y << Buttons[i].Position.y + BUTTON_HEIGHT)
            {
                switch (e.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                    case SDL_MOUSEBUTTONUP:
                    {
                        action = static_cast<ACTION>(ACTION::pause + i);
                        if (!pause) pause = true;
                        else pause = false;
                        break;
                    }
                }
            }
        }
    }
    else action = ACTION::stay;
}

void input::exit()
{
    quit = true;
}