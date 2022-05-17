Tetris game in C++ using SDL2.
_______________________________
How to play:
- Right/Left Arrow: move right/left
- Up Arrow: Rotate
- Down Arrow: Soft Drop
- Space: Hard Drop
- Shift/C: Hold
- Escape: Escape

_______________________________
Instruction:
- Ghost Piece: to locate the piece when hard drop.
- Hold Piece: swap the current piece with the hold piece.
- Lines: the numbers of cleared line.
- Speed: the delay time when a piece (a tetromino) is falling. 10 cleared lines increase 1 speed, or decrease the delay time by 100ms. The start speed is 0 (1000ms) and max speed is 9 (100ms)
- Pause Button: pause the game.
- Theme Switch: switch between dark theme and light theme.
_______________________________
SDL2 instruction: Lazy Foo's SDL tutorials
(https://lazyfoo.net/tutorials/SDL/index.php) 

Game logic and basic tutorial: Javier Lopez's Tetris tutorial
(https://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners)

Game Design: 2009 Tetris Design Guideline
(https://tetris.fandom.com/wiki/Tetris_Guideline)

_______________________________
Game Graphic Design: all designed by Lê Hoàng Minh Hà using Adobe Photoshop.
- Game window: 960px x 720px.
- Block size: 28px.
- Game field: 10 (blocks) x 22 (blocks) (the first two lines where new piece starts are hidden).
- Hold Piece box: 5 (blocks) x 5 (blocks).
- Next Piece box: 5 (blocks) x 5 (blocks).

_______________________________
Sound effects:
- Count Down:
- Move Piece:
- Drop Piece:
- Switch Theme:
- Clear Line:
