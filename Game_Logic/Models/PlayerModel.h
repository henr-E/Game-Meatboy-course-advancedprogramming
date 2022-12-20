//
// Created by henri kerch on 08/12/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_PLAYERMODEL_H
#define INC_2022_PROJECT_HENREY_T_PLAYERMODEL_H
#include "../structures_enums_std_include.h"
#include "Model.h"
#include "iostream"
#include <cmath>

using namespace std;
class PlayerModel : public ownModel::Model {
    float verticalSpeed;
    float horizontalSpeed;
    float accelerationX;
    float accelerationY;
    float gravity;

    bool keyboardLeft;
    bool keyboardRight;
    bool jumpWallLeft;
    bool jumpWallRight;

    ownType::Direction direction;

    ownType::Collision collision;
    ownType::Position previousLeftUpperCorner;

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
    void updateFromKeyboard(ownType::KeyboardInput keyboardInput);
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
    ownType::Direction getDirection() const;
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
    void setCollision(const ownType::Collision& collision);
    /**
     *
     * @return previous position
     */
    const ownType::Position& getPreviousLeftUpperCorner() const;
};
#endif // INC_2022_PROJECT_HENREY_T_PLAYERMODEL_H
