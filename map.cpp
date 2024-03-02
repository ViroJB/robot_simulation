#include <iostream>
#include <vector>

#include "map.h"

Map::Map(int rows, int cols) {
    grid.resize(rows, std::vector<char>(cols, '.'));
}

std::vector<std::vector<char>> Map::getGrid() {
    return grid;
}

void Map::drawRobot(int x, int y) {
    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
        resetMap();
        grid[x][y] = 'R';
    }
}

void Map::resetMap() {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell = '.';
        }
    }
}

void Map::printMap() {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}