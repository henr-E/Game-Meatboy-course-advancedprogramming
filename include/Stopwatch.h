//
// Created by henri kerch on 13/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_STOPWATCH_H
#define INC_2022_PROJECT_HENREY_T_STOPWATCH_H


#include <chrono>
using namespace std::chrono;

class Stopwatch {
private:
    double simulationTick = 0.0116;
    double elapsedTime = 0;

public: Stopwatch(double simulationTick);

public:
    void restart();
};



#endif //INC_2022_PROJECT_HENREY_T_STOPWATCH_H
