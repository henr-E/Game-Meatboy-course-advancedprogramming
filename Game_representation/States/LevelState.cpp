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
    moveScreen();
}

void LevelState::moveScreen() {
    bool moveAllowed = true;
    View view = sfWindow->getView();

    Vector2f oldViewPosition = view.getCenter();
    Vector2f position(544.f / 2, 1024.f / 2);

    float x = world.getPlayer().getLeftUpperCorner().x;
    float y = world.getPlayer().getLeftUpperCorner().y;

    const Position playerPosition = camera->coordinatesToPixel(x,y);

    view.reset(sf::FloatRect(0, 0, 544.f, 1024.f));

    //if goal is in the view, we stop moving the view
    if ((oldViewPosition.y + 1024.f/2) >= screenDimensions.y){
        moveAllowed = false;
    }
    /*
     * playerposition has to be lower than eighty procent of the screen
     * "lower" because the uppder left corner of the screen is (0,0)
     *
     * if the player has reached 80 procent the view has to make the same steps as the player
     * so if the player moves 5 up, the view needs to move 5 up
     */
    if(moveAllowed){
        float eightyPercentageHeight = 1024.f-((1024.f*80.f)/100.f);
        if (playerPosition.y <= eightyPercentageHeight) {
            position.y = playerPosition.y;
        }
    }
    //todo: remember this is the center!
    view.setCenter(position);
    sfWindow->setView(view);
}