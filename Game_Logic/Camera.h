//
// Created by henri kerch on 13/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_CAMERA_H
#define INC_2022_PROJECT_HENREY_T_CAMERA_H

#include "memory"
#include "structures_enums_std_include.h"
#include <iostream>

using namespace std;
/**
 * I used the singleton pattern so I can set the screenDimensions 1 time
 * and use the camera in all the views.
 */
class Camera {
public:
    static shared_ptr<Camera> instance_;
    ownType::Position screenDimensions;

public:
    Camera();
    /**
     * destructor
     */
    virtual ~Camera() = default;
    /**
     * not clonable
     * @param other
     */
    Camera(Camera& other) = delete;
    /**
     * no copy constructor
     */
    void operator=(const Camera&) = delete;
    /**
     *
     * @return Instance
     */
    static shared_ptr<Camera>& getInstance();
    /**
     * converts coordinates to pixels
     * @param xOld
     * @param yOld
     * @return coordinates from pixels
     */
    ownType::Position coordinatesToPixel(float xOld, float yOld);
    /**
     *
     * @param xOld
     * @param yOld
     * @return pixels from coordinates
     */
    ownType::Position pixelToCoordinates(float xOld, float yOld);
    /**
     *
     * @param screenDimensions
     */
    void setScreenDimensions(const ownType::Position& screenDimensions);
    /**
     * gets a camerapositions struct
     * this struct has a viewPosition and a backgroundPosition
     * this method will change this struct by reference
     * @param cameraPositions
     * @param playerPosition
     * @param prevPlayerPosition
     */
    void moveScreenAtEighty(ownType::CameraPositions& cameraPositions, ownType::Position playerPosition,
                            ownType::Position prevPlayerPosition);
    /**
     * move View
     * @param cameraPositions
     */
    void moveScreen(ownType::CameraPositions& cameraPositions);
};

#endif // INC_2022_PROJECT_HENREY_T_CAMERA_H
