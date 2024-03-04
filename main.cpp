#include <thread>
#include <vector>

#include "robot.h"
#include "distance_sensor.h"
#include "map.h"
#include "event_dispatcher.h"

// den shit hier irgendwoanders hin
// und vielleicht ne factory für die sensoren? (builder pattern? factory pattern?)
std::vector<std::unique_ptr<Sensor>> createSensors(EventDispatcher *eventDispatcher)
{
    std::vector<std::unique_ptr<Sensor>> sensors;

    sensors.push_back(std::make_unique<DistanceSensor>(eventDispatcher));

    return sensors;
}

// NEXT UP:
// hmmmmm
int main()
{
    std::vector<Robot *> robots;
    EventDispatcher eventDispatcher;
    int mapSizeX = 10;
    int mapSizeY = 10;
    Map map(&robots, mapSizeX, mapSizeY);

    std::vector<std::unique_ptr<Sensor>> sensors;
    // robot 1
    sensors = createSensors(&eventDispatcher);
    Robot robot1(std::move(sensors), &eventDispatcher, "Robot1", 0, 0, mapSizeX, mapSizeY);
    // robot 2
    sensors = createSensors(&eventDispatcher);
    Robot robot2(std::move(sensors), &eventDispatcher, "Robot2", 3, 3, mapSizeX, mapSizeY);
    // robot 3
    sensors = createSensors(&eventDispatcher);
    Robot robot3(std::move(sensors), &eventDispatcher, "Robot3", 6, 6, mapSizeX, mapSizeY);
    // robot 4
    sensors = createSensors(&eventDispatcher);
    Robot robot4(std::move(sensors), &eventDispatcher, "Robot4", 7, 7, mapSizeX, mapSizeY);

    robots.push_back(&robot1);
    robots.push_back(&robot2);
    robots.push_back(&robot3);
    robots.push_back(&robot4);

    while (true)
    {
        map.printMap();

        for (auto robot : robots)
        {
            #if DEBUG
                robot->printState();
            #endif
            robot->updateState();
        }

        // sleep for 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
