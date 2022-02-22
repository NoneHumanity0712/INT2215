#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

void logSDLError(std::ostream& os, const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) 
    {
        SDL_Quit();
        exit(1);
    }
}

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;
const string WINDOW_TITLE = "TESTING";

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer) 
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    //Khi chạy trong môi trường bình thường (không chạy trong máy ảo)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy ảo (ví dụ tại máy tính trong phòng thực hành ở trường)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    SDL_RenderClear(renderer);
    
    SDL_Rect filled_background;
    filled_background.x = 0;
    filled_background.y = 0;
    filled_background.w = 700;
    filled_background.h = 700;

    SDL_SetRenderDrawColor(renderer, 255, 230, 230, 255);
    SDL_RenderFillRect(renderer, &filled_background);

    SDL_Rect filled_rect1;
    filled_rect1.x = 100;
    filled_rect1.y = 100;
    filled_rect1.w = 100;
    filled_rect1.h = 100;

    SDL_SetRenderDrawColor(renderer, 132, 240, 194, 255);
    SDL_RenderFillRect(renderer, &filled_rect1);

    SDL_Rect filled_rect2;
    filled_rect2.x = 200;
    filled_rect2.y = 100;
    filled_rect2.w = 100;
    filled_rect2.h = 100;

    SDL_SetRenderDrawColor(renderer, 240, 225, 108, 255);
    SDL_RenderFillRect(renderer, &filled_rect2);

    SDL_Rect filled_rect3;
    filled_rect3.x = 100;
    filled_rect3.y = 200;
    filled_rect3.w = 100;
    filled_rect3.h = 100;

    SDL_SetRenderDrawColor(renderer, 113, 84, 240, 255);
    SDL_RenderFillRect(renderer, &filled_rect3);

    SDL_Rect filled_rect4;
    filled_rect4.x = 200;
    filled_rect4.y = 200;
    filled_rect4.w = 100;
    filled_rect4.h = 100;

    SDL_SetRenderDrawColor(renderer, 255, 125, 102, 255);
    SDL_RenderFillRect(renderer, &filled_rect4);

   //Khi thông thường chạy với môi trường bình thường ở nhà
    SDL_RenderPresent(renderer);

    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}