#include "src/app.h"

// TODO
// - create a gamefield class that contains the map, robots, items, or nothing of that? link every coordinate to a pointer, empty ones with nullptr?
int main() {

    App app;
    app.init();
    app.run();

    return 0;
}
