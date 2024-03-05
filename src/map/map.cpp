#include "map.h"

Map::Map(std::vector<Robot *> *robots, int rows, int cols) {
    _grid.resize(rows, std::vector<char>(cols, '.'));
    this->_robots = robots;
}

std::vector<std::vector<char>> Map::getGrid() { return _grid; }

void Map::drawRobots(std::vector<Robot *> *robots) {
    for (auto robot : *robots) {
        std::pair<int, int> coordinates = robot->getCoordinates();
        _grid[coordinates.first][coordinates.second] = 'R';
    }
}

void Map::prepareMap() {
    resetMap();
    drawRobots(_robots);
}

void Map::resetMap() {
    for (auto &row : _grid) {
        for (auto &cell : row) {
            cell = '.';
        }
    }
}

void Map::printMap() {
    prepareMap();

    // outer border
    std::cout << std::endl;
    std::cout << "|-";
    for (int i = 0; i < _grid.size() * 2; i++) {
        std::cout << "-";
    }
    std::cout << "|";
    std::cout << '\n';

    for (const auto &row : _grid) {
        for (const auto &cell : row) {
            // outer border
            if (&cell == &row[0]) {
                std::cout << "| ";
            }

            // actual map
            std::cout << cell << ' ';

            // outer border
            if (&cell == &row[row.size() - 1]) {
                std::cout << "|";
            }
        }
        std::cout << '\n';
    }

    // outer border
    std::cout << "|-";
    for (int i = 0; i < _grid.size() * 2; i++) {
        std::cout << "-";
    }
    std::cout << "|" << std::endl << std::endl;
}