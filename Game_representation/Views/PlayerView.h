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
    /**
     * 2 textures for the player
     */
    Texture playerTextureRight;
    Texture playerTextureLeft;
    /**
     * 2 sprites for the player
     */
    Sprite playerSpriteRight;
    Sprite playerSpriteLeft;
    /**
     * booleans that hold is texture exists
     */
    bool playerTextureExistsRight;
    bool playerTextureExistsLeft;

public:
    /**
     * constructore
     * @param modelPosition
     * @param modelTileType
     * @param sfWindow
     */
    PlayerView(const Position& modelPosition, TileType modelTileType, const shared_ptr<RenderWindow>& sfWindow);
    /**
     * destructor
     */
    ~PlayerView() override = default;
    /**
     * draws player to screen
     */
    void update() override;
    /**
     * update data from model
     * @param position
     * @param direction
     */
    void updateData(Position position, Direction direction) override;
};

#endif // INC_2022_PROJECT_HENREY_T_PLAYERVIEW_H
