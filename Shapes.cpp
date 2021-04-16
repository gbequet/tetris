#include "Shapes.h"

using namespace Shapes;

/////////////
// Shape T //
/////////////

// Fonction pour créer le bloc T

ShapeT::ShapeT() : 
    GraphicsObject(), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(0, 1)};
    tiles_[1] = {std::make_pair(-1, 1), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2)};
    tiles_[2] = {std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[3] = {std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2), std::make_pair(1, 1)};
}


ShapeT::ShapeT(int x, int y) :
    GraphicsObject(x, y), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(0, 1)};
    tiles_[1] = {std::make_pair(-1, 1), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2)};
    tiles_[2] = {std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[3] = {std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2), std::make_pair(1, 1)};
}


ShapeT::~ShapeT()
{
}


/////////////
// Shape Z //
/////////////

// Fonction pour créer le bloc Z

ShapeZ::ShapeZ() : 
    GraphicsObject(), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[1] = {std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(-1, 2)};
    tiles_[2] = tiles_[0];
    tiles_[3] = tiles_[1];
}


ShapeZ::ShapeZ(int x, int y) : 
    GraphicsObject(x, y), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[1] = {std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(-1, 2)};
    tiles_[2] = tiles_[0];
    tiles_[3] = tiles_[1];
}


ShapeZ::~ShapeZ()
{
}


/////////////
// Shape I //
/////////////

// Fonction pour créer le bloc I

ShapeI::ShapeI() :
    GraphicsObject(), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[1] = {std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(-1, 2)};
    tiles_[2] = tiles_[0];
    tiles_[3] = tiles_[1];
}


ShapeI::ShapeI(int x, int y): 
    GraphicsObject(x, y), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(2, 0)};
    tiles_[1] = {std::make_pair(-1, 0), std::make_pair(-1, 1), std::make_pair(-1, 2), std::make_pair(-1, 3)};
    tiles_[2] = tiles_[0];
    tiles_[3] = tiles_[1];
}


ShapeI::~ShapeI()
{
}


/////////////
// Shape O //
/////////////

// Fonction pour créer le bloc O

ShapeO::ShapeO(): 
    GraphicsObject(), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1)};
    tiles_[1] = tiles_[0];
    tiles_[2] = tiles_[0];
    tiles_[3] = tiles_[0];
}


ShapeO::ShapeO(int x, int y) : 
    GraphicsObject(x, y), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1)};
    tiles_[1] = tiles_[0];
    tiles_[2] = tiles_[0];
    tiles_[3] = tiles_[0];
}


ShapeO::~ShapeO()
{
}


/////////////
// Shape L //
/////////////

// Fonction pour créer le bloc L

ShapeL::ShapeL() : 
    GraphicsObject(), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(-1, 1)};
    tiles_[1] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2)};
    tiles_[2] = {std::make_pair(0, 1), std::make_pair(-1, 1), std::make_pair(1, 0), std::make_pair(1, 1)};
    tiles_[3] = {std::make_pair(-1, 0), std::make_pair(-1, 1), std::make_pair(-1, 2), std::make_pair(0, 2)};
}


ShapeL::ShapeL(int x, int y) :
    GraphicsObject(x, y), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(-1, 1)};
    tiles_[1] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2)};
    tiles_[2] = {std::make_pair(0, 1), std::make_pair(-1, 1), std::make_pair(1, 0), std::make_pair(1, 1)};
    tiles_[3] = {std::make_pair(-1, 0), std::make_pair(-1, 1), std::make_pair(-1, 2), std::make_pair(0, 2)};
}


ShapeL::~ShapeL()
{
}


/////////////
// Shape J //
/////////////

// Fonction pour créer le bloc J

ShapeJ::ShapeJ() : 
    GraphicsObject(), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(1, 1)};
    tiles_[1] = {std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2), std::make_pair(-1, 2)};
    tiles_[2] = {std::make_pair(-1, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[3] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(-1, 2)};
}


ShapeJ::ShapeJ(int x, int y) :
    GraphicsObject(x, y), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(1, 1)};
    tiles_[1] = {std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2), std::make_pair(-1, 2)};
    tiles_[2] = {std::make_pair(-1, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[3] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(-1, 2)};
}


ShapeJ::~ShapeJ()
{
}


/////////////
// Shape S //
/////////////

// Fonction pour créer le bloc S

ShapeS::ShapeS() :
    GraphicsObject(), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(0, 1), std::make_pair(-1, 1)};
    tiles_[1] = {std::make_pair(-1, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(0, 2)};
    tiles_[2] = tiles_[0];
    tiles_[3] = tiles_[1];
}


ShapeS::ShapeS(int x, int y) :
    GraphicsObject(x, y), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(0, 1), std::make_pair(-1, 1)};
    tiles_[1] = {std::make_pair(-1, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(0, 2)};
    tiles_[2] = tiles_[0];
    tiles_[3] = tiles_[1];
}


ShapeS::~ShapeS()
{
}
