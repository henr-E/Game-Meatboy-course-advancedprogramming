//
// Created by henri kerch on 13/11/2022.
//

#include "Player.h"
Player::Player(){

    horizontalSpeed = 0;
    verticalSpeed = 0;

    playerHeight_Width = 32;

    gravity = 1;
    onGround = true;
    inAir = false;
    // Set the Bob's starting position
    playerPosition.x = 0;
    playerPosition.y = 960-playerHeight_Width;

    keyboardLeft = false;
    keyboardRight = false;
    keyboardJump = false;
}

const Vector2f & Player::getPlayerPosition() const{
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
              onGround = false;
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
void Player::simulate(float elapsedTime, Collision collision){
    if (keyboardRight and collision != collisionRight){
        playerPosition.x += horizontalSpeed * elapsedTime;
    }
    if (keyboardLeft and collision != collisionLeft){
        playerPosition.x -= horizontalSpeed * elapsedTime;
    }
    if (keyboardJump){//TODO formule aanpassen voor gravity
        if (collision == collisionUp or collision == collisionDown){
            verticalSpeed = 0;
        }
        verticalSpeed += gravity;
        playerPosition.y += verticalSpeed * elapsedTime;
        //add 45 degrees
        if(hitRightWall and !onGround){
            playerPosition.x -= verticalSpeed * elapsedTime;
        }
        else if(hitLeftWall and !onGround){
            playerPosition.x += verticalSpeed * elapsedTime;
        }
    }

    checkOnGround();
    checkHitWall();
    checkInAir();


}
void Player::checkInAir(){
//    if(onGround or hitRightWall or hitLeftWall){
//        inAir = true;
//    }else{
//        inAir = true;
//    }
}
void Player::checkOnGround(){
    if (playerPosition.y == 960-playerHeight_Width){
        onGround = true;
    }
    else if (playerPosition.y > 960-playerHeight_Width){
        playerPosition.y = 960-playerHeight_Width;
        verticalSpeed = 0;
        onGround = true;
    }else if (playerPosition.y < 960-playerHeight_Width){
        onGround = false;
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
int Player::getPlayerHeightWidth() const { return playerHeight_Width; }
