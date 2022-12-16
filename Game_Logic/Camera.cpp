//
// Created by henri kerch on 13/12/2022.
//
#include "Camera.h"
shared_ptr<Camera> Camera::instance_{nullptr};

Camera::Camera() {
    viewMoved = false;
}

Position Camera::coordinatesToPixel(float xOld, float yOld) {
    /*
     * the wallTiles are drawn from bottom to top but when converting we need to move
     * all the wallTiles with the amount of wallTiles that are not visible
     *
     * lets say we have 6 wallTiles that are not visible.
     * these wallTiles are below the game screen so we have to move all the wallTiles up
     * so that these 6 wallTiles will become the bottom of our screen
     */
    //    float tileSize = 2.f/(screenDimensions.x/32);
    //    yOld += tileSize * 2;

    Position p{};
    xOld += 1;
    yOld += 1;

    p.x = xOld * screenDimensions.x / 2;
    p.y = 1024 - yOld * screenDimensions.x / 2;

    return p;
}
void Camera::setScreenDimensions(const Position& screenDimensions) { Camera::screenDimensions = screenDimensions; }

const shared_ptr<Camera>& Camera::getInstance() {
    if (instance_ == nullptr) {
        shared_ptr<Camera> s = make_shared<Camera>();
        instance_ = s;
    }
    return instance_;
}


void Camera::moveScreenAtEighty(CameraPositions& cameraPositions, Position playerPosition, Position prevPlayerPosition) {

    playerPosition = coordinatesToPixel(playerPosition.x, playerPosition.y);
    prevPlayerPosition = coordinatesToPixel(prevPlayerPosition.x, prevPlayerPosition.y);
    Position positionDifference = playerPosition - prevPlayerPosition;
    //    view.reset(sf::FloatRect(0, 0, 544.f, 1024.f));

    /*
     * playerposition has to be lower than eighty procent of the screen
     * "lower" because the uppder left corner of the screen is (0,0)
     *
     * if the player has reached 80 procent the view has to make the same steps as the player
     * so if the player moves 5 up, the view needs to move 5 up
     */
    /*
     * screendimensions.x= 1376
     * ------------------- - (1376 - 1024)
     *
     *
     * -------------------0
     *
     *
     *
     *
     * -------------------1024
     */
    //maximumViewHeight is actually the amount of walls that are above the window
    float maximumViewHeight = -(screenDimensions.y - 1024);
    if ((cameraPositions.viewPosition.y - 1024.f/2) >= maximumViewHeight){

        float bottom = cameraPositions.viewPosition.y + 1024/2;
        float eightyOfBottom = bottom  * 80 / 100 ;
        float eightyPercent = bottom - eightyOfBottom;

        //if player is in 80% and the difference is positive
        //if the differene is negative, the player is going down and the screen shouldnt move
        if (playerPosition.y <= eightyPercent and positionDifference.y > 0) {
            cameraPositions.viewPosition.y -= positionDifference.y;
            cameraPositions.backgroundPosition.y -= positionDifference.y;
            viewMoved = true;
        }
    }
}

void Camera::moveScreen(CameraPositions& cameraPositions){
    cameraPositions.viewPosition.y -= 0.01;
    cameraPositions.backgroundPosition.y -= 0.01;
}


Camera::~Camera() {}
bool Camera::isViewMoved() const { return viewMoved; }
