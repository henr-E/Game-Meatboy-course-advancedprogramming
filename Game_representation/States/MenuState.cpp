//
// Created by henri kerch on 24/11/2022.
//

#include "MenuState.h"
#include "StateManager.h"
MenuState::MenuState(StateManager& stateManager, shared_ptr<RenderWindow>& sfWindow) : State(stateManager, sfWindow) {

    sf::View view = sfWindow->getView();
    view.setCenter(544.f / 2, 1024.f / 2);
    sfWindow->setView(view);

    // load background
    if (!textureBackground.loadFromFile("../content/Background_blurred.png")) {
        cout << ("Failed to load background into texture.") << endl;
    }
    // configure sprite
    spriteBackground.setTexture(textureBackground);

    // load font
    if (!font.loadFromFile("../content/Fonts/Herculanum.ttf")) {
        cout << printf("Failed to load font.") << endl;
    }

    makeTexts();
}

void MenuState::makeTexts() {

    int positionX = 544 / 2;
    int positionY = 960 / 3;

    // select the font
    welcomeText.setFont(font);
    extraText.setFont(font);
    extraText2.setFont(font);
    // set string to present
    welcomeText.setString("WELCOME TO MEAT BOY!");
    extraText.setString("Somoene stole your girlfriend :(");
    extraText2.setString("WHAT ARE YOU WAITING FOR?! FIND HER!");
    // set position
    welcomeText.setPosition(72, 64);
    extraText.setPosition(50, 150);
    extraText2.setPosition(8, 200);
    // set the character size
    welcomeText.setCharacterSize(32);
    extraText.setCharacterSize(25);
    extraText2.setCharacterSize(25);
    // set the color
    welcomeText.setFillColor(Color::Green);
    extraText.setFillColor(Color::White);
    extraText2.setFillColor(Color::White);
    // set the text style
    welcomeText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    extraText.setStyle(sf::Text::Bold);
    extraText2.setStyle(sf::Text::Bold);

    for (int t = 0; t < allTexts.size(); t++) {
        Text& text = allTexts[t];

        text.setFont(font);
        text.setString("LEVEL " + to_string(t + 1));

        text.setPosition(positionX - (5 / 2 * 32), positionY);
        positionY += 100;

        text.setCharacterSize(32);
        text.setFillColor(Color::White);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }
}

void MenuState::userInput(Event& event) {
    // get mousePosition
    mousePosition = Mouse::getPosition(*sfWindow); // window is a sf::OwnWindow

    // check if mouse is on text
    for (int t = 0; t < allTexts.size(); t++) {
        Text& text = allTexts[t];

        Vector2f pos = text.getPosition();
        if (pos.x <= mousePosition.x and mousePosition.x <= pos.x + 7 * 32 and pos.y <= mousePosition.y and
            mousePosition.y <= pos.y + 32) {
            text.setFillColor(Color::Cyan);

            if (Mouse::isButtonPressed(Mouse::Left)) {
                chosenLevel = t + 1;
                shared_ptr<State> newState = make_shared<LevelState>(stateManager, sfWindow, chosenLevel);
                stateManager.setState(newState);
                break;
            }
        } else {
            text.setFillColor(Color::White);
        }
    }
}

void MenuState::simulate() {}
void MenuState::draw() {
    // Rub out the last frame
    sfWindow->clear();

    sfWindow->draw(spriteBackground);

    sfWindow->draw(welcomeText);
    sfWindow->draw(extraText);
    sfWindow->draw(extraText2);

    for (const Text& text : allTexts) {
        sfWindow->draw(text);
    }

    // Show everything we have just drawn
    sfWindow->display();
}
