#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/sensors/distance_sensor.h"

TEST_CASE("DistanceSensor") {
    DistanceSensor sensor;
    sensor.setTargetPosition(1, 1);
    sensor.setRobotPosition(0, 0);
    sensor.measure();
    // CHECK(sensor.getData() == 2);
}