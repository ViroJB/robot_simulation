#ifndef CUBE_H
#define CUBE_H

#include "i_item.h"

class Cube : IItem {
   private:
    std::string _id = "Cube";

   public:
    Cube();
    std::string getId();
};

#endif  // CUBE_H