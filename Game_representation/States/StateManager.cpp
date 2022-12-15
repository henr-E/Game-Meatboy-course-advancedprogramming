//
// Created by henri kerch on 25/11/2022.
//

#include "StateManager.h"

StateManager::StateManager(const shared_ptr<RenderWindow>& sfWindow) : sfWindow(sfWindow) {
    currentState = menustate;
    shared_ptr<State> state1 = make_shared<MenuState>(sfWindow);
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
        checkTransition();
    }
    if (functionCallTo == DRAW){
        state->draw();
    }
    if (functionCallTo == SIMULATE){
        state->simulate();
        checkTransition();
    }
}

void StateManager::checkTransition() {
    if (state->isTransition()){
        if(currentState == menustate){
            int chosenLevel = state->getChosenLevel();

            shared_ptr<State> newState = make_shared<LevelState>(sfWindow);
            state = newState;
            currentState = levelstate;

            state->setChosenLevel(chosenLevel);
        }
        else if(currentState == levelstate){
            shared_ptr<State> newState = make_shared<MenuState>(sfWindow);
            state = newState;
            currentState = menustate;
        }
        state->setTransition(false);
    }
}
