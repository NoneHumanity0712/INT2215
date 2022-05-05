Tetris game in C++ using SDL2.

_______________________________
How to play:
- Right/Left Arrow: move right/left
- Up Arrow: rotate
- Down Arrow: Soft Drop
- Space: Hard Drop
- Shift/C: Hold
- Escape/F1: Pause

Ghost Piece: to locate the piece when hard drop
Hold Piece: swap the current piece with the hold piece

_______________________________
SDL2 instruction: Lazy Foo's SDL tutorials
(https://lazyfoo.net/tutorials/SDL/index.php) 

Game logic and basic tutorial: Javier Lopez's Tetris tutorial
(https://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners)

Game Design: 2009 Tetris Design Guideline
(https://tetris.fandom.com/wiki/Tetris_Guideline)

_______________________________
Game Design Details:
- background color: #effffd (HEX); (239, 255, 253) (RGB)
- matrix (playfield) color: #eeeeee (HEX); (238, 238, 238) (RGB)
- text color: #081d2a (HEX); (8, 28, 42) (RGB)
- text font: ClassiqueSaigon