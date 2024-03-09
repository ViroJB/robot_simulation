#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include <memory>
#include <vector>

class Robot;
#include "../items/i_item.h"
#include "../map/map.h"


class CollisionDetection {
   public:
    CollisionDetection();
    void setRobots(std::vector<Robot *> *robots);
    void setItems(std::vector<std::unique_ptr<IItem>> *items);
    void setMapSize(std::pair<int, int> mapSize);
    bool canRobotMoveTo(int x, int y, std::string robotId);
    bool findItem(int x, int y);

   private:
    std::vector<Robot *> *_robots;
    std::vector<std::unique_ptr<IItem>> *_items;
    std::pair<int, int> _mapSize;
};

#endif  // COLLISION_DETECTION_H