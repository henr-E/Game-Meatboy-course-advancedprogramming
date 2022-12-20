//
// Created by henri kerch on 22/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_STD_INCLUDE_H
#define INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_STD_INCLUDE_H

namespace ownType {
enum KeyboardInput {
    pressMoveLeft,
    pressMoveRight,
    releaseMoveLeft,
    releaseMoveRight,
    pressJump,
    releaseJump,
    esc,
    noKey
};

class Position {
public:
    /**
     * constructor
     */
    Position() = default;
    /**
     * constructor
     * @param x
     * @param y
     */
    Position(float x, float y) : x(x), y(y) {}

    /**
     * - operator
     * @param that
     * @return
     */
    Position operator-(const Position& that) const {
        Position newPos{};
        newPos.x = that.x - this->x;
        newPos.y = that.y - this->y;
        return newPos;
    }

    float x;
    float y;
};

class Collision {
public:
    bool collisionLeft = false;
    bool collisionRight = false;
    bool collisionUp = false;
    bool collisionDown = false;

    void setAllFalse() {
        collisionLeft = false;
        collisionRight = false;
        collisionUp = false;
        collisionDown = false;
    }
};

enum Direction { facingRight, facingLeft };

enum TileType { GIRL, BLOCK, NONE, PLAYER };

enum FunctionCallTo { DRAW, INPUT, SIMULATE };

class inputRectangles {
public:
    Position leftUpperCorner;
    Position rightDownCorner;

    TileType tileType;
    float tileHeightWidth;
};

struct CameraPositions {
    Position viewPosition;
    Position backgroundPosition;
};

enum MoveScreen { MOVE, NOMOVE, DEFAULT };
} // namespace ownType
#endif // INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_STD_INCLUDE_H