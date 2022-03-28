Create your own project with keyboard/mouse AND SDL_utils.h and SDL_utils.cpp in it.

OR 
you can run without a project if you follow the instructions bellow:

1. copy SDL2.dll to this directory
2. modify make-keyboard.bat and make-mouse.bat:

-ID:\setup\SDL2-2.0.5\x86_64-w64-mingw32\include\SDL2 
-LD:\setup\SDL2-2.0.5\x86_64-w64-mingw32\lib

to use the paths to SDL's include\SDL2 and \lib in YOUR computer. 
For example, if your SDL is at C:\SDL
-IC:\SDL\x86_64-w64-mingw32\include\SDL2 
-LC:\SDL\x86_64-w64-mingw32\lib

3. run make-keyboard.bat to build keyboard.exe
4. run make-mouse.bat to build mouse.exe