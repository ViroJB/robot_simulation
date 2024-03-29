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
    const std::map<std::string, std::unique_ptr<Robot>> *_robots = nullptr;
    const std::map<std::string, std::unique_ptr<IItem>> *_items = nullptr;

   public:
    Map(int x, int y);
    std::vector<std::vector<char>> getGrid();
    void drawRobots(const std::map<std::string, std::unique_ptr<Robot>> *robots);
    void drawItems(const std::map<std::string, std::unique_ptr<IItem>> *items);
    void setRobots(const std::map<std::string, std::unique_ptr<Robot>> *robots);
    void setItems(const std::map<std::string, std::unique_ptr<IItem>> *items);
    void prepareMap();
    void resetMap();
    void printMap();
};

#endif  // MAP_H