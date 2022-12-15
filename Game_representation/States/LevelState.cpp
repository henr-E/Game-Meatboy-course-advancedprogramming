//
// Created by henri kerch on 24/11/2022.
//

#include "LevelState.h"
LevelState::LevelState(const shared_ptr<RenderWindow>& sfWindow) : State(sfWindow) {

//    screenMoved = false;

//    View view = sfWindow->getView();
//    Vector2f oldViewPosition = view.getCenter();


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
    checkPlayerDeath();
}

void LevelState::checkPlayerDeath() {
//    if(world.getPlayer().getRightDownCorner().y > (newViewPosition.y + 1024.f/2) and screenMoved){
//        transition = true;
//    }
}

void LevelState::draw() {
    world.updateViews();
    moveScreen();
}

void LevelState::moveScreen() {
    View view = sfWindow->getView();

    Vector2f viewPosition = view.getCenter();
//    Vector2f position(544.f / 2, 1024.f / 2);

    float x = world.getPlayer().getLeftUpperCorner().x;
    float y = world.getPlayer().getLeftUpperCorner().y;

    float prevX = world.getPlayer().getPreviousLeftUpperCorner().x;
    float prevY = world.getPlayer().getPreviousLeftUpperCorner().y;

    const Position playerPosition = camera->coordinatesToPixel(x,y);
    const Position prevPlayerPosition = camera->coordinatesToPixel(prevX, prevY);

    Position positionDifference = playerPosition - prevPlayerPosition;
//    view.reset(sf::FloatRect(0, 0, 544.f, 1024.f));

    /*
     * playerposition has to be lower than eighty procent of the screen
     * "lower" because the uppder left corner of the screen is (0,0)
     *
     * if the player has reached 80 procent the view has to make the same steps as the player
     * so if the player moves 5 up, the view needs to move 5 up
     */
    /*
     * screendimensions.x= 1376
     * ------------------- - (1376 - 1024)
     *
     *
     * -------------------0
     *
     *
     *
     *
     * -------------------1024
     */
    float maximumViewHeight = -(screenDimensions.y - 1024);
    if ((viewPosition.y - 1024.f/2) >= maximumViewHeight){
        float eightyPercentageHeight = 1024.f-((1024.f*80.f)/100.f);
        //if player is in 80% and the difference is positive
        //if the differene is negative, the player is going down and the screen shouldnt move
        if (playerPosition.y <= eightyPercentageHeight and positionDifference.y > 0) {
            viewPosition.y -= positionDifference.y;
        }
    }
    //todo: remember this is the center!
    view.setCenter(viewPosition);
    sfWindow->setView(view);
}