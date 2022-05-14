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

const int width_to_playfield = 340;     // in pixels
const int height_to_playfield = 120;     // in pixels
const int block_size = 28;              // in pixels
const int playfield_width = 10;         // in blocks
const int true_playfield_height = 20;   // in blocks
const int playfield_height = 22;       // The playfield + 2 rows directly above it for spawning the Tetrominos
const int board_height = 32;             // distance from botton where the playfield begins; in pixels
const int matrix_blocks = 5;            //5 x 5 matrix for each piece

/* INPUT */
const int menu_x = 820;
const int pause_x = 720;
const int button_y = 50;

/* TEXTURE */
const int windowWidth = 960;
const int windowHeight = 720;
const char title[] = "TETRIS GAME";

/* RENDER */
const Uint8 backgroundColor_R = 216; //Red channel color for background
const Uint8 backgroundColor_G = 236; //Green channel color for background
const Uint8 backgroundColor_B = 233; //Blue channel color for background 

/* GAME */
const int x_nextPiece = 720;
const int y_nextPiece = 120;
const Uint8 transparency = 100; //set transparency for ghost piece

const int hold_box_x = 100;            // Horizontal distance from top left corner; in pixels
const int hold_box_y = 120;            // Vertical distance from top left corner; in pixels

const SDL_Color text_color_light = {8, 29, 42, 255}; //dark blue
const SDL_Color text_color_dark = { 255, 240, 238, 255 }; //light blue

static std::string minoes_path_light = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/minoes-neumorphism_light.png";
static std::string background_path_light = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/Neumorphism_light.png";

static std::string minoes_path_dark = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/minoes-neumorphism_dark.png";
static std::string background_path_dark = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/Neumorphism_dark.png";

const char font_path_neu[] = "C:/Users/HP/OneDrive - vnu.edu.vn/UET/Courses/INT2215/BTL/Quicksand-Bold.ttf";

#endif