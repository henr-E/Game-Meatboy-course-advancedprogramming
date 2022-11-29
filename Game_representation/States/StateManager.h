//
// Created by henri kerch on 25/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_STATEMANAGER_H
#define INC_2022_PROJECT_HENREY_T_STATEMANAGER_H
#include "MenuState.h"
#include "LevelState.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum CurrentState {
    levelstate,
    menustate
};

enum FunctionCallTo{
    DRAW,
    INPUT,
    SIMULATE
};


class StateManager {
private:
    shared_ptr<RenderWindow> sfWindow;
    shared_ptr<State> state = make_shared<LevelState>();
    //TODO CHANGE BACK
//    shared_ptr<State> state = make_shared<MenuState>();

    Event event;

    CurrentState currentState;

public:
    StateManager();

    void simulate(FunctionCallTo functionCallTo);
    void checkTransition();

    void setSfWindow(shared_ptr<RenderWindow>& sfWindow);
    void setEvent(Event& event);
};

#endif // INC_2022_PROJECT_HENREY_T_STATEMANAGER_H
