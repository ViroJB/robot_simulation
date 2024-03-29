#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <memory>
#include <iostream>

#include "../items/i_item.h"

class Inventory {
   public:
    Inventory();
    void addItem(IItem *item);
    IItem* moveItem(std::string id);

   private:
    std::map<std::string, std::unique_ptr<IItem>>* _items;
};

#endif  // INVENTORY_H