#include "app.h"

App::App() {}

void App::init() {
    srand(static_cast<unsigned int>(time(nullptr)));

    _itemManager = std::make_unique<ItemManager>();
    _pathFinder = std::make_unique<PathFinder>();
    _collisionDetection = std::make_unique<CollisionDetection>();
    _map = std::make_unique<Map>(Config::MAP_SIZE_X, Config::MAP_SIZE_Y);
    _robotManager = std::make_unique<RobotManager>();
    _publisher = std::make_unique<Publisher>();

    _map->setRobots(_robotManager->getRobots());
    _map->setItems(_itemManager->getItems());
    _collisionDetection->setMapSize(std::pair<int, int>(Config::MAP_SIZE_X, Config::MAP_SIZE_Y));
    _collisionDetection->setRobots(_robotManager->getRobots());
    _collisionDetection->setItems(_itemManager->getItems());
    _robotManager->setPublisher(_publisher.get());
    _robotManager->setCollisionDetection(_collisionDetection.get());
    _robotManager->setItemManager(_itemManager.get());
    _robotManager->init();
    _itemManager->setPublisher(_publisher.get());
    _itemManager->init();  // gotta be here for now, after robot manager init, because of event publishing order..

    // TODO remove
    // _publisher->subscribe("testevent", std::bind(&App::testEvent, this, std::placeholders::_1));
    // _publisher->subscribe("testevent", [this](const std::any& data) { this->testEvent(data); });
}

void App::run() {
    int counter = 1;  // 1-indexed! Ha ha.. ha
    int itemIndex = 0;
    while (true) {
        // clear console window (thanks copilot)
        // std::cout << "\033[2J\033[1;1H";
        // std::cout << "Counter: " << counter << std::endl; // for no thread-sleep visibility of the counter
        _map->printMap();

        for (auto &robot : *_robotManager->getRobots()) {
            robot.second->updateState();
        }

        // temp: every 15 ticks spawn items
        if (counter % 10 == 0) {
            _itemManager->createCube("Cube0" + itemIndex, rand() % (Config::MAP_SIZE_X - 1),
                                     rand() % (Config::MAP_SIZE_Y - 1));
            itemIndex++;
            _itemManager->createCube("Cube0" + itemIndex, rand() % (Config::MAP_SIZE_X - 1),
                                     rand() % (Config::MAP_SIZE_Y - 1));
            itemIndex++;
        }

        std::cout << "Counter: " << counter << std::endl;
        counter++;

        // sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}
