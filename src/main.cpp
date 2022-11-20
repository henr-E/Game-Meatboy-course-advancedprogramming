#include <iostream>
#include "../Game_representation/Game.h"

int main() {
    std::cout << "Dont forget:" << std::endl
              << "- code inspection/clang-tidy!!: Code > Inspect Code" << std::endl
              << "- cicleCI" << std::endl
              << "- clang.format" << std::endl
              << "- doxygen" << std::endl;

    // Declare an instance of Engine
    Game g;
    // Start the engine
    g.simulate();
    // Quit the Game

    return 0;
}