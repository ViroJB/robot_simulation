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
    _itemManager->init(); // muss erstmal hier unten sein, nach robotmanager init, wegen event publishing...

    // TODO remove
    // _publisher->subscribe("testevent", std::bind(&App::testEvent, this, std::placeholders::_1));
    // _publisher->subscribe("testevent", [this](const std::any& data) { this->testEvent(data); });
}

void App::run() {
    int counter = 1;  // 1-indexed! Ha ha.. ha
    while (true) {
        // clear console window (thanks copilot)
        std::cout << "\033[2J\033[1;1H";

        _map->printMap();

        for (auto &robot : *_robotManager->getRobots()) {
            robot.second->updateState();
        }

        // alle 15 ticks ein item spawnen
        if (counter % 10 == 0) {
            _itemManager->createCube("Cube0" + counter, rand() % (Config::MAP_SIZE_X -1), rand() % (Config::MAP_SIZE_Y -1));
        }

        std::cout << "Counter: " << counter << std::endl;
        counter++;

        // TODO remove
        // _publisher->publish("testevent", std::make_pair(101, 202));

        // sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}
