#ifndef DISTANCE_SENSOR_HPP
#define DISTANCE_SENSOR_HPP

#include "i_sensor.h"
#include "event_dispatcher.h"

class DistanceSensor : public Sensor {
private:
    std::string id = "DistanceSensor";
    int distance;
    int targetX, targetY;
    int robotX, robotY;
    EventDispatcher* eventDispatcher;

public:
    DistanceSensor(EventDispatcher* eventDispatcher);

    void testTrigger();
    void measure();
    void setTargetPosition(int x, int y);
    void setRobotPosition(int x, int y);
    int getData();
    std::string getId();
};

#endif // DISTANCE_SENSOR_HPP