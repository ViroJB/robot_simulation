#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <iostream>

#include "../debug.h"
#include "../event_dispatcher/event_dispatcher.h"
#include "i_sensor.h"

class DistanceSensor : public ISensor {
   private:
    std::string _id = "DistanceSensor";
    std::string _attachedTo;
    int _distance = 0;
    int _targetX, _targetY;
    int _robotX = 0, _robotY = 0;
    EventDispatcher *_eventDispatcher;

   public:
    DistanceSensor();

    void setEventDispatcher(EventDispatcher *eventDispatcher);
    void attachTo(std::string id);
    void receiveRobotPositionChanged(const std::any &data);
    void receiveTargetPositionChanged(const std::any &data);
    void measure();
    void setTargetPosition(int x, int y);
    void setRobotPosition(int x, int y);
    DataType getData();
    std::string getId();
};

#endif  // DISTANCE_SENSOR_H