//
// Created by henri kerch on 08/12/2022.
//

#include "WallView.h"

WallView::WallView(ownModel::Model& model, const vector<vector<WallModel>>& tiles) : View(model), tiles(tiles) {
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
    drawTiles();
}

void WallView::drawTiles() {
    Texture textureTileOther;
    Texture textureTileGirl;
    Texture textureTileBlock;

    Sprite spriteTile;

    if (textureTileOther.loadFromFile("../content/tileset.png", IntRect(160, 0, 32, 32))){

    }

    if (textureTileGirl.loadFromFile("../content/tileset.png", IntRect(0, 0, 32, 32))){

    }

    if (textureTileBlock.loadFromFile("../content/tileset.png", IntRect(64, 0, 32, 32))){

    }

    for(auto const &row : tiles){
        for(auto const &rect : row){

            float XLeft = rect.getLeftUpperCorner().x;
            float YUp = rect.getLeftUpperCorner().y;

            if(rect.getTileType() == other){
                spriteTile.setTexture(textureTileOther);
            }
            else if(rect.getTileType() == girlfriend){
                spriteTile.setTexture(textureTileGirl);
            }
            else if(rect.getTileType() == block){
                spriteTile.setTexture(textureTileBlock);
            }

            //transform coordinates
            Position p = camera.coordinatesToPixel(XLeft, YUp);

            spriteTile.setPosition(p.x, p.y);


            sfWindow->draw(spriteTile);
        }
    }
}
