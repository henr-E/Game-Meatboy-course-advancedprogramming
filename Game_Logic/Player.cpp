//
// Created by henri kerch on 13/11/2022.
//

#include "Player.h"
Player::Player() {

    horizontalSpeed = 0;
    verticalSpeed = 0;

    gravity = 2;
    // Set the Bob's starting position
    playerPosition.x = -1;
    playerPosition.y = -0.875;

    direction = facingRight;

    jumping = false;
    playerWon = false;

    keyboardLeft = false;
    keyboardRight = false;
    keyboardJump = false;
}

const Position& Player::getPlayerPosition() const { return playerPosition; }

void Player::updateFromKeyboard(KeyboardInput keyboardInput) {
    switch (keyboardInput) {
    case pressMoveLeft:
        direction = facingLeft;
        if (!hitLeftWall) {
            keyboardLeft = true;
            horizontalSpeed = 0.5;
        }
        break;
    case releaseMoveLeft:
        keyboardLeft = false;
        break;
    case pressMoveRight:
        direction = facingRight;
        if (!hitRightWall) {
            keyboardRight = true;
            horizontalSpeed = 0.5;
            cout << "keyboardRight = true" <<endl;
        }
        break;
    case releaseMoveRight:
        keyboardRight = false;
        cout << "keyboardRight = false" <<endl;
        break;
    case pressJump:
        // how bigger the absolute value of verticalSpeed how higher player jumps
        // playerPosition.y += verticalSpeed * elapsedTime;
        if(!jumping or hitLeftWall or hitRightWall or collision.collisionLeft or collision.collisionRight){
            verticalSpeed = -100;
            jumping = true;
        }

        /*
         * the verticalspeed must be changed here and not in the run function
         * because if user presses 'space', the loop is going to keep simulating the player
         * even if user released space. This means that if the verticalSpeed would be changed in
         * player.sumulate(), the speed would be overwritten every time and would never change
         */
        break;
    case releaseJump:
//        keyboardJump = false;
        break;
    case noKey:
        break;
    default:
        cout << "Failed to load keyboard input" << endl;
    }
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Player::simulate(float elapsedTime, const Collision &c) {
    if (keyboardRight and !c.collisionRight ) {
        playerPosition.x += horizontalSpeed * elapsedTime;
    }

    if (keyboardLeft and !c.collisionLeft ) {
        playerPosition.x -= horizontalSpeed * elapsedTime;
    }
    if (jumping){
        if(!c.collisionUp or !c.collisionDown){
            verticalSpeed += gravity;
            playerPosition.y += verticalSpeed * elapsedTime;
        }else if (c.collisionUp){
            verticalSpeed = -verticalSpeed;
        }else if (c.collisionDown){
            verticalSpeed = 0;
            jumping = false;
        }
    }

//            // if the player is against the right wall and not on a tile
//            if (hitRightWall) {
//                playerPosition.x -= verticalSpeed * elapsedTime;
//            }
//            // if the player is against the left wall and not on a tile
//            //else if because player can never be on rightwall and leftwall at the same time
//            else if (hitLeftWall) {
//                playerPosition.x += verticalSpeed * elapsedTime;
//            }

    checkTileAndBorderCollision(c);
}
void Player::checkTileAndBorderCollision(const Collision &c) {
    /*
     * (-1,-1)         (1,-1)
     * _______________
     * |              |
     * |
     * |
     * |
     * |______________|
     * (-1,1)          (1,1)
     */
    // collisionWithGround
    if (playerPosition.y > 1) {
        playerPosition.y = 1;
        verticalSpeed = 0;
    }

    // collisionRightWall
    if (playerPosition.x > 1) {
        playerPosition.x = 1;
        hitRightWall = true;
        horizontalSpeed = 0;
    }
    // collisionLeftWall
    if (playerPosition.x < -1) {
        playerPosition.x = -1;
        hitLeftWall = true;
        horizontalSpeed = 0;
    }
    // no collisionWithWalls
    if (-1 < playerPosition.x and playerPosition.x < 1) {
        hitRightWall = false;
        hitLeftWall = false;
    }

}
Direction Player::getDirection() const { return direction; }
bool Player::isPlayerWon() const { return playerWon; }