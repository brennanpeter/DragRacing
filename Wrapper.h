
#include <SDL2/SDL.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>

#pragma once


class Wrapper
{
    public:
        Wrapper();
        ~Wrapper();
        void handleKeyEvent(SDL_Event e);
        void handleMouseButtonEvent(SDL_Event e);
        void handleMouseMotionEvent(SDL_Event e);
        void handleMouseWheelEvent(SDL_Event e);
        void handleWindowEvent(SDL_Event e);
        void quitEverything(void);
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        uint32_t context;

};

