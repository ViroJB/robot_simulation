#include "robot_manager.h"

RobotManager::RobotManager() {
}

void RobotManager::setPublisher(Publisher *publisher) { _publisher = publisher; }

void RobotManager::setCollisionDetection(CollisionDetection *collisionDetection) { _collisionDetection = collisionDetection; }

void RobotManager::setItemManager(ItemManager *itemManager) { _itemManager = itemManager; }

void RobotManager::init() {
    // Create robots
    std::unique_ptr<Robot> robot1 = std::make_unique<Robot>("Robot1", _publisher);
    std::unique_ptr<Robot> robot2 = std::make_unique<Robot>("Robot2", _publisher);
    std::unique_ptr<Robot> robot3 = std::make_unique<Robot>("Robot3", _publisher);
    std::unique_ptr<Robot> robot4 = std::make_unique<Robot>("Robot4", _publisher);

    _robots.insert(std::make_pair(robot1->getId(), std::move(robot1)));
    _robots.insert(std::make_pair(robot2->getId(), std::move(robot2)));
    _robots.insert(std::make_pair(robot3->getId(), std::move(robot3)));
    _robots.insert(std::make_pair(robot4->getId(), std::move(robot4)));

    // setup robots
    for (auto& robot : _robots) {
        robot.second->setCollisionDetection(_collisionDetection);
        robot.second->setItemManager(_itemManager);
        robot.second->setSensors(std::move(createSensors()));
    }
}

const std::map<std::string, std::unique_ptr<Robot>>* RobotManager::getRobots() const { return &_robots; }

// vielleicht ne factory für die sensoren? (builder pattern? factory pattern?)
std::map<std::string, std::unique_ptr<ISensor>> RobotManager::createSensors() {
    std::map<std::string, std::unique_ptr<ISensor>> sensors;

    sensors.emplace("DistanceSensor", std::make_unique<DistanceSensor>());
    sensors.emplace("ItemSensor", std::make_unique<ItemSensor>());

    return sensors;
}