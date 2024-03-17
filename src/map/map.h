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
    std::map<std::string, std::unique_ptr<Robot>> *_robots = nullptr;
    std::map<std::string, std::unique_ptr<IItem>> *_items = nullptr;

   public:
    Map(std::pair<int, int> mapSize);
    std::vector<std::vector<char>> getGrid();
    void drawRobots(std::map<std::string, std::unique_ptr<Robot>> *robots);
    void drawItems(std::map<std::string, std::unique_ptr<IItem>> *items);
    void setRobots(std::map<std::string, std::unique_ptr<Robot>> *robots);
    void setItems(std::map<std::string, std::unique_ptr<IItem>> *items);
    void prepareMap();
    void resetMap();
    void printMap();
};

#endif  // MAP_H