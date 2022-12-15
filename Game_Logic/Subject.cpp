//
// Created by henri kerch on 08/12/2022.
//

#include "Subject.h"
Subject::Subject() {}

void Subject::addObserver(shared_ptr<Observer> observer) {
    observerList.push_back(observer);
}
void Subject::removeObserver(shared_ptr<Observer> observer) {
    //there is only on observer in our case so you can just delete the first instead of looping
    observerList.erase(observerList.begin());
}
void Subject::updateObservers(){
    for(const auto &observer: observerList){
        observer->update();
    }
}
const vector<shared_ptr<Observer>>& Subject::getObserverList() const { return observerList; }
Subject::~Subject() {}
