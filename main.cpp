#include <thread>
#include <vector>

#include "robot.h"
#include "distance_sensor.h"
#include "map.h"
#include "event_dispatcher.h"

// TODO eventdispatcher dispatch with data
int main() {
    EventDispatcher eventDispatcher;
    // std::vector<Robot> robots;
    Map map = Map(10, 10);
   
    Robot robot1(&map, &eventDispatcher, 0, 0);

    // find a way to put this into Robot class and so it can be dynamic for different robots
    DistanceSensor distanceSensor(&eventDispatcher);
    robot1.addSensor(&distanceSensor);

    // robots.push_back(robot1);

    while (true) {
        map.printMap();
        robot1.printState();

        robot1.updateState();

        // sleep for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
