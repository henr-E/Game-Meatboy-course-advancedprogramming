//
// Created by henri kerch on 24/11/2022.
//

#include "MenuState.h"
MenuState::MenuState(){
    startUp();
}

void MenuState::startUp() {
    //load background
    if (!textureBackground.loadFromFile("../content/Background_blurred.png")) {
        printf("Failed to load background into texture.");
        exit(EXIT_FAILURE);
    }
    // configure sprite
    spriteBackground.setTexture(textureBackground);

    //load font
    if(!font.loadFromFile("../content/Fonts/Herculanum.ttf")){
        exit(EXIT_FAILURE);
    }

    makeTexts();
}

void MenuState::getUserInput(Event event) {
    //get mousePosition
    mousePosition = Mouse::getPosition(*sfWindow.get()); // window is a sf::OwnWindow

    //check if mouse is on text
    for(int t = 0; t < allTexts.size(); t++){
        Text &text = allTexts[t];

        Vector2f pos = text.getPosition();
        if(pos.x <= mousePosition.x and mousePosition.x <= pos.x + 7*32 and pos.y <= mousePosition.y and mousePosition.y <= pos.y + 32) {
            text.setFillColor(Color::Cyan);

            if (Mouse::isButtonPressed(Mouse::Left)) {
                chosenLevel = t+1;
                transition = true;
                break;
            }
        }
        else{
            text.setFillColor(Color::White);
        }
    }
}

void MenuState::makeTexts() {

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


    allTexts = {level1, level2, level3, level4, level5};

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

void MenuState::draw() {
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
void MenuState::simulate() {
    State::simulate();
}
