//
// Created by henri kerch on 08/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_WALLVIEW_H
#define INC_2022_PROJECT_HENREY_T_WALLVIEW_H
#include "View.h"
#include "../InputToGame/InputParser.h"
#include "../../Game_Logic/Camera.h"
class WallView : public ownView::View{
public:
    WallView(const Position& modelPosition, TileType modelTileType, const shared_ptr<RenderWindow>& sfWindow);
    ~WallView() override;
    void update() override;
    void updateData(Position position, Direction direction) override;
};

#endif // INC_2022_PROJECT_HENREY_T_WALLVIEW_H
