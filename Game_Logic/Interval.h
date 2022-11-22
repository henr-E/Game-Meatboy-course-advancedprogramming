//
// Created by henri kerch on 21/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_ROUND_H
#define INC_2022_PROJECT_HENREY_T_ROUND_H

#endif // INC_2022_PROJECT_HENREY_T_ROUND_H
#include <vector>
#include <iostream>
using namespace std;

struct CoordinateInterval{
    int leftValue;
    int rightValue;
    int upValue;
    int downValue;
};
class Interval {
private:
    vector<int> allDivisibleX;
    vector<int> allDivisibleY;
public:
    Interval() {
        /*
     * in case of screenwidth 544 and tilewidth 32
     * the vector will look like 0,32,64,96, 128, ...., 512, 544
         */
        int sum = 0;
        while(sum <= 544){
            allDivisibleX.push_back(sum);
            sum += 32;
        }
        int sum2 = 0;
        while(sum2 <= 960){
            allDivisibleY.push_back(sum2);
            sum2 += 32;
        }
    }
    /*
     * for a given X coordinate for example 33,456 this function is going to find the interval in the
     * tileMap so the interval for this example is (32,64)
     */
    CoordinateInterval calculateLeftRight(float number){
        CoordinateInterval coordinateInterval;

        for(int div = 0; div < allDivisibleX.size(); ++div){
            int a = allDivisibleX[div];
            int b = allDivisibleX[div + 1];
            if ((a <= number and number < b)){
                coordinateInterval.leftValue = a;
                coordinateInterval.rightValue = b;
                return coordinateInterval;
            }
        }
    }
    CoordinateInterval calculateUpDown(float number){
        CoordinateInterval coordinateInterval;

        for(int div = 0; div < allDivisibleY.size(); ++div) {
            int a = allDivisibleY[div];
            int b = allDivisibleY[div + 1];
            if(a <= number and number < b){
                coordinateInterval.upValue = a;
                coordinateInterval.downValue = b;
                return coordinateInterval;
            }
        }
    }
};
