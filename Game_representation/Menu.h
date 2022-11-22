//
// Created by henri kerch on 22/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_MENU_H
#define INC_2022_PROJECT_HENREY_T_MENU_H

#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Game_Logic/structures_enums.h"

///The code using namespace sf; enables us to omit the prefix sf:: from everywhere in our code.
using namespace sf;
using namespace std;

class Menu {;
private:
    ///window
    VideoMode gameVideoMode;
    RenderWindow gameWindow;
    Vector2i screenDimensions;

    Texture textureBackground;
    Sprite spriteBackground;
    Font font;
    SoundBuffer buffer;
    Sound sound;

    KeyboardInput keyboardInput;

public:
    Menu();
    void simulate();
    void userInput(Event event);

    void startingSetup();
    void updateView();

};

#endif // INC_2022_PROJECT_HENREY_T_MENU_H
