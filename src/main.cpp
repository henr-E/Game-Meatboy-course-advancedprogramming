#include "../Game_representation/Game.h"
#include "iostream"
#include "memory"

int main() {
    shared_ptr<Game> g = make_shared<Game>();
    g->run();
    return 0;
}