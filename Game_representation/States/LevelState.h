//
// Created by henri kerch on 24/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_LEVELSTATE_H
#define INC_2022_PROJECT_HENREY_T_LEVELSTATE_H

#include "State.h"
#include "../../Game_Logic/World.h"
#include "../../Game_Logic/structures_enums_std_include.h"
#include "../../Game_Logic/Camera.h"
#include "../ConcreteFactory.h"

/**
 * forward declaration of statemanager
 * include of statemanager in .cpp
 */
class StateManager;
class LevelState: public State {
private:
    //sfml elements
    Texture textureBackground;
    Sprite spriteBackground;

    // selfmade classes/structs
    World world;
    KeyboardInput keyboardInput;

    InputParser inputParser;

    shared_ptr<Camera> camera = Camera::getInstance();

    int chosenLevel;

//    bool screenMoved;
//    Vector2f newViewPosition{};

public:
    /**
     * constructor
     * @param sfWindow
     */
    LevelState(StateManager& stateManager, int chosenLevel);
    virtual ~LevelState() override;
    /**
     *
     */
     void startup(int chosenLevel);
    /**
     * event is passed to this method
     * the event holds which keys are pressed
     * @param event
     */
    virtual void userInput(Event &event);
    /**
     * updates the playerModel
     */
    virtual void simulate();
    /**
     * calls method in world that updates the views
     */
    virtual void draw();


    /**
     *
     */
    bool checkPlayerDeath();
    bool checkPlayerReachGoal();

    void moveScreen();
};

#endif // INC_2022_PROJECT_HENREY_T_LEVELSTATE_H
