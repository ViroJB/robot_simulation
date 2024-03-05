#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <iostream>

#include "../event_dispatcher/event_dispatcher.h"
#include "i_sensor.h"

class DistanceSensor : public ISensor {
   private:
    std::string _id = "DistanceSensor";
    std::string _attachedTo;
    int _distance;
    int _targetX, _targetY;
    int _robotX, _robotY;
    EventDispatcher *_eventDispatcher;

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

#endif  // DISTANCE_SENSOR_H