//
// Created by henri kerch on 24/11/2022.
//

#include "State.h"
State::State(StateManager& stateManager, shared_ptr<RenderWindow>& sfWindow)
    : stateManager(stateManager), sfWindow(sfWindow) {}

void State::userInput(Event &event) {}
void State::draw() {}
void State::simulate() {}

