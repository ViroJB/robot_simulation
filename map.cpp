#include "map.h"

Map::Map(std::vector<Robot*>* robots, int rows, int cols) {
    grid.resize(rows, std::vector<char>(cols, '.'));
    // get first robot from robots vector
    this->robots = robots;
}

std::vector<std::vector<char>> Map::getGrid() {
    return grid;
}

void Map::drawRobots(std::vector<Robot*>* robots) {
    for (auto robot : *robots) {
        std::pair<int, int> coordinates = robot->getCoordinates();
        grid[coordinates.first][coordinates.second] = 'R';
    }
}

void Map::prepareMap() {
    resetMap();
    drawRobots(robots);
}

void Map::resetMap() {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell = '.';
        }
    }
}

void Map::printMap() {
    prepareMap();
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}