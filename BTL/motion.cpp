#include <iostream>
#include <SDL.h>
#include "SDL_utils.h"
#include <time.h>

using namespace std;

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;
const char WINDOW_TITLE[] = "Keyboard in SDL";

const int step = 20;

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect);

int left(SDL_Rect filled_rect)
{
    int x = filled_rect.x - step;
    if (x > 0) return x;
    else return 0;
}

int right(SDL_Rect filled_rect)
{
    int x = filled_rect.x + step;
    if (x < SCREEN_WIDTH - filled_rect.w) return x;
    else return SCREEN_WIDTH - filled_rect.w;
}

void initGame(SDL_Rect filled_rect, SDL_Event e, SDL_Window* window, SDL_Renderer* renderer)
{
    bool out = false;
    while (!out) 
    {
        bool piece_bottom = false;  
        // Nếu không có sự kiện gì thì tiếp tục chạy theo hướng ban đầu
        if (SDL_PollEvent(&e) == 0) SDL_Delay(50);
        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
        else if (e.type == SDL_QUIT) out = true;
        // Nếu có một phím được nhấn, thì xét phím đó là gì để xử lý tiếp
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE: break; 
                //sang trái
                case SDLK_a:
                case SDLK_LEFT: filled_rect.x = left(filled_rect);
                    break;
                //sang phải
                case SDLK_d:
                case SDLK_RIGHT: filled_rect.x = right(filled_rect);
                    break;
                //quay
                // case SDLK_w:
                // case SDLK_LEFT:
                //
                case SDLK_s:
                case SDLK_DOWN: 
                {
                    filled_rect.y = SCREEN_HEIGHT - filled_rect.h;
                    piece_bottom = true;
                    break;
                }
                default: break;
            }
        }
        SDL_Delay(100);
        int y = filled_rect.y + step/4;
        if (y < SCREEN_HEIGHT - filled_rect.h) filled_rect.y = y;
        else 
        {
            filled_rect.y =  SCREEN_HEIGHT - filled_rect.h;
            piece_bottom = true;
        }
        // Xoá toàn bộ màn hình và vẽ lại
        refreshScreen(window, renderer, filled_rect);
    }
}

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    // Your code here
    SDL_Event e;

    // Định nghĩa toạ độ ban đầu và kích cỡ hình chữ nhật
    SDL_Rect filled_rect;
    filled_rect.x = SCREEN_WIDTH / 2;
    filled_rect.y = 0;
    filled_rect.w = 20;
    filled_rect.h = 20;

    // Bước nhảy mỗi khi dịch chuyển
    
    // Xoá toàn bộ màn hình và vẽ
    //refreshScreen(window, renderer, filled_rect);
    
    initGame(filled_rect, e, window, renderer);
    

    quitSDL(window, renderer);
    return 0;
}

// Xoá và vẽ lại toàn bộ màn hình với 1 hình chữ nhật
void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect)
{
    // Đặt màu vẽ thành xanh lam (blue), xoá màn hình về màu xanh lam.
    SDL_SetRenderDrawColor(renderer, 9, 1, 43, 255);   // blue
    SDL_RenderClear(renderer);
    
    // Đặt màu vẽ về trắng và vẽ hình chữ nhật
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);   // white
    SDL_RenderFillRect(renderer, &filled_rect);

    // Dùng lệnh hiển thị (đưa) hình đã vẽ ra mành hình
   //Khi thông thường chạy với môi trường bình thường ở nhà
    SDL_RenderPresent(renderer);
   //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
   //SDL_UpdateWindowSurface(window);
}