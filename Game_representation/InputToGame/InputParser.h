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

using namespace sf;
using namespace std;

enum TileType { girlfriend, block, none };
struct Tile {
    Rect<float> tileRect;
    TileType tileType;
};

class InputParser {
private:
    vector<vector<Tile>> tiles;
    Vector2i screenDimensions;
    float tileSize;

public:
    InputParser();
    void parse();

    const vector<vector<Tile>>& getTiles() const;
    const Vector2i& getScreenDimensions() const;
};

#endif // INC_2022_PROJECT_HENREY_T_INPUTPARSER_H
