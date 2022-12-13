//
// Created by henri kerch on 13/12/2022.
//
#include "Camera.h"
shared_ptr<Camera> Camera::instance_{nullptr};

Camera::Camera() {}

Position Camera::coordinatesToPixel(float xOld, float yOld) {
    /*
     * the tiles are drawn from bottom to top but when converting we need to move
     * all the tiles with the amount of tiles that are not visible
     *
     * lets say we have 6 tiles that are not visible.
     * these tiles are below the game screen so we have to move all the tiles up
     * so that these 6 tiles will become the bottom of our screen
     */
    float tileSize = 2.f/(screenDimensions.x/32);
    yOld += tileSize * amountOfTilesUnderScreen;

    Position p{};
    xOld += 1;
    yOld += 1;

    p.x = xOld * screenDimensions.x / 2;
    p.y = screenDimensions.y - yOld * screenDimensions.x / 2;

    return p;
}
void Camera::setScreenDimensions(const Position& screenDimensions) { Camera::screenDimensions = screenDimensions; }

const shared_ptr<Camera>& Camera::getInstance() {
    if(instance_ == nullptr){
        shared_ptr<Camera> s = make_shared<Camera>();
        instance_ = s;
    }
    return instance_;
}
void Camera::setAmountOfTilesUnderScreen(int amountOfTilesUnderScreen) {
    Camera::amountOfTilesUnderScreen = amountOfTilesUnderScreen;
}
