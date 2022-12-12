//
// Created by henri kerch on 08/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_WALLVIEW_H
#define INC_2022_PROJECT_HENREY_T_WALLVIEW_H
#include "View.h"
#include "../InputToGame/InputParser.h"
#include "../../Game_Logic/Camera.h"
class WallView : public ownView::View{
private:
    Texture textureBackground;
    Sprite spriteBackground;

    Camera camera;
    vector<vector<WallModel>> tiles;
public:
    WallView(const Position& screenDimensions, const shared_ptr<RenderWindow>& sfWindow,
             const vector<vector<WallModel>>& tiles);
    void update() override;
    void updateData(Position position) override;

    void setUp();
    void drawTiles();
};

#endif // INC_2022_PROJECT_HENREY_T_WALLVIEW_H
