#include "Shapes.h"

using namespace Shapes;

/////////////
// Shape T //
/////////////

ShapeT::ShapeT()
    : GraphicsObject(), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(0, 1)};
    tiles_[1] = {std::make_pair(-1, 1), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2)};
    tiles_[2] = {std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[3] = {std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2), std::make_pair(1, 1)};
}

ShapeT::ShapeT(int x, int y)
    : GraphicsObject(x, y), current_rotation_(0)
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

ShapeZ::ShapeZ()
    : GraphicsObject(), current_rotation_(0)
{
    tiles_.resize(4);
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[1] = {std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(-1, 2)};
    tiles_[2] = tiles_[0];
    tiles_[3] = tiles_[1];
}

ShapeZ::ShapeZ(int x, int y)
    : GraphicsObject(x, y), current_rotation_(0)
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
