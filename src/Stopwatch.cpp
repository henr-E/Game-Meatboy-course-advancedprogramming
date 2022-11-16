//
// Created by henri kerch on 13/11/2022.
//

#include "Stopwatch.h"

Stopwatch::Stopwatch() {
    prev_time = steady_clock::now();
}

time_point<steady_clock> Stopwatch::getPrevTime() const {
    return prev_time;
}

void Stopwatch::setPrevTime(time_point<steady_clock> prevTime) {
    prev_time = prevTime;
}


