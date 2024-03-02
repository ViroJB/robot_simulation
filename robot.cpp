#include <iostream>
#include <vector>

#include "robot.h"

Robot::Robot(Map* map, EventDispatcher* eventDispatcher, int x, int y) : map(map), eventDispatcher(eventDispatcher), x(x), y(y), direction(1) {}

void Robot::addSensor(Sensor* sensor) {
    sensors.push_back(sensor);
}

std::pair<int, int> Robot::getCoordinates() {
    return std::make_pair(x, y);
}

void Robot::turnRight()
{
    if(direction == West) {
        direction = North;
    } else {
        direction += 1;
    }
}

void Robot::turnLeft()
{
    if(direction == North) {
        direction = West;
    } else {
        direction -= 1;
    }
}

void Robot::turnTo(int direction)
{
    if(direction >= 0 && direction <= 3) {
        this->direction = direction;
    }
}

void Robot::turnRandom()
{
    turnTo(rand() % 4);
}

void Robot::move()
{
    int rows = map->getGrid().size();
    int cols = map->getGrid()[0].size();

    // change every 20 moves to a random direction
    if(rand() % 20 == 0) {
        std::cout << "Robot is turning randomly" << std::endl;
        turnRandom();
    }

    if(direction == North && y < rows - 1) {
        y++;
    } else if(direction == East && x < cols - 1) {
        x++;
    } else if(direction == South && y > 0) {
        y--;
    } else if(direction == West && x > 0) {
        x--;
    } else {
        turnRandom();
        std::cout << "Robot cannot move in that direction. Turning..." << std::endl;
        move();
    }
}

void Robot::updateState() {
    move();
    map->drawRobot(x, y);

    eventDispatcher->dispatchEvent("RobotChangedPosition");

    for (auto sensor : sensors) {
        // temp stuff
        DistanceSensor* a = static_cast<DistanceSensor*>(sensor);
        a->setRobotPosition(x, y);


        sensor->measure();
    }
}

void Robot::printState() {
    std::cout << "Robot is at: (" << x << ", " << y << ")" << std::endl;

    std::string directionString;
    if(direction == North) {
        directionString = "North";
    } else if(direction == East) {
        directionString = "East";
    } else if(direction == South) {
        directionString = "South";
    } else if(direction == West) {
        directionString = "West";
    }
    std::cout << "Robot is facing: " << directionString << std::endl;

    std::cout << "Robot has " << sensors.size() << " sensors." << std::endl;
    for (auto sensor : sensors) {
        std::cout << sensor->getId() << " Data: " << sensor->getData() << std::endl;
    }
}
