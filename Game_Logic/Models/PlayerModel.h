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
    Direction direction;

    float verticalSpeed;
    float horizontalSpeed;
    float acceleration;
    float gravity;

    /// Which direction(s) is the player currently moving in
    bool keyboardLeft;
    bool keyboardRight;
    bool jumpWallLeft;
    bool jumpWallRight;

    Collision collision;

    Position previousLeftUpperCorner;
public:

    void updateObservers() override;

    PlayerModel();

    ~PlayerModel() override;

    void updateFromKeyboard(KeyboardInput keyboardInput);

    void simulate(float elapsedTime);

    Direction getDirection() const;

    bool intersects(const shared_ptr<Model>& that);

    void setCollision(const Collision& collision);

    const Position& getPreviousLeftUpperCorner() const;

};
#endif // INC_2022_PROJECT_HENREY_T_PLAYERMODEL_H
