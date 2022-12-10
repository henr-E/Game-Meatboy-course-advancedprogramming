//
// Created by henri kerch on 08/12/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_WALLMODEL_H
#define INC_2022_PROJECT_HENREY_T_WALLMODEL_H

#include "Model.h"
class WallModel: public ownModel::Model{
public:
    WallModel() {}

    WallModel& operator=(const WallModel& that) {
        return *this;
    }

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

#endif // INC_2022_PROJECT_HENREY_T_WALLMODEL_H
