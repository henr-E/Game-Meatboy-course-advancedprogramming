//
// Created by henri kerch on 24/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_STATE_H
#define INC_2022_PROJECT_HENREY_T_STATE_H
#include "../Views/View.h"
#include "memory"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;
class StateManager;
class State {
public:
    State(StateManager& stateManager);
    virtual ~State();
    //    void setSfWindow(shared_ptr<RenderWindow>& sfWindow);
//    const shared_ptr<RenderWindow>& getSfWindow() const;

    virtual void userInput(Event &event);
    virtual void simulate();

    virtual void draw();

protected:
    /**
     * hold a reference to the stateManager to change the state
     */
    StateManager& stateManager;
    int chosenLevel;
};

#endif // INC_2022_PROJECT_HENREY_T_STATE_H
