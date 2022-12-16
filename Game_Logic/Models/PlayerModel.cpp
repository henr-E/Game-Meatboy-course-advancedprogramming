//
// Created by henri kerch on 08/12/2022.
//
#include "PlayerModel.h"
PlayerModel::PlayerModel() {
    horizontalSpeed = 0;
    verticalSpeed = 0;
    accelerationX = 0;
    accelerationY = 0;
    gravity = 0.02;


    direction = facingRight;

    previousLeftUpperCorner = leftUpperCorner;

    keyboardLeft = false;
    keyboardRight = false;
    jumpWallLeft = false;
    jumpWallRight = false;
}
PlayerModel::~PlayerModel() {}

void PlayerModel::updateFromKeyboard(KeyboardInput keyboardInput) {
    switch (keyboardInput) {
    case pressMoveLeft:
        direction = facingLeft;
        keyboardLeft = true;
        horizontalSpeed = -0.7;
        accelerationX = 0.1;
        break;

    case releaseMoveLeft:
        keyboardLeft = false;
        break;

    case pressMoveRight:
        direction = facingRight;
        keyboardRight = true;
        horizontalSpeed = 0.7;
        accelerationX = 0.1;
        break;

    case releaseMoveRight:
        keyboardRight = false;
        break;

    case pressJump:
        if(verticalSpeed == 0){
            verticalSpeed = -0.7;
            accelerationY = 0.02;
        }

        if(!collision.collisionDown){
            if(collision.collisionRight){
                horizontalSpeed = -0.7;
                verticalSpeed = -0.7;
                jumpWallRight = true;
                direction = facingLeft;
            }
            if(collision.collisionLeft){
                horizontalSpeed = 0.7;
                verticalSpeed = -0.7;
                jumpWallLeft = true;
                direction = facingRight;
            }
        }
        break;

    case releaseJump:
//        cout << "RELEASE" <<endl;
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
        accelerationY = 0;
        horizontalSpeed = 0;
        accelerationX = 0;
        jumpWallLeft = false;
        jumpWallRight = false;
    }
    //moving left and hitting a wall on the left
    if(horizontalSpeed < 0 and collision.collisionLeft){
        horizontalSpeed = 0;
        accelerationX = 0;
        jumpWallRight = false;
    }
    if(horizontalSpeed > 0 and collision.collisionRight){
        horizontalSpeed = 0;
        accelerationX = 0;
        jumpWallLeft = false;
    }

    if (((keyboardRight and !collision.collisionRight) or jumpWallLeft ) and !jumpWallRight) {
//        cout << "jumpLEFT = " << jumpWallLeft <<endl;
//        cout << "acceleration" << acceleration <<endl;
//        cout << "horizontalSpeed" << horizontalSpeed <<endl;
        float add = horizontalSpeed * elapsedTime + (accelerationX * powf(elapsedTime, 2))/2;
        leftUpperCorner.x += add;
        rightDownCorner.x += add;
    }
    if (((keyboardLeft and !collision.collisionLeft) or jumpWallRight) and !jumpWallLeft){
//        cout << "jumpRIGHT = " << jumpWallRight <<endl;
        float add = horizontalSpeed * elapsedTime + (accelerationX * powf(elapsedTime, 2))/2;
        leftUpperCorner.x += add;
        rightDownCorner.x += add;
    }

    //jumping
    if(!collision.collisionDown){
        verticalSpeed += gravity;
    }

//    cout << "gravity: " << gravity << endl;
//    cout << "acceleration: " << accelerationY   << endl;
//    cout << "verticalSpeed: " << verticalSpeed << endl;
    float addVertical = verticalSpeed * elapsedTime + (accelerationY * powf(elapsedTime, 2)) / 2;
//    cout << "add: " << addVertical << endl;
    leftUpperCorner.y -= addVertical;
    rightDownCorner.y -= addVertical;


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
}

bool PlayerModel::intersects(const shared_ptr<Model>& that) {

    /*
     *  _______
     * |        |
     * |        |
     * |______  |
     * Xleft    Xright
     */

    float thatXLeft= that->getLeftUpperCorner().x;
    float thatXRight= that->getRightDownCorner().x;

    float thatYUp= that->getLeftUpperCorner().y;
    float thatYDown= that->getRightDownCorner().y;

    float playerXLeft= leftUpperCorner.x;
    float playerXRight= rightDownCorner.x;

    float playerYUp= leftUpperCorner.y;
    float playerYDown= rightDownCorner.y;


    bool collides = false;

    //check LEFT DOWN CORNER
    if(thatXLeft <= playerXLeft and playerXLeft <= thatXRight
        and thatYDown <= playerYDown and playerYDown <= thatYUp){
        collides = true;
    }
    //check Right DOWN CORNER
    if(thatXLeft <= playerXRight and playerXRight <= thatXRight
        and thatYDown <= playerYDown and playerYDown <= thatYUp){
        collides = true;
    }

    //check LEFT UP CORNER
    if(thatXLeft <= playerXLeft and playerXLeft <= thatXRight
        and thatYDown <= playerYUp and playerYUp <= thatYUp){
        collides = true;
    }
    //check Right UP CORNER
    if(thatXLeft <= playerXRight and playerXRight <= thatXRight
        and thatYDown <= playerYUp and playerYUp <= thatYUp){
        collides = true;
    }

    return collides;
}

Direction PlayerModel::getDirection() const { return direction; }
void PlayerModel::setCollision(const Collision& collisionNew) { collision = collisionNew; }
const Position& PlayerModel::getPreviousLeftUpperCorner() const { return previousLeftUpperCorner; }

