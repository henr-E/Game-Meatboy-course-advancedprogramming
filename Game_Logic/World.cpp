//
// Created by henri kerch on 13/11/2022.
//

#include "World.h"

#include <utility>


World::World() {}

void World::keyboardToPlayer(KeyboardInput keyboardInput){
    player.updateFromKeyboard(keyboardInput);
}

void World::simulate(vector<vector<Rectangle>> tiles){
    collision.setAllFalse();
    checkCollisionWithTiles(tiles);
    checkCollisionWallsBotom();
    player.setCollision(collision);

    //calculate elapsed time
    auto diff = steady_clock::now() - stopwatch.getPrevTime();
    auto nanoseconds = duration_cast<chrono::nanoseconds>(diff);
    auto nanosecondsAsInt = nanoseconds.count();

    stopwatch.setPrevTime(steady_clock::now());
    float seconds = nanosecondsAsInt/(float)1000000000;

    player.simulate(seconds);
}
const Player & World::getPlayer() const{
    return player;
}

void World::setPlayer(const Player &player) {
    World::player = player;
}

void World::checkCollisionWithTiles(const vector<vector<Rectangle>> &tiles) {
    float playerX = player.getPlayerLeftUpperPosition().x;
    float playerY = player.getPlayerLeftUpperPosition().y;

    int amountOfRows = tiles.size();

    // list begins with index 0 so -1
    int currentPlayerRow = floor(abs(playerY + 1) / 2/17);
    int currentPlayerColumn = floor(abs(playerX + 1) / 2/17);


    Rectangle currentTile{}, upTile{}, downTile{}, leftTile{}, leftDownTile{}, leftUpperTile{}, rightTile{}, rightUpperTile{}, rightDownTile{};

    //all row + 1
    if (currentPlayerRow + 1 < tiles.size()){
        upTile = tiles[currentPlayerRow + 1][currentPlayerColumn];

        if(currentPlayerColumn - 1 > 0) {
            leftDownTile = tiles[currentPlayerRow + 1][currentPlayerColumn - 1];
        }
        if(currentPlayerColumn + 1 < tiles[0].size()) {
            rightDownTile = tiles[currentPlayerRow + 1][currentPlayerColumn + 1];
        }
    }
    //all row -1
    if(currentPlayerRow - 1 > 0){
        downTile = tiles[currentPlayerRow - 1][currentPlayerColumn];

        if(currentPlayerColumn - 1 > 0) {
            leftUpperTile = tiles[currentPlayerRow - 1][currentPlayerColumn - 1];
        }
        if(currentPlayerColumn + 1 < tiles[0].size()) {
            rightUpperTile = tiles[currentPlayerRow - 1][currentPlayerColumn + 1];

        }
    }
    //all just rows
    if(currentPlayerColumn + 1 < tiles[0].size()){
        rightTile = tiles[currentPlayerRow][currentPlayerColumn + 1];
        if(currentPlayerColumn - 1 > 0) {
            leftTile = tiles[currentPlayerRow][currentPlayerColumn - 1];
        }
    }

//        // get tile where current tile is at
//        currentTile = tiles[currentPlayerRow][currentPlayerColumn];

    if (rightTile.getTileType() != other and player.intersects(rightTile)) {
        cout <<"COLLISIONRIGHT"<<endl;
        collision.collisionRight = true;
    }
    if (leftTile.getTileType() != other and player.intersects(leftTile)) {
        collision.collisionLeft = true;
    }
    if (upTile.getTileType() != other and player.intersects(upTile)) {
        collision.collisionUp = true;
    }
    if (downTile.getTileType() != other and player.intersects(downTile)) {
        collision.collisionDown = true;
    }
    if (leftUpperTile.getTileType() != other and player.intersects(leftUpperTile)) {
        collision.collisionUpperLeft = true;
    }
    if (rightUpperTile.getTileType() != other and player.intersects(rightUpperTile)) {
        collision.collisionUpperRight = true;
    }
    if (leftDownTile.getTileType() != other and player.intersects(leftDownTile)) {
        collision.collisionDownLeft = true;
    }
    if (rightDownTile.getTileType() != other and player.intersects(rightDownTile)) {
        collision.collisionDownRight = true;
    }
}
void World::checkCollisionWallsBotom(){
    float XLeft= player.getLeftUpperCorner().x;
    float XRight= player.getRightDownCorner().x;

    float YUp= player.getLeftUpperCorner().y;
    float YDown= player.getRightDownCorner().y;

    // collisionWithGround
    if (YDown <= -1) {
        collision.collisionBottom = true;
    }
    else{
        collision.collisionBottom = false;
    }
    // collisionRightWall
    if (XRight >= 1) {
        collision.collisionRightWall = true;
    }
    else{
        collision.collisionRightWall = false;
    }
    // collisionLeftWall
    if (XLeft <= -1) {
        collision.collisionLeftWall = true;
    }
    else{
        collision.collisionLeftWall = false;
    }
}


