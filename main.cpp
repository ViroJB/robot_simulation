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

// create function to count robots

int main() {
    std::vector<Robot*> robots;
    EventDispatcher eventDispatcher;
    Map map(10, 10);

    // alle robots in nen array und dann an map übergeben, statt den roboter das updaten der map zu überlassen.. oder?

    std::vector<std::unique_ptr<Sensor>> sensors = createSensors(&eventDispatcher);
    Robot robot1(std::move(sensors), &map, &eventDispatcher, 0, 0);

    robots.push_back(&robot1);

    while (true) {
        map.printMap();

        for(auto robot : robots) {
            robot->printState();
            robot->updateState();
        }

        // sleep for 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
