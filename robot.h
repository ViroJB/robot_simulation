#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <vector>
#include <any>
#include <memory>

#include "i_sensor.h"
#include "cardinal_directions.h"
#include "distance_sensor.h"
#include "event_dispatcher.h"

class Robot {
private:
    EventDispatcher* eventDispatcher;
    std::vector<std::unique_ptr<Sensor>> sensors;
    int x, y;
    int direction;
    int mapSizeX;
    int mapSizeY;

public:
    Robot(std::vector<std::unique_ptr<Sensor>>&& sensors, EventDispatcher* eventDispatcher, int x, int y, int mapSizeX, int mapSizeY);
    std::pair<int, int> getCoordinates();
    void setPosition(int x, int y);
    void turnLeft();
    void turnTo(int direction);
    void turnRight();
    void turnRandom();
    void move();
    void updateState();
    void printState();
};

#endif // ROBOT_H