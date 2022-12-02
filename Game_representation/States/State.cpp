//
// Created by henri kerch on 24/11/2022.
//

#include "State.h"
State::State() {
    screenDimensions.x = 544;
    screenDimensions.y = 1024;
}

void State::userInput(Event &event) {}
void State::draw() {}
void State::simulate() {}
bool State::isTransition() const { return transition; }
void State::setSfWindow(shared_ptr<RenderWindow>& sfWindow) {
    State::sfWindow = sfWindow;
    view.setSfWindow(sfWindow);
}
int State::getChosenLevel() const { return chosenLevel; }
void State::setChosenLevel(int chosenLevel) { State::chosenLevel = chosenLevel; }
void State::setTransition(bool transition) { State::transition = transition; }
const shared_ptr<RenderWindow>& State::getSfWindow() const { return sfWindow; }
const Vector2i& State::getScreenDimensions() const { return screenDimensions; }
