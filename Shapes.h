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

    /////////////
    // Shape Z //
    /////////////
    class ShapeZ : public GraphicsObject
    {
    public:
        ShapeZ();
        ShapeZ(int x, int y);
        virtual ~ShapeZ();

    protected:
    
    private:
        int current_rotation_;
    };

    /////////////
    // Shape I //
    /////////////
    class ShapeI : public GraphicsObject
    {
    public:
        ShapeI();
        ShapeI(int x, int y);
        virtual ~ShapeI();

    protected:
    
    private:
        int current_rotation_;
    };

    /////////////
    // Shape O //
    /////////////
    class ShapeO : public GraphicsObject
    {
    public:
        ShapeO();
        ShapeO(int x, int y);
        virtual ~ShapeO();

    protected:
    
    private:
        int current_rotation_;
    };

    /////////////
    // Shape L //
    /////////////
    class ShapeL : public GraphicsObject
    {
    public:
        ShapeL();
        ShapeL(int x, int y);
        virtual ~ShapeL();

    protected:
    
    private:
        int current_rotation_;
    };

    /////////////
    // Shape J //
    /////////////
    class ShapeJ : public GraphicsObject
    {
    public:
        ShapeJ();
        ShapeJ(int x, int y);
        virtual ~ShapeJ();

    protected:
    
    private:
        int current_rotation_;
    };


    /////////////
    // Shape S //
    /////////////
    class ShapeS : public GraphicsObject
    {
    public:
        ShapeS();
        ShapeS(int x, int y);
        virtual ~ShapeS();

    protected:
    
    private:
        int current_rotation_;
    };
}

#endif
