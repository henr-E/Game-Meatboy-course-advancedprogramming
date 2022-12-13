//
// Created by henri kerch on 13/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_CAMERA_H
#define INC_2022_PROJECT_HENREY_T_CAMERA_H

#include <iostream>
#include "structures_enums_std_include.h"

using namespace std;

class Camera {
public:
    static shared_ptr<Camera> instance_;

    Position screenDimensions;
    int amountOfTilesUnderScreen;
    void setAmountOfTilesUnderScreen(int amountOfTilesUnderScreen);

public:
    Camera();
    Camera(Camera& other) = delete;

    void operator=(const Camera&) = delete;

    static const shared_ptr<Camera>& getInstance();

    Position coordinatesToPixel(float xOld, float yOld);
    void setScreenDimensions(const Position& screenDimensions);
};

#endif //INC_2022_PROJECT_HENREY_T_CAMERA_H
