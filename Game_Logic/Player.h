//
// Created by henri kerch on 13/11/2022.
//
#pragma once

#ifndef INC_2022_PROJECT_HENREY_T_PLAYER_H
#define INC_2022_PROJECT_HENREY_T_PLAYER_H

#include "iostream"
#include "Rectangle.h"
#include <cmath>
using namespace std;
class Player : Rectangle{
    Direction direction;

//    int jumpAngle = 45;

    float verticalSpeed;
    float horizontalSpeed;

    float acceleration;
    ///applied to gradually slow down the upwards vertical movement after a inAir,
    /// and will eventually cause the Player to fall back down
    float gravity;

    bool playerWon;


    /// Which direction(s) is the player currently moving in
    bool keyboardLeft;
    bool keyboardRight;
    bool keyboardJump;

    Collision collision;


public:
    // We will set Bob up in the constructor
    Player();

    void updateFromKeyboard(KeyboardInput keyboardInput);

    // We will call this function once every frame
    void simulate(float elapsedTime);

    const Position & getPlayerLeftUpperPosition() const;


    Direction getDirection() const;
    bool isPlayerWon() const;

    virtual bool intersects(const Rectangle &that, CheckCollision checkCollision);


    virtual Position getLeftUpperCorner() const;
    virtual void setLeftUpperCorner(Position leftUpperCorner);

    virtual Position getRightDownCorner() const;
    virtual void setRightDownCorner(Position rightDownCorner);

    virtual float getTileHeightWidth() const;

    void setCollision(const Collision& collision);
};


#endif //INC_2022_PROJECT_HENREY_T_PLAYER_H
