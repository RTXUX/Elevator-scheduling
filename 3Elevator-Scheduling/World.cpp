//
// Created by rtxux on 2018/2/9.
//
#include <cstdio>
#include "World.h"
#include "constants.h"
#include <algorithm>
int World::getTime() const {
    return time;
}

Scheduler *World::getScheduler() const {
    return scheduler;
}

vector<Passenger> &World::getPendingPassengers() {
    return pendingPassengers;
}


void World::setScheduler(Scheduler *scheduler) {
    World::scheduler = scheduler;
}

World::World() {

}

int World::run() {
    int totalWaitTime = 0;
    int lastStop = 0;
    Delivered=0;
    totalPassengers = pendingPassengers.size();
    while (Delivered<totalPassengers) {
        pendingPassengers.erase(std::remove_if(pendingPassengers.begin(),pendingPassengers.end(),[&](Passenger& passenger) {
            if (passenger.getRequestTime()<=time) {
                this->getDispatcher()->dispatch(passenger);
                return true;
            }
            return false;
        }),pendingPassengers.end());
        for (Elevator* elevator : elevators) {
            switch(scheduler->decide(*elevator)) {
                case 0:{
                    elevator->stop();
                    break;
                }
                case 1:{
                    elevator->moveUp();
                    break;
                }
                case -1:{
                    elevator->moveDown();
                    break;
                }
            }
        }
        time++;
    }
    return 0;
}

const vector<Elevator *> &World::getElevators() const {
    return elevators;
}

void World::addElevator(Elevator *elevator) {
    this->elevators.push_back(elevator);
}

Dispatcher *World::getDispatcher() const {
    return dispatcher;
}

void World::setDispatcher(Dispatcher *dispatcher) {
    World::dispatcher = dispatcher;
}

int World::getDelivered() const {
    return Delivered;
}

void World::setDelivered(int Delivered) {
    World::Delivered = Delivered;
}

int World::getTotalPassengers() const {
    return totalPassengers;
}

void World::setTotalPassengers(int totalPassengers) {
    World::totalPassengers = totalPassengers;
}
