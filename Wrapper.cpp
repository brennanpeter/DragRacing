
#include "Wrapper.h"

Wrapper::Wrapper() {
    running = true;
    mode = 1; // Mode is normal playing - this is default
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    //makeTrack();
    window = SDL_CreateWindow("Hello", 10, 10, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    trackStorage = new TrackPieceStorage(renderer);
    trackStorage->readFromFile();
    trackPieces = trackStorage->getTrackPieces();
    SDL_SetRenderDrawColor(renderer, 11, 200, 35, 255);
    //makeTrack();
    SDL_WarpMouseInWindow(window, 225, 225);

    car1 = new Car(renderer);
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
        if(running) {
            SDL_RenderClear(renderer);
            drawEverything();
            SDL_RenderPresent(renderer);
            if(!(checkIfCarOnTrack()) && mode == 1) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            else {
                SDL_SetRenderDrawColor(renderer, 11, 200, 35, 255);
            }
            updateEverything();
        }


    }



}

void Wrapper::updateEverything(void) {
    car1->onUpdate();

    // trackPieces don't need to be updated

}

void Wrapper::makeTrack(void) {
    makeTrackLine(false, 7, 200, 200);
    makeTrackLine(true, 7, 550, 200);
    makeTrackLine(false, 3, 600, 500);
    makeTrackLine(true, 9, 700, 100);
    makeTrackLine(false, 10, 200, 100);
    makeTrackLine(true, 1, 200, 150);
}

void Wrapper::makeTrackLine(bool vertical, int lengthUnits, int startX, int startY) {
    if(vertical) {
        for(int i = 0; i < lengthUnits; i++) {
            trackPieces.push_back(new TrackPiece(renderer, startX, startY + (i * 50), vertical));
        }
    }
    else {
        for(int i = 0; i < lengthUnits; i++) {
            trackPieces.push_back(new TrackPiece(renderer, startX + (i * 50), startY, vertical));
        }
    }
}

bool Wrapper::checkForCollision(DrawableWithPriority* obj1, DrawableWithPriority* obj2) {
    for(unsigned int i = 1; i < obj1->boundingBoxes.size(); i++) {
        for(unsigned int x = 1; x < obj2->boundingBoxes.size(); x++) {
            if(SDL_HasIntersection(obj2->boundingBoxes[x], obj1->boundingBoxes[i]) == true) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

int Wrapper::whichTrackPieceMouseOn(void) {
    int mx, my;
    int toReturn = -1;
    SDL_GetMouseState(&mx, &my);
    std::cout << mx << ", " << my << std::endl;
    SDL_Rect mouseRect;
    mouseRect.x = mx;
    mouseRect.y = my;
    mouseRect.h = 4;
    mouseRect.w = 4;
    std::cout << trackPieces.size() << std::endl;
    for(int i = 0; i < trackPieces.size(); i++) {
        std::cout << trackPieces[i]->boundingBoxes[1]->x << ", " << trackPieces[i]->boundingBoxes[1]->y << std::endl;
        if(SDL_HasIntersection(trackPieces[i]->boundingBoxes[0], &mouseRect) == true) {
            toReturn = i;
        }
    }
    return toReturn;
}

bool Wrapper::checkIfCarOnTrack(void) {
    bool ontrack = false;
    for(int i = 0; i < trackPieces.size(); i++) {
        if(checkForCollision(car1, trackPieces[i])) {
            ontrack = true;
        }
    }
    return ontrack;
}

void Wrapper::quitEverything(void) {
    IMG_Quit();
    delete trackStorage;
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
    if(mode == 2) {
        if(e.type == SDL_MOUSEBUTTONUP) {
            if(e.button.button == SDL_BUTTON_LEFT) {
                if(SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LSHIFT]) {
                    std::cout << "fired!\n";
                    int index = whichTrackPieceMouseOn();
                    if(index != -1) { // Make sure it's not already on a track piece
                        delete trackPieces[index];
                        trackPieces.erase(trackPieces.begin() + index);
                    }
                }
                else {
                    int x, y, roundedX, roundedY;
                    SDL_GetMouseState(&x, &y);
                    roundedX = (x / 50) * 50;
                    roundedY = (y / 50) * 50;
                    if(whichTrackPieceMouseOn() == -1) { // Make sure it's not already on a track piece
                        trackPieces.push_back(new TrackPiece(renderer, roundedX, roundedY, true));
                    }
                }

            }
            else if(e.button.button == SDL_BUTTON_RIGHT) {
                std::cout << "right clicked\n";
                int trackPieceIndex = whichTrackPieceMouseOn();
                if(trackPieceIndex != -1) {
                    trackPieces[trackPieceIndex]->toggleOrientation();
                    std::cout << "Toggled orientation" << std::endl;
                }
            }
            else if(e.button.button == SDL_BUTTON_RIGHT) {
                std::cout << "right clicked\n";
                int trackPieceIndex = whichTrackPieceMouseOn();
                if(trackPieceIndex != -1) {
                    trackPieces[trackPieceIndex]->toggleOrientation();
                    std::cout << "Toggled orientation" << std::endl;
                }
            }
        }
    }

}

void Wrapper::handleKeyEvent(SDL_Event e) {
    if(e.type == SDL_KEYUP) {
        if(e.key.keysym.sym == SDLK_m) {
            if(mode == 1) {
                std::cout << "mode changed to editing\n";
                mode = 2; // track editing mode
            }
            else if(mode == 2) {
                std::cout << "mode changed to playing\n";
                mode = 1; // track editing mode
            }
        }
        else if(e.key.keysym.sym == SDLK_w) {
            if(mode == 2) {
                trackStorage->setTrackPieces(trackPieces);
                trackStorage->writeToFile();

            }

        }
        if(e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_q) {
            std::cout << "Started quitting\n";
            quitEverything();
        }
    }

}

void Wrapper::deleteDrawables(void) {
    delete car1;

    for(int i = 0; i < trackPieces.size(); i++) {
        delete trackPieces[i];
    }
}

void Wrapper::handleMouseMotionEvent(SDL_Event e) {
    car1->setPosition(e.motion.x - (car1->getWidth() / 2), e.motion.y - (car1->getWidth() / 2));
}

void Wrapper::handleMouseWheelEvent(SDL_Event e) {

}

void Wrapper::handleWindowEvent(SDL_Event e) {

}

void Wrapper::drawEverything() {
    for(int i = 0; i < trackPieces.size(); i++) {
        SDL_RenderCopy(renderer, trackPieces[i]->getTexture(), NULL, trackPieces[i]->getRect());
        SDL_RenderDrawRect(renderer, trackPieces[i]->boundingBoxes[1]);
    }

    SDL_RenderCopy(renderer, car1->getTexture(), NULL, car1->getRect());

    // Priority sorting has not been implemented yet. nor will it ever be
}





