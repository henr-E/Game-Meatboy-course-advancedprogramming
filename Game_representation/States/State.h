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
protected:
    /**
     * hold a reference to the stateManager to change the state
     */
    StateManager& stateManager;
    int chosenLevel;
    //    shared_ptr<RenderWindow>& sfWindow;
public:
    //todo statemanager doorgeven in constructor
    /**
     *constructor
     */
    State(StateManager& stateManager);
    /**
     *destructor
     */
    virtual ~State() = default;
    /**
     *
     * @param event
     */
    virtual void userInput(Event &event);
    /**
     * simulate
     */
    virtual void simulate();
    /**
     * draw
     */
    virtual void draw();


};

#endif // INC_2022_PROJECT_HENREY_T_STATE_H
