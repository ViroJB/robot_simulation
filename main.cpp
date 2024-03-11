#include <thread>
#include <vector>
#include <map>

#include "src/debug.h"
#include "src/event_dispatcher/event_dispatcher.h"
#include "src/items/i_item.h"
#include "src/items/cube.h"
#include "src/items/item_manager.h"
#include "src/map/map.h"
#include "src/robots/robot.h"
#include "src/sensors/sensors.h"
#include "src/collision_detection/collision_detection.h"

// shared pointer weil mehrfach items pointer uebergeben?

// NEXT UP:
// items?
int main() {
    std::map<std::string, std::unique_ptr<IItem>> items;
    std::unique_ptr<Cube> cube = std::make_unique<Cube>();
    cube->setPosition(0, 7);
    items.insert(std::make_pair(cube->getId(), std::move(cube)));

    ItemManager itemManager;
    itemManager.setItems(&items);

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
    robot1.setItemManager(&itemManager);
    // robot 2
    sensors = createSensors();
    Robot robot2(std::move(sensors), &eventDispatcher, "Robot2", &collisionDetection);
    robot2.setPosition(3, 3);
    robot2.setItemManager(&itemManager);
    // robot 3
    sensors = createSensors();
    Robot robot3(std::move(sensors), &eventDispatcher, "Robot3", &collisionDetection);
    robot3.setPosition(6, 6);
    robot3.setItemManager(&itemManager);
    // robot 4
    sensors = createSensors();
    Robot robot4(std::move(sensors), &eventDispatcher, "Robot4", &collisionDetection);
    robot4.setPosition(7, 7);
    robot4.setItemManager(&itemManager);

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
