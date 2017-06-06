#include "Wrapper.h"
#include "Contexts.h"

Wrapper::Wrapper() {
    SDL_Init(SDL_INIT_VIDEO);
    context = visible;

    window = SDL_CreateWindow("Hello", 10, 10, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);


    //SDL_Texture * img = IMG_LoadTexture(renderer, "/home/czhanacek/marybday.JPG");
    SDL_SetRenderDrawColor(renderer, 200, 0, 100, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 10, 10, 400, 400);
    SDL_RenderDrawLine(renderer, 10, 10, 400, 10);
    SDL_RenderDrawLine(renderer, 400, 400, 400, 10);
    SDL_RenderPresent(renderer);

    while(true) {
        SDL_Event e;

        if(SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                handleKeyEvent(e);
                break;
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                handleMouseButtonEvent(e);
                break;
            case SDL_MOUSEWHEEL:
                handleMouseWheelEvent(e);
                break;
            case SDL_MOUSEMOTION:
                handleMouseMotionEvent(e);
                break;
            }
        }
    }



}

void Wrapper::quitEverything(void)
{
    // we'll also need to destroy the textures here (once we have some)
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Wrapper::~Wrapper()
{
    quitEverything();
}

void Wrapper::handleMouseButtonEvent(SDL_Event e) {

    std::cout << "HEY!\n";
}

void Wrapper::handleKeyEvent(SDL_Event e)
{
    if(e.type == SDL_KEYUP) {
        if(e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_q) {
            std::cout << "Started quitting\n";
            quitEverything();
        }
    }

}

void Wrapper::handleMouseMotionEvent(SDL_Event e)
{

}

void Wrapper::handleMouseWheelEvent(SDL_Event e)
{

}

void Wrapper::handleWindowEvent(SDL_Event e)
{

}


