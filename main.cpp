#include <thread>
#include <vector>

#include "robot.h"
#include "distance_sensor.h"
#include "map.h"
#include "event_dispatcher.h"


// den shit hier irgendwoanders hin
// und vielleicht ne factory für die sensoren? (builder pattern? factory pattern?)
std::vector<std::unique_ptr<Sensor>> createSensors(EventDispatcher* eventDispatcher) {
    std::vector<std::unique_ptr<Sensor>> sensors;

    sensors.push_back(std::make_unique<DistanceSensor>(eventDispatcher));

    return sensors;
}


int main() {

    int mapSizeX = 10;
    int mapSizeY = 10;

    std::vector<Robot*> robots;
    EventDispatcher eventDispatcher;
    Map map(&robots, mapSizeX, mapSizeY);

    std::vector<std::unique_ptr<Sensor>> sensors = createSensors(&eventDispatcher);
    Robot robot1(std::move(sensors), &eventDispatcher, 0, 0, mapSizeX, mapSizeY);

    std::vector<std::unique_ptr<Sensor>> sensors2 = createSensors(&eventDispatcher);
    Robot robot2(std::move(sensors2), &eventDispatcher, 3, 3, mapSizeX, mapSizeY);

    robots.push_back(&robot1);
    robots.push_back(&robot2);
    

    while (true) {
        map.printMap();

        for(auto robot : robots) {
            // robot->printState();
            robot->updateState();
        }

        // sleep for 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
