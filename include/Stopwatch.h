//
// Created by henri kerch on 13/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_STOPWATCH_H
#define INC_2022_PROJECT_HENREY_T_STOPWATCH_H


#include <ctime>
class Stopwatch {
private:
    // Clock for timing everything
    clock_t tickClock;

public:
    Stopwatch();

    clock_t getTickClock() const;
    void setTickClock(clock_t tickClock);
};



#endif //INC_2022_PROJECT_HENREY_T_STOPWATCH_H
