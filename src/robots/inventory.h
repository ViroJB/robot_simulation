#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>

#include "../items/i_item.h"

class Inventory {
   public:
    Inventory();
    void addItem(std::unique_ptr<IItem> item);
    //void removeItem(std::string id);

   private:
    std::vector<std::shared_ptr<IItem>> _items;
};

#endif  // INVENTORY_H