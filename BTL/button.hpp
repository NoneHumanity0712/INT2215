#ifndef BUTTON
#define BUTTON

#include <SDL.h>
#include <stdio.h>
#include <string>

enum ButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class button
{
	friend class Game;
	friend class input;
    public:
        button();

		button(int x, int y);

		//Handles mouse event
		void handleEvent( SDL_Event* e );

    private:
        //Top left position
		SDL_Point Position;

		//Currently used global sprite
		ButtonSprite CurrentSprite;
};

#endif