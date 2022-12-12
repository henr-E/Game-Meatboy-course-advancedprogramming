//
// Created by henri kerch on 21/11/2022.
//

#include "InputParser.h"
//todo check for two girlfriends becauase hten level is wrong
InputParser::InputParser() {
    screenDimensions.x = 0;
    screenDimensions.y = 0;
    tileSize = 0;
}

void InputParser::parse(int levelNumb) {
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream myFile("../levels/level" + to_string(levelNumb) + ".txt");

    // loop through file and store all lines in a vector
    vector<string> lines;
    while (getline(myFile, myText)) {
        auto s = string(myText);
        lines.emplace_back(s);
    }
    //the string will show how long a row is
    screenDimensions.x = lines[0].size() * 32;
    //amount of strings will show how many rows there are
    screenDimensions.y = lines.size() * 32;

    /**
     * We use a grid system, this means that when converted, the size of a tile has
     * to be 32x32 so we need to check how many tiles there are to know the size
     *
     * if the screen is width 544
     * then 544/32 = 17 => 17 tiles
     *
     * 17 tiles => 2/17 = size of tile in coordinate system
     *
     * so the size of a tile is 2/(screenDimenstionsX/32)
     */

    tileSize = 2.f/(screenDimensions.x/32);

    // set begin of positions
    float leftUpperX = -1;
    float leftUpperY = -0.875;
    float rightDownX = -0.875;
    float rightDownY = -1;
    // loop backwards through the list so the first line of text is
    // actually the first row of tiles at the bottom of the screen
    for (int line = lines.size()-1; line >= 0; --line) {
        // make a tileVector
        vector<WallModel> tileRow;
        // loop through every character in the line
        for (int column = 0; column <= 16; column++) {
            if (lines[line][column] == '#') {
                // make a tile
                WallModel t;
                // set tileType
                t.setTileType(block);
                t.setTileHeightWidth(tileSize);
                // set position
                Position leftUpper;
                leftUpper.x = leftUpperX;
                leftUpper.y = leftUpperY;
                // set position
                Position rightDown;
                rightDown.x = rightDownX;
                rightDown.y = rightDownY;
                // set position
                t.setLeftUpperCorner(leftUpper);
                t.setRightDownCorner(rightDown);

                // add rect to tileRow
                tileRow.push_back(t);
            } else if (lines[line][column] == '.') {
                // make a tile
                WallModel t;
                // set tileType
                t.setTileType(other);
                // add rect to tileRow
                tileRow.push_back(t);
            } else if (lines[line][column]== '&') {
                // make a tile
                WallModel t;
                // set tileType
                t.setTileType(girlfriend);
                t.setTileHeightWidth(tileSize);
                // set position
                Position leftUpper;
                leftUpper.x = leftUpperX;
                leftUpper.y = leftUpperY;
                // set position
                Position rightDown;
                rightDown.x = rightDownX;
                rightDown.y = rightDownY;
                t.setLeftUpperCorner(leftUpper);
                t.setRightDownCorner(rightDown);

                // add rect to tileRow
                tileRow.push_back(t);
            }
            leftUpperX += tileSize;
            rightDownX += tileSize;
        }
        tiles.push_back(tileRow);
        leftUpperX = -1;
        rightDownX = -0.875;

        leftUpperY += tileSize;
        rightDownY += tileSize;
    }
    // Close the file
    myFile.close();
}

const vector<vector<WallModel>> & InputParser::getTiles() const { return tiles; }
const Position& InputParser::getScreenDimensions() const { return screenDimensions; }
float InputParser::getTileSize() const { return tileSize; }
