#include "cube.h"

Cube::Cube() {}

std::string Cube::getId() { return _id; }

void Cube::setPosition(int x, int y) {
    this->_posX = x;
    this->_posY = y;
}

std::pair<int, int> Cube::getPosition() { return std::make_pair(_posX, _posY); }