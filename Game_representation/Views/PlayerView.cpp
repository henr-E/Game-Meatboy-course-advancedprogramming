//
// Created by henri kerch on 08/12/2022.
//

#include "PlayerView.h"

PlayerView::PlayerView(const Position& modelPosition, TileType modelTileType, const shared_ptr<RenderWindow>& sfWindow)
    : View(modelPosition, modelTileType, sfWindow) {
    /**
     * if texture for player moving right doesn exist, make rectangle
     */
    if(!playerTextureRight.loadFromFile("../content/meatboy.png")){
        playerTextureExistsRight = false;
        rectangle.setSize(Vector2f(26, 26));
        rectangle.setFillColor(Color::Red);
        cout << "Can't find file with playerTexture for player moving right => using red rectangle" <<endl;
    }
    else{
        playerTextureExistsRight = true;
        playerTextureRight.setSmooth(true);
        playerSpriteRight.setTexture(playerTextureRight);
    }

    if(!playerTextureLeft.loadFromFile("../content/meatboyMirror.png")){
        playerTextureExistsLeft = false;
        rectangle.setSize(Vector2f(26, 26));
        rectangle.setFillColor(Color::Red);
        cout << "Can't find file with playerTexture for player moving left => using red rectangle" <<endl;
    }
    else{
        playerTextureExistsLeft = true;
        playerTextureLeft.setSmooth(true);
        playerSpriteLeft.setTexture(playerTextureLeft);
    }



}

void PlayerView::update() {
    // convert coordinates to pixels
    Position p = camera->coordinatesToPixel(modelPosition.x, modelPosition.y);

    // make sprite and texture player
    // Associate a texture with the sprite
    // using 2 different sprites

    if(playerDirection == facingRight and playerTextureExistsRight) {
        // Now move the playerSprite to its new position
        playerSpriteRight.setPosition(p.x, p.y);
        // Draw the player
        sfWindow->draw(playerSpriteRight);
    }
    else if (playerDirection == facingLeft and playerTextureExistsLeft){
        // Now move the playerSprite to its new position
        playerSpriteLeft.setPosition(p.x, p.y);
        // Draw the player
        sfWindow->draw(playerSpriteLeft);
    }else{
        rectangle.setPosition(p.x, p.y);
        sfWindow->draw(rectangle);
    }
}
void PlayerView::updateData(Position position, Direction direction) {
    modelPosition = position;
    playerDirection = direction;
}
