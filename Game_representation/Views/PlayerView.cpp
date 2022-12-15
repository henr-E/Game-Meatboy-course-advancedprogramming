//
// Created by henri kerch on 08/12/2022.
//

#include "PlayerView.h"

PlayerView::PlayerView(const Position& modelPosition, TileType modelTileType, const shared_ptr<RenderWindow>& sfWindow)
    : View(modelPosition, modelTileType, sfWindow) {}

void PlayerView::update() {

    // make sprite and texture player
    // Associate a texture with the sprite
    // using 2 different sprites

    if (playerDirection == facingRight) {
        modelTexture.loadFromFile("../content/meatboy.png");
    } else {
        modelTexture.loadFromFile("../content/meatboyMirror.png");
    }
    modelTexture.setSmooth(true);

    modelSprite.setTexture(modelTexture);

    // convert coordinates to pixels
    Position p = camera->coordinatesToPixel(modelPosition.x, modelPosition.y);
    // Now move the playerSprite to its new position
    modelSprite.setPosition(p.x, p.y);
    // Draw the player
    sfWindow->draw(modelSprite);
}
void PlayerView::updateData(Position position, Direction direction) {
    modelPosition = position;
    playerDirection = direction;
}
PlayerView::~PlayerView() {}
