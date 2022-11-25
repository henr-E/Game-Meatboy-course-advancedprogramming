//
// Created by henri kerch on 24/11/2022.
//

#include "LevelState.h"
LevelState::LevelState() {
    startUp();
}
void LevelState::startUp() {
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
    }

    //load background
    if (!textureBackground.loadFromFile("../content/Background_blurred.png")) {
        printf("Failed to load background into texture.");
    }
    // configure sprite
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setScale(1, (float)screenDimensions.y / textureBackground.getSize().y);
    //    spriteBackground.setPosition(0,0);
}



void LevelState::getUserInput(Event event) {
    /*
     * make a keyboardinput object (enum). Assign nokey to it because if not assigned it takes pressMoveRight
     * and the player will move even though there are no keys pressed
     */
    keyboardInput = noKey;
    if (event.type == Event::KeyPressed) {
        // Escape
        if (event.key.code == Keyboard::Escape){
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
    //pass keyboard to player
    world.keyboardToPlayer(keyboardInput);
}

void LevelState::draw() {
    // Now move the playerSprite to its new position
    spritePlayer.setPosition(world.getPlayer().getPlayerPosition().x, world.getPlayer().getPlayerPosition().y);

    // Rub out the last frame
    sfWindow->clear();


    sfWindow->draw(spriteBackground);

    //draw tileMap
    sfWindow->draw(tileMap);

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
    sfWindow->draw(spritePlayer);

    // Show everything we have just drawn
    sfWindow->display();



    /*
     * IF PLAYER WINNNN
     */
    /*
    Font font;

    //load font
    if(!font.loadFromFile("../content/Fonts/Herculanum.ttf")){
    }


    // select the font
    t.setFont(font);
    t.setString("You Won! Press escape.");


     * the position decides where the first character of the string will be
     * one character = 32 pixels
     * if the string is 10 characters
     * then 10*32 is the length of the string
     * 10*32/2 is the length of half the string
     *
     * so if we want to center it =>
     * 544/2 - 10*32/2
     *

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
    */
}
void LevelState::simulate() {
    //run world
    world.simulate(tileMap.getTiles());
}

