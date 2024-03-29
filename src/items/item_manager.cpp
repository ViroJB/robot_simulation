#include "item_manager.h"

ItemManager::ItemManager() {}

void ItemManager::setPublisher(Publisher *publisher) { _publisher = publisher; }

const std::map<std::string, std::unique_ptr<IItem>> *ItemManager::getItems() const { return &_items; }

void ItemManager::init() {
    // TODO add items manually here for now
    createCube("Cube", 0, 7);
    createCube("Cube", 7, 4);
    createCube("Cube", 3, 2);
}

void ItemManager::publishItems() {
    _publisher->publish("ItemListUpdated", getItems());
}

// TODO temp for now, need to create items generically (factory? i dont know...)
void ItemManager::createCube(std::string name, int x, int y) {
    name = name + std::to_string(_idCounter);
    _idCounter++;
    std::unique_ptr<Cube> cube = std::make_unique<Cube>(name);
    cube->setPosition(x, y);
    addItem(std::move(cube));
}

void ItemManager::addItem(std::unique_ptr<IItem> item) {
    _items.emplace(item->getId(), std::move(item));
    publishItems(); // NOTE temp, till we found another way of getting the items
}

void ItemManager::removeItem(std::string id) { _items.erase(id); }

void ItemManager::moveItemToRobot(std::string itemId, Robot *robot) {
    IItem *item = std::move(_items.at(itemId).get());
    robot->getInventory().addItem(item);
    _items.erase(itemId);
    publishItems();
}
