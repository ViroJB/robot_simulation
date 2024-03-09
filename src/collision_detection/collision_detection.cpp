#include "collision_detection.h"
#include "../robots/robot.h"

CollisionDetection::CollisionDetection() {
}

void CollisionDetection::setRobots(std::vector<Robot *> *robots) { _robots = robots; }

void CollisionDetection::setItems(std::vector<std::unique_ptr<IItem>> *items) { _items = items; }

void CollisionDetection::setMapSize(std::pair<int, int> mapSize) { _mapSize = mapSize; }

bool CollisionDetection::canRobotMoveTo(int x, int y, std::string robotId) {
    // is another robot on this position?
    for (auto &robot : *_robots) {
        if (robot->getId() != robotId && robot->getPosition().first == x && robot->getPosition().second == y) {
            return false;
        }
    }

    // do not get out of bounds
    if (x < 0 || x >= _mapSize.first || y < 0 || y >= _mapSize.second) {
        return false;
    }

    return true;
}

bool CollisionDetection::findItem(int x, int y) {
    for (auto &item : *_items) {
        if (item->getPosition().first == x && item->getPosition().second == y) {
            // move item to robot inventory
            

            return true;
        }
    }
    return false;
}