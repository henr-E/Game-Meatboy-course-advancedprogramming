////
//// Created by henri kerch on 10/12/2022.
////
//void LevelState::updateView() {
//    View view;
//
//    view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
//    //    view.setViewport(FloatRect(0,0,0.5,1.0));
//
//    Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
//
//    //    float Position = world.getPlayer().getPlayerLeftUpperPosition().y;
//    const Position playerPosition = world.getPlayer().getLeftUpperCorner();
//
//    /* coordinates
//     * (0,0)         (532,0)
//     * |_________________|
//     * |
//     * |
//     * |
//     * |________________\
//     * |                |
//     * |________________|
//     * (0,800)         (532,800)
//     */
//    // the position is the left side of meatboy so to get the middle we have to add half of meat boy = 25
//    if (playerPosition.y + 16 < screenDimensions.y / 2) {
//        position.y = playerPosition.y + 16;
//    } else {
//        position.y = screenDimensions.y / 2;
//    }
//
//    view.setCenter(position);
//
//    // set the view
//    sfWindow->setView(view);
//}