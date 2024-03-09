#include "inventory.h"

Inventory::Inventory() {
}

void Inventory::addItem(std::unique_ptr<IItem> item) {
    _items.push_back(std::move(item));
}