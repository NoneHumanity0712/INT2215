#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
//#include "board.hpp"
#include "game.hpp"
#include "SDL_utils.hpp"
#include "render.hpp"
#include "texture.hpp"
//#include "input.hpp"

//using namespace std;

const SDL_Color default_text_color = {0, 0, 0, 255}; //black
const int wait_time = 1000;    //1 second

int main(int argc, char **argv)
{
    input *manager = new input;
    std::cout << "input" << std::endl;
    Game tetrisGame;
    render rRenderer;

    if(initSDL());
    {
        loadGraphic();
        std::cout << "loading graphic" << std::endl;

        tetrisGame.initializeScene();
        std::cout << "initializing scence" << std::endl;

        tetrisGame.drawScene();
        std::cout << "drawing scence" << std::endl;

        rRenderer.updateScreen();

        int countdown = 3; // 3... 2... 1...
        texture countdown_text;
        while (countdown > 0)
        {
            rRenderer.clearScreen();
            std::cout << "clearing screen" << std::endl;

            tetrisGame.drawScene();
            std::cout << "drawing scene" << std::endl;

            countdown_text.loadText(std::to_string(countdown), default_text_color);
            std::cout << "loading text" << std::endl;

            rRenderer.renderTexture(&countdown_text, windowWidth/2, windowHeight/2);
            std::cout << "rendering texture" << std::endl;

            rRenderer.updateScreen();
            std::cout << "updating screen" << std::endl;

            SDL_Delay(1000);
            countdown--;
        }
        
        manager->clearQueueEvent();
        std::cout << "clearing queue event" << std::endl;

        SDL_Event e;
        unsigned long long time_1 = SDL_GetTicks();

        while (!manager->ExitGame() && !tetrisGame.gameOver())
        {
            while (SDL_WaitEvent(&e) != 0)
            {
                manager->pollAction(e);
                tetrisGame.event(manager->inputAction());
                std::cout << "get action from keyboard" << std::endl;
            }

            unsigned long long time_2 = SDL_GetTicks();
            if (time_2 - time_1 >= wait_time)
            {
                tetrisGame.pieceFalling();
                time_1 = SDL_GetTicks();
                std::cout << "piece falling down" << std::endl;
            }

            rRenderer.clearScreen();
            std::cout << "clearing screen" << std::endl;

            tetrisGame.drawScene();
            std::cout << "drawing scene" << std::endl;

            rRenderer.updateScreen();
            std::cout << "updating screen" << std::endl;
        }

        texture gameover_text;
        gameover_text.loadText("GAME OVER!", default_text_color);
        std::cout << "loading text" << std::endl;

        while (!manager->ExitGame())
        {
            while (SDL_PollEvent(&e) != 0)
                manager->pollAction(e);

            rRenderer.clearScreen();
            std::cout << "clearing screen" << std::endl;

            tetrisGame.drawScene();
            std::cout << "drawing scene" << std::endl;

            rRenderer.renderTexture(&gameover_text, windowWidth/2, windowHeight/2);
            std::cout << "updating screen" << std::endl;

            rRenderer.updateScreen();
            std::cout << "updating screen" << std::endl;

        }
    }
    delete manager;
    std::cout << "Exiting" << std::endl;
    close();

    system("pause");
    return 0;
}