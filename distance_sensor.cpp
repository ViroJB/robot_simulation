#include "distance_sensor.h"

DistanceSensor::DistanceSensor(EventDispatcher *eventDispatcher) : distance(0), robotX(0), robotY(0), targetX(9), targetY(9), eventDispatcher(eventDispatcher)
{
}

void DistanceSensor::attachTo(std::string id)
{
    attachedTo = id;
    eventDispatcher->registerForEvent(id + "ChangedPosition", [this](const std::any &data)
                                      { this->eventTriggered(data); });
}

void DistanceSensor::eventTriggered(const std::any &data)
{
    if (!data.has_value())
    {
        #if DEBUG
            std::cout << attachedTo << ": " << id << ": missing event data." << std::endl;
        #endif
        return;
    }

    std::pair<int, int> newCoordinates = std::any_cast<std::pair<int, int>>(data);
    setRobotPosition(newCoordinates.first, newCoordinates.second);
    #if DEBUG
        std::cout << attachedTo << ": " << id << ": position updated." << std::endl;
    #endif
}

void DistanceSensor::setTargetPosition(int x, int y)
{
    targetX = x;
    targetY = y;
}

void DistanceSensor::setRobotPosition(int x, int y)
{
    this->robotX = x;
    this->robotY = y;
}

void DistanceSensor::measure()
{
    // Manhatten distance measurement algorithm
    distance = abs(robotX - targetX) + abs(robotY - targetY);
}

int DistanceSensor::getData()
{
    return distance;
}

std::string DistanceSensor::getId()
{
    return id;
}