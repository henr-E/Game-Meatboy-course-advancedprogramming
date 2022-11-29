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

    updatePlayerPosition();

    // make level from input
    inputParser.parse();

    //
    //    // create the tilemap from the level definition
    //    if (!tileMap.load()) {
    //        cout << "Failed to load or make map." << endl;
    //    }

    // load background
    if (!textureBackground.loadFromFile("../content/Background_blurred.png")) {
        cout << "Failed to load background into texture." << endl;
    }
    // configure sprite
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setScale(1, (float)screenDimensions.y / textureBackground.getSize().y);
}

void LevelState::getUserInput(Event &event) {
    cout << "event in LEvelstate = " << &event <<endl;

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

    // draw tileMap
    //    sfWindow->draw(tileMap);

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

    // convert coordinates to pixels
    Position p = camera.coordinatesToPixel(playerRect.left, playerRect.top);
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
void LevelState::simulate() {
    // update player position to rectangle
    updatePlayerPosition();

    // calculate collision
    checkCollision();

    // run world
    world.simulate(collision);
}

void LevelState::checkCollision() {
    vector<vector<Tile>> tiles = inputParser.getTiles();

    float playerX = world.getPlayer().getPlayerPosition().x;
    float playerY = world.getPlayer().getPlayerPosition().y;

    int rowsize = tiles.size();

    // list begins with index 0 so -1
    int currentPlayerRow = rowsize - floor(abs(playerY + 1) / 0.125);
    int currentPlayerColumn = floor(abs(playerX + 1) / 0.125);


    Tile currentTile, upTile, downTile, leftTile, leftDownTile, leftUpperTile, rightTile, rightUpperTile, rightDownTile;

    if (currentPlayerRow + 1 < tiles.size() and currentPlayerRow-1 > 0 and
        currentPlayerColumn + 1 < tiles[0].size() and currentPlayerColumn-1 > 0) {
        // get tile where current tile is at
        currentTile = tiles[currentPlayerRow][currentPlayerColumn];

        // define all tiles
        upTile = tiles[currentPlayerRow + 1][currentPlayerColumn];
        downTile = tiles[currentPlayerRow - 1][currentPlayerColumn];

        leftTile = tiles[currentPlayerRow][currentPlayerColumn - 1];
        leftDownTile = tiles[currentPlayerRow + 1][currentPlayerColumn - 1];
        leftUpperTile = tiles[currentPlayerRow - 1][currentPlayerColumn - 1];

        rightTile = tiles[currentPlayerRow][currentPlayerColumn + 1];
        rightUpperTile = tiles[currentPlayerRow - 1][currentPlayerColumn + 1];
        rightDownTile = tiles[currentPlayerRow + 1][currentPlayerColumn + 1];


        collision.setAllFalse();
        if (rightTile.tileType != none and playerRect.intersects(rightTile.tileRect)) {

            collision.collisionRight = true;
        }
        if (leftTile.tileType != none and playerRect.intersects(leftTile.tileRect)) {
            collision.collisionLeft = true;
        }
        if (upTile.tileType != none and playerRect.intersects(upTile.tileRect)) {
            collision.collisionUp = true;
        }
        if (downTile.tileType != none and playerRect.intersects(downTile.tileRect)) {
            collision.collisionDown = true;
        }
        if (leftUpperTile.tileType != none and playerRect.intersects(leftUpperTile.tileRect)) {
            collision.collisionUpperLeft = true;
        }
        if (rightUpperTile.tileType != none and playerRect.intersects(rightUpperTile.tileRect)) {
            collision.collisionUpperRight = true;
        }
        if (leftDownTile.tileType != none and playerRect.intersects(leftDownTile.tileRect)) {
            collision.collisionDownLeft = true;
        }
        if (rightDownTile.tileType != none and playerRect.intersects(rightDownTile.tileRect)) {
            collision.collisionDownRight = true;
        }
    }
}

void LevelState::updateView() {
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
    sfWindow->setView(view);
}
void LevelState::updatePlayerPosition() {
    playerRect.top = world.getPlayer().getPlayerPosition().y;
    playerRect.left = world.getPlayer().getPlayerPosition().x;
}
