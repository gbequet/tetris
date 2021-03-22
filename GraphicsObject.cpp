#include "GraphicsObject.h"

// Constructor
GraphicsObject::GraphicsObject()
    : x(0), y(0), current_tile_(0)
{
}

GraphicsObject::GraphicsObject(int a, int b)
    : x(a), y(b), current_tile_(0)
{
}

// Destructor
GraphicsObject::~GraphicsObject()
{
}

// Position
int GraphicsObject::getPositionX() const
{
    return x;
}

int GraphicsObject::getPositionY() const
{
    return y;
}

int GraphicsObject::getCurTile() const
{
    return current_tile_;
}

void GraphicsObject::setPositionX(int pValue)
{
    x = pValue;
}

void GraphicsObject::setPositionY(int pValue)
{
    y = pValue;
}

void GraphicsObject::setCurTile(int pValue)
{
    current_tile_ = pValue;
}
