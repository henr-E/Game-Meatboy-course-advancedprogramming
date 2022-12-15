//
// Created by henri kerch on 22/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_STD_INCLUDE_H
#define INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_STD_INCLUDE_H

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
    Position() {}
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

//    bool collisionUpperLeft = false;
//    bool collisionUpperRight = false;
//    bool collisionDownLeft = false;
//    bool collisionDownRight = false;

//    bool collisionRightWall = false;
//    bool collisionLeftWall= false;
//    bool collisionBottom = false;

    void setAllFalse() {
        collisionLeft = false;
        collisionRight = false;
        collisionUp = false;
        collisionDown = false;

//        collisionUpperLeft = false;
//        collisionUpperRight = false;
//        collisionDownLeft = false;
//        collisionDownRight = false;

//        collisionRightWall = false;
//        collisionLeftWall= false;
//        collisionBottom = false;
    }
};

enum Direction { facingRight, facingLeft };

enum MouseInput { rightClick, leftClick, noClick };

enum TileType { GIRL, BLOCK, NONE, PLAYER };

enum CheckCollision {Up, Down, Left, Right, Check};

enum CurrentState {
    levelstate,
    menustate
};

enum FunctionCallTo{
    DRAW,
    INPUT,
    SIMULATE
};

class inputRectangles{
public:
    Position leftUpperCorner;
    Position rightDownCorner;

    TileType tileType;
    float tileHeightWidth;
};
#endif // INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_STD_INCLUDE_H