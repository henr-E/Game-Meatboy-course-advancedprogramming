//
// Created by henri kerch on 13/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_PLAYER_H
#define INC_2022_PROJECT_HENREY_T_PLAYER_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Player {

    Vector2f playerPosition;

    int jumpAngle = 45;
    double verticalSpeed;
    double horizontalSpeed;
    double maxVerticalSpeed;
    double maxHorizontalSpeed;
    double acceleration;
    ///applied to gradually slow down the upwards vertical movement after a jump, and will eventually cause the Player to fall back down
    double gravity;

    bool horizontalJump;
    ///when the Player hits a wall the horizontal speed must be 0
    bool hitWall;
    ///when the Player hits the ceiling the vertical speed negates: v = -v
    bool hitCeiling;
    ///when the Player lands on the floor the vertical speed must be 0
    bool landingOnFloor;

    /// Of course we will need a sprite
    Sprite spritePlayer;

    /// And a texture
    /// player has been working out and he is now a bit more muscular than before
    /// Furthermore, he fancies himself in lumberjack attire
    Texture texturePlayer;

    /// Which direction(s) is the player currently moving in
    bool leftPressed;
    bool rightPressed;


public:

    // We will set Bob up in the constructor
    Player();

    // Send a copy of the sprite to main
    Sprite getSprite();

    // Move Bob in a specific direction
    void moveLeft();

    void moveRight();

    // Stop Bob moving in a specific direction
    void stopLeft();

    void stopRight();

    // We will call this function once every frame
    void update(float elapsedTime);

};



#endif //INC_2022_PROJECT_HENREY_T_PLAYER_H
