#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

#include "robot.h"

class Map
{
private:
    std::vector<std::vector<char>> grid;
    std::vector<Robot *> *robots;

public:
    Map(std::vector<Robot *> *robots, int width, int height);
    std::vector<std::vector<char>> getGrid();
    void drawRobots(std::vector<Robot *> *robots);
    void prepareMap();
    void resetMap();
    void printMap();
};

#endif // MAP_H