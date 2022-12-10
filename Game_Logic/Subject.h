//
// Created by henri kerch on 08/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_SUBJECT_H
#define INC_2022_PROJECT_HENREY_T_SUBJECT_H
#include "Observer.h"
#include "vector"
#include "memory"
using namespace std;

class Subject {
    vector<shared_ptr<Observer>> observerList;

public:
    Subject();
    void addObserver(shared_ptr<Observer> observer);
    void removeObserver(shared_ptr<Observer> observer);
protected:
    virtual void updateObservers();
};

#endif // INC_2022_PROJECT_HENREY_T_SUBJECT_H
