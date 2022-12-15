//
// Created by henri kerch on 25/11/2022.
//

#include "StateManager.h"

StateManager::StateManager(const shared_ptr<RenderWindow>& sfWindow) : sfWindow(sfWindow) {
    shared_ptr<State> state1 = make_shared<MenuState>(*this);
    state = state1;
}

//void StateManager::setSfWindow(shared_ptr<RenderWindow>& sfWindow) {
//    StateManager::sfWindow = sfWindow;
////    state->setSfWindow(sfWindow);
//}

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
StateManager::~StateManager() {}
