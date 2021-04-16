#ifndef _GRAPHICS_OBJECT_H_
#define _GRAPHICS_OBJECT_H_

#include <vector>
#include <utility>

class GraphicsObject
{
    public:
        // Desctructor
        virtual ~GraphicsObject();

        // Position
        int getPositionX() const;
        int getPositionY() const;
        int getCurTile() const;
        void setPositionX(int pValue);
        void setPositionY(int pValue);
        void setCurTile(int pValue);

        using TCoordinate = std::pair<int, int>;
        using TShape = std::vector<TCoordinate>;
        using TRotatedShapes = std::vector<TShape>;
        TRotatedShapes tiles_;

    protected:
        // Constructor
        GraphicsObject();
        GraphicsObject(int a, int b);

    private:
        // Position
        int x;
        int y;
        int current_tile_; // configuration courante
};

#endif
