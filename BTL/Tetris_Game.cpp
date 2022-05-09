#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "game.hpp"
#include "SDL_utils.hpp"
#include "render.hpp"

const SDL_Color default_text_color = {8, 28, 42, 255}; //dark blue

//using namespace std;

int main(int argc, char **argv)
{
    input *manager = new input;
    render rRenderer;

    if(initSDL());
    {
        loadGraphic();

        int countdown = 3; // 3... 2... 1...
        texture countdown_text;
        while (countdown > 0)
        {
            rRenderer.clearScreen();

            countdown_text.loadText(std::to_string(countdown), default_text_color);

            rRenderer.renderTexture(&countdown_text, windowWidth/2, windowHeight/2);

            rRenderer.updateScreen();

            SDL_Delay(1000);
            countdown--;
        }
        rRenderer.clearScreen();

        Game tetrisGame;

        tetrisGame.initializeScene();
        tetrisGame.drawScene();
        rRenderer.updateScreen();
        manager->clearQueueEvent();

        int wait_time = 1000;  //1 second

        SDL_Event e;
        unsigned long long time_1 = SDL_GetTicks();

        while (!manager->ExitGame() && !tetrisGame.gameOver())
        {
            texture cleared_line;
            std::string lines = tetrisGame.clearedLines();
            cleared_line.loadText(lines, default_text_color);

            unsigned long long time_2 = SDL_GetTicks();
            //wait_time -= (tetrisGame.clearedLines() / 10) * 100;

            while (SDL_PollEvent(&e) != 0)
            {
                manager->pollAction(e);
                tetrisGame.event(manager->inputAction());
            }

            if (time_2 - time_1 >= wait_time)
            {
                tetrisGame.pieceFalling();
                time_1 = SDL_GetTicks();
            }

            rRenderer.clearScreen();
            tetrisGame.drawScene();
            rRenderer.renderTexture(&cleared_line, 174, 560);
            rRenderer.updateScreen();
        }
        SDL_Color gameover_text_color = {156, 2, 2, 255};
        texture gameover_text;
        gameover_text.loadText("GAME OVER!", gameover_text_color);
        //std::cout << "loading text" << std::endl;

        while (!manager->ExitGame())
        {
            while (SDL_PollEvent(&e) != 0)
                manager->pollAction(e);

            rRenderer.clearScreen();
            //std::cout << "clearing screen" << std::endl;

            tetrisGame.drawScene();
            //std::cout << "drawing scene" << std::endl;

            rRenderer.renderTexture(&gameover_text, windowWidth/2, windowHeight/2);
            //std::cout << "rendering texture" << std::endl;

            rRenderer.updateScreen();
            //std::cout << "updating screen" << std::endl;

        }
    }
    delete manager;
    //std::cout << "Exiting" << std::endl;
    close();

    system("pause");
    return 0;
}