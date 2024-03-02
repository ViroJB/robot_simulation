#ifndef MAP_HPP
#define MAP_HPP

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

#endif // MAP_HPP