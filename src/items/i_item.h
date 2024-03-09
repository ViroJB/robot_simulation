#ifndef I_ITEM_H
#define I_ITEM_H

#include <string>

class IItem {
   private:
    std::string _id;
    int _posX, _posY;
    bool isPickable;

   public:
    std::string virtual getId() = 0;
    void virtual setPosition(int x, int y) = 0;
    std::pair<int, int> virtual getPosition() = 0;
};

#endif  // I_ITEM_H