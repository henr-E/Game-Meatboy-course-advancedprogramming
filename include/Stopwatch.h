//
// Created by henri kerch on 13/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_STOPWATCH_H
#define INC_2022_PROJECT_HENREY_T_STOPWATCH_H


#include <ctime>
class Stopwatch {
private:
    // Clock for timing everything
    float prev_time;

public:
    Stopwatch();

    float getPrevTime() const;

    void setPrevTime(float prevTime);
};



#endif //INC_2022_PROJECT_HENREY_T_STOPWATCH_H
