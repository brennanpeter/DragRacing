#include "DrawableWithPriority.h"

DrawableWithPriority::DrawableWithPriority()
{
    //ctor
}

DrawableWithPriority::~DrawableWithPriority()
{
    //dtor
}

DrawableWithPriority::DrawableWithPriority(const DrawableWithPriority& other)
{
    //copy ctor
}

DrawableWithPriority& DrawableWithPriority::operator=(const DrawableWithPriority& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
