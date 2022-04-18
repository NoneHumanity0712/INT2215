#include <iostream>
#include "LTexture.hpp"

using namespace std;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//headline
string headline = "TETRIS";

//the game area
SDL_Rect gameZone = {(SCREEN_WIDTH - GameAreaWidth)/2, textPosY*2 + textSize, 
	GameAreaWidth, GameAreaHeight};

//Rendered texture
LTexture texture;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			cout << "Warning: Linear texture filtering not enabled!" << endl;
		}

		//Create window
		gWindow = SDL_CreateWindow( "Tetris Game v1.0", SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
					success = false;
				}

				 //Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Open the font
	gFont = TTF_OpenFont("BTL\\CLASSIQUE-SAIGON_0.TTF", textSize);
	if( gFont == NULL )
	{
		cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << endl;
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = {255, 255, 255};
		if( !texture.loadFromRenderedText( headline, textColor ) )
		{
			cout << "Failed to render text texture!" << endl;
			success = false;
		}'
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		'
	
	
	
	}

	return success;
}

void close()
{
	//Free loaded images
	texture.free();

	//Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() ) cout << "Failed to initialize!" << endl;
	else
	{
		//Load media
		if( !loadMedia() )
		{
			cout << "Failed to load media!" << endl;
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 1, 7, 42, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render current frame
				texture.render( ( SCREEN_WIDTH - texture.getWidth() ) / 2, textPosY);

				//draw game area
				SDL_SetRenderDrawColor( gRenderer, 76, 83, 94, 0xFF );
				SDL_RenderFillRect(gRenderer, &gameZone);

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}