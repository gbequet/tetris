#ifndef _SHAPES_H_
#define _SHAPES_H_

#include <vector>
#include <utility>
#include "GraphicsObject.h"

namespace Shapes
{
    /////////////
    // Shape T //
    /////////////
    class ShapeT : public GraphicsObject
    {
    public:
        ShapeT();
        ShapeT(int x, int y);
        virtual ~ShapeT();

    protected:

    private:
        int current_rotation_;
    };
}

#endif