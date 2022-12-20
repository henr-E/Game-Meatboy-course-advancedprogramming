//
// Created by henri kerch on 02/12/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_MODEL_H
#define INC_2022_PROJECT_HENREY_T_MODEL_H

#include "../Subject.h"
#include "../structures_enums_std_include.h"

namespace ownModel {
class Model : public Subject {
protected:
    ownType::Position leftUpperCorner;
    ownType::Position rightDownCorner;
    ownType::TileType tileType;
    float tileHeightWidth;

public:
    /**
     * default constructor
     */
    Model() = default;
    /**
     * destructor
     */
    ~Model() override = default;
    /**
     * update all observers
     * in this game each model has its own observer
     */
    void updateObservers() override;
    /**
     *
     * @return LeftUpperCorner
     */
    virtual const ownType::Position& getLeftUpperCorner() const;
    /**
     *
     * @param leftUpperCorner
     */
    virtual void setLeftUpperCorner(const ownType::Position& leftUpperCorner);
    /**
     *
     * @return RightDownCorner
     */
    virtual const ownType::Position& getRightDownCorner() const;
    /**
     *
     * @param rightDownCorner
     */
    virtual void setRightDownCorner(const ownType::Position& rightDownCorner);
    /**
     *
     * @return TileType
     */
    virtual ownType::TileType getTileType() const;
    /**
     *
     * @param tileType
     */
    virtual void setTileType(const ownType::TileType& tileType);
    /**
     *
     * @return height/width
     */
    virtual float getTileHeightWidth() const;
    /**
     *
     * @param tileHeightWidth
     */
    virtual void setTileHeightWidth(const float& tileHeightWidth);
    /**
     *
     * @return all observers for this model
     */
    const vector<shared_ptr<Observer>>& getObserverList() const override;
};
} // namespace ownModel
#endif // INC_2022_PROJECT_HENREY_T_MODEL_H