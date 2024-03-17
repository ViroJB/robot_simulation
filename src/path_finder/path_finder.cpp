#include "path_finder.h"

std::pair<int, int> PathFinder::getNextMove(int startX, int startY, int targetX, int targetY) {
    // find next move
    std::pair<int, int> nextMove;
    if (startX < targetX) {
        // move right
        nextMove = std::make_pair(startX + 1, startY);
    } else if (startX > targetX) {
        // move left
        nextMove = std::make_pair(startX - 1, startY);
    } else if (startY < targetY) {
        // move down
        nextMove = std::make_pair(startX, startY + 1);
    } else if (startY > targetY) {
        // move up
        nextMove = std::make_pair(startX, startY - 1);
    } else {
        // already at target
        nextMove = std::make_pair(startX, startY);
    }
    return nextMove;
}