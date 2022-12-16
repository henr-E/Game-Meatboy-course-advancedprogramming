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
    /**
     * constructor
     */
    Subject() = default;
    /**
     * destructor
     */
    virtual ~Subject() = default;
    /**
     * add an observer
     * @param observer
     */
    void addObserver(shared_ptr<Observer> observer);
    /**
     * remove an observer
     * @param observer
     */
    void removeObserver(shared_ptr<Observer> observer);
protected:
    /**
     * update all observers for curretn model
     */
    virtual void updateObservers();
    /**
     *
     * @return list of all observers for current model
     */
    virtual const vector<shared_ptr<Observer>>& getObserverList() const;
};

#endif // INC_2022_PROJECT_HENREY_T_SUBJECT_H
