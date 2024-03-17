#ifndef ROBOT_H
#define ROBOT_H

#include <any>
#include <iostream>
#include <memory>
#include <vector>

class CollisionDetection;
class ItemManager;
#include "../debug.h"
#include "../directions.h"
#include "../event_dispatcher/event_dispatcher.h"
#include "../sensors/distance_sensor.h"
#include "../sensors/i_sensor.h"
#include "inventory.h"
#include "../path_finder/path_finder.h"

class Robot {
   private:
    EventDispatcher *_eventDispatcher;
    std::vector<std::unique_ptr<ISensor>> _sensors;
    ItemManager *_itemManager;
    CollisionDetection *_collisionDetection;
    Inventory _inventory;

    std::vector<std::pair<int, int>> _targets;
    std::string _id;
    int _x = 0, _y = 0;
    int _direction = 0;

   public:
    Robot(std::string id, EventDispatcher *eventDispatcher);
    void setPosition(int x, int y);
    void setSensors(std::vector<std::unique_ptr<ISensor>> &&sensors);
    void setCollisionDetection(CollisionDetection *collisionDetection);
    void setItemManager(ItemManager *itemManager);
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