//
// Created by henri kerch on 13/11/2022.
//

#include "Player.h"
Player::Player() {

    horizontalSpeed = 0;
    verticalSpeed = 0;
    acceleration = 0.1;
    gravity = 0.01;

    // set rectangle members
    leftUpperCorner.x = -1;
    leftUpperCorner.y = -0.875;
    rightDownCorner.x = -0.875;
    rightDownCorner.y = -1;
    //player height width
    tileHeightWidth = 2.f/17.f;

    direction = facingRight;

    playerWon = false;

    keyboardLeft = false;
    keyboardRight = false;
    keyboardJump = false;
}
void Player::updateFromKeyboard(KeyboardInput keyboardInput) {
    switch (keyboardInput) {
    case pressMoveLeft:
        direction = facingLeft;
        keyboardLeft = true;
        horizontalSpeed = 0.5;
        break;

    case releaseMoveLeft:
        keyboardLeft = false;
        break;

    case pressMoveRight:
        direction = facingRight;
        keyboardRight = true;
        horizontalSpeed = 0.5;
        break;

    case releaseMoveRight:
        keyboardRight = false;
        break;

    case pressJump:
        if(verticalSpeed == 0){
            keyboardJump = true;
            verticalSpeed = -0.5;
            acceleration = 0.01;
            horizontalSpeed = 0;
        }
//        if((collision.collisionRight or collision.collisionLeft) and !collision.collisionDown){
//            keyboardJump = true;
//            horizontalSpeed = 0.5;
//            acceleration = 0.01;
//        }
        break;

    case releaseJump:
        keyboardJump = false;
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

    if (keyboardRight and !collision.collisionRight) {
        float add = horizontalSpeed * elapsedTime + (acceleration * powf(elapsedTime, 2))/2;
        leftUpperCorner.x += add;
        rightDownCorner.x += add;
    }
    if (keyboardLeft and !collision.collisionLeft) {
        float add = horizontalSpeed * elapsedTime + (acceleration * powf(elapsedTime, 2))/2;
        leftUpperCorner.x -= add;
        rightDownCorner.x -= add;
    }

    float add = verticalSpeed * elapsedTime + (acceleration * powf(elapsedTime, 2)) / 2;
    verticalSpeed += gravity;

    //todo should jump hirozontally until speed is 0
    //landing
    if(collision.collisionDown and verticalSpeed >= 0){
        verticalSpeed = 0;
        acceleration = 0;
    }


    leftUpperCorner.y -= add;
    rightDownCorner.y -= add;

//    if((collision.collisionRight or collision.collisionLeft) and !collision.collisionDown){
//        add = horizontalSpeed * elapsedTime + (acceleration * powf(elapsedTime, 2))/2;
//
//        if(collision.collisionRight){
//            leftUpperCorner.x -= add;
//            rightDownCorner.x -= add;
//        }
//        if(collision.collisionLeft){
//            leftUpperCorner.x += add;
//            rightDownCorner.x += add;
//        }
//    }


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
    if (collision.collisionUp){
        verticalSpeed = -verticalSpeed;
    }

//    //check hit bottom
//    if(rightDownCorner.y < -1){
//        rightDownCorner.y = -1;
//        leftUpperCorner.y = -1 + (2.f/17.f);
//    }
    if(collision.collisionRight or collision.collisionLeft){
        horizontalSpeed = 0;
    }
}

bool Player::intersects(const Rectangle& that, CheckCollision checkCollision) {

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

    float playerXLeft= leftUpperCorner.x;
    float playerXRight= rightDownCorner.x;

    float playerYUp= leftUpperCorner.y;
    float playerYDown= rightDownCorner.y;


    //check the 4 player corners

    //check LEFT DOWN CORNER
    if(thatXLeft <= playerXLeft and playerXLeft <= thatXRight
        and thatYDown <= playerYDown and playerYDown <= thatYUp){
        return true;
    }
    //check Right DOWN CORNER
    if(thatXLeft <= playerXRight and playerXRight <= thatXRight
        and thatYDown <= playerYDown and playerYDown <= thatYUp){
        return true;
    }

    //check LEFT UP CORNER
    if(thatXLeft <= playerXLeft and playerXLeft <= thatXRight
        and thatYDown <= playerYUp and playerYUp <= thatYUp){
        return true;
    }
    //check Right UP CORNER
    if(thatXLeft <= playerXRight and playerXRight <= thatXRight
        and thatYDown <= playerYUp and playerYUp <= thatYUp){
        return true;
    }
    return false;





//    //playerTile collision on X
//    if(thatXLeft <= leftUpperCorner.x and leftUpperCorner.x <= thatXRight
//        and thatYDown <= leftUpperCorner.y and leftUpperCorner.y <= thatYUp){
//        return true;
//    }
//    if(thatXLeft <= rightDownCorner.x and rightDownCorner.x <= thatXRight
//        and thatYDown <= rightDownCorner.y and rightDownCorner.y <= thatYUp){
//        return true;
//    }
//    return false;
}



const Position& Player::getPlayerLeftUpperPosition() const { return leftUpperCorner; }
Direction Player::getDirection() const { return direction; }
bool Player::isPlayerWon() const { return playerWon; }


Position Player::getLeftUpperCorner() const { return Rectangle::getLeftUpperCorner(); }
void Player::setLeftUpperCorner(Position leftUpperCorner) { Rectangle::setLeftUpperCorner(leftUpperCorner); }
Position Player::getRightDownCorner() const { return Rectangle::getRightDownCorner(); }
void Player::setRightDownCorner(Position rightDownCorner) { Rectangle::setRightDownCorner(rightDownCorner); }
void Player::setCollision(const Collision& collision) { Player::collision = collision; }
float Player::getTileHeightWidth() const {
    return tileHeightWidth;
}
