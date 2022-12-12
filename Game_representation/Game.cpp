//
// Created by henri kerch on 13/11/2022.
//

#include "Game.h"
Game::Game(){
    screenDimensions.x = 544;
    screenDimensions.y = 1024;

    // confiure videoMode
    sfVideoMode.width = screenDimensions.x;
    sfVideoMode.height = screenDimensions.y;

    //  Create and open a window
    sfWindow->create(sfVideoMode, "game");

    // change framerate
    sfWindow->setFramerateLimit(60);

    shared_ptr<StateManager> stateManager1 = make_shared<StateManager>(sfWindow);
    stateManager = stateManager1;

//        if (!music.openFromFile("../content/music.ogg")){}
//
//        music.play();
//
//        music.setLoop(true);
//        music.setVolume(50);


    //    // Load sound
    //    if (!buffer.loadFromFile("../content/bip.wav"))

    //    sound.setBuffer(buffer);
    //    sound.play();
}

void Game::run() {
    //statemanager is made and the statemanager makes a manuState
    while (sfWindow->isOpen()) {
        Event event;

        while (sfWindow->pollEvent(event)) {
            //it is necasary to pass the event after the second while loop
            //because the pollEvent function changes the event
            stateManager->setEvent(event);
            if (event.type == sf::Event::Closed) {
                sfWindow->close();
            }

            functionCallTo = INPUT;
            stateManager->simulate(functionCallTo);
        }
        functionCallTo = SIMULATE;
        stateManager->simulate(functionCallTo);

        functionCallTo = DRAW;
        stateManager->simulate(functionCallTo);
    }
}
