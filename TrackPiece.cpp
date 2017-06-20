#pragma once
#include "TrackPiece.h"

TrackPiece::TrackPiece(SDL_Renderer * &renderer, int x, int y, bool vert) : DrawableWithPriority(renderer, "assets/images/trackpiece.jpg", x, y, 50, 50, 1) {
    boundingBoxes.push_back(new SDL_Rect());
    vertical = vert;
    tx = x;
    ty = y;
    updateBoundingBox();
}


void TrackPiece::toggleOrientation(void) {
    std::cout << vertical << std::endl;
    vertical = !vertical;
    std::cout << vertical << std::endl;
    updateBoundingBox();
}

void TrackPiece::updateBoundingBox(void) {
    if(vertical) {
        boundingBoxes[1]->x = tx + 22;
        boundingBoxes[1]->y = ty;
        boundingBoxes[1]->w = 5;
        boundingBoxes[1]->h = 50;
    }
    else {
        boundingBoxes[1]->x = tx;
        boundingBoxes[1]->y = ty + 22;
        boundingBoxes[1]->w = 50;
        boundingBoxes[1]->h = 5;
    }
}


std::ostream &operator<<( std::ostream &output, const TrackPiece &t ) {
    output << t.tx << "," << t.ty << "," << (int)t.vertical << std::endl;
    return output;
}

TrackPiece::~TrackPiece() {
    //dtor
}
