//
// Created by henri kerch on 13/11/2022.
//

#include "Game.h"

Game::Game() {
    screenDimensions.x = 544;
    screenDimensions.y = 960;
}

void Game::simulate() {
    startingSetup();
    //make level from input
    vector<int> tiles = inputParser.parse();
    //get AmountOfTilesInHeight in level
    int amountOfTilesInHeight = inputParser.getAmountOfTilesInHeight();
    //get AmountOfTilesInWidth in level
    int amountOfTilesInWidth = inputParser.getAmountOfTilesInWidth();

    //set tiles to tilemap
    tileMap.setTiles(tiles);
    //set dimentions in tilemap
    tileMap.setScreenDimensions(screenDimensions);
    //set setAmountOfTilesInHeight
    tileMap.setAmountOfTilesInHeight(amountOfTilesInHeight);
    //set setAmountOfTilesInWidth
    tileMap.setAmountOfTilesInWidth(amountOfTilesInWidth);


    // create the tilemap from the level definition
    if (!tileMap.load()) {
        printf("Failed to load or make map.");
        exit(EXIT_FAILURE);
    }

    while (gameWindow.isOpen()) {
        Event event;
        while (gameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameWindow.close();
            }
            userInput(event);
            world.keyboardToPlayer(keyboardInput);
        }
        updateCollision(amountOfTilesInWidth);

        world.simulate(collision);

        // Now move the playerSprite to its new position
        spritePlayer.setPosition(world.getPlayer().getPlayerPosition());

        // Rub out the last frame
        gameWindow.clear();

        // Draw the background
        //gameWindow.draw(spriteBackground);

        gameWindow.draw(tileMap);

        // Draw the player
        gameWindow.draw(spritePlayer);

        // Show everything we have just drawn
        gameWindow.display();

        // creating views
        updateView();
    }
}

void Game::startingSetup() {
    Player player;

    // add player
    world.setPlayer(player);

    // create videoMode
    // confiure videoMode
    gameVideoMode.width = screenDimensions.x;
    gameVideoMode.height = screenDimensions.y;
    // gameVideoMode.bitsPerPixel = 32;
    //  Create and open a window
    gameWindow.create(gameVideoMode, "game");

    // change framerate
    gameWindow.setFramerateLimit(60);

    // make sprite and texture background
    // Load a sprite to display
    if (!textureBackground.loadFromFile("../content/Background.png")) {
        printf("Failed to load background into texture.");
        exit(EXIT_FAILURE);
    }
    // configure sprite
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setScale(1, (float)screenDimensions.y / textureBackground.getSize().y);
    //    spriteBackground.setPosition(0,0);

    // Load sound
    if (!buffer.loadFromFile("../content/bip.wav"))
        exit(EXIT_FAILURE);
    sound.setBuffer(buffer);

    // make sprite and texture player
    // Associate a texture with the sprite
    texturePlayer.loadFromFile("../content/meatboy.png");
    texturePlayer.setSmooth(true);
    spritePlayer.setTexture(texturePlayer);
}

void Game::updateView() {
    View view;

    view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
    //    view.setViewport(FloatRect(0,0,0.5,1.0));

    Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);

    Vector2f playerPosition = world.getPlayer().getPlayerPosition();

    //    cout<< playerPosition.y <<endl;
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
    if (playerPosition.y + 25 < screenDimensions.y / 2) {
        position.y = playerPosition.y + 25;
    } else {
        position.y = screenDimensions.y / 2;
    }

    view.setCenter(position);

    // set the view
    gameWindow.setView(view);
}


void Game::userInput(Event event) {
    /*
     * make a keyboardinput object (enum). Assign nokey to it because if not assigned it takes pressMoveRight
     * and the player will move even though there are no keys pressed
     */
    keyboardInput = noKey;
    if (event.type == Event::KeyPressed) {
        // Escape
        if (event.key.code == Keyboard::Escape)
            keyboardInput = esc;

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
        if (event.key.code == Keyboard::Left)
            keyboardInput = releaseJump;

        // Left arrow
        if (event.key.code == Keyboard::Left)
            keyboardInput = releaseMoveLeft;

        // Right arrow
        if (event.key.code == Keyboard::Right)
            keyboardInput = releaseMoveRight;
    }
}

void Game::updateCollision(int amountOfTilesInWidth) {
    collision = noCollision;

    int playerPositionX = static_cast<int>(world.getPlayer().getPlayerPosition().x);
    int playerPositionY = static_cast<int>(world.getPlayer().getPlayerPosition().y) + 32;


    /*
     *
     * 1002
     * 0000
     * 3004
     *
     * if the above example is our vertexArray and one tile is 32 pixels
     * 1 = (0,0)
     * 3 = (0,64)
     * 2 = (96,0)
     * 4 = (96,64)
     *
     * in the tileMap vector indexes are:
     * the indexes are column by column
     * 1 = 0
     * 2 = 9
     * 3 = 2
     * 4 = 1&
     *
     */
//    cout << playerPositionX <<endl;
    int rowInTileMap = playerPositionY / 32;
    int columnInTileMap = playerPositionX / 32;

    //index of tile where player is now
    //multiply the player row with the width and add amount of columns
    int currentIndex = columnInTileMap + (rowInTileMap-1) * amountOfTilesInWidth;

    const vector<int> tiles = tileMap.getTiles();

    int rightIndex = currentIndex+1;
    int leftIndex = currentIndex-1;
    int upIndex = currentIndex - 17;
    int downIndex = currentIndex + 17;

    int rightTile = tiles[rightIndex];
    int leftTile = tiles[leftIndex];
    int upTile = tiles[upIndex];
    int downTile = tiles[downIndex];

    if(rightTile == 1){
        collision = collisionRight;
    }
    else if(leftTile == 1){
        collision = collisionLeft;
    }
    else if(upTile == 1){
        collision = collisionUp;
    }
    else if(downTile == 1){
        collision = collisionDown;
    }
}


