//
// Created by WYF on 2018/5/7.
//

#ifndef INC_3ELEVATOR_SCHEDULING_ELEVATORONLYEVENANDONE_H
#define INC_3ELEVATOR_SCHEDULING_ELEVATORONLYEVENANDONE_H

#include "Elevator.h"

class ElevatorOnlyEvenAndOne :public Elevator {
public:
    ElevatorOnlyEvenAndOne(World &world);

    bool isPassengerCompatible(Passenger &passenger) const override;
};


#endif //INC_3ELEVATOR_SCHEDULING_ELEVATORONLYEVENANDONE_H
