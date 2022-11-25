#include "../Game_representation/Game.h"
#include "iostream"
#include "memory"

int main() {
    std::cout << "Dont forget:" << std::endl
              << "- code inspection/clang-tidy!!: Code > Inspect Code" << std::endl
              << "- cicleCI" << std::endl
              << "- clang.format" << std::endl
              << "- doxygen" << std::endl
              << "- NO RAW POINTERS" << std::endl;

    shared_ptr<Game> g = make_shared<Game>();
    g->run();

    return 0;
}