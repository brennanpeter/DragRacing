#include "Car.h"

Car::Car(SDL_Renderer * &renderer) : DrawableWithPriority(renderer, "assets/images/car.png", 300, 300, 25, 25, 1) {
    boundingBoxes.push_back(getRect());
}

Car::~Car() {

}
