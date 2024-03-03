#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

class Map {
    private:
        std::vector<std::vector<char>> grid;

    public:
        Map(int rows, int cols);
        void drawRobot(int x, int y);
        std::vector<std::vector<char>> getGrid();
        void resetMap();
        void printMap();
};

#endif // MAP_H