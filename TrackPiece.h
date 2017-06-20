#pragma once

#include "DrawableWithPriority.h"


class TrackPiece : public DrawableWithPriority {
public:
    TrackPiece(SDL_Renderer * &renderer, int x, int y, bool vert);
    void toggleOrientation(void);
    ~TrackPiece();
    friend std::ostream &operator<<( std::ostream &output, const TrackPiece &t );
protected:
private:
    void updateBoundingBox(void);
    bool vertical;
    int tx, ty;
};


