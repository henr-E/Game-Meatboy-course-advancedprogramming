//
// Created by henri kerch on 08/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_GOALVIEW_H
#define INC_2022_PROJECT_HENREY_T_GOALVIEW_H
#include "View.h"
class GoalView : public ownView::View{
public:
    explicit GoalView(const shared_ptr<RenderWindow>& sfWindow);
    void update() override;
    void updateData(Position position) override;
};

#endif // INC_2022_PROJECT_HENREY_T_GOALVIEW_H
