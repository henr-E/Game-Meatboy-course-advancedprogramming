//
// Created by henri kerch on 17/11/2022.
// source of code from https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
//

#ifndef INC_2022_PROJECT_HENREY_T_INPUTPARSER_H
#define INC_2022_PROJECT_HENREY_T_INPUTPARSER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <fstream>
using namespace sf;
using namespace std;

class InputParser : public Drawable, public Transformable{
private:
    VertexArray m_vertices;
    Texture m_tileset;

    vector<int> tiles;

    Vector2u tileSize;
    string tileset;
    unsigned int amountOfTilesInWidth;
    unsigned int amountOfTilesInHeight;
    

public:
    InputParser();
    // create the tilemap from the level definition
    /*
     * every tile is 32x32
     * the gamewindow is 512x864
     * the amount of tiles in height = 864/32 = 27
     * the amount of tiles in width = 512/32 = 16
     */
    bool load();
    virtual void draw(RenderTarget& target, RenderStates states) const;
    bool parse();
};

#endif // INC_2022_PROJECT_HENREY_T_INPUTPARSER_H
