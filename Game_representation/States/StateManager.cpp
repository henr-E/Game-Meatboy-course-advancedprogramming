//
// Created by henri kerch on 25/11/2022.
//

#include "StateManager.h"

StateManager::StateManager() {
    currentState = menustate;
}
void StateManager::setSfWindow(shared_ptr<RenderWindow>& sfWindow) {
    StateManager::sfWindow = sfWindow;
    state->setSfWindow(sfWindow);
}

void StateManager::setEvent(Event& event) {
    StateManager::event = event;
}

void StateManager::simulate(FunctionCallTo functionCallTo) {
    if (functionCallTo == INPUT){
        state->userInput(event);
        checkTransition();
    }
    if (functionCallTo == DRAW){
        state->draw();
    }
    if (functionCallTo == SIMULATE){
        state->simulate();
    }
}

void StateManager::checkTransition() {
    if (state->isTransition()){
        if(currentState == menustate){
            int chosenLevel = state->getChosenLevel();

            shared_ptr<State> newState = make_shared<LevelState>();
            state = newState;
            currentState = levelstate;

            state->setChosenLevel(chosenLevel);
        }
        else if(currentState == levelstate){
            shared_ptr<State> newState = make_shared<MenuState>();
            state = newState;
            currentState = menustate;
        }
        state->setSfWindow(sfWindow);
        state->setTransition(false);
    }
}

