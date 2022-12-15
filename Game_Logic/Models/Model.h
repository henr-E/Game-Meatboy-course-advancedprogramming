//
// Created by henri kerch on 02/12/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_MODEL_H
#define INC_2022_PROJECT_HENREY_T_MODEL_H
#include "../structures_enums_std_include.h"
#include "../Subject.h"
#endif // INC_2022_PROJECT_HENREY_T_MODEL_H
namespace ownModel {
    class Model: public Subject {
    protected:
        Position leftUpperCorner;
        Position rightDownCorner;

        TileType tileType;
        float tileHeightWidth;

    public:
        Model();
        virtual ~Model() override;

        virtual void updateObservers() override;

        virtual const Position& getLeftUpperCorner() const;
        virtual void setLeftUpperCorner(const Position& leftUpperCorner);

        virtual const Position& getRightDownCorner() const;
        virtual void setRightDownCorner(const Position& rightDownCorner);

        virtual TileType getTileType() const;
        virtual void setTileType(const TileType& tileType);

        virtual float getTileHeightWidth() const;
        virtual void setTileHeightWidth(const float& tileHeightWidth);

        const vector<shared_ptr<Observer>>& getObserverList() const override;
    };
}