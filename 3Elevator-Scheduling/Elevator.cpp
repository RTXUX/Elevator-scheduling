//
// Created by rtxux on 2018/2/9.
//
#include <algorithm>
#include "Elevator.h"

class Passenger;
Elevator::Elevator(World &world) : world(world) {
    world.addElevator(this);
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}


const vector<Passenger> &Elevator::getInsidePassengers() const {
    return insidePassengers;
}

void Elevator::moveDown() {
    lastStop=false;
    currentFloor--;
}

void Elevator::moveUp() {
    lastStop= false;
    currentFloor++;
}

void Elevator::unloadPassengers() {
    for (auto iter=insidePassengers.begin();iter!=insidePassengers.end();) {
        if ((*iter).getDestinstaion()==currentFloor) {
            world.setDelivered(world.getDelivered()+1);
            iter = insidePassengers.erase(iter);
        } else {
            iter++;
        }
    }
}


int Elevator::getDelivered() const {
    return delivered;
}

void Elevator::Output() {
    if (file.is_open()) {
        file << world.getTime() << " " << currentFloor << "\r\n";
    }
}

void Elevator::setOutputFile(string fileName) {
    if (file.is_open()) {
        file.close();
    }
    file.open(fileName, std::ios::out | std::ios::trunc);
}

bool Elevator::isPassengerCompatible(Passenger &passenger) const {
    return true;
}

void Elevator::stop() {
    unloadPassengers();
    triggeredPassengers.erase(std::remove_if(triggeredPassengers.begin(),triggeredPassengers.end(),[this](Passenger& passenger) {
        if (passenger.getInitialFloor()==this->currentFloor) {
            this->insidePassengers.emplace_back(passenger);
            return true;
        }
        return false;
    }),triggeredPassengers.end());
    if (!lastStop) {
        Output();
    }
    lastStop=true;
}

vector<Passenger> &Elevator::getTriggeredPassengers() {
    return triggeredPassengers;
}

void Elevator::setTriggeredPassengers(const vector<Passenger> &triggeredPassengers) {
    Elevator::triggeredPassengers = triggeredPassengers;
}
