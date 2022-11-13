//
// Created by henri kerch on 13/11/2022.
//

#include "Player.h"
Player::Player(){
    // How fast does Bob move?
    horizontalSpeed = 20;

    // Associate a texture with the sprite
    texturePlayer.loadFromFile("../content/meatboy.png");
    spritePlayer.setTexture(texturePlayer);

    // Set the Bob's starting position
    playerPosition.x = 0;
    playerPosition.y = 0;

    leftPressed = false;
    rightPressed = false;
}


Sprite Player::getSprite(){
    return spritePlayer;
}

void Player::moveLeft(){
    leftPressed = true;
}

void Player::moveRight(){
    rightPressed = true;
}

void Player::stopLeft(){
    leftPressed = false;
}

void Player::stopRight(){
    rightPressed = false;
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Player::update(float elapsedTime){
    if (rightPressed)
    {
        playerPosition.x += horizontalSpeed * elapsedTime;
    }

    if (leftPressed)
    {
        playerPosition.x -= horizontalSpeed * elapsedTime;
    }

    // Now move the sprite to its new position
    spritePlayer.setPosition(playerPosition);
}
