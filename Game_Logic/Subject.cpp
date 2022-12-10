//
// Created by henri kerch on 08/12/2022.
//

#include "Subject.h"
Subject::Subject() {}

void Subject::addObserver(shared_ptr<Observer> observer) {
    observerList.push_back(observer);
}
void Subject::removeObserver(shared_ptr<Observer> observer) {
    remove(observerList.begin(), observerList.end(), observer);
}
void Subject::updateObservers() {
    for(const auto &observer: observerList){
        observer->update();
    }
}