#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "i_sensor.h"
#include "map.h"
#include "cardinal_directions.h"
#include "distance_sensor.h"
#include "event_dispatcher.h"

class Robot {
private:
    int x, y;
    Map* map;
    std::vector<Sensor*> sensors;
    int direction;
    EventDispatcher* eventDispatcher;

public:
    Robot(Map* map, EventDispatcher* eventDispatcher, int x, int y);
    void addSensor(Sensor* sensor);
    std::pair<int, int> getCoordinates();
    void turnLeft();
    void turnTo(int direction);
    void turnRight();
    void turnRandom();
    void move();
    void updateState();
    void printState();
};

#endif // ROBOT_HPP