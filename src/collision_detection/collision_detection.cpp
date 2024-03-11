#include "collision_detection.h"
#include "../robots/robot.h"

CollisionDetection::CollisionDetection() {
}

void CollisionDetection::setRobots(std::vector<Robot *> *robots) { _robots = robots; }

void CollisionDetection::setItems(std::map<std::string, std::unique_ptr<IItem>> *items) {
    _items = items;
}

void CollisionDetection::setMapSize(std::pair<int, int> mapSize) { _mapSize = mapSize; }

bool CollisionDetection::canRobotMoveTo(std::string robotId, int x, int y) {
    // is another robot on this position?
    for (auto &robot : *_robots) {
        if (robot->getId() != robotId && robot->getPosition().first == x && robot->getPosition().second == y) {
            return false;
        }
    }

    // don't get out of mapbounds
    if (x < 0 || x >= _mapSize.first || y < 0 || y >= _mapSize.second) {
        return false;
    }

    return true;
}


// muss das hier sein? oder direkt im robot?
std::unique_ptr<IItem> CollisionDetection::findItem(int x, int y) {
    for (auto &item : *_items) {
        if (item.second->getPosition().first == x && item.second->getPosition().second == y) {
            std::cout << "Item found, id: " << item.second->getId() << std::endl;
            return std::move(item.second);
        }
    }
    // return a null/empty object if no item was found
    return nullptr;
}