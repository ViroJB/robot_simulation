#include "robot.h"

Robot::Robot(std::vector<std::unique_ptr<ISensor>> &&sensors, EventDispatcher *eventDispatcher, std::string id, int x,
             int y, int mapSizeX, int mapSizeY)
    : _sensors(std::move(sensors)),
      _eventDispatcher(eventDispatcher),
      _id(id),
      _x(x),
      _y(y),
      _mapSizeX(mapSizeX),
      _mapSizeY(mapSizeY),
      _direction(1) {
    initSensors(id);
}

void Robot::initSensors(std::string id) {
    for (auto &sensor : _sensors) {
        sensor->attachTo(id);
    }
}

std::pair<int, int> Robot::getCoordinates() { return std::make_pair(_x, _y); }

void Robot::setPosition(int x, int y) {
    this->_x = x;
    this->_y = y;
}

void Robot::turnRight() {
    if (_direction == West) {
        _direction = North;
    } else {
        ++_direction;
    }
}

void Robot::turnLeft() {
    if (_direction == North) {
        _direction = West;
    } else {
        --_direction;
    }
}

void Robot::turnTo(int direction) {
    if (direction >= 0 && direction <= 3) {
        this->_direction = direction;
    }
}

void Robot::turnRandom() { turnTo(rand() % 4); }

void Robot::move() {
    // temp
    // change every 20 moves to a random direction
    if (rand() % 20 == 0) {
        DEBUG_MSG(_id << ": turning randomly");
        turnRandom();
    }

    if (_direction == North && _y < _mapSizeX - 1) {
        ++_y;
    } else if (_direction == East && _x < _mapSizeY - 1) {
        ++_x;
    } else if (_direction == South && _y > 0) {
        --_y;
    } else if (_direction == West && _x > 0) {
        --_x;
    } else {
        DEBUG_MSG(_id << ": cannot move in that direction. Turning.");
        turnRandom();
        move();
    }
}

void Robot::updateState() {
    move();
    std::pair<int, int> coordinates = getCoordinates();
    _eventDispatcher->dispatchEvent(_id + "ChangedPosition", coordinates);

    for (auto &sensor : _sensors) {
        sensor->measure();
    }
}

void Robot::printState() {
    std::cout << _id << ": position: (" << _x << ", " << _y << ")" << std::endl;
    std::cout << _id << ": direction: " << _direction << std::endl;

    std::cout << _id << ": Sensors (" << _sensors.size() << "): " << std::endl;
    for (auto &sensor : _sensors) {
        std::cout << "   " << sensor->getId() << " Data: " << sensor->getData() << std::endl;
    }
    std::cout << std::endl;
}
