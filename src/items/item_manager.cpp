#include "item_manager.h"

void ItemManager::setItems(std::map<std::string, std::unique_ptr<IItem>> *items) { _items = items; }

void ItemManager::removeItem(std::string id) {
    _items->erase(id);
}

void ItemManager::moveItemToRobot(std::string itemId, Robot *robot) {
    IItem* item = std::move(_items->at(itemId).get());
    robot->getInventory().addItem(item);
    _items->erase(itemId);
}

// void ItemManager::moveItemToRobot(Robot *robot, IItem *item) {
//     robot->getInventory().addItem(item);
// }

