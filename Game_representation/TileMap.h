//
// Created by henri kerch on 17/11/2022.
// source of code from https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
//

#ifndef INC_2022_PROJECT_HENREY_T_TILEMAP_H
#define INC_2022_PROJECT_HENREY_T_TILEMAP_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

class TileMap : public Drawable, public Transformable{
private:
    Vector2i screenDimensions;

    VertexArray m_vertices;
    Texture m_tileset;

    vector<int> tiles;

    Vector2i tileSize;
    string tileset;
    int amountOfTilesInWidth;
    int amountOfTilesInHeight;
    

public:
    TileMap();
    // create the tilemap from the level definition
    /*
     * every tile is 32x32
     * the gamewindow is 512x864
     * the amount of tiles in height = 864/32 = 27
     * the amount of tiles in width = 512/32 = 16
     */
    bool load();
    virtual void draw(RenderTarget& target, RenderStates states) const;

    const vector<int>& getTiles() const;
    void setTiles(const vector<int>& tiles);

    void setScreenDimensions(const Vector2i& screenDimensions);
    void setAmountOfTilesInWidth(int amountOfTilesInWidth);
    void setAmountOfTilesInHeight(int amountOfTilesInHeight);
};


//// Define the most common types
//typedef Vector2<int>          Vector2i;
//typedef Vector2<unsigned int> Vector2u;
//typedef Vector2<float>        Vector2f;

#endif // INC_2022_PROJECT_HENREY_T_TILEMAP_H
