//
// Created by henri kerch on 13/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_CAMERA_H
#define INC_2022_PROJECT_HENREY_T_CAMERA_H

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
    Position screenDimensions;
    bool viewMoved;

public:
    /**
     * constructor
     */
    Camera();
    virtual ~Camera();
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
    static const shared_ptr<Camera>& getInstance();

    /**
     * converts coordinates to pixels
     * @param xOld
     * @param yOld
     * @return Position
     */
    Position coordinatesToPixel(float xOld, float yOld);
    /**
     *
     * @param screenDimensions
     */
    void setScreenDimensions(const Position& screenDimensions);

     /**
      * gets a camerapositions struct
        * this struct has a viewPosition and a backgroundPosition
        * this method will change this struct by reference
      * @param cameraPositions
      * @param playerPosition
      * @param prevPlayerPosition
      */
    void moveScreen(CameraPositions& cameraPositions, Position playerPosition, Position prevPlayerPosition);

    bool isViewMoved() const;
};

#endif // INC_2022_PROJECT_HENREY_T_CAMERA_H
