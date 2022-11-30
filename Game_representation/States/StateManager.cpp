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
//    cout << "event in StatemanagerSETTER = " << &event <<endl;
    StateManager::event = event;
}

void StateManager::simulate(FunctionCallTo functionCallTo) {
    if (functionCallTo == INPUT){
//        cout << "event in Statemanager = " << &event <<endl;
        state->getUserInput(event);
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
            cout << "sfwindow before trans    " << sfWindow <<endl;
            int chosenLevel = state->getChosenLevel();
            shared_ptr<State> newState = make_shared<LevelState>();
            state = newState;
            state->setChosenLevel(chosenLevel);
            currentState = levelstate;
        }
        else if(currentState == levelstate){
            shared_ptr<State> newState = make_shared<MenuState>();
            state = newState;
            currentState = menustate;
        }
        state->setSfWindow(sfWindow);
        cout << "sfwindow after trans    " << state->getSfWindow() <<endl;
        state->setTransition(false);
    }
}
