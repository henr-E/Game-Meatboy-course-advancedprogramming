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
    public:
        View(const Position& screenDimensions, const shared_ptr<RenderWindow>& sfWindow)
            : screenDimensions(screenDimensions), sfWindow(sfWindow) {}

    protected:
        Position screenDimensions;
        shared_ptr<RenderWindow> sfWindow;
        virtual void setSfWindow(const shared_ptr<RenderWindow>& sfWindowNew) { View::sfWindow = sfWindowNew; }
    };
}



#endif // INC_2022_PROJECT_HENREY_T_VIEW_H
