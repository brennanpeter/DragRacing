#ifndef TRACKPIECESTORAGE_H
#define TRACKPIECESTORAGE_H

#include <fstream>
#include "TrackPiece.h"
class TrackPieceStorage
{
    public:
        TrackPieceStorage();
        std::vector<TrackPiece *> * getTrackPieces(void);
        void readFromFile(void);
        void writeToFile(void);

        virtual ~TrackPieceStorage();
    protected:

    private:
        std::vector<TrackPiece *> trackPieces;
};

#endif // TRACKPIECESTORAGE_H
