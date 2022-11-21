//
// Created by henri kerch on 21/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_ROUND_H
#define INC_2022_PROJECT_HENREY_T_ROUND_H

#endif // INC_2022_PROJECT_HENREY_T_ROUND_H
#include <vector>
#include <iostream>
using namespace std;

class Interval {
private:
    vector<int> allDivisible;
public:
    Interval() {
        int sum = 0;
        /*
     * in case of screenwidth 544 and tilewidth 32
     * the vector will look like 0,32,64,96, 128, ...., 512, 544
         */
        while(sum <= 544){
            allDivisible.push_back(sum);
            sum += 32;
        }
    }
    /*
     * for a given Y coordinate for example 33,456 this function is going to find the interval in the
     * tileMap so the interval for this example is (32,64)
     */
    int calculateLeft(float number){
        for(int div = 0; div < allDivisible.size(); ++div){
            int a = allDivisible[div];
            int b = allDivisible[div + 1];
            if (number == a){
                return a;
            }
            else if (number == b){
                return b;
            }
            else if (a < number and number < b){
                return a;
            }
        }
    }
    /*
     * for a given Y coordinate for example 33,456 this function is going to find the interval in the
     * tileMap so the interval for this example is (32,64)
     */
    int calculateRight(float number){
        for(int div = 0; div < allDivisible.size(); ++div){
            int a = allDivisible[div];
            int b = allDivisible[div + 1];
            if (number == a){
                return a;
            }
            else if (number == b){
                return b;
            }
            else if (a < number and number < b){
                return b;
            }
        }
    }
};
