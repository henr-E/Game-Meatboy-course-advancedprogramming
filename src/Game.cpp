//
// Created by henri kerch on 13/11/2022.
//

#include "Game.h"

Game::Game(){
    gameVideoMode.width = 800.f;
    gameVideoMode.height = 600.f;

    // Create and open a window
    gameWindow.create(gameVideoMode, "game", Style::Resize);
    View view(sf::FloatRect(0, 0, 800.f, 600.f));
    gameWindow.setView(view);

    // Load a sprite to display
    if (!textureBackground.loadFromFile("../content/B1.jpg")){
        printf("Failed to load background into texture.");
        exit(EXIT_FAILURE);
    }
    spriteBackground.setTexture(textureBackground, false);
}

void Game::start()
{
    // Timing
    Clock clock;

    while (gameWindow.isOpen())
    {


        Event event;
        while(gameWindow.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                gameWindow.close();
            }
            world.simulate(event);
        }
        // Restart the clock and save the elapsed time into dt
        Time dt = clock.restart();
        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();
        world.update(dtAsSeconds);
        draw();
    }
}

void Game::draw(){
    // Rub out the last frame
    gameWindow.clear(Color::White);

    // Draw the background
    gameWindow.draw(spriteBackground);

    Player p = world.getPlayer();
    gameWindow.draw(p.getSprite());

    // Show everything we have just drawn
    gameWindow.display();
}
