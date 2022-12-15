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

    void updateFromKeyboard(KeyboardInput keyboardInput);

    void simulate(float elapsedTime);


    Direction getDirection() const;

    bool intersects(const Model &that, CheckCollision checkCollision);

    void setCollision(const Collision& collision);

    const Position& getPreviousLeftUpperCorner() const;

    const Position& getLeftUpperCorner() const override{
        return leftUpperCorner;
    }
    const Position& getRightDownCorner() const override{
        return rightDownCorner;
    }
    float getTileHeightWidth() const override{
        return tileHeightWidth;
    }
    TileType getTileType() const override{
        return tileType;
    }


    void setLeftUpperCorner(const Position& leftUpperCorner) override{
        Model::leftUpperCorner = leftUpperCorner;
    }
    void setRightDownCorner(const Position& rightDownCorner) override{
        Model::rightDownCorner = rightDownCorner;
    }
    void setTileHeightWidth(const float& tileHeightWidthNew) override{
        Model::tileHeightWidth = tileHeightWidthNew;
    }
    void setTileType(const TileType& tileType1) override{
        Model::tileType = tileType1;
    }
};
#endif // INC_2022_PROJECT_HENREY_T_PLAYERMODEL_H
