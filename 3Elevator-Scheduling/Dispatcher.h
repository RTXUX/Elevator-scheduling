//
// Created by WYF on 2018/5/7.
//

#ifndef INC_3ELEVATOR_SCHEDULING_DISPATCHER_H
#define INC_3ELEVATOR_SCHEDULING_DISPATCHER_H


#include "World.h"
#include "Passenger.h"
class Dispatcher {
    World& world;
public:
    Dispatcher(World &world);

    bool dispatch(Passenger& passenger);
};


#endif //INC_3ELEVATOR_SCHEDULING_DISPATCHER_H
