#include "Wrapper.h"
#include "Contexts.h"

Wrapper::Wrapper() {
    running = true;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    context = visible;

    window = SDL_CreateWindow("Hello", 10, 10, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 11, 102, 35, 255);

    drawables.push_back(new DrawableWithPriority(renderer, std::string("assets/images/marybday.JPG"), 300, 140, 300, 300, 1));
    drawables.push_back(new DrawableWithPriority(renderer, std::string("assets/images/awesome.png"), 400, 100, 100, 100, 1));
    drawables[0]->setVelocity(0, 0);
    drawables[1]->setVelocity(0, 0);
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
        SDL_Delay(10);
        checkForCollision(drawables[0], drawables[1]);
        updateEverything();

    }



}

void Wrapper::updateEverything(void) {
    for(int i = 0; i < drawables.size(); i++) {
        drawables[i]->onUpdate();
    }
}


bool Wrapper::checkForCollision(DrawableWithPriority* obj1, DrawableWithPriority* obj2) {
    for(int i = 0; i < obj1->boundingBoxes.size(); i++) {
        for(int x = 0; x < obj2->boundingBoxes.size(); x++) {
            if(SDL_HasIntersection(obj2->boundingBoxes[x], obj1->boundingBoxes[i])) {
                return true;
            }
            else {
                return false;
            }
        }
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
    drawables[1]->setPosition(e.motion.x - (drawables[1]->getWidth() / 2), e.motion.y - (drawables[1]->getWidth() / 2));
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



