//
// Created by henri kerch on 22/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_STD_INCLUDE_H
#define INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_STD_INCLUDE_H

enum KeyboardInput{
    pressMoveLeft,
    pressMoveRight,
    releaseMoveLeft,
    releaseMoveRight,
    pressJump,
    releaseJump,
    esc,
    noKey
};

struct CoordinateInterval{
    int leftValue;
    int rightValue;
    int upValue;
    int downValue;
};

struct Position{
    float x;
    float y;
};
class Collision {
public:
    bool collisionLeft = false;
    bool collisionRight = false;
    bool collisionUp = false;
    bool collisionDown = false;

    bool collisionUpperLeft = false;
    bool collisionUpperRight = false;
    bool collisionDownLeft = false;
    bool collisionDownRight = false;

    void setAllFalse(){
        collisionLeft = false;
        collisionRight = false;
        collisionUp = false;
        collisionDown = false;

        collisionUpperLeft = false;
        collisionUpperRight = false;
        collisionDownLeft = false;
        collisionDownRight = false;
    }
};
enum Direction{
    facingRight,
    facingLeft
};

enum MouseInput {
    rightClick,
    leftClick,
    noClick
};

#endif // INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_STD_INCLUDE_H