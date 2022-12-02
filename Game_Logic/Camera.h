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

public:
    Position coordinatesToPixel(float xOld, float yOld){
        Position p{};
        xOld += 1;
        yOld += 1;

        p.x = xOld * 544 / 2;
        p.y = 1024 - yOld * 544 / 2;
        return p;
    };
};



#endif //INC_2022_PROJECT_HENREY_T_CAMERA_H
