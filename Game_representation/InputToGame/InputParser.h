//
// Created by henri kerch on 21/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_INPUTPARSER_H
#define INC_2022_PROJECT_HENREY_T_INPUTPARSER_H

#include <fstream>
#include <iostream>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../../Game_Logic/Models/WallModel.h"
#include "../../Game_Logic/Models/GoalModel.h"
#include "../../Game_Logic/structures_enums_std_include.h"
using namespace sf;
using namespace std;


class InputParser {
private:
    vector<vector<WallModel>> tiles;
    Vector2i screenDimensions;
    float tileSize;

public:
    InputParser();
    void parse(int levelNumb);

    const vector<vector<WallModel>> & getTiles() const;
    const Vector2i& getScreenDimensions() const;
};

#endif // INC_2022_PROJECT_HENREY_T_INPUTPARSER_H
