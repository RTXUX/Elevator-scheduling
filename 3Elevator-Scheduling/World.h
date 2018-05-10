//
// Created by rtxux on 2018/2/9.
//

#ifndef OBJECT_ORIENTED_WORLD_H
#define OBJECT_ORIENTED_WORLD_H

class World;

class Elevator;

class Scheduler;

class Dispatcher;
#include "Elevator.h"
#include "Scheduler.h"
#include "Passenger.h"
#include "Dispatcher.h"
using std::vector;

class World {
private:
    int time = 0;
    vector<Elevator*> elevators;
    Scheduler *scheduler;
    vector<Passenger> pendingPassengers;
    Dispatcher* dispatcher;
    int Delivered;
    int totalPassengers;
public:
    int getTotalPassengers() const;

    void setTotalPassengers(int totalPassengers);

public:
    int getDelivered() const;

    void setDelivered(int Delivered);

public:
    int getTime() const;

    const vector<Elevator *> &getElevators() const;

    Scheduler *getScheduler() const;

    World();


    void setScheduler(Scheduler *scheduler);

    vector<Passenger> &getPendingPassengers();

    void addElevator(Elevator* elevator);

    int run();

    Dispatcher *getDispatcher() const;

    void setDispatcher(Dispatcher *dispatcher);

};


#endif //OBJECT_ORIENTED_WORLD_H
