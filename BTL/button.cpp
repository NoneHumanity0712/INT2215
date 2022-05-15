#include "button.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include "details.hpp"

button::button()
{
    Position.x = 0;
    Position.y = 0;

    CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

button::button(int x, int y)
{
	Position.x = x;
	Position.y = y;
}

void button::handleEvent(SDL_Event *e)
{
    //If mouse event happened
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < Position.x + button_border)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > Position.x + button_border + button_size)
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < Position.y + button_border)
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > Position.y + button_border + button_size)
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
				case SDL_MOUSEMOTION: CurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;
			
				case SDL_MOUSEBUTTONDOWN: CurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP: CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
					break;
			}
		}
	}
}