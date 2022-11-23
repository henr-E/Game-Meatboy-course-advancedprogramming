//
// Created by henri kerch on 22/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_MENU_H
#define INC_2022_PROJECT_HENREY_T_MENU_H

#include <vector>
#include <fstream>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

class Menu{
private:
    //sfml elements
    VideoMode sfVideoMode;
    RenderWindow sfWindow;
    SoundBuffer buffer;
    Sound sound;
    Music music;

    Vector2i screenDimensions;

    //sfml elements
    sf::Text welcomeText;
    sf::Text level1;
    sf::Text level2;
    sf::Text level3;
    sf::Text level4;
    sf::Text level5;

    Font font;
    Texture textureBackground;
    Sprite spriteBackground;
    Vector2i mousePosition;

    vector<Text> allTexts;


    int chosenLevel;


public:
    Menu();
    virtual ~Menu();

    int simulate();
    int userInput();

    void makeTexts();

    int getChosenLevel() const;
};

#endif // INC_2022_PROJECT_HENREY_T_MENU_H
