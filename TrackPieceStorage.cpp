#include "TrackPieceStorage.h"

TrackPieceStorage::TrackPieceStorage() {
    //ctor
}

TrackPieceStorage::~TrackPieceStorage() {
    //dtor
}

std::vector<TrackPiece*> * TrackPieceStorage::getTrackPieces(void) {
    return &trackPieces;
}

void TrackPieceStorage::readFromFile(void) {
    std::ifstream inFile;
    inFile.open("trackLayout.drag");
    std::string input;
    while(!(inFile.eof() || inFile.fail())) {
            int x, y;
            bool orientation;
            std::getline(inFile, input, ',');

    }




}

void TrackPieceStorage::writeToFile(void) {

}
