#ifndef SENSORS_H
#define SENSORS_H

#include <vector>
#include <memory>

#include "../event_dispatcher/event_dispatcher.h"
#include "i_sensor.h"
#include "distance_sensor.h"

// vielleicht ne factory für die sensoren? (builder pattern? factory pattern?)
std::vector<std::unique_ptr<ISensor>> createSensors()
{
    std::vector<std::unique_ptr<ISensor>> sensors;

    sensors.push_back(std::make_unique<DistanceSensor>());

    return sensors;
}

#endif // SENSORS_H