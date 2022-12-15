//
// Created by henri kerch on 25/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_STATEMANAGER_H
#define INC_2022_PROJECT_HENREY_T_STATEMANAGER_H

#include "LevelState.h"
#include "MenuState.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../../Game_Logic/structures_enums_std_include.h"


class StateManager {
private:
    shared_ptr<RenderWindow> sfWindow;
    shared_ptr<State> state;

    Event event;

public:
    explicit StateManager(const shared_ptr<RenderWindow>& sfWindow);
    virtual ~StateManager();
    void simulate(FunctionCallTo functionCallTo);


    void setState(const shared_ptr<State>& state);
    void setEvent(Event& event);

    const shared_ptr<RenderWindow>& getSfWindow() const;
};

#endif // INC_2022_PROJECT_HENREY_T_STATEMANAGER_H
