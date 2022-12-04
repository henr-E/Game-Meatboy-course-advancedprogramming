//
// Created by henri kerch on 04/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_STOPWATCH_H
#define INC_2022_PROJECT_HENREY_T_STOPWATCH_H

#include <ctime>
#include <chrono>
#include "iostream"
#include "memory"

using namespace std;
using namespace chrono;

class Stopwatch {
public:
    // Clock for timing everything
    time_point<steady_clock> prev_time;

    static shared_ptr<Stopwatch> instance_;

public:
    Stopwatch();
    /**
     * not clonable
     */
    Stopwatch(Stopwatch&other) = delete;

    /**
     * not assignable
     */
    void operator=(const Stopwatch&) = delete;

    float getDifference();

    static shared_ptr<Stopwatch>& getInstance();

};

#endif // INC_2022_PROJECT_HENREY_T_STOPWATCH_H
