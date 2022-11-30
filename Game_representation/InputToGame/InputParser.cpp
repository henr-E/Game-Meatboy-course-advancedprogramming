//
// Created by henri kerch on 21/11/2022.
//

#include "InputParser.h"

InputParser::InputParser() {
    screenDimensions.x = 544;
    screenDimensions.y = 1024;

    /*
     * there can be 16 tiles in width
     * 544 / 32 = 17 = amount of tiles in width
     * we have 544/17 = tiles of width 32
     *
     * we have 2/17 = tiles of width 0.117...
     *
     * */

    tileSize = 2.f/17.f;
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

    // set begin of positions
    float leftUpperX = -1;
    float leftUpperY = -0.875;
    float rightDownX = -0.875;
    float rightDownY = -1;
    // loop backwards through the list so the first line of text is
    // actually the first row of tiles at the bottom of the screen
    for (int line = lines.size()-1; line >= 0; --line) {
        // make a tileVector
        vector<Rectangle> tileRow;
        // loop through every character in the line
        for (int column = 0; column <= 16; column++) {
            if (lines[line][column] == '#') {
                // make a tile
                Rectangle t;
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
                Rectangle t;
                // set tileType
                t.setTileType(other);
                // add rect to tileRow
                tileRow.push_back(t);
            } else if (lines[line][column]== '&') {
                // make a tile
                Rectangle t;
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

//    //there can be 32 tiles on the screen
//    int amountOfTilesY = 17;
//    //substract amount of tiles with the amount of tiles visible on the screen
//    int amountOfTilesOutOfScreen = amountOfTilesY - 32;
//    //buffervalue is the value we need to add to the y coordinates to get all the rows above the
//    //onderkant of the screen
//    float bufferValue = amountOfTilesOutOfScreen * tileSize;
//    for (auto &row: tiles){
//        for (auto &column: row){
//            Position leftUpperCorner = column.getLeftUpperCorner();
//            Position rightDownCorner = column.getRightDownCorner();
//
//            leftUpperCorner.y -= bufferValue;
//            rightDownCorner.y -= bufferValue;
//
//            column.setLeftUpperCorner(leftUpperCorner);
//            column.setRightDownCorner(rightDownCorner);
//        }
//    }
    // Close the file
    myFile.close();
}
const vector<vector<Rectangle>> & InputParser::getTiles() const { return tiles; }
const Vector2i& InputParser::getScreenDimensions() const { return screenDimensions; }
