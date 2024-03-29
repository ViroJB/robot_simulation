#include <cstdlib>
#include <ctime>
#include <map>
#include <thread>
#include <vector>

#include "src/collision_detection/collision_detection.h"
#include "src/debug.h"
#include "src/event_dispatcher/event_dispatcher.h"
#include "src/items/cube.h"
#include "src/items/i_item.h"
#include "src/items/item_manager.h"
#include "src/map/map.h"
#include "src/robots/robot.h"
#include "src/sensors/sensors.h"
#include "src/path_finder/path_finder.h"

#include "src/app.h"

// TODO
// - create an app class that containts the loop and gives access to stuff like the map, robots, items, etc
// - create a gamefield class that contains the map, robots, items, or nothing of that? link every coordinate to a pointer, empty ones with nullptr?
int main() {
    // seed rand with current time
    // srand(static_cast<unsigned int>(time(nullptr)));

    // std::unique_ptr<ItemManager> itemManager = std::make_unique<ItemManager>();
    // std::unique_ptr<EventDispatcher> eventDispatcher = std::make_unique<EventDispatcher>();
    // std::map<std::string, std::unique_ptr<Robot>> robots; // <-- put into robotManager
    // std::map<std::string, std::unique_ptr<IItem>> items; // <-- put into itemManager
    // PathFinder pathFinder;

    // Map map(10, 10);

    // map.setRobots(&robots);
    // map.setItems(&items);

    // CollisionDetection collisionDetection;
    // collisionDetection.setRobots(&robots);
    // collisionDetection.setItems(&items);
    // collisionDetection.setMapSize(std::pair<int, int>(10, 10));

    // // robot stuff
    // std::unique_ptr<Robot> robot1 = std::make_unique<Robot>("Robot1", eventDispatcher.get());
    // std::unique_ptr<Robot> robot2 = std::make_unique<Robot>("Robot2", eventDispatcher.get());
    // std::unique_ptr<Robot> robot3 = std::make_unique<Robot>("Robot3", eventDispatcher.get());
    // std::unique_ptr<Robot> robot4 = std::make_unique<Robot>("Robot4", eventDispatcher.get());

    // robots.insert(std::make_pair(robot1->getId(), std::move(robot1)));
    // // robots.insert(std::make_pair(robot2->getId(), std::move(robot2)));
    // // robots.insert(std::make_pair(robot3->getId(), std::move(robot3)));
    // // robots.insert(std::make_pair(robot4->getId(), std::move(robot4)));


    // // setup robots
    // std::vector<std::unique_ptr<ISensor>> sensors;
    // for (auto &robot : robots) {
    //     robot.second->setCollisionDetection(&collisionDetection);
    //     robot.second->setItemManager(itemManager.get());
    //     sensors = createSensors();
    //     robot.second->setSensors(std::move(sensors));
    // }

    // itemManager->setItems(&items);

    // int counter = 1; // 1-indexed! Ha ha.. ha
    // while (true) {
    //     // clear console window (thanks copilot)
    //     // std::cout << "\033[2J\033[1;1H";

    //     map.printMap();

    //     for (auto &robot : robots) {
    //         robot.second->updateState();
    //     }

    //     std::cout << "Counter: " << counter << std::endl;
    //     counter++;

    //     // sleep
    //     std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // }

    App app;
    app.init();
    app.run();

    return 0;
}
