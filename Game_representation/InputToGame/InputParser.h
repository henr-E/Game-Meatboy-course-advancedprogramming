//
// Created by henri kerch on 21/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_INPUTPARSER_H
#define INC_2022_PROJECT_HENREY_T_INPUTPARSER_H

#include <fstream>
#include <iostream>
#include <vector>

#include "../../Game_Logic/Models/GoalModel.h"
#include "../../Game_Logic/Models/WallModel.h"
#include "../../Game_Logic/structures_enums_std_include.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class InputParser {
private:
    vector<vector<ownType::inputRectangles>> tiles;
    ownType::Position screenDimensions;
    float tileSize;
    ownType::MoveScreen moveScreenInput;

public:
    /**
     * default constructor
     */
    InputParser();
    /**
     *
     */
    virtual ~InputParser() = default;
    /**
     * parses the level that is given
     * takes input from "levels" directory and makes level
     * @param levelNumb
     */
    void parse(int levelNumb);

    /**
     *
     * @return walls
     */
    const vector<vector<ownType::inputRectangles>>& getTiles() const;
    /**
     *
     * @return screenDimensions that were generated from the input
     * this is not the same as windowDimensions
     *
     */
    const ownType::Position& getScreenDimensions() const;
    /**
     *
     * @return tileSize
     */
    float getTileSize() const;
    /**
     *
     * @return
     */
    ownType::MoveScreen getMoveScreen() const;
};

#endif // INC_2022_PROJECT_HENREY_T_INPUTPARSER_H
