#ifndef DETAILS
#define DETAILS

#include <iostream>
#include <string>
#include <SDL.h>

/* PIECE */

const char tetrominoes_name[] = {'I', 'J', 'L', 'O', 'S', 'Z', 'T'};

//shape of tetrominoes in 5x5 matrixes
const int tetrominoes_type[7][4][5][5] = 
{
    //I
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 2, 1, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 2, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {1, 1, 2, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 2, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        }
    },

    //J
    {
        {
            {0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 1, 2, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 2, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 2, 1, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 2, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0}
        }
    },

    //L
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 1, 2, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 2, 0, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 2, 1, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 2, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        }
    },

    //O
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        }
    },

    //S
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0},
            {0, 1, 2, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 1, 2, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        }
    },

    //Z
    {
        {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 2, 0, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 1, 2, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0}
        }
    },

    //T
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 1, 2, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 2, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 1, 2, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        }
    }
};
const int beginPosition[7][4][2] = 
{
    //I
    {
        {-2, -3},
        {0, -3},
        {-2, -2},
        {0, -3}
    },

    //J
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -3}
    },

    //L
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -3}
    },

    //O
    {
        {-2, -3},
        {-2, -3},
        {-2, -2},
        {-2, -3}
    },

    //S
    {
        {-2, -3},
        {-2, -3},
        {-2, -2},
        {-2, -3}
    },

    //Z
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -3}
    },

    //T
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -3}
    }
};

/* BOARD */

const SDL_Point playfield = {340, 120};
const int block_size = 28;              // in pixels
const int playfield_width = 10;         // in blocks
const int true_playfield_height = 20;   // in blocks
const int playfield_height = 22;       // The playfield + 2 rows directly above it for spawning the Tetrominos
const int board_height = 32;             // distance from botton where the playfield begins; in pixels
const int matrix_blocks = 5;            //5 x 5 matrix for each piece


/* BUTTON */

const int button_sprite_size = 68; // in pixels
const int button_size = 36;
const int button_border = (button_sprite_size - button_size)/2;
static std::string button_path_light = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/pause_light.png";
static std::string button_path_dark = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/pause_dark.png";

/* SWITCH */
const SDL_Rect themeSwitchRect = {724, 46, 80, 36};
static std::string switch_path_light = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/theme_switch_light.png";
static std::string switch_path_dark = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/theme_switch_dark.png";

/* INPUT */
const SDL_Point pauseButtonPos = {808, 30};

/* TEXTURE */
const int windowWidth = 960;
const int windowHeight = 720;
const char title[] = "TETRIS GAME";

/* RENDER */
const SDL_Color backgroundColorLight = {216, 236, 233, 255};

/* GAME */
const SDL_Point nextPiecePos = {720, 120};

const SDL_Point holdBoxPos = {100, 120};

const SDL_Color text_color_light = {8, 29, 42, 255}; //dark blue
const SDL_Color text_color_dark = { 255, 240, 238, 255 }; //light blue

static std::string minoes_path_light = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/minoes-neumorphism_light.png";
static std::string background_path_light = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/Neumorphism_light.png";
static std::string ghost_minoes_path_light = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/minoes-neumorphism_ghost_light.png";

static std::string minoes_path_dark = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/minoes-neumorphism_dark.png";
static std::string background_path_dark = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/Neumorphism_dark.png";
static std::string ghost_minoes_path_dark = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/minoes-neumorphism_ghost_dark.png";

const char font_path_neu[] = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/Quicksand-Bold.ttf";

#endif