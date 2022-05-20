#include <iostream>
#include <cmath>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "game.hpp"
#include "SDL_utils.hpp"
#include "render.hpp"
#include "pause.hpp"
#include "button.hpp"
#include "sound.hpp"
#include "highscores.hpp"

void game(Game &tetrisGame, input *manager, render rRenderer, SDL_Event e)
{
    //set up game
    tetrisGame.initializeScene();

    texture score;
    std::string currentScore = "Score: " + std::to_string(tetrisGame.score);
    score.loadText(currentScore, tetrisGame.text_color);

    texture speed;
    std::string Level = "Level: " + std::to_string(tetrisGame.level());
    speed.loadText(Level, tetrisGame.text_color);

    int countdown = 3; // 3... 2... 1...
    texture countdown_text;

    sound count_down_sound[2];
    for (int i = 0; i < 2; i++)
    {
        std::string sound_path = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/countdown" + std::to_string(i) + ".wav";
        count_down_sound[i].loadSound(sound_path);
    }

    manager->clearQueueEvent();

    while (countdown > 0)
    {
        rRenderer.clearScreen();

        tetrisGame.drawScene();

        rRenderer.renderTexture(&score, 174, 560);
        rRenderer.renderTexture(&speed, 174, 600);

        countdown_text.loadText(std::to_string(countdown), tetrisGame.text_color);

        rRenderer.renderTexture(&countdown_text, windowWidth / 2, windowHeight / 2);

        rRenderer.updateScreen();

        count_down_sound[0].playSound();

        SDL_Delay(1000);
        countdown--;
    }
    rRenderer.clearScreen();

    //rRenderer.updateScreen();
    manager->clearQueueEvent();

    unsigned long long time_1 = SDL_GetTicks();

    count_down_sound[1].playSound();

    while (!tetrisGame.gameOver() && !manager->ExitGame())
    {
        long int wait_time = 1000 - (tetrisGame.level() - 1)*100;

        currentScore = "Score: " + std::to_string(tetrisGame.score);
        score.loadText(currentScore, tetrisGame.text_color);

        Level = "Level: " + std::to_string(tetrisGame.level());
        speed.loadText(Level, tetrisGame.text_color);

        unsigned long long time_2 = SDL_GetTicks();

        while (SDL_PollEvent(&e) != 0)
        {
            manager->pollAction(e);
            tetrisGame.event(manager->inputAction());
            tetrisGame.PauseButton(e);
            tetrisGame.ThemeSwitch(e);
            tetrisGame.MuteSound(e);
        }

        if (time_2 - time_1 >= wait_time && !tetrisGame.isPause)
        {
            tetrisGame.pieceFalling();
            time_1 = SDL_GetTicks();
        }

        rRenderer.clearScreen();
        tetrisGame.drawScene();
        rRenderer.renderTexture(&score, 174, 560);
        rRenderer.renderTexture(&speed, 174, 600);

        rRenderer.updateScreen();
    }
    for (int i = 0; i < 2; i++)
    {
        count_down_sound[i].~sound();
    }
    std::cout << "end" << std::endl;
}

int main(int argc, char **argv)
{
    bool startgame = false;

    do
    {
        startgame = false;
        if (initSDL())
        {
            input* manager = new input;
            render rRenderer;

            loadGraphic();

            SDL_Event e;

            Game tetrisGame;
            rRenderer.clearScreen();

            if (SDL_PollEvent(&e) != 0)
            {
                game(tetrisGame, manager, rRenderer, e);
            }
 
            string newName;
            getline(cin, newName);
            loadScore("C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/highscores.txt", newName, tetrisGame.score);

            rRenderer.clearScreen();
            std::cout << "2" << std::endl;
            while (!manager->ExitGame() && !tetrisGame.isRestart)
            {
                while (SDL_PollEvent(&e) != 0 )
                {
                    manager->pollAction(e);
                    tetrisGame.YesButton(e);
                    tetrisGame.NoButton(e, manager);
                }

                rRenderer.clearScreen();
                tetrisGame.drawScene();
                rRenderer.updateScreen();
            }
            startgame = tetrisGame.isRestart;
            tetrisGame.~Game();
            delete manager;
        }
        close();
    }
    while (startgame);

    system("pause");
    return 0;
}