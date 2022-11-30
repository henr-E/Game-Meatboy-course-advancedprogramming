//
// Created by henri kerch on 13/11/2022.
//
#pragma once

#ifndef INC_2022_PROJECT_HENREY_T_PLAYER_H
#define INC_2022_PROJECT_HENREY_T_PLAYER_H

#include "iostream"
#include "Rectangle.h"
using namespace std;
class Player : Rectangle{
    Direction direction;

//    int jumpAngle = 45;

    float verticalSpeed;
    float horizontalSpeed;

    double acceleration;
    ///applied to gradually slow down the upwards vertical movement after a jump,
    /// and will eventually cause the Player to fall back down
    float gravity;



    bool jumping;

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

    void checkTileAndBorderCollision();

    Direction getDirection() const;
    bool isPlayerWon() const;

    virtual bool intersects(const Rectangle &that);


    virtual Position getLeftUpperCorner() const;
    virtual void setLeftUpperCorner(Position leftUpperCorner);

    virtual Position getRightDownCorner() const;
    virtual void setRightDownCorner(Position rightDownCorner);

    void setCollision(const Collision& collision);
};


#endif //INC_2022_PROJECT_HENREY_T_PLAYER_H
