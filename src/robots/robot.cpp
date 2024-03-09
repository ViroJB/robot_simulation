#include "robot.h"
#include "../collision_detection/collision_detection.h"

Robot::Robot(std::vector<std::unique_ptr<ISensor>> &&sensors, EventDispatcher *eventDispatcher, std::string id,
             CollisionDetection *collisionDetection)
    : _sensors(std::move(sensors)),
      _eventDispatcher(eventDispatcher),
      _collisionDetection(collisionDetection),
      _id(id),
      _direction(1) {
    initSensors(id);
}

void Robot::initSensors(std::string id) {
    for (auto &sensor : _sensors) {
        sensor->setEventDispatcher(_eventDispatcher);
        sensor->attachTo(id);
    }
}

std::pair<int, int> Robot::getPosition() { return std::make_pair(_x, _y); }

std::string Robot::getId() { return _id; }

Inventory Robot::getInventory() { return _inventory; }

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
        turnTo(rand() % 4);
    }

    if (_direction == North) {
        ++_y;
    } else if (_direction == East) {
        ++_x;
    } else if (_direction == South) {
        --_y;
    // West
    } else {
        --_x;
    }
}

void Robot::updateState() {

    int oldX = _x;
    int oldY = _y;

    move();

    while(!_collisionDetection->canRobotMoveTo(_x, _y, _id)) {
        DEBUG_MSG(_id << ": Next move not possible. Trying a different move." << std::endl);
        _x = oldX;
        _y = oldY;
        turnTo(rand() % 4);
        move();
    }

    if(_collisionDetection->findItem(_x, _y)) {
        std::cout << _id << ": Item found!" << std::endl;
    }

    std::pair<int, int> coordinates = getPosition();
    _eventDispatcher->dispatchEvent(_id + "ChangedPosition", coordinates);

    for (auto &sensor : _sensors) {
        sensor->measure();
    }
#ifdef DEBUG
    printState();
#endif
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
