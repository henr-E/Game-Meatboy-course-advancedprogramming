//
// Created by henri kerch on 24/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_LEVELSTATE_H
#define INC_2022_PROJECT_HENREY_T_LEVELSTATE_H

#include "State.h"
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

    Camera camera;

    vector<vector<Rectangle>> tiles;
    //selfmade classes/structs
    World world;
    KeyboardInput keyboardInput;
    InputParser inputParser;

public:
    LevelState();
    virtual void userInput(Event &event);
    virtual void simulate();
    virtual void draw();

    virtual const Vector2i& getScreenDimensions() const;
    const Texture& getTextureBackground() const;
    const Sprite& getSpriteBackground() const;
    const Sprite& getSpritePlayer() const;
    const Texture& getTexturePlayer() const;
    const vector<vector<Rectangle>>& getTiles() const;
    const World& getWorld() const;
    const Camera& getCamera() const;
    void updateView();
};

#endif // INC_2022_PROJECT_HENREY_T_LEVELSTATE_H
