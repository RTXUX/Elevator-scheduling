//
// Created by rtxux on 2018/2/9.
//

#ifndef OBJECT_ORIENTED_SCHEDULER_H
#define OBJECT_ORIENTED_SCHEDULER_H

#include "World.h"

class Scheduler {
private:
    World &world;
    int direction = 0;
public:
    Scheduler(World &world);

    int decide(Elevator& elevator);

};


#endif //OBJECT_ORIENTED_SCHEDULER_H
