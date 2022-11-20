//
// Created by henri kerch on 17/11/2022.
// source of code from https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
//

#include "inputparser.h"
InputParser::InputParser() {
    tileset = "../content/tileset2.png";
    tileSize.x = 32;
    tileSize.y = 32;
    amountOfTilesInHeight = 40;
    amountOfTilesInWidth = 17;
}

bool InputParser::parse() {
    // define the level with an array of tile indices
    tiles = {
        2,1,2,3,0,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2,
        2,1,2,3,1,1,2,3,1,1,2,3,3,1,2,3,2
    };
    return true;
}
bool InputParser::load() {

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

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < amountOfTilesInWidth; ++i)
        for (unsigned int j = 0; j < amountOfTilesInHeight; ++j) {
            // get the current tile number
            int tileNumber = tiles[i + j * amountOfTilesInWidth];

            // find its position in the tileset texture
            // the tileset is the png with the different tiles (forest, brick, ...)
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            Vertex* quad = &m_vertices[(i + j * amountOfTilesInWidth) * 4];

            // define its 4 corners
            quad[0].position = Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}
void InputParser::draw(RenderTarget& target, RenderStates states) const {

    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}

