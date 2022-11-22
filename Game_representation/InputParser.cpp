//
// Created by henri kerch on 21/11/2022.
//

#include "InputParser.h"
InputParser::InputParser() {
    amountOfTilesInWidth = 0;
    amountOfTilesInHeight = 0;
}


vector<int> InputParser::parse() {
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream myFile("../levels/level1.txt");
    // Create and open a text file
    ofstream myOutputFile("../levels/OutputLevel1.txt");


    // Use a while loop together with the getline() function to read the file line by line
    while (getline (myFile, myText)) {
        amountOfTilesInHeight +=1;
        for(int i = 0; i < myText.size(); i++){
            if (myText[i] == '#'){
                tiles.push_back(1);
                myOutputFile << 1;
            }
            else if (myText[i] == '.'){
                tiles.push_back(4);
                myOutputFile << 4;
            }
            else if (myText[i] == '/'){
                tiles.push_back(0);
                myOutputFile << 0;
            }
        }
        myOutputFile << '\n';
    }
    //MyText is now the last line in the txt
    amountOfTilesInWidth = myText.size();

    // Close the file
    myFile.close();
    // Close the file
    myOutputFile.close();

    return tiles;
}
int InputParser::getAmountOfTilesInWidth() const { return amountOfTilesInWidth; }
int InputParser::getAmountOfTilesInHeight() const { return amountOfTilesInHeight; }
