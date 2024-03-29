#include "robot.h"

#include "../collision_detection/collision_detection.h"
#include "../items/item_manager.h"

Robot::Robot(std::string id, Publisher *publisher) : _id(id), _publisher(publisher) {
}

void Robot::setCollisionDetection(CollisionDetection *collisionDetection) { _collisionDetection = collisionDetection; }
void Robot::setItemManager(ItemManager *itemManager) { _itemManager = itemManager; }
void Robot::setPosition(int x, int y) {
    _x = x;
    _y = y;
}
void Robot::setSensors(std::map<std::string, std::unique_ptr<ISensor>> sensors) {
    _sensors = std::move(sensors);
    initSensors();
}
void Robot::setDirection(int direction) { _direction = direction; }
int Robot::getDirection() { return _direction; }
std::pair<int, int> Robot::getPosition() { return std::make_pair(_x, _y); }
std::string Robot::getId() { return _id; }
Inventory Robot::getInventory() { return _inventory; }

void Robot::initSensors() {
    for (auto &sensor : _sensors) {
        sensor.second->setPublisher(_publisher);
        sensor.second->attachTo(_id);
    }
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
    // TODO remove this random thingy
    // change every 15 moves to a random direction
    if (rand() % 15 == 0) {
        DEBUG_MSG(_id << ": turning randomly");
        turn(Random);
    }

    if (_direction == North) {
        ++_y;
    } else if (_direction == East) {
        ++_x;
    } else if (_direction == South) {
        --_y;
    } else {
        // West
        --_x;
    }
}

void Robot::moveTo(std::pair<int, int> coordinates) {
    _x = coordinates.first;
    _y = coordinates.second;
}

void Robot::updateState() {
    int oldX = _x;
    int oldY = _y;

    // find next move
    if (!_targets.empty()) {
        std::pair<int, int> firstTarget = _targets.front();  // only first for now
        std::pair<int, int> nextMove = PathFinder::getNextMove(_x, _y, firstTarget.first, firstTarget.second);

        if (nextMove.first == _x && nextMove.second == _y) {
            DEBUG_MSG(_id << ": Robot is at target");

            // if target is an item, pick it up
            std::string itemId = _collisionDetection->findItem(_x, _y);
            if (!itemId.empty()) {
                _itemManager->moveItemToRobot(itemId, this);
            }

            _targets.erase(_targets.begin());
            move();
        } else {
            _x = nextMove.first;
            _y = nextMove.second;
        }
    } else {
        move();
    }

    // check next move
    int i = 0;
    while (!_collisionDetection->canRobotMoveTo(_id, _x, _y)) {
        // TODO redo this...
        DEBUG_MSG(_id << ": Next move (" << _x << ", " << _y << ") not possible. Trying a different move." << std::endl);
        _x = oldX;
        _y = oldY;
        // jump out of loop if robot tries to move more than 10 times
        if (i >= 10) {
            DEBUG_MSG(_id << ": No possible moves. Staying in place." << std::endl);
            break;
        }
        turn(Random);
        move();
        i++;
    }

    // publish new position
    std::pair<int, int> coordinates = getPosition();
    _publisher->publish(_id + "ChangedPosition", coordinates);

    for (auto &sensor : _sensors) {
        sensor.second->measure();
    }

    // NOTE: for now, update targets manually
    // TODO find closest target and publish that
    _targets = std::any_cast<std::vector<std::pair<int, int>>>(_sensors["ItemSensor"]->getData());
    if(!_targets.empty()) {
        _publisher->publish(_id + "TargetChangedPosition", _targets.front());
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
        std::cout << "   " << sensor.second->getId() << " Data: ";

        if(sensor.second->getData().type() == typeid(int)) {
            std::cout << std::any_cast<int>(sensor.second->getData());
        } else if(sensor.second->getData().type() == typeid(std::vector<std::pair<int, int>>)) {
            auto data = std::any_cast<std::vector<std::pair<int, int>>>(sensor.second->getData());
            std::cout << "ItemSize: " << data.size();
        } else {
            std::cout << "unknown data type";
        }
        std::cout << std::endl;
    }
    // std::cout << std::endl;
}
