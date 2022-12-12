//
// Created by henri kerch on 10/12/2022.
//
#include "Model.h"
ownModel::Model::Model() {}
void ownModel::Model::updateObservers() { Subject::updateObservers();}

const Position& ownModel::Model::getLeftUpperCorner() const { return leftUpperCorner; }
void ownModel::Model::setLeftUpperCorner(const Position& leftUpperCorner) { Model::leftUpperCorner = leftUpperCorner; }
const Position& ownModel::Model::getRightDownCorner() const { return rightDownCorner; }
void ownModel::Model::setRightDownCorner(const Position& rightDownCorner) { Model::rightDownCorner = rightDownCorner; }
TileType ownModel::Model::getTileType() const { return tileType; }
void ownModel::Model::setTileType(const TileType& tileType) { Model::tileType = tileType; }
float ownModel::Model::getTileHeightWidth() const { return tileHeightWidth; }
void ownModel::Model::setTileHeightWidth(const float& tileHeightWidth) { Model::tileHeightWidth = tileHeightWidth; }
const vector<shared_ptr<Observer>>& ownModel::Model::getObserverList() const { return Subject::getObserverList(); }
