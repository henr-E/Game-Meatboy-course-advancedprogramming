//
// Created by henri kerch on 24/11/2022.
//

#include "LevelState.h"
LevelState::LevelState() {
    // make level from input
    inputParser.parse(2);

    tiles = inputParser.getTiles();

    shared_ptr<AbstractFactory> conc = make_shared<ConcreteFactory>(sfWindow);

    //add absstractFactory
    world.setAbstractFactory(conc);
    //make player goal wall
    world.setUp(tiles);
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
    world.updatePlayerModel();
}

void LevelState::draw() {
    world.updateViews();
}

const Vector2i& LevelState::getScreenDimensions() const { return screenDimensions; }
