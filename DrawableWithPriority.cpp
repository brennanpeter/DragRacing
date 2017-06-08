#include "DrawableWithPriority.h"

DrawableWithPriority::DrawableWithPriority(SDL_Renderer * &renderer, std::string image, int x, int y, int w, int h, int newPriority) {
    surface = IMG_Load(image.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    priority = newPriority;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

DrawableWithPriority::~DrawableWithPriority() {
    SDL_FreeSurface(surface);
    std::cout << "Deleted";
    // There might be other cleanup that needs to occur here.
}


int DrawableWithPriority::getXPosition(void) {
    return rect.x;
}

int DrawableWithPriority::getYPosition(void) {
    return rect.y;
}

int DrawableWithPriority::getHeight(void) {
    return rect.h;
}

int DrawableWithPriority::getWidth(void) {
    return rect.w;
}

SDL_Rect * DrawableWithPriority::getRect(void) {
    return &rect;
}

SDL_Texture * DrawableWithPriority::getTexture(void) {
    return texture;
}

void DrawableWithPriority::setXPosition(int x) {
    rect.x = x;
}

void DrawableWithPriority::setYPosition(int y) {
    rect.y = y;
}

void DrawableWithPriority::setHeight(int h) {
    rect.h = h;
}

void DrawableWithPriority::setWidth(int w) {
    rect.w = w;
}


DrawableWithPriority::DrawableWithPriority(const DrawableWithPriority& other) {
    //copy ctor
    // obviously not yet implemented yet
}

DrawableWithPriority& DrawableWithPriority::operator=(const DrawableWithPriority& rhs) {
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
