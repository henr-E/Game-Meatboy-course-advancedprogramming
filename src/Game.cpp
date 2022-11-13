//
// Created by henri kerch on 13/11/2022.
//

#include "Game.h"
#include <iostream>
#include<unistd.h>

Game::Game(){
    world.setPlayer(player);

    gameVideoMode.width = 532;
    gameVideoMode.height = 850;

    // Create and open a window
    gameWindow.create(gameVideoMode, "game", Style::Default);
    View view(sf::FloatRect(0, 0, 532, 850));
    gameWindow.setView(view);
    gameWindow.setFramerateLimit(60);

    // Load a sprite to display
    if (!textureBackground.loadFromFile("../content/B1.png")){
        printf("Failed to load background into texture.");
        exit(EXIT_FAILURE);
    }
    //configure sprite
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0,0);

    // Load sound
    if (!buffer.loadFromFile("../content/bip.wav"))
        exit(EXIT_FAILURE);
    sound.setBuffer(buffer);

    // Associate a texture with the sprite
    texturePlayer.loadFromFile("../content/meatboy.png");
    texturePlayer.setSmooth(true);
    spritePlayer.setTexture(texturePlayer);

//    // Create a text object
//    sf::Text hud;
//    hud.setFont(font);
//    hud.setCharacterSize(24);
//    hud.setFillColor(sf::Color::White);
//    hud.setPosition(10, 10);

}

void Game::start()
{
    /*
     * todo make a stopwatch
     */
    // Clock for timing everything
    sf::Clock clock;


    while (gameWindow.isOpen()){

        Event event;
        while(gameWindow.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                gameWindow.close();
            }
            keyboardInput = userInput(event);
            world.keyboardToPlayer(keyboardInput);
        }
        sf::Time dt = clock.restart();

        world.simulate(dt.asSeconds());

        // Now move the sprite to its new position
        spritePlayer.setPosition(world.getPlayer().getPlayerPosition());
        draw();
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