//
// Created by henri kerch on 13/11/2022.
//

#include "Game.h"
Game::Game() {
    // TODO moeten we verschillende breetes kunnen ondersteuenn voor grotere levels?
    windowDimentions.x = 544;
    windowDimentions.y = 1024;

    // confiure videoMode
    sfVideoMode.width = windowDimentions.x;
    sfVideoMode.height = windowDimentions.y;

    //  Create and open a window
    sfWindow->create(sfVideoMode, "MEAT BOY");

    // change framerate
    sfWindow->setFramerateLimit(60);

    shared_ptr<StateManager> stateManager1 = make_shared<StateManager>(sfWindow);
    stateManager = stateManager1;

    if (!music.openFromFile("../content/music.ogg")) {
    }

    music.play();

    music.setLoop(true);
    music.setVolume(15);

    // Load sound
    if (!buffer.loadFromFile("../content/bip.wav"))

        sound.setBuffer(buffer);
    sound.play();
}

void Game::run() {
    // statemanager is made and the statemanager makes a manuState
    while (sfWindow->isOpen()) {
        Event event;

        while (sfWindow->pollEvent(event)) {
            // it is necasary to pass the event after the second while loop
            // because the pollEvent function changes the event
            stateManager->setEvent(event);
            if (event.type == sf::Event::Closed) {
                sfWindow->close();
            }

            functionCallTo = ownType::INPUT;
            stateManager->simulate(functionCallTo);
        }
        functionCallTo = ownType::SIMULATE;
        stateManager->simulate(functionCallTo);

        functionCallTo = ownType::DRAW;
        stateManager->simulate(functionCallTo);
    }
}
