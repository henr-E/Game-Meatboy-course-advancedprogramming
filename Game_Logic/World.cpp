//
// Created by henri kerch on 13/11/2022.
//

#include "World.h"

void World::setUp(vector<vector<inputRectangles>> tiles) {
    player = abstractFactory->createPlayer();

    /**
     * turn the inputparser inputrectangles into wallModels with views
     */
    for(const vector<inputRectangles>& tilerow: tiles){
        vector<shared_ptr<WallModel>> wallModelRow;
        for(const inputRectangles& wall: tilerow){
            if(wall.tileType == BLOCK){
                shared_ptr<WallModel> wallModel = abstractFactory->createWall(wall);
                wallModelRow.push_back(wallModel);
            }else{
                wallModelRow.push_back(nullptr);
                if(wall.tileType == GIRL){
                    goal = abstractFactory->createGoal(wall);

                }else if(wall.tileType != NONE){
                    //TODO throw exception
                }
            }
        }
        walls.push_back(wallModelRow);
    }
}

void World::keyboardToPlayer(KeyboardInput keyboardInput){
    player->updateFromKeyboard(keyboardInput);
}
void World::updatePlayerModel(){
    collision.setAllFalse();
    checkCollisionWithTiles();
    checkCollisionWallsBotom();
    player->setCollision(collision);
    float elapsed = stopwatch->getDifference();
    player->simulate(elapsed);
}
void World::updateViews() {
    for(const vector<shared_ptr<WallModel>>& wallRow: walls) {
        for (shared_ptr<WallModel> wall : wallRow) {
            if (wall != nullptr) {
                wall->updateObservers();
            }
        }
    }
    for(auto &observer: player->getObserverList()){
        observer->updateData(player->getLeftUpperCorner(), player->getDirection());
    }
    player->updateObservers();
    goal->updateObservers();
}
void World::checkCollisionWithTiles() {

    float playerXUp = player->getLeftUpperCorner().x;
    float playerYUp = player->getLeftUpperCorner().y;

    float playerX = playerXUp + player->getTileHeightWidth() / 2;
    float playerY = playerYUp + player->getTileHeightWidth() / 2;

    int currentPlayerRow = floor((playerY + 1.f) / tileSize) - 1;
    int currentPlayerColumn = floor((playerX + 1.f) / tileSize);

    //    cout << "currentPlayerRow " << currentPlayerRow <<endl;
    //    cout << "currentPlayerColumn " << currentPlayerColumn<<endl;
    shared_ptr<WallModel> currentTile{}, upTile{}, downTile{}, leftTile{}, leftDownTile{}, leftUpperTile{}, rightTile{},
        rightUpperTile{}, rightDownTile{};

    // all row + 1
    if (currentPlayerRow + 1 <= walls.size() - 1) {
        upTile = walls[currentPlayerRow + 1][currentPlayerColumn];

        if (currentPlayerColumn - 1 > 0) {
            leftUpperTile = walls[currentPlayerRow + 1][currentPlayerColumn - 1];
        }
        if (currentPlayerColumn + 1 < walls[0].size()) {
            rightUpperTile = walls[currentPlayerRow + 1][currentPlayerColumn + 1];
        }
    }
    // all row -1
    if (currentPlayerRow - 1 >= 0) {
        downTile = walls[currentPlayerRow - 1][currentPlayerColumn];

        if (currentPlayerColumn - 1 > 0) {
            leftDownTile = walls[currentPlayerRow - 1][currentPlayerColumn - 1];
        }
        if (currentPlayerColumn + 1 < walls[0].size()) {
            rightDownTile = walls[currentPlayerRow - 1][currentPlayerColumn + 1];
        }
    }
    // all just rows
    if (currentPlayerColumn + 1 <= walls[0].size() - 1) {
        rightTile = walls[currentPlayerRow][currentPlayerColumn + 1];
        if (currentPlayerColumn - 1 > 0) {
            leftTile = walls[currentPlayerRow][currentPlayerColumn - 1];
        }
    }


    if (rightTile != nullptr and rightTile->getLeftUpperCorner().y > bottomViewY and player->intersects(rightTile)) {
        collision.collisionRight = true;
    }
    if (leftTile != nullptr and leftTile->getLeftUpperCorner().y > bottomViewY and player->intersects(leftTile)) {
        collision.collisionLeft = true;
//        cout << "collision LEFT"<< endl;
    }
    if (upTile != nullptr and upTile->getLeftUpperCorner().y > bottomViewY and player->intersects(upTile)) {
        collision.collisionUp = true;
//        cout << "collision UP"<< endl;
    }
    if (downTile != nullptr and downTile->getLeftUpperCorner().y > bottomViewY and player->intersects(downTile)) {
        collision.collisionDown = true;
//        cout << "collision DOWN"<< endl;
    }

    /*
     * collision right and left will happen when against a wall
     * if we dont do this check and we jump against a wall
     * there will be collision rightDown of collision leftdown and the player wont move
     */
    if(!collision.collisionRight and !collision.collisionLeft) {

        if (leftUpperTile != nullptr and leftUpperTile->getLeftUpperCorner().y > bottomViewY and player->intersects(leftUpperTile)) {
            collision.collisionUp = true;
        }
        if (rightUpperTile != nullptr and rightUpperTile->getLeftUpperCorner().y > bottomViewY and player->intersects(rightUpperTile)) {
            collision.collisionUp = true;
        }
        if (leftDownTile != nullptr and leftDownTile->getLeftUpperCorner().y > bottomViewY and player->intersects(leftDownTile)) {
            collision.collisionDown = true;
        }
        if (rightDownTile != nullptr and rightDownTile->getLeftUpperCorner().y > bottomViewY and player->intersects(rightDownTile)) {
            collision.collisionDown = true;
        }
    }

}
void World::checkCollisionWallsBotom(){
    float XLeft= player->getLeftUpperCorner().x;
    float XRight= player->getRightDownCorner().x;

    float YUp= player->getLeftUpperCorner().y;
    float YDown= player->getRightDownCorner().y;

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
void World::setTileSize(float tileSize) { World::tileSize = tileSize; }

World::World() {}
World::~World() {}
const shared_ptr<PlayerModel>& World::getPlayer() const { return player; }
const shared_ptr<GoalModel>& World::getGoal() const { return goal; }
void World::setBottomViewY(float bottomViewY) { World::bottomViewY = bottomViewY; }
