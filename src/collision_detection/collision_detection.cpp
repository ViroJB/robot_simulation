#include "collision_detection.h"

//  here because of looping includes shit thingy
#include "../robots/robot.h"

void CollisionDetection::setRobots(const std::map<std::string, std::unique_ptr<Robot>> *robots) { _robots = robots; }

void CollisionDetection::setItems(const std::map<std::string, std::unique_ptr<IItem>> *items) { _items = items; }

void CollisionDetection::setMapSize(std::pair<int, int> mapSize) { _mapSize = mapSize; }

bool CollisionDetection::canRobotMoveTo(std::string robotId, int x, int y) {
    // is another robot on this position?
    for (auto &robot : *_robots) {
        if (robot.second->getId() != robotId && robot.second->getPosition().first == x &&
            robot.second->getPosition().second == y) {
            return false;
        }
    }

    // don't get out of mapbounds
    if (x < 0 || x >= _mapSize.first || y < 0 || y >= _mapSize.second) {
        return false;
    }

    return true;
}

std::string CollisionDetection::findItem(int x, int y) {
    for (auto &item : *_items) {
        if (item.second->getPosition().first == x && item.second->getPosition().second == y) {
            return item.first;
        }
    }
    return "";
}
