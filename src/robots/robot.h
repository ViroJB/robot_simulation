#ifndef ROBOT_H
#define ROBOT_H

#include <any>
#include <iostream>
#include <memory>
#include <vector>

class CollisionDetection;
class ItemManager;
#include "inventory.h"
#include "../debug.h"
#include "../directions.h"
#include "../events/publisher.h"
#include "../sensors/distance_sensor.h"
#include "../sensors/i_sensor.h"
#include "../path_finder/path_finder.h"

class Robot {
    // TODO robot boot function? and actuators and bla
   private:
    Publisher *_publisher;
    CollisionDetection *_collisionDetection;
    ItemManager *_itemManager;
    Inventory _inventory;
    std::map<std::string, std::unique_ptr<ISensor>> _sensors;
    std::vector<std::pair<int, int>> _targets;
    std::string _id;
    int _x = 0, _y = 0;
    int _direction = 0;

   public:
    Robot(std::string id, Publisher *publisher);
    void setSensors(std::map<std::string, std::unique_ptr<ISensor>> sensors);
    void setCollisionDetection(CollisionDetection *collisionDetection);
    void setItemManager(ItemManager *itemManager);
    void setPosition(int x, int y);
    void setDirection(int direction);
    void receiveNewTargets(const std::any &data);
    int getDirection();
    std::pair<int, int> getPosition();
    std::string getId();
    void initSensors();
    Inventory getInventory();
    void turn(int direction);
    void move();
    void moveTo(std::pair<int, int> coordinates);
    void updateState();
    void printState();
};

#endif  // ROBOT_H