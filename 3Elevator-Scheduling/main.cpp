#include <iostream>
#include "constants.h"
#include "World.h"
#include "ElevatorOnlyEvenAndOne.h"
#include "ElevatorOnlyOdd.h"
#include <fstream>
#include <ctime>
int main() {
    srand(time(0));
    std::ifstream fin("input.txt");
    World world;
    Scheduler scheduler(world);
    Elevator elevator2(world);
    ElevatorOnlyEvenAndOne elevator3(world);
    ElevatorOnlyOdd elevator1(world);
    Dispatcher dispatcher(world);
    int n;
    fin >> n;
    world.setTotalPassengers(n);
    elevator1.setOutputFile("output1.txt");
    elevator2.setOutputFile("output2.txt");
    elevator3.setOutputFile("output3.txt");
    int requestTime, initialFloor, destination;
    for (int i = 0; i < n; i++) {
        fin >> requestTime >> initialFloor >> destination;
        //if (destination == 0) destination = 10;
        world.getPendingPassengers().emplace_back(requestTime, initialFloor, destination);
    }
    world.run();
    return 0;
}