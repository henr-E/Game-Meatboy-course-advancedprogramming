//
// Created by henri kerch on 08/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_PLAYERVIEW_H
#define INC_2022_PROJECT_HENREY_T_PLAYERVIEW_H
#include "View.h"
#include "../../Game_Logic/Camera.h"
class PlayerView : public ownView::View{
private:
    Direction playerDirection;

public:
    PlayerView(const Position& modelPosition, TileType modelTileType, const shared_ptr<RenderWindow>& sfWindow);
    ~PlayerView() override;
    void update() override;
    void updateData(Position position, Direction direction) override;
};

#endif // INC_2022_PROJECT_HENREY_T_PLAYERVIEW_H
