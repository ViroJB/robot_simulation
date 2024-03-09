#include <thread>
#include <vector>

#include "src/debug.h"
#include "src/event_dispatcher/event_dispatcher.h"
#include "src/items/cube.h"
#include "src/items/i_item.h"
#include "src/map/map.h"
#include "src/robots/robot.h"
#include "src/sensors/sensors.h"
#include "src/collision_detection/collision_detection.h"


// NEXT UP:
// items?
int main() {
    std::vector<std::unique_ptr<IItem>> items;
    std::unique_ptr<Cube> cube = std::make_unique<Cube>();
    cube->setPosition(0, 7);
    items.push_back(std::move(cube));

    std::vector<Robot *> robots;
    EventDispatcher eventDispatcher;
    std::pair<int, int> mapSize = {10, 10};
    Map map(mapSize, &robots, &items);
    CollisionDetection collisionDetection;
    collisionDetection.setRobots(&robots);
    collisionDetection.setItems(&items);
    collisionDetection.setMapSize(mapSize);

    // robot stuff
    std::vector<std::unique_ptr<ISensor>> sensors;
    // robot 1
    sensors = createSensors();
    Robot robot1(std::move(sensors), &eventDispatcher, "Robot1", &collisionDetection);
    robot1.setPosition(0, 0);
    // robot 2
    sensors = createSensors();
    Robot robot2(std::move(sensors), &eventDispatcher, "Robot2", &collisionDetection);
    robot2.setPosition(3, 3);
    // robot 3
    sensors = createSensors();
    Robot robot3(std::move(sensors), &eventDispatcher, "Robot3", &collisionDetection);
    robot3.setPosition(6, 6);
    // robot 4
    sensors = createSensors();
    Robot robot4(std::move(sensors), &eventDispatcher, "Robot4", &collisionDetection);
    robot4.setPosition(7, 7);

    robots.push_back(&robot1);
    robots.push_back(&robot2);
    robots.push_back(&robot3);
    robots.push_back(&robot4);

    while (true) {
        map.printMap();

        for (auto robot : robots) {
            robot->updateState();
        }

        // sleep for 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
