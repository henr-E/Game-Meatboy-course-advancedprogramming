//
// Created by henri kerch on 13/11/2022.
//

#include "Game.h"
Game::Game(){
    screenDimensions.x = 544;
    screenDimensions.y = 960;

    // confiure videoMode
    sfVideoMode.width = screenDimensions.x;
    sfVideoMode.height = screenDimensions.y;

    //  Create and open a window
    sfWindow->create(sfVideoMode, "game");

    // change framerate
    sfWindow->setFramerateLimit(60);

    stateManager.setSfWindow(sfWindow);

    //    if (!music.openFromFile("../content/music.ogg"))

    //    music.play();
    //
    //    music.setLoop(true);
    //    music.setVolume(50);


    //    // Load sound
    //    if (!buffer.loadFromFile("../content/bip.wav"))

    //    sound.setBuffer(buffer);
    //    sound.play();
}

void Game::run() {
    //statemanager is made and the statemanager makes a manuState
    while (sfWindow->isOpen()) {
        Event event;
        stateManager.setEvent(event);

        while (sfWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                sfWindow->close();
            }

            functionCallTo = INPUT;
            stateManager.setFunctionCallTo(functionCallTo);
            stateManager.simulate();
        }
        functionCallTo = SIMULATE;
        stateManager.setFunctionCallTo(functionCallTo);
        stateManager.simulate();

        functionCallTo = DRAW;
        stateManager.setFunctionCallTo(functionCallTo);
        stateManager.simulate();
    }
}
