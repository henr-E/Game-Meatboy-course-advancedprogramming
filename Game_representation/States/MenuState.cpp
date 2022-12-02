//
// Created by henri kerch on 24/11/2022.
//

#include "MenuState.h"
MenuState::MenuState(){
    view.setUpMenuState(textureBackground, spriteBackground, font, welcomeText,allTexts);
}

void MenuState::userInput(Event &event) {
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

void MenuState::simulate() {
    State::simulate();
}
void MenuState::draw() {
    view.drawMenuState(spriteBackground, welcomeText,allTexts);
}
const Texture& MenuState::getTextureBackground() const { return textureBackground; }
const Sprite& MenuState::getSpriteBackground() const { return spriteBackground; }
const Font& MenuState::getFont() const { return font; }
const vector<Text>& MenuState::getAllTexts() const { return allTexts; }
const Text& MenuState::getWelcomeText() const { return welcomeText; }
const Vector2i& MenuState::getScreenDimensions() const { return screenDimensions; }

