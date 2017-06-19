#include "TrackPieceStorage.h"

TrackPieceStorage::TrackPieceStorage(SDL_Renderer * theRenderer) {
    renderer = renderer;
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

    while(!(inFile.peek() != EOF || inFile.fail())) {
            // each line of the CSV will be formatted like this:
            // [x position],[y position],[orientation (1 for vertical, 0 for horizontal)], <--- note the comma at the end!

            int x, y;
            bool orientation;
            std::getline(inFile, input, ','); // get the x position
            std::cout << input;
            x = stoi(input);
            std::getline(inFile, input, ','); // get the x position
            y = stoi(input);
            std::getline(inFile, input, ','); // get the x position
            orientation = (bool)stoi(input);
            trackPieces.push_back(new TrackPiece(renderer, x, y, orientation));
    }
    inFile.close();



}

void TrackPieceStorage::writeToFile(void) {

}
