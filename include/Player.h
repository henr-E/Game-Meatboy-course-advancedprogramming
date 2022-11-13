//
// Created by henri kerch on 13/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_PLAYER_H
#define INC_2022_PROJECT_HENREY_T_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

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

class Player {

    Vector2f playerPosition;

//    int jumpAngle = 45;

    float verticalSpeed;
    float horizontalSpeed;

//    double maxVerticalSpeed;
//    double maxHorizontalSpeed;

    double acceleration;
    ///applied to gradually slow down the upwards vertical movement after a jump,
    /// and will eventually cause the Player to fall back down
    float gravity;

    bool onGround;
//
//    bool horizontalJump;
    ///when the Player hits a wall the horizontal speed must be 0
    bool hitWall;
//    ///when the Player hits the ceiling the vertical speed negates: v = -v
//    bool hitCeiling;
//    ///when the Player lands on the floor the vertical speed must be 0
//    bool landingOnFloor;

    /// Which direction(s) is the player currently moving in
    bool keyboardLeft;
    bool keyboardRight;
    bool keyboardJump;


public:

    // We will set Bob up in the constructor
    Player();

    void updateFromKeyboard(KeyboardInput keyboardInput);
    // We will call this function once every frame
    void simulate(float elapsedTime);

    const Vector2f &getPlayerPosition() const;

    void checkOnGroundAfterJump();
    void checkHitWall();

};



#endif //INC_2022_PROJECT_HENREY_T_PLAYER_H
