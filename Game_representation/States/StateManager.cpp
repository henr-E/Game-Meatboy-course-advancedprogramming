//
// Created by henri kerch on 25/11/2022.
//

#include "StateManager.h"

StateManager::StateManager(shared_ptr<RenderWindow>& sfWindow) : sfWindow(sfWindow) {
    state = make_shared<MenuState>(*this, sfWindow);
}

void StateManager::setEvent(Event& event) {
    StateManager::event = event;
}

void StateManager::simulate(FunctionCallTo functionCallTo) {
    if (functionCallTo == INPUT){
        state->userInput(event);
    }
    if (functionCallTo == DRAW){
        state->draw();
    }
    if (functionCallTo == SIMULATE){
        state->simulate();
    }
}
void StateManager::setState(const shared_ptr<State>& state) { StateManager::state = state; }
const shared_ptr<RenderWindow>& StateManager::getSfWindow() const { return sfWindow; }
