#include "inventory.h"

Inventory::Inventory() {
    _items = new std::map<std::string, std::unique_ptr<IItem>>;
}

void Inventory::addItem(IItem *item) {
    std::cout << "Inventory Size before: " << _items->size() << std::endl;
    _items->emplace(item->getId(), std::unique_ptr<IItem>(item));
    std::cout << "Inventory Size after: " << _items->size() << std::endl;
}