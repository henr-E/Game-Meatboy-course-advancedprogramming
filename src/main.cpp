#include "../Game_representation/StateManager.h"
#include "iostream"
using namespace std;

int main() {
    std::cout << "Dont forget:" << std::endl
              << "- code inspection/clang-tidy!!: Code > Inspect Code" << std::endl
              << "- cicleCI" << std::endl
              << "- clang.format" << std::endl
              << "- doxygen" << std::endl
              << "- NO RAW POINTERS" << std::endl;

    StartGame();
    return 0;
}