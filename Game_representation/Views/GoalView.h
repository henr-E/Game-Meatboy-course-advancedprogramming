//
// Created by henri kerch on 08/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_GOALVIEW_H
#define INC_2022_PROJECT_HENREY_T_GOALVIEW_H
#include "View.h"
class GoalView : public ownView::View {
public:
    /**
     * constructor
     * @param modelPosition
     * @param modelTileType
     * @param sfWindow
     */
    GoalView(const ownType::Position& modelPosition, ownType::TileType modelTileType,
             const shared_ptr<RenderWindow>& sfWindow);
    /**
     * destructor
     */
    ~GoalView() override = default;
    /**
     * draws the goal on the screen
     */
    void update() override;
    /**
     * update data from model
     * @param position
     * @param direction
     */
    void updateData(ownType::Position position, ownType::Direction direction) override;
};

#endif // INC_2022_PROJECT_HENREY_T_GOALVIEW_H
