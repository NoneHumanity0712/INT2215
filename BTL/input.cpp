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

/*
void input::setButtonPos()
{
    pauseButton.setPosition(pause_x, button_y); //pause button
    menuButton.setPosition(menu_x, button_y); //menu button
}
*/

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
    /*
    else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x >= pauseButton.Position.x && x <= pauseButton.Position.x + BUTTON_WIDTH
            && y >= pauseButton.Position.y && y <= pauseButton.Position.y + BUTTON_HEIGHT)
        {
            //click
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                action = ACTION::pause;
                if (isPause) isPause = false;
                else isPause = true;
            }
        }
        else if (x >= menuButton.Position.x && x <= menuButton.Position.x + BUTTON_WIDTH
            && y >= menuButton.Position.y && y <= menuButton.Position.y + BUTTON_HEIGHT)
        {
            //click
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                action = ACTION::menu;
            }
        }
    }
    */
    else action = ACTION::stay;
}

void input::exit()
{
    quit = true;
}