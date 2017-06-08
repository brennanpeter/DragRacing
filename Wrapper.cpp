#include "Wrapper.h"
#include "Contexts.h"

Wrapper::Wrapper() {
    running = true;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    context = visible;

    window = SDL_CreateWindow("Hello", 10, 10, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);


    drawables.push_back(new DrawableWithPriority(renderer, std::string("assets/images/marybday.JPG"), 220, 140, 100, 300, 1));


    while(running) {
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
        SDL_RenderClear(renderer);
        drawEverything();
        SDL_RenderPresent(renderer);
    }



}

void Wrapper::quitEverything(void) {
    IMG_Quit();
    deleteDrawables();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    running = false;
}

Wrapper::~Wrapper() {
    quitEverything();
}

void Wrapper::handleMouseButtonEvent(SDL_Event e) {

}

void Wrapper::handleKeyEvent(SDL_Event e) {
    if(e.type == SDL_KEYUP) {
        if(e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_q) {
            std::cout << "Started quitting\n";
            quitEverything();
        }
    }

}

void Wrapper::deleteDrawables(void) {
    for(int i = 0; i < drawables.size(); i++) {
        delete drawables[i];
    }
}

void Wrapper::handleMouseMotionEvent(SDL_Event e) {

}

void Wrapper::handleMouseWheelEvent(SDL_Event e) {

}

void Wrapper::handleWindowEvent(SDL_Event e) {

}

void Wrapper::drawEverything() {
    // Priority sorting has not been implemented yet.
    for(int i = 0; i < drawables.size(); i++) {
        SDL_RenderCopy(renderer, drawables[i]->getTexture(), NULL, drawables[i]->getRect());
    }
}



