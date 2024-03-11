#include "item_manager.h"

void ItemManager::setItems(std::map<std::string, std::unique_ptr<IItem>> *items) { _items = items; }

void ItemManager::removeItem(std::string id) {
    _items->erase(id);
}

void ItemManager::moveItemToRobot(Robot *robot, IItem *item) {
    robot->getInventory().addItem(item);
}

