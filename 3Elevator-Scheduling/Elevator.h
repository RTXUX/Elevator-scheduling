//
// Created by rtxux on 2018/2/9.
//

#ifndef OBJECT_ORIENTED_ELEVATOR_H
#define OBJECT_ORIENTED_ELEVATOR_H

#include <vector>
#include "World.h"
#include "Passenger.h"
#include <fstream>
using std::vector;
using std::ofstream;
using std::string;
class Elevator {
private:
    World &world;
    int delivered = 0;
    ofstream file;
    vector<Passenger> triggeredPassengers;
    bool lastStop=true;
public:
    vector<Passenger> &getTriggeredPassengers();

    void setTriggeredPassengers(const vector<Passenger> &triggeredPassengers);

public:
    int getDelivered() const;

public:
    Elevator(World &world);

    int getCurrentFloor() const;

    const vector<Passenger> &getInsidePassengers() const;

    void moveUp();

    void moveDown();

    void unloadPassengers();

    void Output();

    void setOutputFile(string fileName);

    virtual bool isPassengerCompatible(Passenger& passenger) const;

    void stop();
private:
    int currentFloor = 1;
    vector<Passenger> insidePassengers;

};


#endif //OBJECT_ORIENTED_ELEVATOR_H
