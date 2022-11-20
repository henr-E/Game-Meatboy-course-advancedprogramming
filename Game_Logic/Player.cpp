//
// Created by henri kerch on 13/11/2022.
//

#include "Player.h"
Player::Player(){

    horizontalSpeed = 1000;
    verticalSpeed = 100000;

    playerHeight_Width = 32;

    gravity = 0.5;
    onGround = true;

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
          keyboardLeft = true;
          break;
      case releaseMoveLeft:
          keyboardLeft = false;
          break;
      case pressMoveRight:
          keyboardRight = true;
          break;
        case releaseMoveRight:
          keyboardRight = false;
          break;
      case pressJump:
          if(onGround){
            keyboardJump = true;
            onGround = false;
            verticalSpeed = -100;
          }
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
void Player::simulate(float elapsedTime){
    if (keyboardRight){
        playerPosition.x += horizontalSpeed * elapsedTime;
    }
    if (keyboardLeft){
        playerPosition.x -= horizontalSpeed * elapsedTime;
    }
    if (keyboardJump){//TODO formule aanpassen voor gravity
        verticalSpeed += gravity;
        playerPosition.y += verticalSpeed * elapsedTime;
    }
    checkOnGroundAfterJump();
    checkHitWall();

}

void Player::checkOnGroundAfterJump(){
        if (playerPosition.y >= 960-playerHeight_Width){
            playerPosition.y = 960-playerHeight_Width;
            verticalSpeed = 0;
            onGround = true;
        }
}
void Player::checkHitWall(){
    if (playerPosition.x >= (544-playerHeight_Width)){
        playerPosition.x = 544-playerHeight_Width;
    }
    if (playerPosition.x <= 0){
        playerPosition.x = 0;
    }
}
