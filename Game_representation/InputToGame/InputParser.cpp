//
// Created by henri kerch on 21/11/2022.
//

#include "InputParser.h"
InputParser::InputParser() {
    screenDimensions.x = 544;
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
    //amount of strings will show how many rows there are
    screenDimensions.y = (lines.size() - 1) * 32;

    if (lines[0] == "MOVE"){
        moveScreen = MOVE;
    }else if (lines[0] == "NOMOVE"){
        moveScreen = NOMOVE;
    }else{
        cout << "No movement of level was found in the configurationFile => using move" << endl;
        moveScreen = DEFAULT;
        screenDimensions.y = (lines.size()) * 32;
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
    int forLoopEnd = 0;
    /*
     * if moveScreenAtEighty input is default we have one line less in the configurationFile
     */
    if(moveScreen != DEFAULT){
        forLoopEnd = 1;
    }

    // loop backwards through the list so the first line of text is
    // actually the first row of wallTiles at the bottom of the screen
    for (int line = lines.size()-1; line >= forLoopEnd; --line) {
        //if line is empty
        if(lines[line].empty()){
            cout << "An empty line was given in the configurationFile => ignoring line" << endl;
        }else{
            if(lines[line].size() > 17){
                cout << "A row in the configurationFile is longer than allowed, the amount of tiles in a row is 17 => taking first 17 and ignoring the rest" << endl;
            }
            // make a tileVector
            vector<inputRectangles> tileRow;
            // loop through every character in the line
            for (int column = 0; column <= 16; column++) {
                inputRectangles tile;
                if (lines[line][column] == '#') {
                    // set tileType
                    tile.tileType = BLOCK;
                } else if (lines[line][column] == '.') {
                    // set tileType
                    tile.tileType = NONE;
                } else if (lines[line][column]== '&') {
                    /**
                 * if there are 0 girlfriends
                     */
                    if(countGirlfriends == 0){
                        // set tileType
                        tile.tileType = GIRL;
                    }else{
                        cout << "more than one girlfriends were provided in the configurationFile => skipping all girlfriends except first one" << endl;
                        // set tileType
                        tile.tileType = NONE;
                    }
                    /**
                 * add girlfriendCount
                     */
                    countGirlfriends += 1;
                }
                //set height
                tile.tileHeightWidth = tileSize;
                // set position
                Position leftUpper;
                leftUpper.x = leftUpperX;
                leftUpper.y = leftUpperY;
                // set position
                Position rightDown;
                rightDown.x = rightDownX;
                rightDown.y = rightDownY;
                // set position
                tile.leftUpperCorner = leftUpper;
                tile.rightDownCorner = rightDown;

                // add rect to tileRow
                tileRow.push_back(tile);

                leftUpperX += tileSize;
                rightDownX += tileSize;
            }
            tiles.push_back(tileRow);
            leftUpperX = -1;
            rightDownX = -1 + tileSize;

            leftUpperY += tileSize;
            rightDownY += tileSize;
        }
    }
    /**
     * if there are no girlfriends its a false level because the goal pointer will be a nullptr
     * todo throw exceptions !!!
     */
    if(countGirlfriends == 0){
        cout << "No girlfriend was provided in the configurationFile => making girlfriend at random location" << endl;
        /*
         * looping through all the tiles to find an empty place to put the girlfriend randomly
         */
        int row = 0;
        int column = 2;
        while(tiles[row][column].tileType != NONE){
            column += 1;
            if(column == tiles[row].size()-1){
                row +=1;
                column = 2;
            }
        }
        /*
         * change the NONE tile to a GIRL tile
         */
        // make a tile
        inputRectangles t;
        // set tileType
        t.tileType = GIRL;
        t.tileHeightWidth = tileSize;
        // set position
        Position leftUpper;
        leftUpper.x = tiles[row][column].leftUpperCorner.x;
        leftUpper.y = tiles[row][column].leftUpperCorner.y;
        // set position
        Position rightDown;
        rightDown.x = tiles[row][column].rightDownCorner.x;
        rightDown.y = tiles[row][column].rightDownCorner.y;
        // set position
        t.leftUpperCorner = leftUpper;
        t.rightDownCorner = rightDown;

        tiles[row][column] = t;
    }

    // Close the file
    myFile.close();
}

const vector<vector<inputRectangles>>  & InputParser::getTiles() const { return tiles; }
const Position& InputParser::getScreenDimensions() const { return screenDimensions; }
float InputParser::getTileSize() const { return tileSize; }
InputParser::~InputParser() {}
MoveScreen InputParser::getMoveScreen() const { return moveScreen; }
