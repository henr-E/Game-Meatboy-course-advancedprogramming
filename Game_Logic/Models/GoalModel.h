//
// Created by henri kerch on 08/12/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_GOALMODEL_H
#define INC_2022_PROJECT_HENREY_T_GOALMODEL_H

#include "Model.h"
class GoalModel: public ownModel::Model{
public:
    virtual const Position& getLeftUpperCorner() const override{
        return leftUpperCorner;
    }
    virtual const Position& getRightDownCorner() const override{
        return rightDownCorner;
    }
    virtual float getTileHeightWidth() const override{
        return tileHeightWidth;
    }
    virtual TileType getTileType() const override{
        return tileType;
    }


    virtual void setLeftUpperCorner(const Position& leftUpperCorner) override{
        Model::leftUpperCorner = leftUpperCorner;
    }
    virtual void setRightDownCorner(const Position& rightDownCorner) override{
        Model::rightDownCorner = rightDownCorner;
    }
    void setTileHeightWidth(const float& tileHeightWidthNew) override{
        Model::tileHeightWidth = tileHeightWidthNew;
    }
    virtual void setTileType(const TileType& tileType1) override{
        Model::tileType = tileType1;
    }
};


#endif // INC_2022_PROJECT_HENREY_T_GOALMODEL_H
