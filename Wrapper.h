#include "DrawableWithPriority.h"

#pragma once


class Wrapper {
public:
    Wrapper();
    ~Wrapper();
    void handleKeyEvent(SDL_Event e);
    void handleMouseButtonEvent(SDL_Event e);
    void handleMouseMotionEvent(SDL_Event e);
    void handleMouseWheelEvent(SDL_Event e);
    void handleWindowEvent(SDL_Event e);
    void drawEverything(void);
    void quitEverything(void);
    void deleteDrawables(void);
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    uint32_t context;
    bool running;
    std::vector<DrawableWithPriority *> drawables;

};

