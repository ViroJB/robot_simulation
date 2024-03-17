#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include <utility>

class PathFinder {
    public:
     static std::pair<int, int> getNextMove(int startX, int startY, int endX, int endY);
    private:
};

#endif  // PATH_FINDER_H