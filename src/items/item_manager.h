#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <memory>
#include <map>

// wieder der scheiss mit loop von class includes...
#include "i_item.h"
#include "../robots/robot.h"

class ItemManager {
   public:
    ItemManager() {}
    void setItems(std::map<std::string, std::unique_ptr<IItem>> *items);
    // void addItem(IItem *item);
    void removeItem(std::string id);
    void moveItemToRobot(Robot *robot, IItem *item);
    // void removeItemFromRobot(Robot *robot, IItem *item);

   private:
    std::map<std::string, std::unique_ptr<IItem>> *_items;
};

#endif  // ITEM_MANAGER_H