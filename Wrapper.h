#include "Car.h"
#include "TrackPiece.h"
#include "TrackPieceStorage.h"

#include "Contexts.h"
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
    void makeTrackLine(bool vertical, int lengthUnits, int startX, int startY);
    void makeTrack(void);
    void updateEverything(void);
    bool checkForCollision(DrawableWithPriority* obj1, DrawableWithPriority* obj2);
    bool checkIfCarOnTrack(void);
    int whichTrackPieceMouseOn(void);

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int mode;
    bool running;

    TrackPieceStorage * trackStorage;
    std::vector<TrackPiece *> trackPieces;
    Car * car1;
};

