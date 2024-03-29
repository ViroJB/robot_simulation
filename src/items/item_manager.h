#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <memory>
#include <map>

// wieder der scheiss mit loop von class includes...
#include "i_item.h"
#include "../robots/robot.h"
#include "cube.h"
#include "../events/publisher.h"

// TODO create items here
class ItemManager {
   public:
    ItemManager();
    void init();
    void publishItems();
    const std::map<std::string, std::unique_ptr<IItem>>* getItems() const;
    void setPublisher(Publisher *publisher);
    void createCube(std::string name, int x, int y);
    // void createItem(std::string name, std::pair<int, int> position);
    void addItem(std::unique_ptr<IItem> item);
    void removeItem(std::string id);
    void moveItemToRobot(std::string itemId, Robot *robot);
    // void removeItemFromRobot(Robot *robot, IItem *item);

   private:
    int _idCounter = 0;
    Publisher *_publisher = nullptr;
    std::map<std::string, std::unique_ptr<IItem>> _items;
};
#endif  // ITEM_MANAGER_H