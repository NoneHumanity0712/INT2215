#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "game.hpp"
#include "SDL_utils.hpp"
#include "render.hpp"
#include "pause.hpp"

int main(int argc, char **argv)
{
    input *manager = new input;
    render rRenderer;

    if(initSDL());
    {
        loadGraphic();
        Game tetrisGame;

        //set up game
        tetrisGame.initializeScene();

        texture cleared_line;
        std::string lines = tetrisGame.clearedLines();
        cleared_line.loadText(lines, tetrisGame.text_color);

        texture speed;
        std::string Speed = "Speed: " + std::to_string((1000 - tetrisGame.falling_speed()) / 100);
        speed.loadText(Speed, tetrisGame.text_color);

        int countdown = 3; // 3... 2... 1...
        texture countdown_text;

        while (countdown > 0)
        {
            rRenderer.clearScreen();

            tetrisGame.drawScene();

            rRenderer.renderTexture(&cleared_line, 174, 560);
            rRenderer.renderTexture(&speed, 174, 600);

            countdown_text.loadText(std::to_string(countdown), tetrisGame.text_color);

            rRenderer.renderTexture(&countdown_text, windowWidth / 2, windowHeight / 2);

            rRenderer.updateScreen();

            SDL_Delay(1000);
            countdown--;
        }
        rRenderer.clearScreen();

        SDL_Event e;

        //rRenderer.updateScreen();
        manager->clearQueueEvent();

        unsigned long long time_1 = SDL_GetTicks();

        while (!manager->ExitGame() && !tetrisGame.gameOver())
        {
            int wait_time = tetrisGame.falling_speed();

            lines = tetrisGame.clearedLines();
            cleared_line.loadText(lines, tetrisGame.text_color);

            Speed = "Speed: " + std::to_string((1000 - tetrisGame.falling_speed()) / 100);
            speed.loadText(Speed, tetrisGame.text_color);

            unsigned long long time_2 = SDL_GetTicks();

            while (SDL_PollEvent(&e) != 0)
            {
                manager->pollAction(e);
                tetrisGame.event(manager->inputAction());
                tetrisGame.PauseButton(e);
                tetrisGame.ThemeSwitch(e);
            }

            if (time_2 - time_1 >= wait_time && !tetrisGame.isPause)
            {
                tetrisGame.pieceFalling();
                time_1 = SDL_GetTicks();
            }

            rRenderer.clearScreen();
            tetrisGame.drawScene();
            rRenderer.renderTexture(&cleared_line, 174, 560);
            rRenderer.renderTexture(&speed, 174, 600);

            rRenderer.updateScreen();
        }
        SDL_Color gameover_text_color = {156, 2, 2, 255};
        texture gameover_text;
        gameover_text.loadText("GAME OVER!", gameover_text_color);

        while (!manager->ExitGame())
        {
            while (SDL_PollEvent(&e) != 0)
            {
                manager->pollAction(e);
                tetrisGame.ThemeSwitch(e);
            }
            rRenderer.clearScreen();

            tetrisGame.drawScene();
            tetrisGame.PauseButton(e);

            rRenderer.renderTexture(&gameover_text, windowWidth/2, windowHeight/2);

            rRenderer.updateScreen();
        }
    }
    delete manager;
    close();

    system("pause");
    return 0;
}