//
// Created by henri kerch on 08/12/2022.
//

#include "WallView.h"

WallView::WallView(const shared_ptr<RenderWindow>& sfWindow,
                   const vector<vector<WallModel>>& tiles): View(sfWindow), tiles(tiles) {
    setUp();
}

void WallView::setUp() {
    // load background
    if (!textureBackground.loadFromFile("../content/Background_blurred.png")) {
        cout << "Failed to load background into texture." << endl;
    }
    // configure sprite
    spriteBackground.setTexture(textureBackground);

    spriteBackground.setScale(1, (float)1024 / textureBackground.getSize().y);
}


void WallView::update() {
    sfWindow->clear();
    sfWindow->draw(spriteBackground);

    drawTiles();
}

void WallView::drawTiles() {
    Texture textureTileOther;
    Texture textureTileGirl;
    Texture textureTileBlock;

    Sprite spriteTile;

    if (textureTileOther.loadFromFile("../content/tileset.png", IntRect(256, 0, 32, 32))){

    }

    if (textureTileGirl.loadFromFile("../content/tileset.png", IntRect(0, 0, 32, 32))){

    }

    if (textureTileBlock.loadFromFile("../content/tileset.png", IntRect(64, 0, 32, 32))){

    }

    for(auto const &row : tiles){
        for(auto const & wallModel : row){

            float XLeft = wallModel.getLeftUpperCorner().x;
            float YUp = wallModel.getLeftUpperCorner().y;

            if(wallModel.getTileType() == other){
                spriteTile.setTexture(textureTileOther);
            }
            else if(wallModel.getTileType() == girlfriend){
                spriteTile.setTexture(textureTileGirl);
            }
            else if(wallModel.getTileType() == block){
                spriteTile.setTexture(textureTileBlock);
            }
            //transform coordinates
            Position p = camera->coordinatesToPixel(XLeft, YUp);
            spriteTile.setPosition(p.x, p.y);
            sfWindow->draw(spriteTile);
        }
    }
}
void WallView::updateData(Position position, Direction direction) {}

