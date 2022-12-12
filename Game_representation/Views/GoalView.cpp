//
// Created by henri kerch on 08/12/2022.
//

#include "GoalView.h"

void GoalView::update() { }
void GoalView::updateData(Position position) {}
GoalView::GoalView(const Position& screenDimensions, const shared_ptr<RenderWindow>& sfWindow)
    : View(screenDimensions, sfWindow) {}
