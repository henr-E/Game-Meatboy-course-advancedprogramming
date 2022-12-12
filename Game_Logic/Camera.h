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
private:
    Position screenDimensions;
public:
    Position coordinatesToPixel(float xOld, float yOld){
        Position p{};
        xOld += 1;
        yOld += 1;

        p.x = xOld * screenDimensions.x / 2;
        p.y = screenDimensions.y - yOld * screenDimensions.x / 2;
        return p;
    };
    void setScreenDimensions(const Position& screenDimensions) { Camera::screenDimensions = screenDimensions; }
};



#endif //INC_2022_PROJECT_HENREY_T_CAMERA_H
