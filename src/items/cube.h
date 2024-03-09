#ifndef CUBE_H
#define CUBE_H

#include "i_item.h"

class Cube : public IItem {
   private:
    std::string _id = "Cube";
    int _posX, _posY;

   public:
    Cube();
    std::string getId();
    void setPosition(int x, int y);
    std::pair<int, int> getPosition();
};

#endif  // CUBE_H