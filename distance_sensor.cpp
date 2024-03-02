#include <iostream>

#include "distance_sensor.h"

DistanceSensor::DistanceSensor(EventDispatcher* eventDispatcher) : distance(0), robotX(0), robotY(0), targetX(9), targetY(9), eventDispatcher(eventDispatcher) {
    eventDispatcher->registerForEvent("RobotChangedPosition", [this]() {
        this->testTrigger();
    });
}

void DistanceSensor::testTrigger() {
    std::cout << "Distance sensor triggered" << std::endl;
}

void DistanceSensor::setTargetPosition(int x, int y) {
    targetX = x;
    targetY = y;
}

void DistanceSensor::setRobotPosition(int x, int y) {
    this->robotX = x;
    this->robotY = y;
}

void DistanceSensor::measure() {
    // Manhatten distance measurement algorithm
    distance = abs(robotX - targetX) + abs(robotY - targetY);
}

int DistanceSensor::getData() {
    return distance;
}        

std::string DistanceSensor::getId() {
    return id;
}