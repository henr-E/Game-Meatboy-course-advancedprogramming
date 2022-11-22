//
// Created by henri kerch on 22/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_H
#define INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_H

#endif // INC_2022_PROJECT_HENREY_T_STRUCTURES_ENUMS_H
enum KeyboardInput{
    pressMoveLeft,
    pressMoveRight,
    releaseMoveLeft,
    releaseMoveRight,
    pressJump,
    releaseJump,
    esc,
    noKey
};
struct Position{
    float x;
    float y;
};
struct Collision {
    bool collisionLeft = false;
    bool collisionRight = false;
    bool collisionUp = false;
    bool collisionDown = false;
    bool noCollision = false;
};
enum Direction{
    facingRight,
    facingLeft
};