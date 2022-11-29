//
// Created by henri kerch on 24/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_LEVELSTATE_H
#define INC_2022_PROJECT_HENREY_T_LEVELSTATE_H

#include "State.h"
#include <cmath>

#include "../Game_Logic/Player.h"
#include "../Game_Logic/World.h"
#include "../InputToGame/InputParser.h"
#include "../../Game_Logic/structures_enums_std_include.h"
#include "../../Game_Logic/Camera.h"

class LevelState:public State {
private:
    //sfml elements
    Texture textureBackground;
    Sprite spriteBackground;

    Sprite spritePlayer;
    Texture texturePlayer;

    Rect<float> playerRect;


    Camera camera;

    //selfmade classes/structs
    World world;
    KeyboardInput keyboardInput;
    InputParser inputParser;

    Collision collision;

public:
    LevelState();
    virtual void getUserInput(Event &event);
    virtual void draw();
    virtual void simulate();

    void checkCollision();
    void startUp();

    void updateView();
    void updatePlayerPosition();
};

#endif // INC_2022_PROJECT_HENREY_T_LEVELSTATE_H
