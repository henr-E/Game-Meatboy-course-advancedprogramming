//
// Created by henri kerch on 10/12/2022.
//
#include "Model.h"
void ownModel::Model::updateObservers() { Subject::updateObservers(); }
const ownType::Position& ownModel::Model::getLeftUpperCorner() const { return leftUpperCorner; }
void ownModel::Model::setLeftUpperCorner(const ownType::Position& leftUpperCorner1) {
    Model::leftUpperCorner = leftUpperCorner1;
}
const ownType::Position& ownModel::Model::getRightDownCorner() const { return rightDownCorner; }
void ownModel::Model::setRightDownCorner(const ownType::Position& rightDownCorner1) {
    Model::rightDownCorner = rightDownCorner1;
}
ownType::TileType ownModel::Model::getTileType() const { return tileType; }
void ownModel::Model::setTileType(const ownType::TileType& tileType1) { Model::tileType = tileType1; }
float ownModel::Model::getTileHeightWidth() const { return tileHeightWidth; }
void ownModel::Model::setTileHeightWidth(const float& tileHeightWidth1) { Model::tileHeightWidth = tileHeightWidth1; }
const vector<shared_ptr<Observer>>& ownModel::Model::getObserverList() const { return Subject::getObserverList(); }
