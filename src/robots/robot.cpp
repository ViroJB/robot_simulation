#include "robot.h"

#include "../collision_detection/collision_detection.h"
#include "../items/item_manager.h"

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

void Robot::setItemManager(ItemManager *itemManager) { _itemManager = itemManager; }

std::pair<int, int> Robot::getPosition() { return std::make_pair(_x, _y); }

std::string Robot::getId() { return _id; }

Inventory Robot::getInventory() { return _inventory; }

void Robot::setPosition(int x, int y) {
    this->_x = x;
    this->_y = y;
}

void Robot::turn(int direction) {
    // return if direction is bigger than the size of the enum Directions
    if (direction > 6) {
        return;
    }

    if (direction == Left) {
        if (_direction == North) {
            _direction = West;
        } else {
            --_direction;
        }
    } else if (direction == Right) {
        if (_direction == West) {
            _direction = North;
        } else {
            ++_direction;
        }
    } else if (direction == Random) {
        _direction = rand() % 4;
    } else {
        _direction = direction;
    }
}

void Robot::move() {
    // temp
    // change every 20 moves to a random direction
    if (rand() % 20 == 0) {
        DEBUG_MSG(_id << ": turning randomly");
        turn(Random);
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

    while (!_collisionDetection->canRobotMoveTo(_id, _x, _y)) {
        DEBUG_MSG(_id << ": Next move not possible. Trying a different move." << std::endl);
        _x = oldX;
        _y = oldY;
        turn(Right);
        move();
    }

    std::unique_ptr<IItem> item = _collisionDetection->findItem(_x, _y);
    if (item != nullptr) {
        // remove item from items after its being moved
        _itemManager->removeItem(item->getId());
        _itemManager->moveItemToRobot(this, item.get());
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
