#ifndef I_ITEM_H
#define I_ITEM_H

#include <string>

class IItem {
   private:
    std::string id_;

   public:
    std::string virtual getId() = 0;
};

#endif  // I_ITEM_H