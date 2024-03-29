#include "cube.h"

Cube::Cube() {}
Cube::Cube(std::string id) : _id(id) {}

std::string Cube::getId() { return _id; }

void Cube::setPosition(int x, int y) {
    _posX = x;
    _posY = y;
}



std::pair<int, int> Cube::getPosition() { return std::make_pair(_posX, _posY); }