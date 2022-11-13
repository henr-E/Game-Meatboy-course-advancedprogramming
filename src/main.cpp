#include <iostream>
#include "Game.h"

int main(int argc, char* argv[]) {
    std::cout << "Dont forget:" << std::endl
              << "- code inspection/clang-tidy!!: Code > Inspect Code" << std::endl
              << "- cicleCI" << std::endl
              << "- clang.format" << std::endl
              << "- doxygen" << std::endl;

    // Declare an instance of Engine
    Game g;
    // Start the engine
    g.start();
    // Quit the Game

    return 0;
}
