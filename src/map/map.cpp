#include "map.h"

Map::Map(int sizeX, int sizeY) { _grid.resize(sizeX, std::vector<char>(sizeY, '.')); }

void Map::setRobots(const std::map<std::string, std::unique_ptr<Robot>> *robots) { _robots = robots; }
void Map::setItems(const std::map<std::string, std::unique_ptr<IItem>> *items) { _items = items; }

std::vector<std::vector<char>> Map::getGrid() { return _grid; }

void Map::drawRobots(const std::map<std::string, std::unique_ptr<Robot>> *robots) {
    std::pair<int, int> coordinates;

    for (auto &robot : *robots) {
        coordinates = robot.second->getPosition();
        _grid[coordinates.first][coordinates.second] = 'R';
    }
}

void Map::drawItems(const std::map<std::string, std::unique_ptr<IItem>> *items) {
    for (auto &item : *items) {
        std::pair<int, int> coordinates = item.second->getPosition();
        _grid[coordinates.first][coordinates.second] = 'i';
    }
}

void Map::prepareMap() {
    resetMap();
    if (_items != nullptr && _items->empty() == false) {
        drawItems(_items);
    }
    if (_robots != nullptr && _robots->empty() == false) {
        drawRobots(_robots);
    }
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