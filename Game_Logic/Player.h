//
// Created by henri kerch on 13/11/2022.
//
#pragma once

#ifndef INC_2022_PROJECT_HENREY_T_PLAYER_H
#define INC_2022_PROJECT_HENREY_T_PLAYER_H

#include "Interval.h"
#include "structures_enums_std_include.h"
using namespace std;
class Player {
    Interval interval;
    Collision collision;
    Direction direction;

    int playerHeight_Width;
    Position playerPosition;

    //this is for collision; the position will not be higher than de values
    int playerMaximumRight;
    int playerMaximumLeft;
    int playerMaximumUp;
    int playerMaximumDown;

//    int jumpAngle = 45;

    float verticalSpeed;
    float horizontalSpeed;

    double acceleration;
    ///applied to gradually slow down the upwards vertical movement after a jump,
    /// and will eventually cause the Player to fall back down
    float gravity;


    ///when the Player hits a wall the horizontal speed must be 0
    bool hitLeftWall;
    bool hitRightWall;
    bool onTile;
    bool jumping;

    bool playerWon;




//    ///when the Player hits the ceiling the vertical speed negates: v = -v
//    bool hitCeiling;

    /// Which direction(s) is the player currently moving in
    bool keyboardLeft;
    bool keyboardRight;
    bool keyboardJump;


public:

    // We will set Bob up in the constructor
    Player();

    void updateFromKeyboard(KeyboardInput keyboardInput);
    // We will call this function once every frame
    void simulate(float elapsedTime, vector<int> tiles);

    const Position &getPlayerPosition() const;

//    void checkOnTile();
//    void checkHitWall();

//    void changeSpeedOnHitWall();

    void calculateTileCollision(const vector<int> &tiles);
    void checkTileAndBorderCollision();

    Direction getDirection() const;
    bool isPlayerWon() const;
};


#endif //INC_2022_PROJECT_HENREY_T_PLAYER_H
