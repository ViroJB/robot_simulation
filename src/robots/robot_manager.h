#ifndef ROBOT_MANAGER_H
#define ROBOT_MANAGER_H

#include <map>
#include <memory>

#include "robot.h"
#include "../events/publisher.h"
#include "../sensors/distance_sensor.h"
#include "../sensors/item_sensor.h"

class RobotManager {
   public:
    RobotManager();
    void init();
    const std::map<std::string, std::unique_ptr<Robot>>* getRobots() const;
    std::map<std::string, std::unique_ptr<ISensor>> createSensors();
    void setPublisher(Publisher *publisher);
    void setCollisionDetection(CollisionDetection *collisionDetection);
    void setItemManager(ItemManager *itemManager);

   private:
    std::map<std::string, std::unique_ptr<Robot>> _robots;
    Publisher *_publisher;
    CollisionDetection *_collisionDetection;
    ItemManager *_itemManager;
};

#endif  // ROBOT_MANAGER_H