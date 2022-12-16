//
// Created by henri kerch on 21/11/2022.
//

#include "InputParser.h"
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
    //the first one will define movement so the screendimensions need to be ficed
    //the string will show how many columns there are
    screenDimensions.x = lines[1].size() * 32;
    //amount of strings will show how many rows there are
    screenDimensions.y = (lines.size() - 1) * 32;

    //amount of inputlines - amount of lines that fit in 1024
//    amountOfTilesUnderScreen = lines.size() - (1024.f/32.f) ;

    if (lines[0] == "MOVE"){

    }else if (lines[0] == "NOMOVE"){

    }else{
        cout << "ERROR ADD MOVE OR NOMOVE" << endl;
    }



    /**
     * We use a grid system, this means that when converted, the size of a tile has
     * to be 32x32 so we need to check how many wallTiles there are to know the size
     *
     * if the screen is width 544
     * then 544/32 = 17 => 17 wallTiles
     *
     * 17 wallTiles => 2/17 = size of tile in coordinate system
     *
     * so the size of a tile is 2/(screenDimenstionsX/32)
     */

    tileSize = 2.f/(screenDimensions.x/32);

    // set begin of positions
    float leftUpperX = -1;
    float leftUpperY = -1 + tileSize;
    float rightDownX = -1 + tileSize;
    float rightDownY = -1;

    int countGirlfriends = 0;
    // loop backwards through the list so the first line of text is
    // actually the first row of wallTiles at the bottom of the screen
    for (int line = lines.size()-1; line >= 1; --line) {
        // make a tileVector
        vector<inputRectangles> tileRow;
        // loop through every character in the line
        for (int column = 0; column <= 16; column++) {
            if (lines[line][column] == '#') {
                // make a tile
                inputRectangles t;
                // set tileType
                t.tileType = BLOCK;
                t.tileHeightWidth = tileSize;
                // set position
                Position leftUpper;
                leftUpper.x = leftUpperX;
                leftUpper.y = leftUpperY;
                // set position
                Position rightDown;
                rightDown.x = rightDownX;
                rightDown.y = rightDownY;
                // set position
                t.leftUpperCorner = leftUpper;
                t.rightDownCorner = rightDown;

                // add rect to tileRow
                tileRow.push_back(t);
            } else if (lines[line][column] == '.') {
                // make a tile
                inputRectangles t;
                // set tileType
                t.tileType = NONE;
                // add rect to tileRow
                tileRow.push_back(t);
            } else if (lines[line][column]== '&') {
                /**
                 * if there are 0 girlfriends
                 */
                if(countGirlfriends == 0){
                    // make a tile
                    inputRectangles t;
                    // set tileType
                    t.tileType = GIRL;
                    t.tileHeightWidth = tileSize;
                    // set position
                    Position leftUpper;
                    leftUpper.x = leftUpperX;
                    leftUpper.y = leftUpperY;
                    // set position
                    Position rightDown;
                    rightDown.x = rightDownX;
                    rightDown.y = rightDownY;
                    // set position
                    t.leftUpperCorner = leftUpper;
                    t.rightDownCorner = rightDown;

                    // add rect to tileRow
                    tileRow.push_back(t);
                }else{
                    // make a tile
                    inputRectangles t;
                    // set tileType
                    t.tileType = NONE;
                    // add rect to tileRow
                    tileRow.push_back(t);
                    //TODO throw exception multiple girlfriends
                }
                /**
                 * add girlfriendCount
                 */
                countGirlfriends += 1;
            }
            leftUpperX += tileSize;
            rightDownX += tileSize;
        }
        tiles.push_back(tileRow);
        leftUpperX = -1;
        rightDownX = -1 + tileSize;

        leftUpperY += tileSize;
        rightDownY += tileSize;
    }
    /**
     * if there are no girlfriends its a false level because the goal pointer will be a nullptr
     * todo throw exceptions !!!
     */
    if(countGirlfriends == 0){

    }
    // Close the file
    myFile.close();
}

const vector<vector<inputRectangles>>  & InputParser::getTiles() const { return tiles; }
const Position& InputParser::getScreenDimensions() const { return screenDimensions; }
float InputParser::getTileSize() const { return tileSize; }
InputParser::~InputParser() {}
