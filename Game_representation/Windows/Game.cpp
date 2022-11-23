//
// Created by henri kerch on 13/11/2022.
//

#include "Game.h"
Game::Game() {
    screenDimensions.x = 544;
    screenDimensions.y = 960;

    // confiure videoMode
    sfVideoMode.width = screenDimensions.x;
    sfVideoMode.height = screenDimensions.y;

    //  Create and open a window
    sfWindow.create(sfVideoMode, "game");

    // change framerate
    sfWindow.setFramerateLimit(60);

    cout << "ownWindowConstructor"<< endl;


    if (!music.openFromFile("../content/music.ogg"))
        exit(EXIT_FAILURE);
    music.play();

    music.setLoop(true);
    music.setVolume(50);


    //    // Load sound
    //    if (!buffer.loadFromFile("../content/bip.wav"))
    //        exit(EXIT_FAILURE);
    //    sound.setBuffer(buffer);
    //    sound.play();
    cout << "GameConstructor"<< endl;
}

int Game::simulate() {
    // make Player
    Player player;
    // add player
    world.setPlayer(player);

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

    while (sfWindow.isOpen()) {
        Event event;
        while (sfWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                sfWindow.close();
                return 0;
            }
            userInput(event);
            if(keyboardInput == esc){
                sfWindow.close();
                return 0;
            }
            world.keyboardToPlayer(keyboardInput);
//            if(world.getPlayer().isPlayerWon()){
//                drawPlayerWin();
//                if(keyboardInput == esc) {
//                    sfWindow.close();
//                }
//            }
        }
        //simulate world
        world.simulate(tileMap.getTiles());

        // Now move the playerSprite to its new position
        spritePlayer.setPosition(world.getPlayer().getPlayerPosition().x, world.getPlayer().getPlayerPosition().y);

        // Rub out the last frame
        sfWindow.clear();

        //draw tileMap
        sfWindow.draw(tileMap);

        // make sprite and texture player
        // Associate a texture with the sprite
        // using 2 different sprites
        if (world.getPlayer().getDirection() == facingRight){
            texturePlayer.loadFromFile("../content/meatboy.png");
        }else{
            texturePlayer.loadFromFile("../content/meatboy_mirror.png");
        }
        texturePlayer.setSmooth(true);
        spritePlayer.setTexture(texturePlayer);

        // Draw the player
        sfWindow.draw(spritePlayer);

        // Show everything we have just drawn
        sfWindow.display();
    }
}

void Game::userInput(Event event) {
    /*
     * make a keyboardinput object (enum). Assign nokey to it because if not assigned it takes pressMoveRight
     * and the player will move even though there are no keys pressed
     */
    keyboardInput = noKey;
    if (event.type == Event::KeyPressed) {
        // Escape
        if (event.key.code == Keyboard::Escape){
            keyboardInput = esc;
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
}
void Game::setChosenLevel(int chosenLevel) { Game::chosenLevel = chosenLevel; }
void Game::drawPlayerWin() {
    Font font;

    //load font
    if(!font.loadFromFile("../content/Fonts/Herculanum.ttf")){
        exit(EXIT_FAILURE);
    }


    // select the font
    t.setFont(font);
    t.setString("You Won! Press escape.");

    /*
     * the position decides where the first character of the string will be
     * one character = 32 pixels
     * if the string is 10 characters
     * then 10*32 is the length of the string
     * 10*32/2 is the length of half the string
     *
     * so if we want to center it =>
     * 544/2 - 10*32/2
     *
     */
    //position is position of first character
    int positionX = 544/2;

    t.setPosition(positionX - (12.5/2*32),64);

    // set the character size
    t.setCharacterSize(32);
    // set the color
    t.setFillColor(Color::Green);
    // set the text style
    t.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sfWindow.draw(t);
}
