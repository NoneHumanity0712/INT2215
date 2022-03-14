#include <iostream>
#include <SDL.h>

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
const string WINDOW_TITLE = "SDL test";

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

// void waitUntilKeyPressed()
// {
//     SDL_Event e;
//     while (true) {
//         if ( SDL_WaitEvent(&e) == 0) SDL_De 
        
//              (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
//             return;
//         SDL_Delay(100);
//     }
// }

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) == 0) SDL_Delay(100);
        else if (e.type == SDL_QUIT) break;
        else if (e.type == SDL_KEYDOWN)
        {
            cerr << "_" << e.key.keysym.sym << "_" << endl;
        }
    }

   //Khi thông thường chạy với môi trường bình thường ở nhà
    SDL_RenderPresent(renderer);

    // waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}