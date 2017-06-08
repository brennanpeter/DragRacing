#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#pragma once
class DrawableWithPriority {
public:
    DrawableWithPriority(SDL_Renderer * &renderer, std::string image, int x, int y, int w, int h, int newPriority);
    ~DrawableWithPriority();
    DrawableWithPriority(const DrawableWithPriority& other);
    DrawableWithPriority& operator=(const DrawableWithPriority& other);
    void setXPosition(int x);
    void setYPosition(int y);
    void setHeight(int h);
    void setWidth(int w);
    void setVelocity(double downward, double rightward);
    void modifyVelocity(double deltaX, double deltaY);
    void onUpdate(void);
    void setPosition(int x, int y);
    SDL_Texture * getTexture(void);
    int getXPosition(void);
    int getYPosition(void);
    int getHeight(void);
    int getWidth(void);
    std::vector<SDL_Rect *> boundingBoxes;
    SDL_Rect * getRect(void);

protected:
private:
    SDL_Surface * surface;
    SDL_Texture * texture;
    SDL_Rect rect;

    int priority;
    double downwardVelocity;
    double rightwardVelocity;


};

