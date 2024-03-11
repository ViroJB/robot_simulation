#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "../items/i_item.h"
#include "../robots/robot.h"

class Map {
   private:
    std::vector<std::vector<char>> _grid;
    std::vector<Robot *> *_robots;
    std::map<std::string, std::unique_ptr<IItem>> *_items;

   public:
    Map(std::pair<int, int> mapSize, std::vector<Robot *> *robots, std::map<std::string, std::unique_ptr<IItem>> *items);
    std::vector<std::vector<char>> getGrid();
    void drawRobots(std::vector<Robot *> *robots);
    void drawItems(std::map<std::string, std::unique_ptr<IItem>> *items);
    void prepareMap();
    void resetMap();
    void printMap();
};

#endif  // MAP_H