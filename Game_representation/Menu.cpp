//
// Created by henri kerch on 22/11/2022.
//

#include "Menu.h"
//
// Created by henri kerch on 13/11/2022.
//

#include "Menu.h"

Menu::Menu() {
    screenDimensions.x = 544;
    screenDimensions.y = 960;
}

void Menu::simulate() {
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

        world.simulate(tileMap.getTiles());

        // Now move the playerSprite to its new position
        spritePlayer.setPosition(world.getPlayer().getPlayerPosition().x, world.getPlayer().getPlayerPosition().y);

        // Rub out the last frame
        gameWindow.clear();

        // Draw the background
        //gameWindow.draw(spriteBackground);

        gameWindow.draw(tileMap);

        // make sprite and texture player
        // Associate a texture with the sprite
        if (world.getPlayer().getDirection() == facingRight){
            texturePlayer.loadFromFile("../content/meatboy.png");
        }else{
            texturePlayer.loadFromFile("../content/meatboy_mirror.png");
        }
        texturePlayer.setSmooth(true);
        spritePlayer.setTexture(texturePlayer);

        // Draw the player
        gameWindow.draw(spritePlayer);

        // Show everything we have just drawn
        gameWindow.display();

        // creating views
        updateView();
    }
}

void Menu::startingSetup() {
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

    //    // make sprite and texture background
    //    // Load a sprite to display
    //    if (!textureBackground.loadFromFile("../content/Background.png")) {
    //        printf("Failed to load background into texture.");
    //        exit(EXIT_FAILURE);
    //    }
    //    // configure sprite
    //    spriteBackground.setTexture(textureBackground);
    //    spriteBackground.setScale(1, (float)screenDimensions.y / textureBackground.getSize().y);
    //    //    spriteBackground.setPosition(0,0);

    // Load sound
    if (!buffer.loadFromFile("../content/bip.wav"))
        exit(EXIT_FAILURE);
    sound.setBuffer(buffer);


}

void Menu::updateView() {
    View view;

    view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
    //    view.setViewport(FloatRect(0,0,0.5,1.0));

    Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);

    //    float Position = world.getPlayer().getPlayerPosition().y;
    const Position playerPosition = world.getPlayer().getPlayerPosition();

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
    if (playerPosition.y + 16 < screenDimensions.y / 2) {
        position.y = playerPosition.y + 16;
    } else {
        position.y = screenDimensions.y / 2;
    }

    view.setCenter(position);

    // set the view
    gameWindow.setView(view);
}


void Menu::userInput(Event event) {
    /*
     * make a keyboardinput object (enum). Assign nokey to it because if not assigned it takes pressMoveRight
     * and the player will move even though there are no keys pressed
     */
    keyboardInput = noKey;
    if (event.type == Event::KeyPressed) {
        // Escape
        if (event.key.code == Keyboard::Escape){

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
Menu::Menu() {}
