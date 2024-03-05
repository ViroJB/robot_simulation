#include "distance_sensor.h"

DistanceSensor::DistanceSensor(EventDispatcher *eventDispatcher)
    : _distance(0), _robotX(0), _robotY(0), _targetX(9), _targetY(9), _eventDispatcher(eventDispatcher) {}

void DistanceSensor::attachTo(std::string id) {
    _attachedTo = id;
    _eventDispatcher->registerForEvent(id + "ChangedPosition",
                                      [this](const std::any &data) { this->eventTriggered(data); });
}

void DistanceSensor::eventTriggered(const std::any &data) {
    if (!data.has_value()) {
        DEBUG_MSG(_attachedTo << ": " << _id << ": missing event data.");
        return;
    }

    std::pair<int, int> newCoordinates = std::any_cast<std::pair<int, int>>(data);
    setRobotPosition(newCoordinates.first, newCoordinates.second);
    DEBUG_MSG(_attachedTo << ": " << _id << ": position updated.");
}

void DistanceSensor::setTargetPosition(int x, int y) {
    _targetX = x;
    _targetY = y;
}

void DistanceSensor::setRobotPosition(int x, int y) {
    this->_robotX = x;
    this->_robotY = y;
}

void DistanceSensor::measure() {
    // Manhatten distance measurement algorithm
    _distance = abs(_robotX - _targetX) + abs(_robotY - _targetY);
}

int DistanceSensor::getData() { return _distance; }

std::string DistanceSensor::getId() { return _id; }