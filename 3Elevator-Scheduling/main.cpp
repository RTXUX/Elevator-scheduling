#include <iostream>
#include "constants.h"
#include "World.h"
#include "ElevatorOnlyEvenAndOne.h"
#include "ElevatorOnlyOdd.h"
#include <fstream>
#include <ctime>
using namespace std;
int main(int argc, char* argv[]) {
    std::ifstream fin;
    if (argc<2) {
        cout << "Too few arguments";
        return 1;
    } else if (argc==2||argc==5) {
        fin.open(argv[1]);
    } else if (argc>5) {
        cout << "Too many arguments";
        return 1;
    }

    srand(time(0));
    World world;
    Scheduler scheduler(world);
    Elevator elevator2(world);
    ElevatorOnlyEvenAndOne elevator3(world);
    ElevatorOnlyOdd elevator1(world);
    Dispatcher dispatcher(world);
    int n;
    fin >> n;
    world.setTotalPassengers(n);
    if (argc==5) {
        elevator1.setOutputFile(argv[2]);
        elevator2.setOutputFile(argv[3]);
        elevator3.setOutputFile(argv[4]);
    } else {
        elevator1.setOutputFile("output1.txt");
        elevator2.setOutputFile("output2.txt");
        elevator3.setOutputFile("output3.txt");
    }
    int requestTime, initialFloor, destination;
    for (int i = 0; i < n; i++) {
        fin >> requestTime >> initialFloor >> destination;
        //if (destination == 0) destination = 10;
        world.getPendingPassengers().emplace_back(requestTime, initialFloor, destination);
    }
    world.run();
    return 0;
}