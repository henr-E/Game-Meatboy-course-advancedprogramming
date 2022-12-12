//
// Created by henri kerch on 24/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_MENUSTATE_H
#define INC_2022_PROJECT_HENREY_T_MENUSTATE_H

#include "State.h"
class MenuState: public State {
private:
    //sfml elements
    Texture textureBackground;
    Sprite spriteBackground;

    //sfml elements
    sf::Text welcomeText;
    sf::Text level1;
    sf::Text level2;
    sf::Text level3;
    sf::Text level4;
    sf::Text level5;

    Font font;

    Vector2i mousePosition;
    vector<Text> allTexts = {level1, level2, level3, level4, level5};

public:
    explicit MenuState(const shared_ptr<RenderWindow>& sfWindow);
    virtual void userInput(Event &event);
    virtual void simulate();
    virtual void draw();
    void makeTexts();

    const Texture& getTextureBackground() const;
    const Sprite& getSpriteBackground() const;
    const Font& getFont() const;
    const vector<Text>& getAllTexts() const;
    const Text& getWelcomeText() const;
};


#endif // INC_2022_PROJECT_HENREY_T_MENUSTATE_H
