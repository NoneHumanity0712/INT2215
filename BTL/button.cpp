#include "button.hpp"
#include <SDL.h>
#include <SDL_image.h>

button::button()
{
    Position.x = 0;
    Position.y = 0;

    CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
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
		if( x < Position.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > Position.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < Position.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > Position.y + BUTTON_HEIGHT )
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
				case SDL_MOUSEMOTION:
				CurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;
			
				case SDL_MOUSEBUTTONDOWN:
			    CurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

				case SDL_MOUSEBUTTONUP:
				CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}