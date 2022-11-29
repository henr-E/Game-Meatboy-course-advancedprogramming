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
    Position coordinatesToPixel(float x, float y);
};



#endif //INC_2022_PROJECT_HENREY_T_CAMERA_H
