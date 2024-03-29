//
// Created by henri kerch on 25/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_STATEMANAGER_H
#define INC_2022_PROJECT_HENREY_T_STATEMANAGER_H

#include "LevelState.h"
#include "MenuState.h"

#include "../../Game_Logic/structures_enums_std_include.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class StateManager {
private:
    shared_ptr<RenderWindow> sfWindow;
    shared_ptr<State> state;
    Event event;

public:
    /**
     *
     * @param sfWindow
     */
    explicit StateManager(shared_ptr<RenderWindow>& sfWindow);
    /**
     *
     */
    virtual ~StateManager() = default;
    /**
     * run draw, input and simulate of game
     * @param functionCallTo
     */
    void simulate(ownType::FunctionCallTo functionCallTo);
    /**
     *
     * @param state
     */
    void setState(const shared_ptr<State>& state);
    /**
     *
     * @param event
     */
    void setEvent(Event& event);
    /**
     *
     * @return sfWindow
     */
    const shared_ptr<RenderWindow>& getSfWindow() const;
};

#endif // INC_2022_PROJECT_HENREY_T_STATEMANAGER_H
