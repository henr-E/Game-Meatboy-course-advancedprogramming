//
// Created by henri kerch on 08/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_OBSERVER_H
#define INC_2022_PROJECT_HENREY_T_OBSERVER_H

#include "memory"
using namespace std;
//forward declaration
namespace ownModel{
    class Model;
}


class Observer {
public:
    explicit Observer(ownModel::Model& model) : model(model) {}
    virtual void update() = 0;

protected:
    ownModel::Model& model;
};

#endif // INC_2022_PROJECT_HENREY_T_OBSERVER_H
