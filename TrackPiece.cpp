#pragma once
#include "TrackPiece.h"

TrackPiece::TrackPiece(SDL_Renderer * &renderer, int x, int y, bool vert) : DrawableWithPriority(renderer, "assets/images/trackpiece.jpg", x, y, 50, 50, 1) {
    boundingBoxes.push_back(new SDL_Rect());
    vertical = vert;
    if(vert) {
        boundingBoxes[1]->x = x + 22;
        boundingBoxes[1]->y = y;
        boundingBoxes[1]->w = 5;
        boundingBoxes[1]->h = 50;
    }
    else {
        boundingBoxes[1]->x = x;
        boundingBoxes[1]->y = y + 22;
        boundingBoxes[1]->w = 50;
        boundingBoxes[1]->h = 5;
    }



}

TrackPiece::~TrackPiece() {
    //dtor
}
