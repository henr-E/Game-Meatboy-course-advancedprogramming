//
// Created by henri kerch on 21/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_INPUTPARSER_H
#define INC_2022_PROJECT_HENREY_T_INPUTPARSER_H

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class InputParser {
private:
    int amountOfTilesInWidth;
    int amountOfTilesInHeight;

    vector<int> tiles;
public:
    InputParser();
    vector<int> parse();

    int getAmountOfTilesInWidth() const;
    int getAmountOfTilesInHeight() const;
};

#endif // INC_2022_PROJECT_HENREY_T_INPUTPARSER_H
