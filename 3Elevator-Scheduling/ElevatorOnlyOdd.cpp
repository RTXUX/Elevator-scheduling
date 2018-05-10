//
// Created by WYF on 2018/5/7.
//

#include "ElevatorOnlyOdd.h"

ElevatorOnlyOdd::ElevatorOnlyOdd(World &world) : Elevator(world) {
}

bool ElevatorOnlyOdd::isPassengerCompatible(Passenger &passenger) const {
    if (passenger.getDestinstaion()%2==1&&passenger.getInitialFloor()%2==1) {
        return true;
    }
    return false;
}
