#pragma once

#include "DrawableWithPriority.h"


class TrackPiece : public DrawableWithPriority {
public:
    TrackPiece(SDL_Renderer * &renderer, int x, int y, bool vert);
    ~TrackPiece();
protected:
private:
    bool vertical;
};
