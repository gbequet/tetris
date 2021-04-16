#include "GraphicsObject.h"


// Constructeur
GraphicsObject::GraphicsObject() : 
    x(0), y(0), current_tile_(0)
{
}


// Constructeur avec paramètres
GraphicsObject::GraphicsObject(int a, int b) :
    x(a), y(b), current_tile_(0)
{
}


// Destructor
GraphicsObject::~GraphicsObject()
{
}


// Getters Position X
int GraphicsObject::getPositionX() const
{
    return x;
}


// Getters Position Y
int GraphicsObject::getPositionY() const
{
    return y;
}


// Getters forme du bloc courant
int GraphicsObject::getCurTile() const
{
    return current_tile_;
}


// Setters Position X
void GraphicsObject::setPositionX(int pValue)
{
    x = pValue;
}


// Setters Position Y
void GraphicsObject::setPositionY(int pValue)
{
    y = pValue;
}


// Setters donner rotation pour la forme
void GraphicsObject::setCurTile(int pValue)
{
    current_tile_ = pValue;
}
