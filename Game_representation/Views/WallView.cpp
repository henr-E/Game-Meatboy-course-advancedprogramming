//
// Created by henri kerch on 08/12/2022.
//

#include "WallView.h"


WallView::WallView(const Position& modelPosition, TileType modelTileType, const shared_ptr<RenderWindow>& sfWindow)
    : View(modelPosition, modelTileType, sfWindow) {

    //transform coordinates
    Position p = camera->coordinatesToPixel(modelPosition.x, modelPosition.y);

    if (!modelTexture.loadFromFile("../content/tileset.png", IntRect(64, 0, 32, 32))){
        cout << "Can't find file with tileTexture for walls => using green rectangle" <<endl;
        rectangle.setSize(Vector2f(32, 32));
        rectangle.setPosition(p.x, p.y);
        rectangle.setFillColor(sf::Color(130, 220, 120));
        textureFileExists = false;
    }
    else{
        modelSprite.setPosition(p.x, p.y);
        modelSprite.setTexture(modelTexture);
        textureFileExists = true;
    }
}

void WallView::update() {
    if(textureFileExists){
        sfWindow->draw(modelSprite);
    }
    else{
        sfWindow->draw(rectangle);
    }
}
void WallView::updateData(Position position, Direction direction){}



