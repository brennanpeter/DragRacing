#ifndef TRACKPIECESTORAGE_H
#define TRACKPIECESTORAGE_H

#include <fstream>
#include "TrackPiece.h"
class TrackPieceStorage
{
    public:
        TrackPieceStorage(SDL_Renderer * theRenderer);
        std::vector<TrackPiece *> * getTrackPieces(void);
        void readFromFile(void);
        void writeToFile(void);

        virtual ~TrackPieceStorage();
    protected:

    private:
        SDL_Renderer * renderer;
        std::vector<TrackPiece *> trackPieces;
};

#endif // TRACKPIECESTORAGE_H
