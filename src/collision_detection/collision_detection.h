#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include <map>
#include <memory>
#include <vector>

class Robot;
#include "../items/i_item.h"
#include "../map/map.h"

class CollisionDetection {
   public:
    CollisionDetection() {}
    void setRobots(const std::map<std::string, std::unique_ptr<Robot>> *robots);
    void setItems(const std::map<std::string, std::unique_ptr<IItem>> *items);
    void setMapSize(std::pair<int, int> mapSize);
    bool canRobotMoveTo(std::string robotId, int x, int y);
    std::string findItem(int x, int y);

   private:
    const std::map<std::string, std::unique_ptr<Robot>> *_robots = nullptr;
    const std::map<std::string, std::unique_ptr<IItem>> *_items = nullptr;
    std::pair<int, int> _mapSize;
};

#endif  // COLLISION_DETECTION_H