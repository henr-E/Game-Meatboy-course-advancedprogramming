//
// Created by henri kerch on 04/12/2022.
//
#include "Stopwatch.h"
shared_ptr<Stopwatch> Stopwatch::instance_{nullptr};
Stopwatch::Stopwatch() { prev_time = steady_clock::now(); }
float Stopwatch::getDifference() {
    // calculate elapsed time
    duration<float> elapsed = steady_clock::now() - prev_time;
    float elapsedFloat = elapsed.count();

    prev_time = steady_clock::now();
    return elapsedFloat;
}
shared_ptr<Stopwatch>& Stopwatch::getInstance() {
    if (instance_ == nullptr) {
        shared_ptr<Stopwatch> s = make_shared<Stopwatch>();
        instance_ = s;
    }
    return instance_;
}
