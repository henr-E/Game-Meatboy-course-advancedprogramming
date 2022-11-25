//
// Created by henri kerch on 13/11/2022.
//

#include "Player.h"
Player::Player() {

    horizontalSpeed = 0;
    verticalSpeed = 0;

    playerHeight_Width = 32;

    gravity = 2;
    onTile = true;
    // Set the Bob's starting position
    playerPosition.x = 0;
    playerPosition.y = 960 - playerHeight_Width;

    playerMaximumLeft = 0;
    playerMaximumRight = 544;
    playerMaximumDown = 960 - 32;
    playerMaximumUp = 0;

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
            horizontalSpeed = 100;
        }
        break;
    case releaseMoveLeft:
        keyboardLeft = false;
        break;
    case pressMoveRight:
        direction = facingRight;
        if (!hitRightWall) {
            keyboardRight = true;
            horizontalSpeed = 100;
        }
        break;
    case releaseMoveRight:
        keyboardRight = false;
        break;
    case pressJump:
        // how bigger the absolute value of verticalSpeed how higher player jumps
        // playerPosition.y += verticalSpeed * elapsedTime;
        if (collision.collisionDown){

        }
        if(onTile or !jumping or hitLeftWall or hitRightWall or collision.collisionLeft or collision.collisionRight){
            verticalSpeed = -100;
            jumping = true;
            onTile = false;
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
        printf("Failed to load keyboard input");
    case esc:
        break;
    }
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Player::simulate(float elapsedTime, vector<int> tiles) {
    if (keyboardRight) {
        playerPosition.x += horizontalSpeed * elapsedTime;
    }
    if (keyboardLeft) {
        playerPosition.x -= horizontalSpeed * elapsedTime;
    }


    if (jumping) { // TODO formule aanpassen voor gravity

        /*
         * 3 cases:
         * 1 = on a tile/against right or left wall on tile
         * 2 = against left wall and not on tiles
         * 3 = against right wall and not on tiles
         */
        //jump up in a straight line

            verticalSpeed += gravity;
            playerPosition.y += verticalSpeed * elapsedTime;

//            // if the player is against the right wall and not on a tile
//            if (hitRightWall) {
//                playerPosition.x -= verticalSpeed * elapsedTime;
//            }
//            // if the player is against the left wall and not on a tile
//            //else if because player can never be on rightwall and leftwall at the same time
//            else if (hitLeftWall) {
//                playerPosition.x += verticalSpeed * elapsedTime;
//            }


    }

    checkTileAndBorderCollision();
    calculateTileCollision(tiles);

}
void Player::checkTileAndBorderCollision() {

    // collisionRight
    if (playerPosition.x >= playerMaximumRight - 32 and collision.collisionRight) {
        playerPosition.x = playerMaximumRight - 32;
    }
    // collisionLeft
    if (playerPosition.x <= playerMaximumLeft and collision.collisionLeft) {
        playerPosition.x = playerMaximumLeft;
    }


    // tileCollisionUp
    if (playerPosition.y <= playerMaximumUp and collision.collisionUp) {
        playerPosition.y = playerMaximumUp;
    }
    // tileCollisionDown
    if (playerPosition.y >= playerMaximumDown - 32  and collision.collisionDown) {
        playerPosition.y = playerMaximumDown - 32;
    }
    //todo jump onTile doesnt work
    if (collision.collisionDown){
        onTile = true;
    }
    if (!collision.collisionDown and playerPosition.y < 960 - playerHeight_Width){
        onTile = false;
    }

    // collisionWithGround
    if (playerPosition.y > 960 - playerHeight_Width) {
        playerPosition.y = 960 - playerHeight_Width;
        verticalSpeed = 0;
        onTile = true;
    }



    // collisionRightWall
    if (playerPosition.x > (544 - playerHeight_Width)) {
        playerPosition.x = 544 - playerHeight_Width;
        hitRightWall = true;
    }
    // collisionLeftWall
    if (playerPosition.x < 0) {
        playerPosition.x = 0;
        hitLeftWall = true;
    }
    // no collisionWithWalls
    if (0 < playerPosition.x and playerPosition.x < (544 - playerHeight_Width)) {
        hitRightWall = false;
        hitLeftWall = false;
    }

}

void Player::calculateTileCollision(const vector<int>& tiles) {

    /*
     * there is only collision when the player is
     */
    /*
     *
     * 1002
     * 0000
     * 3004
     *
     * if the above example is our vertexArray and one tile is 32 pixels
     * 1 = (0,0)
     * 3 = (0,64)
     * 2 = (96,0)
     * 4 = (96,64)
     *
     * in the tileMap vector indexes are:
     * the indexes are column by column
     * 1 = 0
     * 2 = 9
     * 3 = 2
     * 4 = 1&
     *
     */

    int rowInTileMap = static_cast<int>((playerPosition.y + 32)/ 32);
    int columnInTileMap = static_cast<int>(playerPosition.x / 32);

    // index of tile where player is now
    // multiply the player row with the width and add amount of columns
    int currentIndex = columnInTileMap + (rowInTileMap - 1) * 17;

    int rightIndex = currentIndex + 1;
    int leftIndex = currentIndex - 1;
    int upIndex = currentIndex - 17;
    int downIndex = currentIndex + 17;

    int currentTile = tiles[currentIndex];


    int rightTile = 100;
    int leftTile = 100;
    int upTile = 100;
    int downTile = 100;


    if (playerPosition.x < (544 - 32)) {
        rightTile = tiles[rightIndex];
    }
    // check if player is not against left wall
    if (playerPosition.x > 32) {
        leftTile = tiles[leftIndex];
    }
    // check if player is not against ceiling
    if (playerPosition.y > 32) {
        upTile = tiles[upIndex];
    }
    // check if player is not against ground
    if (playerPosition.y < 960 - 32) {
        downTile = tiles[downIndex];
    }
    if(upTile == 1){

    }
    /*
     * the player coordinate (x,y) is in the players left upper corner
     * if there is a block on x = 64
     * then the player cant move past x = 64
     * BUT because the x coordinate of the player is in the left upper corner we have to change
     * the rightValue to rightValue-32
     * => rightValue = 32
     * => leftValue = 32
     */

    int rightValue = interval.calculateLeftRight(playerPosition.x).rightValue;
    int leftValue = interval.calculateLeftRight(playerPosition.x).leftValue;
    /*
     * if y value is 35 than upvalue = 32 and downvalue = 64
     */

    int upValue = interval.calculateUpDown(playerPosition.y).upValue;
    int downValue = interval.calculateUpDown(playerPosition.y).downValue;

    if (currentTile == 0){
        playerWon = true;
    }
    // check if player is not against right wall
    //-32 because the player is 32 in width
    if (rightTile == 1 and playerPosition.x < (544 - 32)) {
        playerMaximumRight = rightValue;
        collision.collisionRight = true;
    }
    // check if player is not against left wall
    if (leftTile == 1 and playerPosition.x > 0) {
        playerMaximumLeft = leftValue;
        collision.collisionLeft = true;
    }
    // check if player is not against ceiling
    if (upTile == 1 and playerPosition.y > 0) {
        playerMaximumUp = upValue;
        collision.collisionUp = true;
    }
    // check if player is not against ground
    if (downTile == 1 and playerPosition.y < 960) {
        playerMaximumDown = downValue;
        collision.collisionDown = true;
    }

    if (rightTile != 1){
        collision.collisionRight = false;
        playerMaximumRight = 544;
    }
    if(leftTile != 1){
        collision.collisionLeft = false;
        playerMaximumLeft = 0;
    }
    if(upTile != 1){
        collision.collisionUp = false;
        playerMaximumUp = 0;
    }
    if(downTile != 1) {
        collision.collisionDown = false;
        playerMaximumDown = 960 - 32;
    }
}
Direction Player::getDirection() const { return direction; }
bool Player::isPlayerWon() const { return playerWon; }