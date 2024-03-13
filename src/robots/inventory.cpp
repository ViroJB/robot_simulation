#include "inventory.h"

Inventory::Inventory() {
    _items = new std::map<std::string, std::unique_ptr<IItem>>;
}

void Inventory::addItem(IItem *item) {
    _items->emplace(item->getId(), std::unique_ptr<IItem>(item));
}

IItem* Inventory::moveItem(std::string id) {
    IItem* item = std::move(_items->at(id).get());
    _items->erase(id);
    return item;
}