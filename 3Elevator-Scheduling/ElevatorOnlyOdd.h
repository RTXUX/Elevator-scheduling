//
// Created by WYF on 2018/5/7.
//

#ifndef INC_3ELEVATOR_SCHEDULING_ELEVATORONLYODD_H
#define INC_3ELEVATOR_SCHEDULING_ELEVATORONLYODD_H

#include "Elevator.h"

class ElevatorOnlyOdd : public Elevator{
public:
    ElevatorOnlyOdd(World &world);

    bool isPassengerCompatible(Passenger &passenger) const override;

};


#endif //INC_3ELEVATOR_SCHEDULING_ELEVATORONLYODD_H
