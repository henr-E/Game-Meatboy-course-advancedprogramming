//
// Created by henri kerch on 24/11/2022.
//

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
    vector<Text> allTexts;

public:
    MenuState();
    virtual void getUserInput(Event &event);
    virtual void draw();
    virtual void simulate();
    void startUp();
    void makeTexts();
};


#endif // INC_2022_PROJECT_HENREY_T_MENUSTATE_H
