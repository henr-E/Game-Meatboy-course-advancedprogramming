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

class LevelState:public State {
private:
    //selfmade classes/structs
    World world;
    KeyboardInput keyboardInput;

    vector<vector<WallModel>> tiles;
    InputParser inputParser;

    shared_ptr<Camera> camera = Camera::getInstance();

//    bool screenMoved;
//    Vector2f newViewPosition{};

public:
    explicit LevelState(const shared_ptr<RenderWindow>& sfWindow);
    virtual void userInput(Event &event);
    virtual void simulate();
    virtual void draw();

    void moveScreen();
    void checkPlayerDeath();
};

#endif // INC_2022_PROJECT_HENREY_T_LEVELSTATE_H
