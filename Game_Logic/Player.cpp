//
// Created by henri kerch on 13/11/2022.
//

#include "Player.h"
Player::Player() {

    horizontalSpeed = 0;
    verticalSpeed = 0;

    gravity = 2;
    // Set the Bob's starting position
    leftUpperCorner.x = -1;
    leftUpperCorner.y = -0.875;

    rightDownCorner.x = -0.875;
    rightDownCorner.y = -1;

    direction = facingRight;

    jumping = false;
    playerWon = false;

    keyboardLeft = false;
    keyboardRight = false;
    keyboardJump = false;
}
void Player::updateFromKeyboard(KeyboardInput keyboardInput) {
    switch (keyboardInput) {
    case pressMoveLeft:
        direction = facingLeft;
        if (!collision.collisionLeftWall) {
            keyboardLeft = true;
            horizontalSpeed = 0.5;
        }
        break;
    case releaseMoveLeft:
        keyboardLeft = false;
        break;
    case pressMoveRight:
        direction = facingRight;
        if (!collision.collisionRightWall) {
            keyboardRight = true;
            horizontalSpeed = 0.5;
        }
        break;
    case releaseMoveRight:
        keyboardRight = false;
        break;
    case pressJump:
        // how bigger the absolute value of verticalSpeed how higher player jumps
        // playerPosition.y += verticalSpeed * elapsedTime;
        if(!jumping or collision.collisionLeftWall or collision.collisionRightWall or collision.collisionLeft or collision.collisionRight){
            verticalSpeed = -100;
            jumping = true;
        }
        break;
    case releaseJump:
        //keyboardJump = false;
    case noKey:
        break;
    default:
        cout << "Failed to load keyboard input" << endl;
        break;
    }

}

// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Player::simulate(float elapsedTime) {

    if (keyboardRight and !collision.collisionRight and !collision.collisionRightWall) {
        leftUpperCorner.x += horizontalSpeed * elapsedTime;
        rightDownCorner.x += horizontalSpeed * elapsedTime;
    }

    if (keyboardLeft and !collision.collisionLeft and !collision.collisionLeftWall) {
        leftUpperCorner.x -= horizontalSpeed * elapsedTime;
        rightDownCorner.x -= horizontalSpeed * elapsedTime;
    }
    if (jumping){
        if(!collision.collisionUp or !collision.collisionDown){
            verticalSpeed += gravity;
            leftUpperCorner.y += verticalSpeed * elapsedTime;
            rightDownCorner.y += verticalSpeed * elapsedTime;
        }else if (collision.collisionUp){
            verticalSpeed = -verticalSpeed;
        }else if (collision.collisionDown){
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

    checkTileAndBorderCollision();
}
void Player::checkTileAndBorderCollision() {
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
    if (collision.collisionBottom) {
        leftUpperCorner.y = -0.875;;
        rightDownCorner.y = -1;
        verticalSpeed = 0;
    }

    // collisionRightWall
    if (collision.collisionRightWall) {
        horizontalSpeed = 0;
    }
    // collisionLeftWall
    if (collision.collisionLeftWall) {
        horizontalSpeed = 0;
    }
}

bool Player::intersects(const Rectangle& that) {

    /*
     *  _______
     * |        |
     * |        |
     * |______  |
     * Xleft    Xright
     */


    float thatXLeft= that.getLeftUpperCorner().x;
    float thatXRight= that.getRightDownCorner().x;

    float thatYUp= that.getLeftUpperCorner().y;
    float thatYDown= that.getRightDownCorner().y;
    bool intersection = false;
    //playerTile collision on X
    if(thatXLeft <= leftUpperCorner.x and leftUpperCorner.x <= thatXRight
        and thatYDown <= leftUpperCorner.y and leftUpperCorner.y <= thatYUp){
        intersection = true;
    }
    if(thatXLeft <= rightDownCorner.x and rightDownCorner.x <= thatXRight
        and thatYDown <= rightDownCorner.y and rightDownCorner.y <= thatYUp){
        intersection = true;
    }
    return intersection;
}



const Position& Player::getPlayerLeftUpperPosition() const { return leftUpperCorner; }
Direction Player::getDirection() const { return direction; }
bool Player::isPlayerWon() const { return playerWon; }


Position Player::getLeftUpperCorner() const { return Rectangle::getLeftUpperCorner(); }
void Player::setLeftUpperCorner(Position leftUpperCorner) { Rectangle::setLeftUpperCorner(leftUpperCorner); }
Position Player::getRightDownCorner() const { return Rectangle::getRightDownCorner(); }
void Player::setRightDownCorner(Position rightDownCorner) { Rectangle::setRightDownCorner(rightDownCorner); }
void Player::setCollision(const Collision& collision) { Player::collision = collision; }

