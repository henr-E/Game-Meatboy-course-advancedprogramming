//
// Created by henri kerch on 13/11/2022.
//

#include "World.h"

void World::setUp(vector<vector<WallModel>>& tiles1) {
    tiles = tiles1;
    player = abstractFactory->createPlayer(screenDimensions);
    goal = abstractFactory->createGoal(screenDimensions);
    wall = abstractFactory->createWalls(tiles, screenDimensions);
}
void World::keyboardToPlayer(KeyboardInput keyboardInput){
    player.updateFromKeyboard(keyboardInput);
}

void World::updatePlayerModel(){
    collision.setAllFalse();
    checkCollisionWithTiles();
    checkCollisionWallsBotom();
    player.setCollision(collision);
    float elapsed = stopwatch->getDifference();
    player.simulate(elapsed);
}
void World::updateViews() {
    wall.updateObservers();
    goal.updateObservers();

    for(auto &observer: player.getObserverList()){
        observer->updateData(player.getLeftUpperCorner());
    }

    player.updateObservers();
}
void World::checkCollisionWithTiles() {

    float playerXUp = player.getLeftUpperCorner().x;
    float playerYUp = player.getLeftUpperCorner().y;

    float playerX = playerXUp + player.getTileHeightWidth()/2;
    float playerY = playerYUp + player.getTileHeightWidth()/2;

    int currentPlayerRow = floor((playerY+ 1.f) / tileSize) - 1;
    int currentPlayerColumn = floor((playerX + 1.f) / tileSize);

//    cout << "currentPlayerRow " << currentPlayerRow <<endl;
//    cout << "currentPlayerColumn " << currentPlayerColumn<<endl;
    WallModel currentTile{}, upTile{}, downTile{}, leftTile{}, leftDownTile{}, leftUpperTile{}, rightTile{}, rightUpperTile{}, rightDownTile{};

    //all row + 1
    if (currentPlayerRow + 1 <= tiles.size()-1){
        upTile = tiles[currentPlayerRow + 1][currentPlayerColumn];

        if(currentPlayerColumn - 1 > 0) {
            leftUpperTile = tiles[currentPlayerRow + 1][currentPlayerColumn - 1];
        }
        if(currentPlayerColumn + 1 < tiles[0].size()) {
            rightUpperTile = tiles[currentPlayerRow + 1][currentPlayerColumn + 1];
        }
    }
    //all row -1
    if(currentPlayerRow - 1 >= 0){
        downTile = tiles[currentPlayerRow - 1][currentPlayerColumn];

        if(currentPlayerColumn - 1 > 0) {
            leftDownTile = tiles[currentPlayerRow - 1][currentPlayerColumn - 1];
        }
        if(currentPlayerColumn + 1 < tiles[0].size()) {
            rightDownTile = tiles[currentPlayerRow - 1][currentPlayerColumn + 1];

        }
    }
    //all just rows
    if(currentPlayerColumn + 1 <= tiles[0].size()-1){
        rightTile = tiles[currentPlayerRow][currentPlayerColumn + 1];
        if(currentPlayerColumn - 1 > 0) {
            leftTile = tiles[currentPlayerRow][currentPlayerColumn - 1];
        }
    }

//        // get tile where current tile is at
//        currentTile = tiles[currentPlayerRow][currentPlayerColumn];

    if (rightTile.getTileType() == block and player.intersects(rightTile, Right)) {
//        cout << "collision RIGHT"<< endl;
        collision.collisionRight = true;
    }
    if (leftTile.getTileType() == block and player.intersects(leftTile, Left)) {
        collision.collisionLeft = true;
//        cout << "collision LEFT"<< endl;
    }
    if (upTile.getTileType() == block and player.intersects(upTile, Up)) {
        collision.collisionUp = true;
//        cout << "collision UP"<< endl;
    }
    if (downTile.getTileType() == block and player.intersects(downTile, Down)) {
        collision.collisionDown = true;
//        cout << "collision DOWN"<< endl;
    }
    if (leftUpperTile.getTileType() == block  and player.intersects(leftUpperTile, Left)) {
        collision.collisionUp = true;
    }
    if (rightUpperTile.getTileType() == block  and player.intersects(rightUpperTile, Right)) {
        collision.collisionUp = true;
    }
    if (leftDownTile.getTileType() == block  and player.intersects(leftDownTile,Up)) {
        collision.collisionDown = true;
    }
    if (rightDownTile.getTileType() == block  and player.intersects(rightDownTile,Down)) {
        collision.collisionDown = true;
    }
}
void World::checkCollisionWallsBotom(){
    float XLeft= player.getLeftUpperCorner().x;
    float XRight= player.getRightDownCorner().x;

    float YUp= player.getLeftUpperCorner().y;
    float YDown= player.getRightDownCorner().y;

    // collisionWithGround
    if (YDown <= -1) {
        collision.collisionDown = true;
    }
     // collisionRightWall
    if (XRight >= 1) {
        collision.collisionRight = true;
    }
    // collisionLeftWall
    if (XLeft <= -1) {
        collision.collisionLeft = true;
    }
}
void World::setAbstractFactory(const shared_ptr<AbstractFactory>& abstractFactory) {
    World::abstractFactory = abstractFactory;
}
void World::setScreenDimensions(const Position& screenDimensions) { World::screenDimensions = screenDimensions; }
void World::setTileSize(float tileSize) { World::tileSize = tileSize; }
