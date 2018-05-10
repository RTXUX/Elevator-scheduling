//
// Created by WYF on 2018/5/7.
//

#include "ElevatorOnlyEvenAndOne.h"

ElevatorOnlyEvenAndOne::ElevatorOnlyEvenAndOne(World &world) : Elevator(world) {}

bool ElevatorOnlyEvenAndOne::isPassengerCompatible(Passenger &passenger) const {
    if (passenger.getInitialFloor()==1||passenger.getInitialFloor()%2==0) {
        if (passenger.getDestinstaion()==1||passenger.getDestinstaion()%2==0) {
            return true;
        }
    }
    return false;
}
