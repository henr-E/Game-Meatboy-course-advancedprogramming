//
// Created by henri kerch on 24/11/2022.
//

#include "LevelState.h"
LevelState::LevelState() {
    // make Player
    Player player;
    // add player
    world.setPlayer(player);

    // make level from input
    inputParser.parse(2);

    tiles = inputParser.getTiles();

    view.setUpLevelState(textureBackground, spriteBackground, screenDimensions);
}

void LevelState::userInput(Event &event) {
    /*
     * make a keyboardinput object (enum). Assign nokey to it because if not assigned it takes pressMoveRight
     * and the player will move even though there are no keys pressed
     */
    keyboardInput = noKey;
    if (event.type == Event::KeyPressed) {
        // Escape
        if (event.key.code == Keyboard::Escape) {
            transition = true;
            return;
        }
        // Space
        if (event.key.code == Keyboard::Space)
            keyboardInput = pressJump;

        // Left arrow
        if (event.key.code == Keyboard::Left)
            keyboardInput = pressMoveLeft;

        // Right arrow
        if (event.key.code == Keyboard::Right)
            keyboardInput = pressMoveRight;
    }

    if (event.type == Event::KeyReleased) {
        // Space
        if (event.key.code == Keyboard::Space)
            keyboardInput = releaseJump;

        // Left arrow
        if (event.key.code == Keyboard::Left)
            keyboardInput = releaseMoveLeft;

        // Right arrow
        if (event.key.code == Keyboard::Right)
            keyboardInput = releaseMoveRight;
    }
    // pass keyboard to player
    world.keyboardToPlayer(keyboardInput);
}

void LevelState::simulate() {
    // run world
    world.simulate(inputParser.getTiles());
}

void LevelState::draw() { view.drawLevelState(spriteBackground, texturePlayer, world, spritePlayer, camera, tiles);}

void LevelState::updateView() {
    View view;

    view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
    //    view.setViewport(FloatRect(0,0,0.5,1.0));

    Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);

    //    float Position = world.getPlayer().getPlayerLeftUpperPosition().y;
    const Position playerPosition = world.getPlayer().getPlayerLeftUpperPosition();

    /* coordinates
     * (0,0)         (532,0)
     * |_________________|
     * |
     * |
     * |
     * |________________\
     * |                |
     * |________________|
     * (0,800)         (532,800)
     */
    // the position is the left side of meatboy so to get the middle we have to add half of meat boy = 25
    if (playerPosition.y + 16 < screenDimensions.y / 2) {
        position.y = playerPosition.y + 16;
    } else {
        position.y = screenDimensions.y / 2;
    }

    view.setCenter(position);

    // set the view
    sfWindow->setView(view);
}
const vector<vector<Rectangle>>& LevelState::getTiles() const { return tiles; }
const World& LevelState::getWorld() const { return world; }
const Texture& LevelState::getTextureBackground() const { return textureBackground; }
const Sprite& LevelState::getSpriteBackground() const { return spriteBackground; }
const Sprite& LevelState::getSpritePlayer() const { return spritePlayer; }
const Texture& LevelState::getTexturePlayer() const { return texturePlayer; }
const Camera& LevelState::getCamera() const { return camera; }
const Vector2i& LevelState::getScreenDimensions() const { return screenDimensions; }
