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

class State {
public:
    explicit State(const shared_ptr<RenderWindow>& sfWindow);

    //    void setSfWindow(shared_ptr<RenderWindow>& sfWindow);
//    const shared_ptr<RenderWindow>& getSfWindow() const;

    virtual void userInput(Event &event);
    virtual void simulate();

    virtual void draw();

    bool isTransition() const;
    void setTransition(bool transition);

    int getChosenLevel() const;
    void setChosenLevel(int chosenLevel);

    virtual const Vector2i& getScreenDimensions() const;

protected:

    int chosenLevel;
    bool transition;
    Vector2i screenDimensions;
    shared_ptr<RenderWindow> sfWindow;
};

#endif // INC_2022_PROJECT_HENREY_T_STATE_H
