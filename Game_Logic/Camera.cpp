//
// Created by henri kerch on 13/11/2022.
//

#include "Camera.h"
Position Camera::coordinatesToPixel(float xOld, float yOld) {
    Position p{};
    xOld += 1;
    yOld += 1;

    p.x = xOld * 544 / 2;
    p.y = 1024 - yOld * 544 / 2;
    return p;
}
