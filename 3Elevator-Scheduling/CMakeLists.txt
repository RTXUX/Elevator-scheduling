cmake_minimum_required(VERSION 3.5)
project(3Elevator_scheduling)

set(CMAKE_CXX_STANDARD 11)

add_executable(3Elevator_scheduling main.cpp Elevator.cpp Elevator.h Scheduler.cpp Scheduler.h World.cpp World.h Dispatcher.cpp Dispatcher.h ElevatorOnlyOdd.cpp ElevatorOnlyOdd.h ElevatorOnlyEvenAndOne.cpp ElevatorOnlyEvenAndOne.h Passenger.cpp Passenger.h)