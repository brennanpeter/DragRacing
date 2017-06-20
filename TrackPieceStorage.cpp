#include "TrackPieceStorage.h"

TrackPieceStorage::TrackPieceStorage(SDL_Renderer * &theRenderer) {
    renderer = theRenderer;
    //ctor
}

TrackPieceStorage::~TrackPieceStorage() {
    //dtor
}

std::vector<TrackPiece*> TrackPieceStorage::getTrackPieces(void) {
    return trackPieces;
}

void TrackPieceStorage::readFromFile(void) {
    std::ifstream inFile;
    inFile.open("trackLayout.drag");
    std::string input;

    while(!(inFile.peek() == EOF || inFile.fail())) {
        // each line of the CSV will be formatted like this:
        // [x position],[y position],[orientation (1 for vertical, 0 for horizontal)]

        int x, y;
        bool orientation;
        std::getline(inFile, input, ','); // get the x position
        std::cout << input << std::endl;
        x = stoi(input);
        std::getline(inFile, input, ','); // get the y position
        y = stoi(input);
        std::getline(inFile, input); // get the orientation
        orientation = (bool)stoi(input);
        trackPieces.push_back(new TrackPiece(renderer, x, y, orientation));
    }
    inFile.close();
}


void TrackPieceStorage::setTrackPieces(std::vector<TrackPiece* > newTrack) {
    trackPieces = newTrack;
}



void TrackPieceStorage::writeToFile(void) {
    remove("trackLayout.drag");
    std::ofstream output;
    output.open("trackLayout.drag");
    for(int i = 0; i < trackPieces.size(); i++) {
        output << *(trackPieces[i]);

    }
}
