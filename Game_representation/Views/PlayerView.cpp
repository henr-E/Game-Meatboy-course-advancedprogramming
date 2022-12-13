//
// Created by henri kerch on 08/12/2022.
//

#include "PlayerView.h"

PlayerView::PlayerView(const shared_ptr<RenderWindow>& sfWindow)
    : View(sfWindow) {}

void PlayerView::update() {

    // make sprite and texture player
    // Associate a texture with the sprite
    // using 2 different sprites

    if (playerDirection == facingRight) {
        texturePlayer.loadFromFile("../content/meatboy.png");
    } else {
        texturePlayer.loadFromFile("../content/meatboyMirror.png");
    }
    texturePlayer.setSmooth(true);

    spritePlayer.setTexture(texturePlayer);

    // convert coordinates to pixels
    Position p = camera->coordinatesToPixel(playerPosition.x, playerPosition.y);
    // Now move the playerSprite to its new position
    spritePlayer.setPosition(p.x, p.y);
    // Draw the player
    sfWindow->draw(spritePlayer);

    sfWindow->display();
}
void PlayerView::updateData(Position position, Direction direction) {
    playerPosition = position;
    playerDirection = direction;
}

