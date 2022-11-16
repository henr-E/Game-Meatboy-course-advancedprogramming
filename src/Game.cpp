//
// Created by henri kerch on 13/11/2022.
//

#include "Game.h"
#include <iostream>

Game::Game(){
    screenDimensions.x = 532;
    screenDimensions.y = 850;
}

void Game::start(){

    //add player
    world.setPlayer(player);
    //confiure videoMode
    gameVideoMode.width = screenDimensions.x;
    gameVideoMode.height = screenDimensions.y;
    gameVideoMode.bitsPerPixel = 32;
    // Create and open a window
    gameWindow.create(gameVideoMode, "game", Style::Default);
    //change framerate
    gameWindow.setFramerateLimit(60);

    // Load a sprite to display
    if (!textureBackground.loadFromFile("../content/B1.png")){
        printf("Failed to load background into texture.");
        exit(EXIT_FAILURE);
    }
    //configure sprite
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setScale(1, (float)screenDimensions.y/textureBackground.getSize().y);
//    spriteBackground.setPosition(0,0);

    // Load sound
    if (!buffer.loadFromFile("../content/bip.wav"))
        exit(EXIT_FAILURE);
    sound.setBuffer(buffer);

    // Associate a texture with the sprite
    texturePlayer.loadFromFile("../content/meatboy.png");
    texturePlayer.setSmooth(true);
    spritePlayer.setTexture(texturePlayer);


    while (gameWindow.isOpen()){

        Event event;
        while(gameWindow.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                gameWindow.close();
            }
            keyboardInput = userInput(event);
            world.keyboardToPlayer(keyboardInput);
        }
        world.simulate();

        // Now move the sprite to its new position
        spritePlayer.setPosition(world.getPlayer().getPlayerPosition());

        loadTestLevel();
        //creating views
        updateView();
    }
}

void Game::draw(){
    // Rub out the last frame
    gameWindow.clear();

    // Draw the background
    gameWindow.draw(spriteBackground);

    gameWindow.draw(spritePlayer);

    // Show everything we have just drawn
    gameWindow.display();
}

KeyboardInput Game::userInput(Event event){
    /*
     * make a keyboardinput object (enum). Assign nokey to it because if not assigned it takes pressMoveRight
     * and the player will move even though there are no keys pressed
    */
    KeyboardInput keyboardInput = noKey;
    if (event.type == Event::KeyPressed)
    {
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

    if (event.type == Event::KeyReleased)
    {
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
    return keyboardInput;
}

void Game::updateView() {
    View view;

    view.reset(sf::FloatRect(0, 0, 532, 850));
//    view.setViewport(FloatRect(0,0,0.5,1.0));

    Vector2f position(screenDimensions.x / 2,screenDimensions.y/2);

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
    //the position is the left side of meatboy so to get the middle we have to add half of meat boy = 25
    if(playerPosition.y + 25 < screenDimensions.y / 2){
        position.y = playerPosition.y + 25;
    }
    else{
        position.y = screenDimensions.y / 2;
    }

    view.setCenter(position);

    //set the view
    gameWindow.setView(view);
}

void Game::loadTestLevel() {
}
