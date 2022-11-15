//
// Created by henri kerch on 13/11/2022.
//

#include "Stopwatch.h"

Stopwatch::Stopwatch() {
    prev_time = 0;
}

float Stopwatch::getPrevTime() const {
    return prev_time;
}

void Stopwatch::setPrevTime(float prevTime) {
    prev_time = prevTime;
}


