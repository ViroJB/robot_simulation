#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <iostream>

#include "i_sensor.h"
#include "../debug.h"
#include "../events/publisher.h"

class DistanceSensor : public ISensor {
   private:
    std::string _id = "DistanceSensor";
    std::string _attachedTo;
    int _distance = 0;
    int _targetX = 0, _targetY = 0;
    int _robotX = 0, _robotY = 0;
    Publisher *_publisher;

   public:
    DistanceSensor();

    void setPublisher(Publisher *publisher);
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