//
// Created by henri kerch on 02/12/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_VIEW_H
#define INC_2022_PROJECT_HENREY_T_VIEW_H

#include "../../Game_Logic/Camera.h"
#include "../../Game_Logic/World.h"
#include "../../Game_Logic/structures_enums_std_include.h"
#include "iostream"
#include "memory"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


namespace ownView {
    class View : public Observer {
    protected:
        Sprite modelSprite;
        Texture modelTexture;
        RectangleShape rectangle;
        bool textureFileExists;

        shared_ptr<Camera> camera = Camera::getInstance();

        Position modelPosition;
        TileType modelTileType;

        shared_ptr<RenderWindow> sfWindow;

    public:
        /**
         * constructor
         * @param modelPosition
         * @param modelTileType
         * @param sfWindow
         */
        View(const Position& modelPosition, TileType modelTileType, const shared_ptr<RenderWindow>& sfWindow)
            : modelPosition(modelPosition), modelTileType(modelTileType), sfWindow(sfWindow) {}
        /**
         * draw to screen
         */
        void update() override = 0;
        /**
         * updates any data from model
         * @param position
         * @param direction
         */
        void updateData(Position position, Direction direction) override = 0;
    };
}



#endif // INC_2022_PROJECT_HENREY_T_VIEW_H
