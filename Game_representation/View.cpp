//
// Created by henri kerch on 02/12/2022.
//

#include "View.h"

ownView::View::View() {}
void ownView::View::setSfWindow(shared_ptr<RenderWindow>& sfWindow) { View::sfWindow = sfWindow; }

void ownView::View::drawMenuState(Sprite &spriteBackground, Text &welcomeText, vector<Text> &allTexts){
    // Rub out the last frame
    sfWindow->clear();

    sfWindow->draw(spriteBackground);

    sfWindow->draw(welcomeText);
    for(const Text& text: allTexts) {
        sfWindow->draw(text);
    }

    // Show everything we have just drawn
    sfWindow->display();

}

void ownView::View::drawLevelState(Sprite &spriteBackground, Texture &texturePlayer, World &world, Sprite &spritePlayer, Camera &c,vector<vector<Rectangle>> tiles){
    // Rub out the last frame
    sfWindow->clear();

    sfWindow->draw(spriteBackground);

    drawTiles(tiles, c);

    // make sprite and texture player
    // Associate a texture with the sprite
    // using 2 different sprites
    if (world.getPlayer().getDirection() == facingRight) {
        texturePlayer.loadFromFile("../content/meatboy.png");
    } else {
        texturePlayer.loadFromFile("../content/meatboy_mirror.png");
    }
    texturePlayer.setSmooth(true);

    spritePlayer.setTexture(texturePlayer);

    Position position = world.getPlayer().getPlayerLeftUpperPosition();
    // convert coordinates to pixels
    Position p = c.coordinatesToPixel(position.x, position.y);
    // Now move the playerSprite to its new position
    spritePlayer.setPosition(p.x, p.y);
    // Draw the player
    sfWindow->draw(spritePlayer);
    // Show everything we have just drawn
    sfWindow->display();

}
#include <unistd.h>
void ownView::View::drawTiles(vector<vector<Rectangle>> tiles, Camera &camera) {
    Texture textureTileOther;
    Texture textureTileGirl;
    Texture textureTileBlock;

    Sprite spriteTile;

    if (textureTileOther.loadFromFile("../content/tileset.png", IntRect(160, 0, 32, 32))){

    }

    if (textureTileGirl.loadFromFile("../content/tileset.png", IntRect(0, 0, 32, 32))){

    }

    if (textureTileBlock.loadFromFile("../content/tileset.png", IntRect(64, 0, 32, 32))){

    }


    for(auto const &row : tiles){
        for(auto const &rect : row){

            float XLeft = rect.getLeftUpperCorner().x;
            float YUp = rect.getLeftUpperCorner().y;

            if(rect.getTileType() == other){
                spriteTile.setTexture(textureTileOther);
            }
            else if(rect.getTileType() == girlfriend){
                spriteTile.setTexture(textureTileGirl);
            }
            else if(rect.getTileType() == block){
                spriteTile.setTexture(textureTileBlock);
            }

            //transform coordinates
            Position p = camera.coordinatesToPixel(XLeft, YUp);

            spriteTile.setPosition(p.x, p.y);

            sfWindow->draw(spriteTile);
        }
    }
}


void ownView::View::setUpMenuState(Texture &textureBackground, Sprite &spriteBackground, Font &font, Text &welcomeText, vector<Text> &allTexts) {

    //load background
    if (!textureBackground.loadFromFile("../content/Background_blurred.png")) {
        cout << ("Failed to load background into texture.") << endl;

    }
    // configure sprite
    spriteBackground.setTexture(textureBackground);

    //load font
    if(!font.loadFromFile("../content/Fonts/Herculanum.ttf")){
        cout << printf("Failed to load font.") << endl;
    }

    makeTexts(welcomeText, allTexts, font);
}
void ownView::View::setUpLevelState(Texture &textureBackground, Sprite &spriteBackground, Vector2i& sceenDimenstions) {
    // load background
    if (!textureBackground.loadFromFile("../content/Background_blurred.png")) {
        cout << "Failed to load background into texture." << endl;
    }
    // configure sprite
    spriteBackground.setTexture(textureBackground);

    spriteBackground.setScale(1, (float)sceenDimenstions.y / textureBackground.getSize().y);
}

void ownView::View::makeTexts(Text &welcomeText, vector<Text> &allTexts, Font &font) {

    int positionX = 544/2;
    int positionY = 960/3;

    // select the font
    welcomeText.setFont(font);
    welcomeText.setString("WELCOME TO MEAT BOY!");

    /*
     * the position decides where the first character of the string will be
     * one character = 32 pixels
     * if the string is 10 characters
     * then 10*32 is the length of the string
     * 10*32/2 is the length of half the string
     *
     * so if we want to center it =>
     * 544/2 - 10*32/2
     *
     */
    //position is position of first character

    welcomeText.setPosition(positionX - (12.5/2*32),64);

    // set the character size
    welcomeText.setCharacterSize(32);
    // set the color
    welcomeText.setFillColor(Color::Red);
    // set the text style
    welcomeText.setStyle(sf::Text::Bold | sf::Text::Underlined);

    for(int t = 0; t < allTexts.size(); t++){
        Text &text = allTexts[t];

        text.setFont(font);
        text.setString("LEVEL " + to_string(t+1));

        text.setPosition(positionX - (5/2*32),positionY);
        positionY += 100;

        text.setCharacterSize(32);
        text.setFillColor(Color::White);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }
}