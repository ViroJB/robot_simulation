#ifndef ROBOT_H
#define ROBOT_H

#include <any>
#include <iostream>
#include <memory>
#include <vector>

#include "../directions.h"
#include "../sensors/i_sensor.h"
#include "../sensors/distance_sensor.h"
#include "../event_dispatcher/event_dispatcher.h"

class Robot {
   private:
    EventDispatcher *_eventDispatcher;
    std::vector<std::unique_ptr<ISensor>> _sensors;
    std::string _id;
    int _x, _y;
    int _direction;
    int _mapSizeX;
    int _mapSizeY;

   public:
    Robot(std::vector<std::unique_ptr<ISensor>> &&sensors, EventDispatcher *eventDispatcher, std::string id, int x,
          int y, int mapSizeX, int mapSizeY);
    std::pair<int, int> getCoordinates();
    void initSensors(std::string id);
    void setPosition(int x, int y);
    void turnLeft();
    void turnTo(int direction);
    void turnRight();
    void turnRandom();
    void move();
    void updateState();
    void printState();
};

#endif  // ROBOT_H