//
// Created by henri kerch on 13/11/2022.
//

#include "Stopwatch.h"

Stopwatch::Stopwatch() {
    tickClock = clock();
}

clock_t Stopwatch::getTickClock() const {
    return tickClock;
}

void Stopwatch::setTickClock(clock_t tickClock) {
    Stopwatch::tickClock = tickClock;
}


