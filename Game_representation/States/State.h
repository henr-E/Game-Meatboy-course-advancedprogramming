//
// Created by henri kerch on 24/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_STATE_H
#define INC_2022_PROJECT_HENREY_T_STATE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "memory"

#include <iostream>

using namespace sf;
using namespace std;

class State {
public:
    State();

    void setSfWindow(shared_ptr<RenderWindow>& sfWindow);
    const shared_ptr<RenderWindow>& getSfWindow() const;

    virtual void getUserInput(Event event);
    virtual void draw();
    virtual void simulate();

    bool isTransition() const;
    void setTransition(bool transition);

    int getChosenLevel() const;
    void setChosenLevel(int chosenLevel);


protected:
    int chosenLevel;
    bool transition;
    Vector2i screenDimensions;
    shared_ptr<RenderWindow> sfWindow;
    Texture textureBackground;
    Sprite spriteBackground;


};

#endif // INC_2022_PROJECT_HENREY_T_STATE_H
