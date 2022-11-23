//
// Created by henri kerch on 23/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_STATEMANAGER_H
#define INC_2022_PROJECT_HENREY_T_STATEMANAGER_H

#include <iostream>
#include <memory>
#include <typeinfo>


#include "Windows/Game.h"
#include "Windows/Menu.h"

using namespace std;

int StartGame(){
    shared_ptr<Menu> m = make_shared<Menu>();
    if(m->simulate() == 0){
        int level = m->getChosenLevel();
        //shared pointer dies when no more pointers exist to Menu
        m = nullptr;
        shared_ptr<Game> g = make_shared<Game>();
        g->setChosenLevel(level);
        if(g->simulate() == 0){
            g = nullptr;
            StartGame();
        }
    }

    return 0;
};
#endif // INC_2022_PROJECT_HENREY_T_STATEMANAGER_H
