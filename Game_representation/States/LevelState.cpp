//
// Created by henri kerch on 24/11/2022.
//

#include "LevelState.h"
#include "StateManager.h"

LevelState::LevelState(StateManager& stateManager, shared_ptr<RenderWindow>& sfWindow, int chosenLevel)
    : State(stateManager, sfWindow), chosenLevel(chosenLevel) {
    startup(chosenLevel);

    cout << "Level " <<chosenLevel <<" is started." <<endl;

}

void LevelState::startup(int chosenLevel) {

    sf::View view = sfWindow->getView();
    view.setCenter(544.f/2, 1024.f/2);
    sfWindow->setView(view);

    // make level from input
    inputParser.parse(chosenLevel);

    vector<vector<inputRectangles>> tiles = inputParser.getTiles();

    Position screenDimensions = inputParser.getScreenDimensions();

    camera->setScreenDimensions(screenDimensions);

    shared_ptr<AbstractFactory> conc = make_shared<ConcreteFactory>(sfWindow);

    //add absstractFactory
    world.setAbstractFactory(conc);
    //pass wallTiles to world
    world.setUp(tiles);
    //pass tileSize to world
    world.setTileSize(inputParser.getTileSize());

    //load background
    if (!textureBackground.loadFromFile("../content/Background_blurred.png")) {
        cout << ("Failed to load background into texture.") << endl;

    }
    // configure sprite
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);
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
            shared_ptr<State> newState = make_shared<MenuState>(stateManager, sfWindow);
            stateManager.setState(newState);
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
    moveScreen();
    world.updatePlayerModel();

    //start level again
    if(checkPlayerDeath()){
        shared_ptr<State> newState = make_shared<LevelState>(stateManager, sfWindow, chosenLevel);
        stateManager.setState(newState);
        return;
    }
    //start next level
    if(world.getPlayer()->intersects(world.getGoal())){
        shared_ptr<State> newState = make_shared<LevelState>(stateManager, sfWindow, chosenLevel + 1);
        stateManager.setState(newState);
        return;
    }

}
void LevelState::moveScreen(){
    auto view = sfWindow->getView();

    Position viewCenter(view.getCenter().x, view.getCenter().y);
    Position backgroundLeftUpCorner(spriteBackground.getPosition().x, spriteBackground.getPosition().y);

    Position playerPosition = world.getPlayer()->getLeftUpperCorner();
    Position prevPlayerPosition = world.getPlayer()->getPreviousLeftUpperCorner();

    CameraPositions positions;
    positions.viewPosition = viewCenter;
    positions.backgroundPosition = backgroundLeftUpCorner;

    camera->moveScreenAtEighty(positions, playerPosition, prevPlayerPosition);
    if(inputParser.getMoveScreen() == MOVE){
        camera->moveScreen(positions);
    }

    //remember this is the center!
    view.setCenter(positions.viewPosition.x, positions.viewPosition.y);
    spriteBackground.setPosition(positions.backgroundPosition.x, positions.backgroundPosition.y);

    sfWindow->setView(view);
    Position bottomView = camera->pixelToCoordinates(0, positions.viewPosition.y + 1024.f/2);
    world.setBottomViewY(bottomView.y);
}
//TODO
bool LevelState::checkPlayerDeath() {
//    //check if view is moved otherwise its the beginning of the game
//    bool viewMoved = camera->isViewMoved();
    //get player position in pixels
    Position playerY = camera->coordinatesToPixel(world.getPlayer()->getLeftUpperCorner().x, world.getPlayer()->getLeftUpperCorner().y);
    //get view position
    auto viewCenter = sfWindow->getView().getCenter();

    if(playerY.y > (viewCenter.y + 1024.f/2)){
        return true;
    }
    return false;
}


void LevelState::draw() {
    sfWindow->clear();
    sfWindow->draw(spriteBackground);
    world.updateViews();
    sfWindow->display();
}

