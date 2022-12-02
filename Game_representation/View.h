//
// Created by henri kerch on 02/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_VIEW_H
#define INC_2022_PROJECT_HENREY_T_VIEW_H

#include "../Game_Logic/structures_enums_std_include.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "memory"
#include "iostream"
#include "../Game_Logic/Rectangle.h"
#include "../Game_Logic/World.h"
#include "../Game_Logic/Camera.h"

using namespace sf;
using namespace std;


namespace ownView{
    class View {
    private:
        shared_ptr<RenderWindow> sfWindow;
    public:
        void setUpMenuState(Texture &textureBackground, Sprite &spriteBackground, Font &font, Text &welcomeText, vector<Text> &allTexts);
        void setUpLevelState(Texture &textureBackground, Sprite &spriteBackground, Vector2i& sceenDimenstions);

        void drawMenuState(Sprite &spriteBackground, Text &welcomeText, vector<Text> &allTexts);
        void drawLevelState(Sprite &spriteBackground, Texture &texturePlayer, World &world, Sprite &spritePlayer, Camera &c,vector<vector<Rectangle>> tiles);


        void drawTiles(vector<vector<Rectangle>> tiles, Camera &camera);

        void setSfWindow(shared_ptr<RenderWindow>& sfWindow);

        View();
        void makeTexts(Text &welcomeText, vector<Text> &allTexts, Font &font);
    };

}


#endif // INC_2022_PROJECT_HENREY_T_VIEW_H
