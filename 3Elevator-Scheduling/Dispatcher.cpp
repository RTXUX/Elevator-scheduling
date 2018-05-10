//
// Created by WYF on 2018/5/7.
//

#include <algorithm>
#include "Dispatcher.h"

Dispatcher::Dispatcher(World &world) : world(world) {
    world.setDispatcher(this);
}

bool Dispatcher::dispatch(Passenger &passenger) {
    vector<Elevator *> compatibleElevators;
    std::copy_if(world.getElevators().begin(), world.getElevators().end(), std::back_inserter(compatibleElevators),
                 [&](Elevator *elevator) {
                     return elevator->isPassengerCompatible(passenger);
                 });
    compatibleElevators[rand() % compatibleElevators.size()]->getTriggeredPassengers().emplace_back(passenger);
    return true;
}
