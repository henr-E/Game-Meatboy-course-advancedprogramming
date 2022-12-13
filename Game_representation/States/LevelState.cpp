//
// Created by henri kerch on 24/11/2022.
//

#include "LevelState.h"
LevelState::LevelState(const shared_ptr<RenderWindow>& sfWindow) : State(sfWindow) {

    // make level from input
    inputParser.parse(3);

    tiles = inputParser.getTiles();

    screenDimensions = inputParser.getScreenDimensions();

    camera->setScreenDimensions(screenDimensions);
    camera->setAmountOfTilesUnderScreen(inputParser.getAmountOfTilesUnderScreen());

    shared_ptr<AbstractFactory> conc = make_shared<ConcreteFactory>(sfWindow);

    //add absstractFactory
    world.setAbstractFactory(conc);
    //pass screendimentions to world
    world.setScreenDimensions(screenDimensions);
    //pass tiles to world
    world.setUp(tiles);
    //pass tileSize to world
    world.setTileSize(inputParser.getTileSize());
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

void LevelState::moveScreen() {
    View view = sfWindow->getView();

    view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));

    Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);

    //    float Position = world.getPlayer().getPlayerLeftUpperPosition().y;
    const Position playerPosition = world.getPlayer().getLeftUpperCorner();

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
}