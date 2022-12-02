//
// Created by henri kerch on 30/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_RECTANGLE_H
#define INC_2022_PROJECT_HENREY_T_RECTANGLE_H

#include "structures_enums_std_include.h"

class Rectangle {
private:

protected:
    Position leftUpperCorner;
    Position rightDownCorner;

    TileType tileType;
    float tileHeightWidth;

public:
    virtual Position getLeftUpperCorner() const;
    virtual void setLeftUpperCorner(Position leftUpperCorner);

    virtual Position getRightDownCorner() const;
    virtual void setRightDownCorner(Position rightDownCorner);

    TileType getTileType() const;
    void setTileType(TileType tileType);

    virtual float getTileHeightWidth() const;
    void setTileHeightWidth(float tileHeightWidth);

    virtual bool intersects(const Rectangle &that, CheckCollision checkCollision);
};

#endif // INC_2022_PROJECT_HENREY_T_RECTANGLE_H
