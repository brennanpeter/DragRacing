#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#pragma once
class DrawableWithPriority
{
    public:
        DrawableWithPriority();
        ~DrawableWithPriority();
        DrawableWithPriority(const DrawableWithPriority& other);
        DrawableWithPriority& operator=(const DrawableWithPriority& other);


    protected:
    private:
        SDL_Surface surface;



};

