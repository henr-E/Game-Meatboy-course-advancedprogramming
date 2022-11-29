//
// Created by henri kerch on 21/11/2022.
//

#include "InputParser.h"
InputParser::InputParser() {
    screenDimensions.x = 544;
    screenDimensions.y = 1024;

    tileSize = 0.125;
}

void InputParser::parse() {
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream myFile("../levels/level1.txt");

    /*
     * look into the tileset.png, the number that should be output is the same as the tilenuùber in the tilesetpng
     */
    int X = -1;
    int Y = -1;
    /*
     * a Rect<T> has its coordinates in the left upper corner
     */
    while (getline(myFile, myText)) {
        vector<Tile> tileRow;

        for (int column = 0; column <= 16; column++) {
            if (myText[column] == '#') {
                // make a tile
                Tile t;
                // set tileType
                t.tileType = block;
                // make a rect
                Rect<float> f(X, Y, tileSize, tileSize);
                // set tileRect
                t.tileRect = f;
                // add rect to tileRow
                tileRow.push_back(t);
            } else if (myText[column] == '.') {
                // make a tile
                Tile t;
                // set tileType
                t.tileType = none;
                // add rect to tileRow
                tileRow.push_back(t);
            } else if (myText[column] == '&') {
                // make a tile
                Tile t;
                // set tileType
                t.tileType = girlfriend;
                // make a rect
                Rect<float> f(X, Y, tileSize, tileSize);
                // set tileRect
                t.tileRect = f;
                // add rect to tileRow
                tileRow.push_back(t);
            }
            X += tileSize;
        }
        tiles.push_back(tileRow);
        X = 0;
        Y -= tileSize;
    }

    //there can be 32 tiles on the screen
    int amountOfTilesY = 544/32;
    //substract amount of tiles with the amount of tiles visible on the screen
    int amountOfTilesOutOfScreen = amountOfTilesY - 32;
    //buffervalue is the value we need to add to the y coordinates to get all the rows above the
    //onderkant of the screen
    int bufferValue = amountOfTilesOutOfScreen * tileSize;

    for (auto &row: tiles){
        for (auto &column: row){
            column.tileRect.top -= bufferValue;
            column.tileRect.left -= bufferValue;
        }
    }
    // Close the file
    myFile.close();
}
const vector<vector<Tile>>& InputParser::getTiles() const { return tiles; }
const Vector2i& InputParser::getScreenDimensions() const { return screenDimensions; }
