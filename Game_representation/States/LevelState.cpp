//
// Created by henri kerch on 24/11/2022.
//

#include "LevelState.h"
LevelState::LevelState() { startUp(); }
void LevelState::startUp() {
    // make Player
    Player player;
    // add player
    world.setPlayer(player);

    // make level from input
    inputParser.parse(1);

    // load background
    if (!textureBackground.loadFromFile("../content/Background_blurred.png")) {
        cout << "Failed to load background into texture." << endl;
    }
    // configure sprite
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setScale(1, (float)screenDimensions.y / textureBackground.getSize().y);
}

void LevelState::getUserInput(Event &event) {
//    cout << "event in LEvelstate = " << &event <<endl;

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

void LevelState::draw() {

    // Rub out the last frame
    sfWindow->clear();

    sfWindow->draw(spriteBackground);

    drawTiles();

    // make sprite and texture player
    // Associate a texture with the sprite
    // using 2 different sprites
    if (world.getPlayer().getDirection() == facingRight) {
        texturePlayer.loadFromFile("../content/meatboy.png");
    } else {
        texturePlayer.loadFromFile("../content/meatboy_mirror.png");
    }
    texturePlayer.setSmooth(true);
    spritePlayer.setTexture(texturePlayer);

    Position position = world.getPlayer().getPlayerLeftUpperPosition();
    // convert coordinates to pixels
    Position p = camera.coordinatesToPixel(position.x, position.y);
    // Now move the playerSprite to its new position
    spritePlayer.setPosition(p.x, p.y);
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
#include <unistd.h>
void LevelState::drawTiles() {
    auto tiles = inputParser.getTiles();
    for(auto const &row : tiles){
        for(auto const &rect : row){
            Texture textureTile;
            Sprite spriteTile;

            float XLeft = rect.getLeftUpperCorner().x;
            float XRight = rect.getRightDownCorner().x;

            float YUp = rect.getLeftUpperCorner().y;
            float YDown = rect.getRightDownCorner().y;

            if(rect.getTileType() == other){
                if (textureTile.loadFromFile("../content/tileset.png", IntRect(160, 0, 32, 32))){

                }
            }

            else if(rect.getTileType() == girlfriend){
                if (textureTile.loadFromFile("../content/tileset.png", IntRect(0, 0, 32, 32))){

                }
            }
            else if(rect.getTileType() == block){
                if (textureTile.loadFromFile("../content/tileset.png", IntRect(64, 0, 32, 32))){

                }
            }

            spriteTile.setTexture(textureTile);

            //transform coordinates
            Position p = camera.coordinatesToPixel(XLeft, YUp);

            spriteTile.setPosition(p.x, p.y);

            sfWindow->draw(spriteTile);
        }
    }
}

void LevelState::simulate() {
    // run world
    world.simulate(inputParser.getTiles());
}

void LevelState::updateView() {
    View view;

    view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
    //    view.setViewport(FloatRect(0,0,0.5,1.0));

    Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);

    //    float Position = world.getPlayer().getPlayerLeftUpperPosition().y;
    const Position playerPosition = world.getPlayer().getPlayerLeftUpperPosition();

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
    sfWindow->setView(view);
}
