//
// Created by henri kerch on 08/12/2022.
//

#include "PlayerView.h"
void PlayerView::update() {

    // make sprite and texture player
    // Associate a texture with the sprite
    // using 2 different sprites

//    if (model->getDirection() == facingRight) {
        texturePlayer.loadFromFile("../content/meatboy.png");
//    } else {
//        texturePlayer.loadFromFile("../content/meatboy_mirror.png");
//    }
    texturePlayer.setSmooth(true);

    spritePlayer.setTexture(texturePlayer);

    Position position = model.getLeftUpperCorner();
    // convert coordinates to pixels
    Position p = camera.coordinatesToPixel(position.x, position.y);
    // Now move the playerSprite to its new position
    spritePlayer.setPosition(p.x, p.y);
    // Draw the player
    sfWindow->draw(spritePlayer);
}

PlayerView::PlayerView(ownModel::Model& model) : View(model) {}
