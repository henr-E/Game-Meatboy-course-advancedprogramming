//
// Created by henri kerch on 04/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_STOPWATCH_H
#define INC_2022_PROJECT_HENREY_T_STOPWATCH_H

#include "iostream"
#include "memory"
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

class Stopwatch {
public:
    time_point<steady_clock> prev_time;
    static shared_ptr<Stopwatch> instance_;

public:
    /**
     * constructor
     */
    Stopwatch();
    /**
     * destructor
     */
    virtual ~Stopwatch() = default;
    /**
     * not clonable
     */
    Stopwatch(Stopwatch& other) = delete;

    /**
     * not assignable
     */
    void operator=(const Stopwatch&) = delete;

    /**
     *
     * @return difference in time between two clock ticks in a float
     */
    float getDifference();

    /**
     *
     * @return instance
     */
    static shared_ptr<Stopwatch>& getInstance();
};

#endif // INC_2022_PROJECT_HENREY_T_STOPWATCH_H
