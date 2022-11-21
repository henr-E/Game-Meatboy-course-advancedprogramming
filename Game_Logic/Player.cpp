//
// Created by henri kerch on 13/11/2022.
//

#include "Player.h"
Player::Player(){

    horizontalSpeed = 0;
    verticalSpeed = 0;

    playerHeight_Width = 32;

    gravity = 2;
    onTile = true;
    inAir = false;
    // Set the Bob's starting position
    playerPosition.x = 0;
    playerPosition.y = 960-playerHeight_Width;

    playerMaximumXLeft = 0;
    playerMaximumXRight = 544;

    keyboardLeft = false;
    keyboardRight = false;
    keyboardJump = false;
}

const Position & Player::getPlayerPosition() const{
 return playerPosition;
}

void Player::updateFromKeyboard(KeyboardInput keyboardInput){
    switch(keyboardInput) {
      case pressMoveLeft:
          if(!hitLeftWall){
              keyboardLeft = true;
              horizontalSpeed = 100;
          }
          break;
      case releaseMoveLeft:
          keyboardLeft = false;
          break;
      case pressMoveRight:
          if(!hitRightWall) {
              keyboardRight = true;
              horizontalSpeed = 100;
          }
          break;
        case releaseMoveRight:
          keyboardRight = false;
          break;
      case pressJump:
//          if (!inAir) {
              inAir = true;
              onTile = false;
              keyboardJump = true;
              /*
               * the verticalspeed must be changed here and not in the simulate function
               * because if user presses 'space', the loop is going to keep simulating the player
               * even if user released space. This means that if the verticalSpeed would be changed in
               * player.sumulate(), the speed would be overwritten every time and would never change
               */
              //how bigger the absolute value of verticalSpeed how higher player jumps
              //playerPosition.y += verticalSpeed * elapsedTime;
              verticalSpeed = -100;
//          }
          break;
      case releaseJump:
          keyboardJump = false;
          break;
      case noKey:
          break;
      default:
          printf("Failed to load keyboard input");
          exit(EXIT_FAILURE);
    }
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Player::simulate(float elapsedTime, vector<int> tiles){
    if (keyboardRight){
        playerPosition.x += horizontalSpeed * elapsedTime;
    }
    if (keyboardLeft){
        playerPosition.x -= horizontalSpeed * elapsedTime;
    }
    if (keyboardJump){//TODO formule aanpassen voor gravity
//        if (collision == collisionUp or collision == collisionDown){
//            verticalSpeed = 0;
//        }
        verticalSpeed += gravity;
        playerPosition.y += verticalSpeed * elapsedTime;
        //add 45 degrees
        if(hitRightWall and !onTile){
            playerPosition.x -= verticalSpeed * elapsedTime;
        }
        else if(hitLeftWall and !onTile){
            playerPosition.x += verticalSpeed * elapsedTime;
        }
    }
    checkCollision();
    calculateCollision(tiles);
    checkOnGround();
    checkHitWall();
    checkInAir();

}
void Player::checkInAir(){
//    if(onTile or hitRightWall or hitLeftWall){
//        inAir = true;
//    }else{
//        inAir = true;
//    }
}
void Player::checkOnGround(){
    if (playerPosition.y == 960-playerHeight_Width){
        onTile = true;
    }
    else if (playerPosition.y > 960-playerHeight_Width){
        playerPosition.y = 960-playerHeight_Width;
        verticalSpeed = 0;
        onTile = true;
    }else if (playerPosition.y < 960-playerHeight_Width){
        onTile = false;
    }
}
void Player::checkHitWall(){
    //hitting the right wall
    if (playerPosition.x >= (544-playerHeight_Width)){
        playerPosition.x = 544-playerHeight_Width;
        hitRightWall = true;
    }
    //hitting the left wall
    else if (playerPosition.x <= 0){
        playerPosition.x = 0;
        hitLeftWall = true;
    }
    //not hitting walls
    else{
        hitRightWall = false;
        hitLeftWall = false;
    }
}
void Player::changeSpeedOnHitWall() {
    if (hitLeftWall or hitRightWall){
        horizontalSpeed = 0;
    }
}
void Player::checkCollision() {
    if(playerPosition.x >= playerMaximumXRight){
        playerPosition.x = playerMaximumXRight;
    }
    if(playerPosition.x <= playerMaximumXLeft){
        playerPosition.x = playerMaximumXLeft;
    }

}

void Player::calculateCollision(const vector<int> &tiles) {
//    collision = noCollision;

    float playerPositionX = playerPosition.x;
    float playerPositionY = playerPosition.y + 32;

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

    int rowInTileMap = static_cast<int>(playerPositionY / 32);
    int columnInTileMap = static_cast<int>(playerPositionX / 32);

    //index of tile where player is now
    //multiply the player row with the width and add amount of columns
    int currentIndex = columnInTileMap + (rowInTileMap - 1) * 17;


    int rightIndex = currentIndex + 1;
    int leftIndex = currentIndex - 1;
    int upIndex = currentIndex - 17;
    int downIndex = currentIndex + 17;

    int rightTile = tiles[rightIndex];
    int leftTile = tiles[leftIndex];
    int upTile = tiles[upIndex];
    int downTile = tiles[downIndex];

    int rightValue = interval.calculateRight(playerPositionX - 16);
    int leftValue = interval.calculateLeft(playerPositionX);



    /*
     * |
     * |
     * |
     * |
     * |
     * |o
     * we need to check if player o is against the wall/bottom/ceiling so by example
     * when the player is against the left wall there is no left collission
     */
    //check if player is not against right wall
    if(rightTile == 1 and playerPositionX < (544 - 32)){
        playerMaximumXRight = rightValue;
//        collision = collisionRight;

        cout << "collisionRight" <<endl;
    }
    //check if player is not against left wall
    if(leftTile == 1 and playerPositionX > 32){
        playerMaximumXLeft = leftValue;
        cout << "currentTile = "<< tiles[currentIndex] << endl;
        cout << "playerPsotisionX = " << playerPositionX << endl;
//        collision = collisionLeft;
    }
    //check if player is not against ceiling
    if(upTile == 1 and playerPositionY > 32){
//        collision = collisionUp;
    }
    //check if player is not against ground
    if(downTile == 1 and playerPositionY < (960 - 32)){
//        collision = collisionDown;
    }

    if(rightTile!= 1 and leftTile != 1 and upTile != 1 and downTile != 1){
        playerMaximumXRight = 544;
        playerMaximumXLeft = 0;
    }
}