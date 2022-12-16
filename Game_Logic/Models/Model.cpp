//
// Created by henri kerch on 10/12/2022.
//
#include "Model.h"
void ownModel::Model::updateObservers() { Subject::updateObservers();}
const Position& ownModel::Model::getLeftUpperCorner() const { return leftUpperCorner; }
void ownModel::Model::setLeftUpperCorner(const Position& leftUpperCorner1) { Model::leftUpperCorner = leftUpperCorner1; }
const Position& ownModel::Model::getRightDownCorner() const { return rightDownCorner; }
void ownModel::Model::setRightDownCorner(const Position& rightDownCorner1) { Model::rightDownCorner = rightDownCorner1; }
TileType ownModel::Model::getTileType() const { return tileType; }
void ownModel::Model::setTileType(const TileType& tileType1) { Model::tileType = tileType1; }
float ownModel::Model::getTileHeightWidth() const { return tileHeightWidth; }
void ownModel::Model::setTileHeightWidth(const float& tileHeightWidth1) { Model::tileHeightWidth = tileHeightWidth1; }
const vector<shared_ptr<Observer>>& ownModel::Model::getObserverList() const { return Subject::getObserverList(); }
