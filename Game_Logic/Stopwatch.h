//
// Created by henri kerch on 13/11/2022.
//
#pragma once
#ifndef INC_2022_PROJECT_HENREY_T_STOPWATCH_H
#define INC_2022_PROJECT_HENREY_T_STOPWATCH_H

#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

class Stopwatch {
private:
    // Clock for timing everything
    time_point<steady_clock> prev_time;

public:
    Stopwatch();

    time_point<steady_clock> getPrevTime() const;

    void setPrevTime(time_point<steady_clock> prevTime);


};



#endif //INC_2022_PROJECT_HENREY_T_STOPWATCH_H
