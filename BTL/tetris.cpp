#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "board.h"
#include "game.h"
#include "SDL_utils.h"
#include "render.h"
#include "texture.h"
#include "input.h"

using namespace std;

const SDL_Color default_text_color = {0, 0, 0, 255}; //black
const int wait_time = 1000;    //1 second

int main(int argc, char **argv)
{
    input *manager = new input;
    Game tetrisGame;
    render rRenderer;
    if (init())
    {
        loadGraphic();

        tetrisGame.initializeScene();
        tetrisGame.drawScene();
        rRenderer.updateScreen();

        int countdown = 3; // 3... 2... 1...
        texture countdown_text;
        while (countdown > 0)
        {
            rRenderer.clearScreen();
            tetrisGame.drawScene();
            countdown_text.loadText(to_string(countdown), default_text_color);
            rRenderer.renderTexture(&countdown_text, windowWidth/2, windowHeight/2);
            rRenderer.updateScreen();
            SDL_Delay(1000);
            countdown--;
        }
        
        manager->clearQueueEvent();
        SDL_Event e;
        unsigned long long time_1 = SDL_GetTicks();
        while (!manager->ExitGame() && !tetrisGame.gameOver())
        {
            while (SDL_PollEvent(&e) != 0)
            {
                manager->pollAction(e);
                tetrisGame.event(manager->inputAction());
            }

            unsigned long long time_2 = SDL_GetTicks();
            if (time_2 - time_1 >= wait_time)
            {
                tetrisGame.pieceFalling();
                time_1 = SDL_GetTicks();
            }

            rRenderer.clearScreen();
            tetrisGame.drawScene();
            rRenderer.updateScreen();
        }

        texture gameover_text;
        gameover_text.loadText("GAME OVER!", default_text_color);
        while (!manager->ExitGame())
        {
            while (SDL_PollEvent(&e) != 0)
                manager->pollAction(e);
            rRenderer.clearScreen();
            tetrisGame.drawScene();
            rRenderer.renderTexture(&gameover_text, windowWidth/2, windowHeight/2);
            rRenderer.updateScreen();
        }
    }
    delete manager;
    cout << "Exiting" << endl;
    close();
    return 0;
}