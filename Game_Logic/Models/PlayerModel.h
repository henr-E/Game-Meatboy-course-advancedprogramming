//
// Created by henri kerch on 08/12/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_PLAYERMODEL_H
#define INC_2022_PROJECT_HENREY_T_PLAYERMODEL_H
#include <cmath>
#include "Model.h"
#include "iostream"
#include "../structures_enums_std_include.h"

using namespace std;
class PlayerModel: public ownModel::Model{
    float verticalSpeed;
    float horizontalSpeed;
    float accelerationX;
    float accelerationY;
    float gravity;

    bool keyboardLeft;
    bool keyboardRight;
    bool jumpWallLeft;
    bool jumpWallRight;

    Direction direction;

    Collision collision;
    Position previousLeftUpperCorner;
public:
    /**
     * constructor
     */
    PlayerModel();
    /**
     * destructor
     */
    ~PlayerModel() override;
    /**
     * the world passes keyboard user input to the player
     * @param keyboardInput
     */
    void updateFromKeyboard(KeyboardInput keyboardInput);
    /**
     * simulate the speed, position, ...
     * @param elapsedTime
     */
    void simulate(float elapsedTime);
    /**
     *
     * @return Direction of the player
     * this is used to define the playerSprite
     */
    Direction getDirection() const;
    /**
     *checks if 2 models intersect
     * @param that
     * @return
     */
    bool intersects(const shared_ptr<Model>& that);
    /**
     *
     * @param collision
     */
    void setCollision(const Collision& collision);
    /**
     *
     * @return previous position
     */
    const Position& getPreviousLeftUpperCorner() const;
};
#endif // INC_2022_PROJECT_HENREY_T_PLAYERMODEL_H
