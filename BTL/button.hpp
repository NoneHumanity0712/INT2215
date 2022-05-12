#ifndef BUTTON
#define BUTTON

#include <SDL.h>
#include <stdio.h>
#include <string>

const int BUTTON_WIDTH = 28;
const int BUTTON_HEIGHT = 28;
const int TOTAL_BUTTONS = 2;

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

		//Sets top left position
		void setPosition( int x, int y );

		//Handles mouse event
		void handleEvent( SDL_Event* e );

    private:
        //Top left position
		SDL_Point Position;

		//Currently used global sprite
		ButtonSprite CurrentSprite;
};

#endif