#ifndef APP_H
#define APP_H

#include <cstdlib>
#include <ctime>

#include <memory>
#include <thread>

#include "collision_detection/collision_detection.h"
#include "config.h"
#include "items/item_manager.h"
#include "map/map.h"
#include "path_finder/path_finder.h"
#include "robots/robot_manager.h"
#include "events/publisher.h"


class App {
   public:
    App();
    void init();
    void run();

   private:
    std::unique_ptr<ItemManager> _itemManager;
    std::unique_ptr<PathFinder> _pathFinder;
    std::unique_ptr<CollisionDetection> _collisionDetection;
    std::unique_ptr<Map> _map;
    std::unique_ptr<RobotManager> _robotManager;
    std::unique_ptr<Publisher> _publisher;
};

#endif  // APP_H