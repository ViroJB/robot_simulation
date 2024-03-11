#include "map.h"

Map::Map(std::pair<int, int> mapSize, std::vector<Robot *> *robots, std::map<std::string, std::unique_ptr<IItem>> *items) {
    _grid.resize(mapSize.first, std::vector<char>(mapSize.second, '.'));
    _robots = robots;
    _items = items;
}

std::vector<std::vector<char>> Map::getGrid() { return _grid; }

void Map::drawRobots(std::vector<Robot *> *robots) {
    for (auto robot : *robots) {
        std::pair<int, int> coordinates = robot->getPosition();
        _grid[coordinates.first][coordinates.second] = 'R';
    }
}

void Map::drawItems(std::map<std::string, std::unique_ptr<IItem>> *items) {
    for (auto &item : *items) {
        std::pair<int, int> coordinates = item.second->getPosition();
        _grid[coordinates.first][coordinates.second] = 'I';
    }
}

void Map::prepareMap() {
    resetMap();
    drawItems(_items);
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