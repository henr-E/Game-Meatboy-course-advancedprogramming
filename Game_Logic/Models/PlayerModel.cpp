//
// Created by henri kerch on 08/12/2022.
//
#include "PlayerModel.h"
PlayerModel::PlayerModel() {
    horizontalSpeed = 0;
    verticalSpeed = 0;
    acceleration = 0.1;
    gravity = 0.01;

    /**
     * if there are 17 tiles in width then the size of one tile is 2/17 because the
     * coodinate system is [-1,1]
     *
     * 2/17 in coordinates = 32 in pixels
     * => 32/272 = (2/17)
     *
     * but player is 26 pixels
     * => 26/272
     */
    tileHeightWidth = 26.f/272.f;


    // set rectangle members
    leftUpperCorner.x = -1;
    leftUpperCorner.y = -1 + tileHeightWidth;
    rightDownCorner.x = -1 + tileHeightWidth;
    rightDownCorner.y = -1;


    direction = facingRight;

    previousLeftUpperCorner = leftUpperCorner;

    keyboardLeft = false;
    keyboardRight = false;
    jumpWallLeft = false;
    jumpWallRight = false;
}

void PlayerModel::updateFromKeyboard(KeyboardInput keyboardInput) {
    switch (keyboardInput) {
    case pressMoveLeft:
        direction = facingLeft;
        keyboardLeft = true;
        horizontalSpeed = 0.7;
        break;

    case releaseMoveLeft:
        keyboardLeft = false;
        break;

    case pressMoveRight:
        direction = facingRight;
        keyboardRight = true;
        horizontalSpeed = 0.7;
        break;

    case releaseMoveRight:
        keyboardRight = false;
        break;

    case pressJump:
        if(verticalSpeed == 0){
            verticalSpeed = -0.7;
            acceleration = 0.02;
        }

        if(!collision.collisionDown){
            if(collision.collisionRight){
                horizontalSpeed = 0.7;
                jumpWallRight = true;
                direction = facingLeft;
            }
            if(collision.collisionLeft){
                horizontalSpeed = 0.7;
                jumpWallLeft = true;
                direction = facingRight;
            }
        }
        break;

    case releaseJump:
        cout << "RELEASE" <<endl;
    case noKey:
        break;
    default:
        cout << "Failed to load keyboard input" << endl;
        break;
    }

}


void PlayerModel::simulate(float elapsedTime) {
    previousLeftUpperCorner = leftUpperCorner;
    //landing
    if(collision.collisionDown and verticalSpeed > 0){
        verticalSpeed = 0;
        horizontalSpeed = 0;
        acceleration = 0;
        jumpWallLeft = false;
        jumpWallRight = false;
    }

    if (((keyboardRight and !collision.collisionRight) or jumpWallLeft ) and !jumpWallRight) {
//        cout << "jumpLEFT = " << jumpWallLeft <<endl;
//        cout << "acceleration" << acceleration <<endl;
//        cout << "horizontalSpeed" << horizontalSpeed <<endl;
        float add = horizontalSpeed * elapsedTime + (acceleration * powf(elapsedTime, 2))/2;
        leftUpperCorner.x += add;
        rightDownCorner.x += add;
    }
    if (((keyboardLeft and !collision.collisionLeft) or jumpWallRight) and !jumpWallLeft){
//        cout << "jumpRIGHT = " << jumpWallRight <<endl;
        float add = horizontalSpeed * elapsedTime + (acceleration * powf(elapsedTime, 2))/2;
        leftUpperCorner.x -= add;
        rightDownCorner.x -= add;
    }

    //jumping
    if(verticalSpeed != 0){
        verticalSpeed += gravity;
    }

    float add = verticalSpeed * elapsedTime + (acceleration * powf(elapsedTime, 2)) / 2;
    leftUpperCorner.y -= add;
    rightDownCorner.y -= add;


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
    if (collision.collisionUp and verticalSpeed < 0){
        //collision up can only occur when verticalspeed is negative so we make it positive
        verticalSpeed = -verticalSpeed;
    }

    if((collision.collisionRight or collision.collisionLeft) and !jumpWallLeft and !jumpWallRight ){
        horizontalSpeed = 0;
    }

}

bool PlayerModel::intersects(const Model& that, CheckCollision checkCollision) {

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
}

Direction PlayerModel::getDirection() const { return direction; }

void PlayerModel::setCollision(const Collision& collisionNew) { collision = collisionNew; }
void PlayerModel::updateObservers() { Model::updateObservers(); }
const Position& PlayerModel::getPreviousLeftUpperCorner() const { return previousLeftUpperCorner; }
