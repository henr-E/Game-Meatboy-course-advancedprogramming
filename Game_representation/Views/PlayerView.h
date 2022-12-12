//
// Created by henri kerch on 08/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_PLAYERVIEW_H
#define INC_2022_PROJECT_HENREY_T_PLAYERVIEW_H
#include "View.h"
#include "../../Game_Logic/Camera.h"
class PlayerView : public ownView::View{
private:
    Sprite spritePlayer;
    Texture texturePlayer;
    Camera camera;

    Position playerPosition;

public:
    explicit PlayerView(const shared_ptr<RenderWindow>& sfWindow);
    void update() override;
    void updateData(Position position) override;
};

#endif // INC_2022_PROJECT_HENREY_T_PLAYERVIEW_H
