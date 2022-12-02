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
    float playerXUp = player.getPlayerLeftUpperPosition().x;
    float playerYUp = player.getPlayerLeftUpperPosition().y;

    float playerX = playerXUp + player.getTileHeightWidth()/2;
    float playerY = playerYUp + player.getTileHeightWidth()/2;

//    auto a = (playerX + 1.f) / (2.f/17.f);
    // list begins with index 0 so -1
    int currentPlayerRow = floor((playerY+ 1.f) / (2.f/17.f)) - 1;
    int currentPlayerColumn = floor((playerX + 1.f) / (2.f/17.f));

    cout << "currentPlayerRow " << currentPlayerRow <<endl;
    cout << "currentPlayerColumn " << currentPlayerColumn<<endl;
    Rectangle currentTile{}, upTile{}, downTile{}, leftTile{}, leftDownTile{}, leftUpperTile{}, rightTile{}, rightUpperTile{}, rightDownTile{};

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


