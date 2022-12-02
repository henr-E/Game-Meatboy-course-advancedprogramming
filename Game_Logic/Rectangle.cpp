//
// Created by henri kerch on 30/11/2022.
//

#include "Rectangle.h"
Position Rectangle::getLeftUpperCorner() const { return leftUpperCorner; }
void Rectangle::setLeftUpperCorner(Position leftUpperCorner) { Rectangle::leftUpperCorner = leftUpperCorner; }
Position Rectangle::getRightDownCorner() const { return rightDownCorner; }
void Rectangle::setRightDownCorner(Position rightDownCorner) { Rectangle::rightDownCorner = rightDownCorner; }
TileType Rectangle::getTileType() const { return tileType; }
void Rectangle::setTileType(TileType tileType) { Rectangle::tileType = tileType; }
float Rectangle::getTileHeightWidth() const { return tileHeightWidth; }
void Rectangle::setTileHeightWidth(float tileHeightWidth) { Rectangle::tileHeightWidth = tileHeightWidth; }
bool Rectangle::intersects(const Rectangle& that, CheckCollision checkCollision) {}
