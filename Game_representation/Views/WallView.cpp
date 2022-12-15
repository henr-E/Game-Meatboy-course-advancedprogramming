//
// Created by henri kerch on 08/12/2022.
//

#include "WallView.h"


WallView::WallView(const Position& modelPosition, TileType modelTileType, const shared_ptr<RenderWindow>& sfWindow)
    : View(modelPosition, modelTileType, sfWindow) {
    if (modelTexture.loadFromFile("../content/tileset.png", IntRect(64, 0, 32, 32))){
        //TODO throw exception
    }
    modelSprite.setTexture(modelTexture);

}

WallView::~WallView() {}

void WallView::update() {
    //transform coordinates
    Position p = camera->coordinatesToPixel(modelPosition.x, modelPosition.y);
    modelSprite.setPosition(p.x, p.y);

    sfWindow->draw(modelSprite);
}
void WallView::updateData(Position position, Direction direction){}



