#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <iostream>

#include "i_sensor.h"
#include "event_dispatcher.h"

class DistanceSensor : public Sensor
{
private:
    std::string id = "DistanceSensor";
    std::string attachedTo;
    int distance;
    int targetX, targetY;
    int robotX, robotY;
    EventDispatcher *eventDispatcher;

public:
    DistanceSensor(EventDispatcher *eventDispatcher);

    void attachTo(std::string id);
    void eventTriggered(const std::any &data);
    void measure();
    void setTargetPosition(int x, int y);
    void setRobotPosition(int x, int y);
    int getData();
    std::string getId();
};

#endif // DISTANCE_SENSOR_H