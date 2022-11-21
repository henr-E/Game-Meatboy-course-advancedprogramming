//
// Created by henri kerch on 17/11/2022.
// source of code from https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
//

#include "TileMap.h"
TileMap::TileMap() {
    tileset = "../content/tileset2.png";
    tileSize.x = 32;
    tileSize.y = 32;
    amountOfTilesInHeight = 35;
    amountOfTilesInWidth = 17;
}
bool TileMap::load() {

    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    /*
     * vertex SFML description
     * Define a point with color and texture coordinates.
     * A vertex is an improved point.
     * It has a position and other extra attributes that will be used for drawing: in SFML, vertices also have a color
     * and a pair of texture coordinates. The vertex is the building block of drawing. Everything which is visible on
     * screen is made of vertices. They are grouped as 2D primitives (triangles, quads, ...), and these primitives are
     * grouped to create even more complex 2D entities such as sprites, texts, etc. If you use the graphical entities of
     * SFML (sprite, text, shape) you won't have to deal with vertices directly. But if you want to define your own 2D
     * entities, such as tiled maps or particle systems, using vertices will allow you to get maximum performances.
     */
    // resize the vertex array to fit the level size
    // Construct the vertex array with a type and an initial number of vertices.
    // This function defines how the vertices must be interpreted when it's time to draw them
    m_vertices.setPrimitiveType(Quads);
    // If vertexCount is greater than the current size, the previous vertices are kept and new (default-constructed)
    // vertices are added. If vertexCount is less than the current size, existing vertices are removed from the array.
    m_vertices.resize(amountOfTilesInWidth * amountOfTilesInHeight * 4);


    // TODO rebuild the whole thing ->> 1 for  loop through tiles but make a schets
    //  populate the vertex array, with one quad per tile
    for (unsigned int column = 0; column < amountOfTilesInWidth; ++column) {
        for (unsigned int row = 0; row < amountOfTilesInHeight; ++row) {
            // get the current tile number
            int tileNumber = tiles[column + row * amountOfTilesInWidth];

            // find its position in the tileset texture
            // the tileset is the png with the different tiles (forest, brick, ...)
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            Vertex* quad = &m_vertices[(column + row * amountOfTilesInWidth) * 4];

            // define its 4 corners
            quad[0].position = Vector2f(column * tileSize.x, row * tileSize.y);
            quad[1].position = Vector2f((column + 1) * tileSize.x, row * tileSize.y);
            quad[2].position = Vector2f((column + 1) * tileSize.x, (row + 1) * tileSize.y);
            quad[3].position = Vector2f(column * tileSize.x, (row + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }
    /*
     * if the height of the game is  960 pixels and a tile is 32 pixels
     * then there can be 960/32 = 30 rows of tiles in our game
     * As the following formules start making tiles at 0,0 the tiles that are not visible
     * are below the screen. We want those tiles to be above the screen so when we go up
     * they will be visible.
     *
     * to do so we have to move every tile
     * so the y value has to go up the screen
     *
     * if we have 35 tiles by example, the 5 tiles will be found under the screen
     * we have to move all tiles with 5*32

    */
    int tileMovementYValue = (amountOfTilesInHeight - (screenDimensions.y/tileSize.y)) * tileSize.y;

    for (int k = 0; k < m_vertices.getVertexCount(); k++){
        Vertex* quad = &m_vertices[k];
        quad->position.y -= tileMovementYValue;
    }

    return true;
}
void TileMap::draw(RenderTarget& target, RenderStates states) const {

    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}
const vector<int>& TileMap::getTiles() const { return tiles; }
void TileMap::setTiles(const vector<int>& tiles) { TileMap::tiles = tiles; }
void TileMap::setScreenDimensions(const Vector2i& screenDimensions) { TileMap::screenDimensions = screenDimensions; }
void TileMap::setAmountOfTilesInWidth(int amountOfTilesInWidth) {
    TileMap::amountOfTilesInWidth = amountOfTilesInWidth;
}
void TileMap::setAmountOfTilesInHeight(int amountOfTilesInHeight) {
    TileMap::amountOfTilesInHeight = amountOfTilesInHeight;
}
