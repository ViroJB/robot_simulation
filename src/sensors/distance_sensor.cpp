#include "distance_sensor.h"

DistanceSensor::DistanceSensor() : _targetX(9), _targetY(9) {} // TODO remove default target position

void DistanceSensor::attachTo(std::string id) {
    _attachedTo = id;
    // TODO reenable this after new event dispatcher is implemented
    // _eventDispatcher->registerForEvent(id + "ChangedPosition",
    //                                    [this](const std::any &data) { this->receiveRobotPositionChanged(data); });
    _publisher->subscribe(id + "ChangedPosition", std::bind(&DistanceSensor::receiveRobotPositionChanged, this, std::placeholders::_1));
    _publisher->subscribe(id + "TargetChangedPosition", std::bind(&DistanceSensor::receiveTargetPositionChanged, this, std::placeholders::_1));
}

void DistanceSensor::setPublisher(Publisher *publisher) { _publisher = publisher; }

void DistanceSensor::receiveRobotPositionChanged(const std::any &data) {
    if (!data.has_value()) {
        DEBUG_MSG(_attachedTo << ": " << _id << ": missing event data.");
        return;
    }

    std::pair<int, int> newCoordinates = std::any_cast<std::pair<int, int>>(data);
    setRobotPosition(newCoordinates.first, newCoordinates.second);
    DEBUG_MSG(_attachedTo << ": " << _id << ": position updated.");
}

void DistanceSensor::receiveTargetPositionChanged(const std::any &data) {
    if (!data.has_value()) {
        DEBUG_MSG(_attachedTo << ": " << _id << ": missing event data.");
        return;
    }

    std::pair<int, int> newCoordinates = std::any_cast<std::pair<int, int>>(data);
    setTargetPosition(newCoordinates.first, newCoordinates.second);
    DEBUG_MSG(_attachedTo << ": " << _id << ": target position updated.");
}

void DistanceSensor::setTargetPosition(int x, int y) {
    _targetX = x;
    _targetY = y;
}

void DistanceSensor::setRobotPosition(int x, int y) {
    this->_robotX = x;
    this->_robotY = y;
}

ISensor::DataType DistanceSensor::getData() {
    DataType data = _distance;
    return data;
}

void DistanceSensor::measure() {
    // Manhatten distance measurement algorithm
    _distance = abs(_robotX - _targetX) + abs(_robotY - _targetY);
}

std::string DistanceSensor::getId() { return _id; }
